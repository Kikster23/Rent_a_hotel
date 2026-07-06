//---------------------------------------------------------------------------

#include <vcl.h>
#include <IniFiles.hpp>
#include <registry.hpp>
#pragma hdrstop

#include "Registracija.h"
#include "staticno.h"
#include "Login.h"
#include "XMLLogovi.h"
#include "Postavke.h"
#include ".\DLLForma\Pogreska.h"
#include ".\DLLForma\Dobro.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_CryptographicLibrary"
#pragma link "uTPLb_Hash"
#pragma resource "*.dfm"
TForm2 *Form2;
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
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	translation["Povratak"] = {
		{"EN", "Back:"},
		{"HR", "Povratak:"}
	};
	translation["Registriraj"] = {
		{"EN", "Sign up:"},
		{"HR", "Registriraj se:"}
	};
	translation["Label1"] = {
		{"EN", "Name:"},
		{"HR", "Ime:"}
	};
	translation["Label2"] = {
		{"EN", "Surname:"},
		{"HR", "Prezime:"}
	};
    translation["Label4"] = {
		{"EN", "Password:"},
		{"HR", "Lozinka:"}
	};
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
int korisnikID=0;
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
void __fastcall TForm2::RegistirajClick(TObject *Sender)
{
	String email=EditEmail->Text.Trim();
	String OIB=EditOIB->Text;
    String txt="";
	PrijavaKorisnik korisnik(email,OIB);
	if(!korisnik.ProvjeraEmail()){
	txt=txt+"Nije u @gmail.formatu\n";
	}
	if(!korisnik.ProvjeraOIB11()){
	txt=txt+"Nema 11 znakova.\n";
	}
	if(!korisnik.ProvjeraOIBBrojevi()){
	txt=txt+"OIB sadrži samo brojeve.";
	}
    if(txt!=""){
            HINSTANCE hInstDLL = LoadLibrary(L"DLLForma.dll");
			if (hInstDLL == NULL) {
				ShowMessage("Ne može uèitati DLL.");
			}
			else {
				TDLLForm1* Form = new TDLLForm1(this);
				Form->Label1->Caption =txt;
				Form->Show();
				FreeLibrary(hInstDLL);
			}
	}else{
        String email=EditEmail->Text.Trim();
		String lozinka=EditLozinka->Text.Trim();

		Hash2->HashString(email, TEncoding::UTF8);
		String sol=Stream_To_Hex(Hash2->HashOutputValue);
		String hashUnesene=lozinka+sol;
		String hashUnesene2=hashUnesene+Random(100);
		Hash1->HashString(hashUnesene2,TEncoding::UTF8);
		String hashUnesene3=Stream_To_Hex(Hash1->HashOutputValue);
        TKorisnici->Append();

		TKorisnici->FieldByName("Ime")->AsString = EditIme->Text;
		TKorisnici->FieldByName("Prezime")->AsString = EditPrezime->Text;
		TKorisnici->FieldByName("Email")->AsString = EditEmail->Text;
		TKorisnici->FieldByName("Lozinka")->AsString = hashUnesene3;
		TKorisnici->FieldByName("OIB")->AsString = EditOIB->Text;
		TKorisnici->FieldByName("Tip")->AsString = "Korisnik";
		TKorisnici->Post();

        if (TKorisnici->Locate("Email", email, TLocateOptions())) {
		korisnikID = TKorisnici->FieldByName("Korisnik_ID")->AsInteger;
        }
        _di_IXMLlogoviType Logovi= Getlogovi(XMLDocument1);
		_di_IXMLlogType Log= Logovi->Add();
		String today = FormatDateTime(L"yyyy-mm-dd", Date());
		Log->datum = today;
		Log->id=korisnikID;
		Log->aktivnost="Registracija";
		XMLDocument1->SaveToFile(XMLDocument1->FileName);
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm2::PovratakClick(TObject *Sender)
{
	Hide();
    Form1->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormShow(TObject *Sender)
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

