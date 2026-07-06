//---------------------------------------------------------------------------

#ifndef MainAdminH
#define MainAdminH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TButton *PregledKorisnika;
	TButton *PregledHotela;
	TButton *PregledRezervacija;
	TButton *PregledLogova;
	TButton *Odjava;
	TButton *PregledRecepcija;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall PregledKorisnikaClick(TObject *Sender);
	void __fastcall PregledHotelaClick(TObject *Sender);
	void __fastcall PregledRezervacijaClick(TObject *Sender);
	void __fastcall PregledLogovaClick(TObject *Sender);
	void __fastcall PregledRecepcijaClick(TObject *Sender);
	void __fastcall OdjavaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
