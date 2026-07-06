//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PregledHotela.h"
#include "MainAdmin.h"
#include "Dinamicno.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::PovratakClick(TObject *Sender)
{
	Hide();
	Form4->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm6::DodajClick(TObject *Sender)
{
AnsiString cijena = EditCijena->Text;
AnsiString wifi = ComboWiFi->Text;
AnsiString jacuzzi = ComboJacuzzi->Text;
ProvjeraHotela provjera(
	std::string(cijena.c_str()),
	std::string(wifi.c_str()),
    std::string(jacuzzi.c_str())
);

bool wifiOk = provjera.provjeraWifi();
bool jacuzziOk = provjera.provjeraJacuzzi();
String greske="";

if (!wifiOk) {
	greske=greske+"Ne moze wifi biti za manje od 100.\n";
}
if (!jacuzziOk) {
    greske=greske+"Ne možete uzeti jacuzzi za manje od 200.\n";
}
if (greske!="") {
	  ShowMessage(greske);
} else{
	  ADOTable1->Insert();
	ADOTable1->FieldByName("Ime")->AsString              = EditIme->Text;
	ADOTable1->FieldByName("Adresa")->AsString           = EditAdresa->Text;
	ADOTable1->FieldByName("Broj_soba")->AsInteger      = EditSoba->Text.ToInt();
	ADOTable1->FieldByName("Wi-Fi")->AsString           = wifi;
	ADOTable1->FieldByName("Jacuzzi")->AsString= jacuzzi;
	ADOTable1->FieldByName("Cijena_Dan")->AsFloat = EditCijena->Text.ToDouble();
	ADOTable1->Post();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm6::ObrišiClick(TObject *Sender)
{
ADOTable1->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TForm6::UrediClick(TObject *Sender)
{
     AnsiString cijena = EditCijena->Text;
AnsiString wifi = ComboWiFi->Text;
AnsiString jacuzzi = ComboJacuzzi->Text;
ProvjeraHotela provjera(
	std::string(cijena.c_str()),
	std::string(wifi.c_str()),
    std::string(jacuzzi.c_str())
);

bool wifiOk = provjera.provjeraWifi();
bool jacuzziOk = provjera.provjeraJacuzzi();
String greske="";

if (!wifiOk) {
	greske=greske+"Ne moze wifi biti za manje od 100.\n";
}
if (!jacuzziOk) {
    greske=greske+"Ne možete uzeti jacuzzi za manje od 200.\n";
}
if (greske!="") {
	  ShowMessage(greske);
} else{
	  ADOTable1->Edit();
	ADOTable1->FieldByName("Ime")->AsString              = EditIme->Text;
	ADOTable1->FieldByName("Adresa")->AsString           = EditAdresa->Text;
	ADOTable1->FieldByName("Broj_soba")->AsInteger      = EditSoba->Text.ToInt();
	ADOTable1->FieldByName("Wi-Fi")->AsString           = wifi;
	ADOTable1->FieldByName("Jacuzzi")->AsString= jacuzzi;
	ADOTable1->FieldByName("Cijena_Dan")->AsFloat = EditCijena->Text.ToDouble();
	ADOTable1->Post();
}
}
//---------------------------------------------------------------------------

void __fastcall TForm6::SpremiClick(TObject *Sender)
{
	if(OpenDialog1->Execute()){
		ADOTable1->Edit();
		static_cast<TBlobField*>(ADOTable1->FieldByName("Slika"))->LoadFromFile(OpenDialog1->FileName);
        ADOTable1->Post() ;
    }
}
//---------------------------------------------------------------------------

