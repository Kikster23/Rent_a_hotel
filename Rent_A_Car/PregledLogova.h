//---------------------------------------------------------------------------

#ifndef PregledLogovaH
#define PregledLogovaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include <Xml.Win.msxmldom.hpp>
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label3;
	TEdit *EditAktivnost;
	TLabel *Label2;
	TEdit *EditKorisnik;
	TLabel *Label1;
	TDateTimePicker *DateTimeDatum;
	TButton *Ucitaj;
	TButton *Dodaj;
	TButton *Izbriši;
	TButton *Uredi;
	TButton *Povratak;
	TListView *ListView1;
	TXMLDocument *XMLDocument1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall PovratakClick(TObject *Sender);
	void __fastcall UcitajClick(TObject *Sender);
	void __fastcall DodajClick(TObject *Sender);
	void __fastcall IzbrišiClick(TObject *Sender);
	void __fastcall UrediClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm8(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
