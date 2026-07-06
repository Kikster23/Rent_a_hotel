//---------------------------------------------------------------------------

#ifndef PregledKorisnikaH
#define PregledKorisnikaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include "uTPLb_Hash.hpp"
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *EditIme;
	TLabel *Label2;
	TEdit *EditPrezime;
	TLabel *Label3;
	TEdit *EditEmail;
	TLabel *Label6;
	TEdit *EditLozinka;
	TLabel *Label4;
	TEdit *EditOib;
	TLabel *Label5;
	TComboBox *ComboTip;
	TButton *Dodaj;
	TButton *Obrisi;
	TButton *Uredi;
	TButton *Povratak;
	TDBGrid *DBGrid1;
	TADOConnection *ADOConnection1;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;
	TCryptographicLibrary *CryptographicLibrary1;
	THash *Hash1;
	THash *Hash2;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall PovratakClick(TObject *Sender);
	void __fastcall DodajClick(TObject *Sender);
	void __fastcall ObrisiClick(TObject *Sender);
	void __fastcall UrediClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
