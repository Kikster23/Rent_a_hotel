//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.DateUtils.hpp>
#include <IniFiles.hpp>
#include <registry.hpp>
#pragma hdrstop

#include "NovaRezervacija.h"
#include "MainKorisnik.h"
#include "TrenutniID.h"
#include "Postavke.h"
#include ".\DLLForma\Pogreska.h"
#include ".\DLLForma\Dobro.h"
#include <IniFiles.hpp>
#include <map>
#include <registry.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
void translateForm(TForm* Form, String Language, const std::map<String, std::map<String, String>>& translation){
	for(int i = 0; i < Form->ComponentCount; i++)
        for(auto it_ComponentName = translation.begin(); it_ComponentName != translation.end(); it_ComponentName++)
			if(Form->Components[i]->Name == it_ComponentName->first)
                for(auto it_Language = it_ComponentName->second.begin(); it_Language != it_ComponentName->second.end(); it_Language++)
					if(it_Language->first == Language)
                        if(IsPublishedProp(Form->Components[i], "Caption"))
                            SetPropValue(Form->Components[i], "Caption", it_Language->second);
}
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
	: TForm(Owner)
{
	translation["Povratak"] = {
		{"EN", "Back"},
		{"HR", "Povratak"}
	};
	translation["Rezerviraj"] = {
		{"EN", "Make a reservation"},
		{"HR", "Rezerviraj"}
	};
	translation["Label1"] = {
		{"EN", "From:"},
		{"HR", "Od:"}
	};
	translation["Label2"] = {
		{"EN", "To:"},
		{"HR", "Do:"}
	};
	translation["Label3"] = {
		{"EN", "Choose a hotel:"},
		{"HR", "Odaberi hotel:"}
	};
}
//---------------------------------------------------------------------------
void __fastcall TForm10::PovratakClick(TObject *Sender)
{
Hide();
Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm10::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm10::RezervirajClick(TObject *Sender)
{
		int HotelID = DataSource1->DataSet->FieldByName("Hotel_ID")->AsInteger;
		int cijenaDan = DataSource1->DataSet->FieldByName("Cijena_Dan")->AsInteger;
		int dani = DaysBetween(DateTimeDo->Date, DateTimeOd->Date);
		if(DateTimeOd->Date>=DateTimeDo->Date){
        HINSTANCE hInstDLL = LoadLibrary(L"DLLForma.dll");
			if (hInstDLL == NULL) {
				ShowMessage("Ne može uèitati DLL.");
			}
			else {
				TDLLForm1* Form = new TDLLForm1(this);
				Form->Label1->Caption ="Ne može datum do kada rezervirate biti\n prije od kada ga uzimate.";
				Form->Show();
				FreeLibrary(hInstDLL);
			}
		}else{
		double ukupno = cijenaDan * dani;
		ADOTable2->Insert();
		ADOTable2->FieldByName("Korisnik_ID")->AsInteger = TrenutniID;
		ADOTable2->FieldByName("Hotel_ID")->AsInteger = HotelID;
		ADOTable2->FieldByName("Datum_OD")->AsDateTime = DateTimeOd->Date;
		ADOTable2->FieldByName("Datum_DO")->AsDateTime = DateTimeDo->Date;
		ADOTable2->FieldByName("Ukupna_Cijena")->AsFloat = ukupno;
		ADOTable2->Post();
        HINSTANCE hInstDLL = LoadLibrary(L"DLLForma.dll");
			if (hInstDLL == NULL) {
				ShowMessage("Ne može uèitati DLL.");
			}
			else {
				TDLLForm2* Form = new TDLLForm2(this);
				Form->Label1->Caption ="Uspješno ste rezervirali hotel od "+DateToStr(DateTimeOd->Date)+"\n do "+DateToStr(DateTimeDo->Date);
				Form->Show();
				FreeLibrary(hInstDLL);
			}
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm10::FormShow(TObject *Sender)
{
String jezik;
    TIniFile *ini = new TIniFile(GetCurrentDir() + "\\jezik.INI");
    jezik = ini->ReadString("Postavke", "Jezik", "HR");
    delete ini;
	translateForm(this,jezik,translation);
    String vrstaFonta;
    TIniFile *ini1 = new TIniFile(GetCurrentDir() + "\\vrsta.INI");
    vrstaFonta = ini1->ReadString("Postavke", "Vrsta", "Arial");
    delete ini1;

	String tema;
    TRegistry *reg = new TRegistry(KEY_READ);
    reg->RootKey = HKEY_CURRENT_USER;
    if (reg->OpenKey("\\Software\\MojaAplikacija\\Postavke", false)) {
        tema = reg->ReadString("Tema");
        reg->CloseKey();
    }
    delete reg;

    int velicinaFonta = 10;
    TRegistry *reg1 = new TRegistry(KEY_READ);
    reg1->RootKey = HKEY_CURRENT_USER;
    if (reg1->OpenKey("\\Software\\MojaAplikacija\\Postavke", false)) {
        velicinaFonta = StrToIntDef(reg1->ReadString("Velicina"), 10);
        reg1->CloseKey();
    }
    delete reg1;

    if (tema == "Svjetla")
        this->Color = TColor(RGB(229, 229, 229));
    else if (tema == "Tamna")
		this->Color = TColor(RGB(102, 102, 102));

    for(int i = 0; i < this->ControlCount; i++) {
        TLabel *lbl = dynamic_cast<TLabel*>(this->Controls[i]);
        if (lbl) {
            lbl->Font->Name = vrstaFonta;
            lbl->Font->Size = velicinaFonta;
            continue;
        }
        TButton *btn = dynamic_cast<TButton*>(this->Controls[i]);
        if (btn) {
            btn->Font->Name = vrstaFonta;
            btn->Font->Size = velicinaFonta;
            continue;
        }
        TEdit *edit = dynamic_cast<TEdit*>(this->Controls[i]);
        if (edit) {
            edit->Font->Name = vrstaFonta;
            edit->Font->Size = velicinaFonta;
            continue;
        }
    }

}
//---------------------------------------------------------------------------


void __fastcall TForm10::DBGrid1TitleClick(TColumn *Column)
{
if (ADOTable1->IndexFieldNames == "Cijena_Dan DESC")
    ADOTable1->IndexFieldNames = "Cijena_Dan ASC";
else
    ADOTable1->IndexFieldNames = "Cijena_Dan DESC";
}
//---------------------------------------------------------------------------


void __fastcall TForm10::ADOTable1CalcFields(TDataSet *DataSet)
{
const double PDV = 0.25;
    double baza = DataSet->FieldByName("Cijena_Dan")->AsFloat;
    DataSet->FieldByName("Cijena_Dan_PDV")->AsFloat = baza * (1.0 + PDV);
}
//---------------------------------------------------------------------------

