//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.JSON.hpp>
#pragma hdrstop

#include "PregledRecepcija.h"
#include "MainAdmin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm9 *Form9;
//---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm9::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm9::PovratakClick(TObject *Sender)
{
Hide();
	Form4->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm9::UcitajClick(TObject *Sender)
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
    String jsonDoc;
jsonDoc = "{";
jsonDoc += "\"recepcije\":";
jsonDoc += "[";

for (int i = 0; i < ListView1->Items->Count; i++) {
    jsonDoc +=
		"{"
		"\"ime\":\""            + ListView1->Items->Item[i]->Caption                            + "\","
		"\"grad\":\""           + ListView1->Items->Item[i]->SubItems->Strings[0]               + "\","
		"\"broj_telefona\":\""  + ListView1->Items->Item[i]->SubItems->Strings[1]               + "\","
		"\"email\":\""          + ListView1->Items->Item[i]->SubItems->Strings[2]               + "\","
        "\"radnovrijeme\":\""   + ListView1->Items->Item[i]->SubItems->Strings[3]               + "\""
		"}";

    jsonDoc += (i + 1 != ListView1->Items->Count) ? "," : "";
}

jsonDoc += "]";
jsonDoc += "}";
jsonDoc = ( (TJSONObject*)TJSONObject::ParseJSONValue(jsonDoc) )->Format(2);

std::unique_ptr<TStringStream> ss(new TStringStream);
ss->WriteString(jsonDoc);
ss->SaveToFile("recepcije.json");
}
}
//---------------------------------------------------------------------------

void __fastcall TForm9::DodajClick(TObject *Sender)
{
ListView1->Items->Add();
	int zadnjikoristeni=ListView1->Items->Count-1;
	ListView1->Items->Item[zadnjikoristeni]->Caption = EditIme->Text;
	ListView1->Items->Item[zadnjikoristeni]->SubItems->Add(EditGrad->Text);
	ListView1->Items->Item[zadnjikoristeni]->SubItems->Add(EditBrTel->Text);
	ListView1->Items->Item[zadnjikoristeni]->SubItems->Add(EditEmail->Text);
	ListView1->Items->Item[zadnjikoristeni]->SubItems->Add(EditVrijeme->Text);
    String jsonDoc;
jsonDoc = "{";
jsonDoc += "\"recepcije\":";
jsonDoc += "[";

for (int i = 0; i < ListView1->Items->Count; i++) {
	jsonDoc +=
		"{"
		"\"ime\":\""           + ListView1->Items->Item[i]->Caption                            + "\","
		"\"grad\":\""           + ListView1->Items->Item[i]->SubItems->Strings[0]               + "\","
		"\"broj_telefona\":\""  + ListView1->Items->Item[i]->SubItems->Strings[1]               + "\","
		"\"email\":\""  + ListView1->Items->Item[i]->SubItems->Strings[2]               + "\","
		"\"radnovrijeme\":\""  + ListView1->Items->Item[i]->SubItems->Strings[3]               + "\""
		"}";

	jsonDoc += (i + 1 != ListView1->Items->Count) ? "," : "";
}

jsonDoc += "]";
jsonDoc += "}";
jsonDoc = ( (TJSONObject*)TJSONObject::ParseJSONValue(jsonDoc) )->Format(2);

std::unique_ptr<TStringStream> ss(new TStringStream);
ss->WriteString(jsonDoc);
ss->SaveToFile("recepcije.json");
}
//---------------------------------------------------------------------------

void __fastcall TForm9::ObrisiClick(TObject *Sender)
{
ListView1->DeleteSelected();
    String jsonDoc;
jsonDoc = "{";
jsonDoc += "\"recepcije\":";
jsonDoc += "[";

for (int i = 0; i < ListView1->Items->Count; i++) {
		jsonDoc +=
		"{"
		"\"ime\":\""           + ListView1->Items->Item[i]->Caption                            + "\","
		"\"grad\":\""           + ListView1->Items->Item[i]->SubItems->Strings[0]               + "\","
		"\"broj_telefona\":\""  + ListView1->Items->Item[i]->SubItems->Strings[1]               + "\","
		"\"email\":\""  + ListView1->Items->Item[i]->SubItems->Strings[2]               + "\","
		"\"radnovrijeme\":\""  + ListView1->Items->Item[i]->SubItems->Strings[3]               + "\""
		"}";

    jsonDoc += (i + 1 != ListView1->Items->Count) ? "," : "";
}

jsonDoc += "]";
jsonDoc += "}";
jsonDoc = ( (TJSONObject*)TJSONObject::ParseJSONValue(jsonDoc) )->Format(2);

std::unique_ptr<TStringStream> ss(new TStringStream);
ss->WriteString(jsonDoc);
ss->SaveToFile("recepcije.json");
}
//---------------------------------------------------------------------------

void __fastcall TForm9::UrediClick(TObject *Sender)
{
	int zadnjikoristeni = ListView1->Selected->Index;
	ListView1->Items->Item[zadnjikoristeni]->Caption = EditIme->Text;
	ListView1->Items->Item[zadnjikoristeni]->SubItems->Strings[0]=EditGrad->Text;
	ListView1->Items->Item[zadnjikoristeni]->SubItems->Strings[1]=(EditBrTel->Text);
	ListView1->Items->Item[zadnjikoristeni]->SubItems->Strings[2]=(EditEmail->Text);
	ListView1->Items->Item[zadnjikoristeni]->SubItems->Strings[3]=(EditVrijeme->Text);
	String jsonDoc;
jsonDoc = "{";
jsonDoc += "\"recepcije\":";
jsonDoc += "[";

for (int i = 0; i < ListView1->Items->Count; i++) {
    jsonDoc +=
		"{"
		"\"ime\":\""           + ListView1->Items->Item[i]->Caption                            + "\","
		"\"grad\":\""           + ListView1->Items->Item[i]->SubItems->Strings[0]               + "\","
		"\"broj_telefona\":\""  + ListView1->Items->Item[i]->SubItems->Strings[1]               + "\","
		"\"email\":\""  + ListView1->Items->Item[i]->SubItems->Strings[2]               + "\","
		"\"radnovrijeme\":\""  + ListView1->Items->Item[i]->SubItems->Strings[3]               + "\""
		"}";

    jsonDoc += (i + 1 != ListView1->Items->Count) ? "," : "";
}

jsonDoc += "]";
jsonDoc += "}";
jsonDoc = ( (TJSONObject*)TJSONObject::ParseJSONValue(jsonDoc) )->Format(2);

std::unique_ptr<TStringStream> ss(new TStringStream);
ss->WriteString(jsonDoc);
ss->SaveToFile("recepcije.json");
}
//---------------------------------------------------------------------------


