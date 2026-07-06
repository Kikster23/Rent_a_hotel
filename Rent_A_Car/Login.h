//---------------------------------------------------------------------------

#ifndef LoginH
#define LoginH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include "uTPLb_Hash.hpp"
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Xml.Win.msxmldom.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include<map>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TLabel *Label1;
	TEdit *EditEmail;
	TLabel *Label2;
	TEdit *EditLozinka;
	TButton *Registracija;
	TButton *Prijava;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TCryptographicLibrary *CryptographicLibrary1;
	THash *Hash1;
	THash *Hash2;
	THash *Hash3;
	TADOTable *TKorisnici;
	TXMLDocument *XMLDocument1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall PrijavaClick(TObject *Sender);
	void __fastcall RegistracijaClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall Image1MouseEnter(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
std::map<String, std::map<String, String>> translation;
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
