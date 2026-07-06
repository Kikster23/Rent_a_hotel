//---------------------------------------------------------------------------

#include <vcl.h>
#include <IniFiles.hpp>
#include <registry.hpp>
#include <map>
#pragma hdrstop
#include "Postavke.h"
#include "Login.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm14 *Form14;
//---------------------------------------------------------------------------
__fastcall TForm14::TForm14(TComponent* Owner)
	: TForm(Owner)
{       translation["Label3"] = {
		{"EN", "Language:"},
		{"HR", "Jezik:"}
		};
		translation["Label4"] = {
		{"EN", "Theme:"},
		{"HR", "Tema:"}
	};
    translation["Label2"] = {
		{"EN", "Font-type:"},
		{"HR", "Vrsta fonta::"}
	};
	translation["Label1"] = {
		{"EN", "Font-size:"},
		{"HR", "Velièina fonta:"}
	};
}
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
void __fastcall TForm14::Button1Click(TObject *Sender)
{
	TIniFile *ini = new TIniFile(GetCurrentDir() + "\\jezik.INI");
	ini->WriteString("Postavke", "Jezik",ComboJezik->Text);
	delete ini;
	TIniFile *ini1 = new TIniFile(GetCurrentDir() + "\\vrsta.INI");
	ini1->WriteString("Postavke", "Vrsta",ComboVrsta->Text);
	delete ini1;
    TRegistry *reg = new TRegistry(KEY_WRITE);
    reg->RootKey = HKEY_CURRENT_USER;
    if(reg->OpenKey("\\Software\\MojaAplikacija\\Postavke", true))
    {
        reg->WriteString("Tema", ComboTema->Text);
        reg->CloseKey();
    }
	delete reg;
	TRegistry *reg1 = new TRegistry(KEY_WRITE);
	reg1->RootKey = HKEY_CURRENT_USER;
	if(reg1->OpenKey("\\Software\\MojaAplikacija\\Postavke", true))
    {
		reg1->WriteString("Velicina", ComboVelicina->Text);
		reg1->CloseKey();
	}
	delete reg1;
    int velicinaFonta = StrToIntDef(ComboVelicina->Text, 10);
	translateForm(this,ComboJezik->Text,translation);
	if (ComboTema->Text == "Svjetla")
		this->Color = TColor(RGB(229, 229, 229));
	else if (ComboTema->Text == "Tamna")
		this->Color = TColor(RGB(102, 102, 102));

    for(int i = 0; i < this->ControlCount; i++) {
		TLabel *lbl = dynamic_cast<TLabel*>(this->Controls[i]);
		if (lbl) {
			lbl->Font->Name = ComboVrsta->Text;
			lbl->Font->Size = velicinaFonta;
			continue;
		}
        TButton *btn = dynamic_cast<TButton*>(this->Controls[i]);
		if (btn) {
			btn->Font->Name = ComboVrsta->Text;
			btn->Font->Size = velicinaFonta;
			continue;
		}
		TEdit *edit = dynamic_cast<TEdit*>(this->Controls[i]);
		if (edit) {
			edit->Font->Name = ComboVrsta->Text;
			edit->Font->Size = velicinaFonta;
			continue;
		}
	}
   

}
//---------------------------------------------------------------------------
void __fastcall TForm14::FormClose(TObject *Sender, TCloseAction &Action)
{
	Hide();
    Form1->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm14::FormShow(TObject *Sender)
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
