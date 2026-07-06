//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PregledLogova.h"
#include "MainAdmin.h"
#include "XMLLogovi.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm8::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm8::PovratakClick(TObject *Sender)
{
Hide();
	Form4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm8::UcitajClick(TObject *Sender)
{
	_di_IXMLlogoviType Logovi= Getlogovi(XMLDocument1);

	ListView1->Items->Clear();
	for(int i=0;i<Logovi->Count;i++){
		ListView1->Items->Add();
		ListView1->Items->Item[i]->Caption=Logovi->log[i]->datum;
		ListView1->Items->Item[i]->SubItems->Add(Logovi->log[i]->id);
        ListView1->Items->Item[i]->SubItems->Add(Logovi->log[i]->aktivnost);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm8::DodajClick(TObject *Sender)
{
	_di_IXMLlogoviType Logovi= Getlogovi(XMLDocument1);
	  _di_IXMLlogType Log= Logovi->Add();
	  if(EditAktivnost->Text.IsEmpty() || EditKorisnik->Text.IsEmpty()){
        ShowMessage("Nisi upisao aktivnost ili ID.");
	  }else{
		  String datum1 = FormatDateTime(L"yyyy-mm-dd", DateTimeDatum->Date);
		  Log->datum=datum1;
		  Log->id=EditKorisnik->Text;
		  Log->aktivnost=EditAktivnost->Text;
		   XMLDocument1->SaveToFile(XMLDocument1->FileName);
	  }
}
//---------------------------------------------------------------------------

void __fastcall TForm8::IzbrišiClick(TObject *Sender)
{
_di_IXMLlogoviType Logovi= Getlogovi(XMLDocument1);
		Logovi->Delete(ListView1->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TForm8::UrediClick(TObject *Sender)
{
if(ListView1->Selected == NULL) return;

	_di_IXMLlogoviType Logovi= Getlogovi(XMLDocument1);
	_di_IXMLlogType log=Logovi->log[ListView1->Selected->Index];
	 String datum1 = FormatDateTime(L"yyyy-mm-dd", DateTimeDatum->Date);
	log->datum=datum1;
		  log->id=EditKorisnik->Text;
		  log->aktivnost=EditAktivnost->Text;
		  XMLDocument1->SaveToFile(XMLDocument1->FileName);
}
//---------------------------------------------------------------------------

