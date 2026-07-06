//---------------------------------------------------------------------------

#ifndef RegistracijaH
#define RegistracijaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
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
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *EditIme;
	TLabel *Label2;
	TEdit *EditPrezime;
	TLabel *Label3;
	TEdit *EditEmail;
	TLabel *Label4;
	TEdit *EditLozinka;
	TLabel *Label7;
	TEdit *EditOIB;
	TButton *Registiraj;
	TButton *Povratak;
	TCryptographicLibrary *CryptographicLibrary1;
	THash *Hash1;
	THash *Hash2;
	TADOConnection *ADOConnection1;
	TADOTable *TKorisnici;
	TADOQuery *ADOQuery1;
	TXMLDocument *XMLDocument1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall RegistirajClick(TObject *Sender);
	void __fastcall PovratakClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
std::map<String, std::map<String, String>> translation;
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
