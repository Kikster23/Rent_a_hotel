//---------------------------------------------------------------------------

#ifndef DobroH
#define DobroH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
#ifdef EXPORTS
  #define DLL_EXPORT __declspec(dllexport)
#else
  #define DLL_EXPORT __declspec(dllimport)
#endif
class DLL_EXPORT TDLLForm2 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TLabel *Label1;
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TDLLForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern DLL_EXPORT TDLLForm2 *DLLForm2;
//---------------------------------------------------------------------------
#endif
