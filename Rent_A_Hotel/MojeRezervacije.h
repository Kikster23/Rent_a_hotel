//---------------------------------------------------------------------------

#ifndef MojeRezervacijeH
#define MojeRezervacijeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include<map>
//---------------------------------------------------------------------------
class TForm11 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TDBGrid *DBGrid1;
	TButton *Povratak;
	TADOConnection *ADOConnection1;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;
	TAutoIncField *ADOTable1Rezervacija_ID;
	TWideStringField *ADOTable1Korisnik_ID;
	TWideStringField *ADOTable1Hotel_ID;
	TDateTimeField *ADOTable1Datum_OD;
	TDateTimeField *ADOTable1Datum_DO;
	TIntegerField *ADOTable1Ukupna_Cijena;
	TFloatField *ADOTable1Ukupna_Cijena_PDV;
	void __fastcall PovratakClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ADOTable1CalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
std::map<String, std::map<String, String>> translation;
	__fastcall TForm11(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm11 *Form11;
//---------------------------------------------------------------------------
#endif
