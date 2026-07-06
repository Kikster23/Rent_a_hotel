//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PregledKorisnika.h"
#include "MainAdmin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_CryptographicLibrary"
#pragma link "uTPLb_Hash"
#pragma resource "*.dfm"
TForm5 *Form5;
String Stream_To_Hex(TStream* stream) {
    stream->Position = 0;
    String result = "";
	unsigned char byte;

    while (stream->Read(&byte, 1) == 1) {
        result += IntToHex(byte, 2);
    }
    return result;
}
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm5::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::PovratakClick(TObject *Sender)
{
Hide();
	Form4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::DodajClick(TObject *Sender)
{
		String email=EditEmail->Text.Trim();
		String lozinka=EditLozinka->Text.Trim();

		Hash2->HashString(email, TEncoding::UTF8);
		String sol=Stream_To_Hex(Hash2->HashOutputValue);
		String hashUnesene=lozinka+sol;
		String hashUnesene2=hashUnesene+Random(100);
		Hash1->HashString(hashUnesene2,TEncoding::UTF8);
		String hashUnesene3=Stream_To_Hex(Hash1->HashOutputValue);
        	ADOTable1->Insert();
	ADOTable1->FieldByName("Ime")->AsString        = EditIme->Text;
	ADOTable1->FieldByName("Prezime")->AsString    = EditPrezime->Text;
	ADOTable1->FieldByName("Email")->AsString      = EditEmail->Text;
	ADOTable1->FieldByName("Lozinka")->AsString    = hashUnesene3;
	ADOTable1->FieldByName("OIB")->AsString = EditOib->Text;
	ADOTable1->FieldByName("Tip")->AsString        = ComboTip->Text;
	ADOTable1->Post();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::ObrisiClick(TObject *Sender)
{
ADOTable1->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TForm5::UrediClick(TObject *Sender)
{
ADOTable1->Edit();
             String email=EditEmail->Text.Trim();
		String lozinka=EditLozinka->Text.Trim();

		Hash2->HashString(email, TEncoding::UTF8);
		String sol=Stream_To_Hex(Hash2->HashOutputValue);
		String hashUnesene=lozinka+sol;
		String hashUnesene2=hashUnesene+Random(50);
		Hash1->HashString(hashUnesene2,TEncoding::UTF8);
		String hashUnesene3=Stream_To_Hex(Hash1->HashOutputValue);
	ADOTable1->FieldByName("Ime")->AsString        = EditIme->Text;
	ADOTable1->FieldByName("Prezime")->AsString    = EditPrezime->Text;
	ADOTable1->FieldByName("Email")->AsString      = EditEmail->Text;
	ADOTable1->FieldByName("Lozinka")->AsString    = hashUnesene3;
	ADOTable1->FieldByName("OIB")->AsString = EditOib->Text;
	ADOTable1->FieldByName("Tip")->AsString        = ComboTip->Text;
	ADOTable1->Post();
}
//---------------------------------------------------------------------------

