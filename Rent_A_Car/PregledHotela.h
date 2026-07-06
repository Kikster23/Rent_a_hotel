//---------------------------------------------------------------------------

#ifndef PregledHotelaH
#define PregledHotelaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *EditIme;
	TLabel *Label6;
	TLabel *Label2;
	TEdit *EditAdresa;
	TLabel *Label4;
	TLabel *Label3;
	TEdit *EditSoba;
	TLabel *Label5;
	TEdit *EditCijena;
	TButton *Dodaj;
	TButton *Obriši;
	TButton *Uredi;
	TButton *Spremi;
	TButton *Povratak;
	TDBImage *DBImage1;
	TComboBox *ComboWiFi;
	TComboBox *ComboJacuzzi;
	TADOTable *ADOTable1;
	TADOConnection *ADOConnection1;
	TDataSource *DataSource1;
	TDBGrid *DBGrid1;
	TOpenDialog *OpenDialog1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall PovratakClick(TObject *Sender);
	void __fastcall DodajClick(TObject *Sender);
	void __fastcall ObrišiClick(TObject *Sender);
	void __fastcall UrediClick(TObject *Sender);
	void __fastcall SpremiClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
