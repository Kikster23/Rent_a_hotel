//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainKorisnik.h"
#include "NovaRezervacija.h"
#include "MojeRezervacije.h"
#include "PonudaHotela.h"
#include "InfoRecepcije.h"
#include "Postavke.h"
#include "Login.h"
#include <IniFiles.hpp>
#include <map>
#include <registry.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
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
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	translation["Ponuda"] = {
		{"EN", "Watch hotel offer"},
		{"HR", "Pogledajte ponudu hotela"}
	};
	translation["Info"] = {
		{"EN", "About a receptions"},
		{"HR", "Informacije o recepcijama"}
	};
	translation["NovaRezervacija"] = {
		{"EN", "New reservation"},
		{"HR", "Nova rezervacija"}
	};
    translation["MojeRezervacije"] = {
		{"EN", "My reservations"},
		{"HR", "Moje rezervacije"}
	};
	translation["Odjava"] = {
		{"EN", "Sign out"},
		{"HR", "Odjevi se"}
	};
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::NovaRezervacijaClick(TObject *Sender)
{
Hide();
Form10->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::MojeRezervacijeClick(TObject *Sender)
{
Hide();
Form11->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::PonudaClick(TObject *Sender)
{
Hide();
Form13->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm3::InfoClick(TObject *Sender)
{
Hide();
Form12->Show();

}
//---------------------------------------------------------------------------

void __fastcall TForm3::OdjavaClick(TObject *Sender)
{
	Hide();
    Form1->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm3::FormShow(TObject *Sender)
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

