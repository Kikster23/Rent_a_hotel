//---------------------------------------------------------------------------

#include <vcl.h>
#include <IdSSLOpenSSLHeaders.hpp>
#include <IniFiles.hpp>
#include <registry.hpp>
#pragma hdrstop

#include "PonudaHotela.h"
#include "MainKorisnik.h"
#include "Postavke.h"
#include <IniFiles.hpp>
#include <map>
#include <registry.hpp>
#include ".\DLLForma\Dobro.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm13 *Form13;
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
__fastcall TForm13::TForm13(TComponent* Owner)
	: TForm(Owner)
{
translation["Povratak"] = {
		{"EN", "Back"},
		{"HR", "Povratak"}
	};
	translation["BezOgranicenja"] = {
		{"EN", "No limit"},
		{"HR", "Bez ogranicenja"}
	};
    translation["Preuzmi"] = {
		{"EN", "Take a hotel offers:"},
		{"HR", "Preuzmi ponudu hotela:"}
	};
	translation["LabelPostotak"] = {
		{"EN", "Percentage:"},
		{"HR", "Postotak:"}
	};
}
//---------------------------------------------------------------------------
void __fastcall TForm13::PovratakClick(TObject *Sender)
{
Hide();
Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm13::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm13::Brzina1Click(TObject *Sender)
{
IdInterceptThrottler1->BitsPerSec = 409600;
}
//---------------------------------------------------------------------------

void __fastcall TForm13::Brzina2Click(TObject *Sender)
{
IdInterceptThrottler1->BitsPerSec =819200;
}
//---------------------------------------------------------------------------


void __fastcall TForm13::BezOgranicenjaClick(TObject *Sender)
{
IdInterceptThrottler1->BitsPerSec = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm13::InternetWorkBegin(TObject *ASender, TWorkMode AWorkMode,
          __int64 AWorkCountMax)
{
ProgressBar1->Position = 0;
	 ProgressBar1->Max = AWorkCountMax;
}
//---------------------------------------------------------------------------

void __fastcall TForm13::InternetWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount)

{
	ProgressBar1->Position = AWorkCount;
	Application->ProcessMessages();

        ProgressBar1->Position = AWorkCount;
    int percent = 0;
    if (ProgressBar1->Max > 0)
        percent = (100 * ProgressBar1->Position) / ProgressBar1->Max;
    LabelPostotak->Caption = IntToStr(percent) + "%";
	Application->ProcessMessages();
}
//---------------------------------------------------------------------------

void __fastcall TForm13::PreuzmiClick(TObject *Sender)
{
TFileStream* x = new TFileStream("ponuda_hotela.pdf", fmCreate);
	Internet->Get("https://drive.google.com/uc?export=download&id=1G7EZP_v_y_Flu7biKFOBDPkYvmrnejGt",x)    ;
	delete x;
    HINSTANCE hInstDLL = LoadLibrary(L"DLLForma.dll");
			if (hInstDLL == NULL) {
				ShowMessage("Ne može uèitati DLL.");
			}
			else {
				TDLLForm2* Form = new TDLLForm2(this);
				Form->Label1->Caption = "Uspješno ste preuzeli katalog";
				Form->Show();
				FreeLibrary(hInstDLL);
			}
}
//---------------------------------------------------------------------------

void __fastcall TForm13::FormShow(TObject *Sender)
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

