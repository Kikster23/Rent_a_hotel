//---------------------------------------------------------------------------

#ifndef NovaRezervacijaH
#define NovaRezervacijaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Data.Win.ADODB.hpp>
#include<map>
//---------------------------------------------------------------------------
class TForm10 : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TLabel *Label3;
	TLabel *Label1;
	TDateTimePicker *DateTimeOd;
	TDateTimePicker *DateTimeDo;
	TButton *Rezerviraj;
	TDBImage *DBImage1;
	TButton *Povratak;
	TLabel *Label2;
	TADOConnection *ADOConnection1;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;
	TADOTable *ADOTable2;
	TAutoIncField *ADOTable1Hotel_ID;
	TWideStringField *ADOTable1Ime;
	TWideStringField *ADOTable1Adresa;
	TIntegerField *ADOTable1Broj_soba;
	TWideStringField *ADOTable1WiFi;
	TWideStringField *ADOTable1Jacuzzi;
	TIntegerField *ADOTable1Cijena_Dan;
	TBlobField *ADOTable1Slika;
	TFloatField *ADOTable1Cijena_Dan_PDV;
	void __fastcall PovratakClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall RezervirajClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall DBGrid1TitleClick(TColumn *Column);
	void __fastcall ADOTable1CalcFields(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
std::map<String, std::map<String, String>> translation;
	__fastcall TForm10(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm10 *Form10;
//---------------------------------------------------------------------------
#endif
