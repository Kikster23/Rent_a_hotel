//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.JSON.hpp>
#pragma hdrstop

#include "InfoRecepcije.h"
#include "MainKorisnik.h"
#include <IniFiles.hpp>
#include <map>
#include <registry.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm12 *Form12;
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
__fastcall TForm12::TForm12(TComponent* Owner)
	: TForm(Owner)
{
translation["Label1"] = {
		{"EN", "About a receptions:"},
		{"HR", "Informacije o recepcijama:"}
	};
	translation["Povratak"] = {
		{"EN", "Back:"},
		{"HR", "Povratak:"}
	};
}
//---------------------------------------------------------------------------
void __fastcall TForm12::PovratakClick(TObject *Sender)
{
Hide();
Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm12::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm12::FormShow(TObject *Sender)
{
	std::unique_ptr<TStringStream> jsonStream(new TStringStream);
	jsonStream->LoadFromFile("recepcije.json");
	TJSONObject* recepcije =(TJSONObject*)TJSONObject::ParseJSONValue(jsonStream->DataString);
	TJSONArray* recepcije_p = (TJSONArray*)TJSONObject::ParseJSONValue(recepcije->GetValue("recepcije")->ToString());
	ListView1->Items->Clear();
    for (int i = 0; i < recepcije_p->Count; i++) {
	String ime          = recepcije_p->Items[i]->GetValue<UnicodeString>("ime");
	String grad        = recepcije_p->Items[i]->GetValue<UnicodeString>("grad");
	String brojTelefona  = recepcije_p->Items[i]->GetValue<UnicodeString>("broj_telefona");
	String email  = recepcije_p->Items[i]->GetValue<UnicodeString>("email");
	String radnoVrijeme  = recepcije_p->Items[i]->GetValue<UnicodeString>("radnovrijeme");
    ListView1->Items->Add();
	ListView1->Items->Item[i]->Caption = ime;
	ListView1->Items->Item[i]->SubItems->Add(grad);
	ListView1->Items->Item[i]->SubItems->Add(brojTelefona);
	ListView1->Items->Item[i]->SubItems->Add(email);
	ListView1->Items->Item[i]->SubItems->Add(radnoVrijeme);
	}
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

