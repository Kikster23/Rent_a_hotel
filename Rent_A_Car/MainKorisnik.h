//---------------------------------------------------------------------------

#ifndef MainKorisnikH
#define MainKorisnikH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include<map>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TButton *NovaRezervacija;
	TButton *MojeRezervacije;
	TButton *Ponuda;
	TButton *Odjava;
	TButton *Info;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall NovaRezervacijaClick(TObject *Sender);
	void __fastcall MojeRezervacijeClick(TObject *Sender);
	void __fastcall PonudaClick(TObject *Sender);
	void __fastcall InfoClick(TObject *Sender);
	void __fastcall OdjavaClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
std::map<String, std::map<String, String>> translation;
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
