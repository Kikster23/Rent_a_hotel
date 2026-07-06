//---------------------------------------------------------------------------

#ifndef PregledRezervacijaH
#define PregledRezervacijaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TComboBox *ComboKorisnik;
	TComboBox *ComboHotel;
	TButton *Dodaj;
	TButton *Obriši;
	TDateTimePicker *DateTimeOd;
	TDateTimePicker *DateTimeDo;
	TLabel *Label5;
	TLabel *Label4;
	TButton *Promijeni;
	TButton *Povratak;
	TADOConnection *ADOConnection1;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TADOQuery *ADOQuery1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall PovratakClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall DodajClick(TObject *Sender);
	void __fastcall ObrišiClick(TObject *Sender);
	void __fastcall PromijeniClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm7(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
