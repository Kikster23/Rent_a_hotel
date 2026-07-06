//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <Vcl.StdCtrls.hpp>
#include "Login.h"
#include "MainKorisnik.h"
#include "MainAdmin.h"
#include "Registracija.h"
#include "XMLLogovi.h"
#include "TrenutniID.h"
#include ".\DLLForma\Pogreska.h"
#include ".\DLLForma\Dobro.h"
#include "Postavke.h"
#include <IniFiles.hpp>
#include <map>
#include <registry.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_CryptographicLibrary"
#pragma link "uTPLb_Hash"
#pragma resource "*.dfm"
TForm1 *Form1;
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
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	translation["Label2"] = {
		{"EN", "Password:"},
		{"HR", "Lozinka:"}
	};
	translation["Prijava"] = {
		{"EN", "Log in:"},
		{"HR", "Prijava:"}
	};
    translation["Registracija"] = {
		{"EN", "Sign up:"},
		{"HR", "Registracija:"}
	};
}
class Prijava1{
	public:
	Prijava1();
	Prijava1(String i,String p){
	ime=i;
	prezime=p;
	}
	String ime,prezime;
	String recenica(){
          return "Pozdrav "+ime+" "+prezime+"!";
	}
	void Pozdrav(String p){
    ShowMessage(p);
	}
};
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------
String Stream_To_Hex(TStream* stream) {
    stream->Position = 0;
    String result = "";
	unsigned char byte;

    while (stream->Read(&byte, 1) == 1) {
        result += IntToHex(byte, 2);
    }
    return result;
}
bool isLozinkaTocna=false;
void __fastcall TForm1::PrijavaClick(TObject *Sender)
{
	String unesenaLozinka = EditLozinka->Text.Trim();
	String email=EditEmail->Text.Trim();
    ADOQuery1->Close();
	ADOQuery1->SQL->Text =
		"SELECT Lozinka, Tip,Korisnik_ID,Ime,Prezime FROM Korisnici WHERE Email=:email";
    ADOQuery1->Parameters->ParamByName("Email")->Value = EditEmail->Text.Trim();
    ADOQuery1->Open();

    if (ADOQuery1->RecordCount == 1)
	{
		String hashLozinka = ADOQuery1->FieldByName("Lozinka")->AsString;
		String tipKorisnika = ADOQuery1->FieldByName("Tip")->AsString;
		String ime= ADOQuery1->FieldByName("Ime")->AsString;
        String prezime= ADOQuery1->FieldByName("Prezime")->AsString;
		int id = ADOQuery1->FieldByName("Korisnik_ID")->AsInteger;
		Hash2->HashString(email, TEncoding::UTF8);
		String sol=Stream_To_Hex(Hash2->HashOutputValue);
		String hashUnesene=unesenaLozinka+sol;
		for(int i=0;i<=100;i++){
		String hashUnesene2=hashUnesene+i;
		Hash1->HashString(hashUnesene2,TEncoding::UTF8);
		String hashUnesene3=Stream_To_Hex(Hash1->HashOutputValue);

		if (hashUnesene3 == hashLozinka)
		{
			_di_IXMLlogoviType Logovi= Getlogovi(XMLDocument1);
			_di_IXMLlogType Log= Logovi->Add();
            String today = FormatDateTime(L"yyyy-mm-dd", Date());
			Log->datum = today;
			Log->id=IntToStr(id);
			Log->aktivnost="Prijava";
            XMLDocument1->SaveToFile(XMLDocument1->FileName);
			if (tipKorisnika == "Admin") {
                TrenutniID=id;
				Form4->Show();
			} else {
				Prijava1 p(ime,prezime);
				p.Pozdrav(p.recenica());
				TrenutniID=id;
                Form3->Show();
			}
            isLozinkaTocna=true;
            this->Hide();
		}
		}
         if (!isLozinkaTocna) {
            HINSTANCE hInstDLL = LoadLibrary(L"DLLForma.dll");
            if (hInstDLL == NULL) {
                ShowMessage("Ne može uèitati DLL.");
            }
            else {
                TDLLForm1* Form = new TDLLForm1(this);
                Form->Label1->Caption = "Pogrešna lozinka.";
                Form->Show();
				FreeLibrary(hInstDLL);
            }
        }
	}else{
		HINSTANCE hInstDLL = LoadLibrary(L"DLLForma.dll");
		if (hInstDLL == NULL)
		{
		ShowMessage("Ne moze ucitati.");
		}
		TDLLForm1* Form = new TDLLForm1(this);
		Form->Label1->Caption="Ne postoji email.";
		Form->Show();
        FreeLibrary(hInstDLL);

	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RegistracijaClick(TObject *Sender)
{
	Hide();
    Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	HINSTANCE pngDll;
	if((pngDll = LoadLibrary(L"DLLForma.dll"))==NULL) {
        ShowMessage("Cannot load mydll.dll!");
        return;
    }
	TResourceStream* rs = new TResourceStream((int)pngDll, "settings", RT_RCDATA);
    Image1->Picture->LoadFromStream(rs);
    delete rs;
	FreeLibrary(pngDll);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image1Click(TObject *Sender)
{
    Hide();
    Form14->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseEnter(TObject *Sender)
{
Image1->Cursor = crHandPoint;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
	String jezik;
    int velicinaFonta;
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

