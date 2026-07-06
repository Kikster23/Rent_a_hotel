//---------------------------------------------------------------------------

#ifndef PregledRecepcijaH
#define PregledRecepcijaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm9 : public TForm
{
__published:	// IDE-managed Components
	TEdit *EditGrad;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label4;
	TEdit *EditVrijeme;
	TEdit *EditBrTel;
	TButton *Ucitaj;
	TButton *Dodaj;
	TButton *Obrisi;
	TButton *Uredi;
	TButton *Povratak;
	TEdit *EditEmail;
	TLabel *Label5;
	TEdit *EditIme;
	TLabel *Label6;
	TListView *ListView1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall PovratakClick(TObject *Sender);
	void __fastcall UcitajClick(TObject *Sender);
	void __fastcall DodajClick(TObject *Sender);
	void __fastcall ObrisiClick(TObject *Sender);
	void __fastcall UrediClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm9(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm9 *Form9;
//---------------------------------------------------------------------------
#endif
