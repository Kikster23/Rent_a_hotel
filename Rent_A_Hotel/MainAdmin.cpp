//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainAdmin.h"
#include "PregledKorisnika.h"
#include "PregledHotela.h"
#include "PregledRezervacija.h"
#include "PregledLogova.h"
#include "PregledRecepcija.h"
#include "Login.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::PregledKorisnikaClick(TObject *Sender)
{
Hide();
	Form5->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::PregledHotelaClick(TObject *Sender)
{
Hide();
	Form6->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::PregledRezervacijaClick(TObject *Sender)
{
Hide();
	Form7->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::PregledLogovaClick(TObject *Sender)
{
Hide();
	Form8->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::PregledRecepcijaClick(TObject *Sender)
{
Hide();
    Form9->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm4::OdjavaClick(TObject *Sender)
{
	Hide();
    Form1->Show();
}
//---------------------------------------------------------------------------

