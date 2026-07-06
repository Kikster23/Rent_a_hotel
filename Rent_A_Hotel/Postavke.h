//---------------------------------------------------------------------------

#ifndef PostavkeH
#define PostavkeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include<map>
//---------------------------------------------------------------------------
class TForm14 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label3;
	TComboBox *ComboJezik;
	TLabel *Label4;
	TComboBox *ComboTema;
	TComboBox *ComboVrsta;
	TLabel *Label2;
	TLabel *Label1;
	TComboBox *ComboVelicina;
	TButton *Button1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
std::map<String, std::map<String, String>> translation;
	__fastcall TForm14(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm14 *Form14;
//---------------------------------------------------------------------------
#endif
