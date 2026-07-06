//---------------------------------------------------------------------------

#include <vcl.h>
#include <System.DateUtils.hpp>
#pragma hdrstop

#include "PregledRezervacija.h"
#include "MainAdmin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm7::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::PovratakClick(TObject *Sender)
{
Hide();
	Form4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::FormCreate(TObject *Sender)
{
ADOQuery1->SQL->Text = "SELECT Korisnik_ID FROM Korisnici ORDER BY Korisnik_ID";
    ADOQuery1->Open();
	while(!ADOQuery1->Eof){
	ComboKorisnik->Items->Add(ADOQuery1->FieldByName("Korisnik_ID")->AsString);
	ADOQuery1->Next();
	}
	ADOQuery1->Close();
	ADOQuery1->SQL->Text = "SELECT Hotel_ID FROM Hoteli ORDER BY Hotel_ID";
    ADOQuery1->Open();
	while(!ADOQuery1->Eof){
	ComboHotel->Items->Add(ADOQuery1->FieldByName("Hotel_ID")->AsString);
	ADOQuery1->Next(); }
    ADOQuery1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::DodajClick(TObject *Sender)
{
 int korisnikID = ComboKorisnik->Text.ToInt();
	int hotelID   = ComboHotel->Text.ToInt();

	ADOQuery1->SQL->Text = "SELECT Cijena_Dan FROM Hoteli WHERE Hotel_ID = :id";
	ADOQuery1->Parameters->ParamByName("id")->Value = hotelID;
	ADOQuery1->Open();
	double cijenaDan = ADOQuery1->FieldByName("Cijena_Dan")->AsFloat;
	ADOQuery1->Close();

    int dani = DaysBetween(DateTimeDo->Date, DateTimeOd->Date);
	double ukupno = cijenaDan * dani;
    ADOTable1->Append();
    ADOTable1->FieldByName("Korisnik_ID")->AsInteger = ComboKorisnik->Text.ToInt();
    ADOTable1->FieldByName("Hotel_ID")->AsInteger   = hotelID;
	ADOTable1->FieldByName("Datum_OD")->AsDateTime   = DateTimeOd->Date;
	ADOTable1->FieldByName("Datum_DO")->AsDateTime   = DateTimeDo->Date;
    ADOTable1->FieldByName("Ukupna_Cijena")->AsFloat = ukupno;
	ADOTable1->Post();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::ObrišiClick(TObject *Sender)
{
ADOTable1->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::PromijeniClick(TObject *Sender)
{
      int korisnikID = ComboKorisnik->Text.ToInt();
	int hotelID   = ComboHotel->Text.ToInt();

	ADOQuery1->SQL->Text = "SELECT Cijena_Dan FROM Hoteli WHERE Hotel_ID = :id";
	ADOQuery1->Parameters->ParamByName("id")->Value = hotelID;
	ADOQuery1->Open();
	double cijenaDan = ADOQuery1->FieldByName("Cijena_Dan")->AsFloat;
	ADOQuery1->Close();

    int dani = DaysBetween(DateTimeDo->Date, DateTimeOd->Date);
	double ukupno = cijenaDan * dani;
    ADOTable1->Edit();
    ADOTable1->FieldByName("Korisnik_ID")->AsInteger = ComboKorisnik->Text.ToInt();
    ADOTable1->FieldByName("Hotel_ID")->AsInteger   = hotelID;
	ADOTable1->FieldByName("Datum_OD")->AsDateTime   = DateTimeOd->Date;
	ADOTable1->FieldByName("Datum_DO")->AsDateTime   = DateTimeDo->Date;
    ADOTable1->FieldByName("Ukupna_Cijena")->AsFloat = ukupno;
	ADOTable1->Post();
}
//---------------------------------------------------------------------------

