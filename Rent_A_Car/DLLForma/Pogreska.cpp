//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Pogreska.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDLLForm1 *DLLForm1;
//---------------------------------------------------------------------------
__fastcall TDLLForm1::TDLLForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDLLForm1::FormCreate(TObject *Sender)
{

	HINSTANCE jpgDll;
    if((jpgDll = LoadLibrary(L"DLLForma.dll"))==NULL) {
        ShowMessage("Cannot load mydll.dll!");
        return;
    }
    TResourceStream* rs = new TResourceStream((int)jpgDll, "error", RT_RCDATA);
    Image1->Picture->LoadFromStream(rs);
    delete rs;
    FreeLibrary(jpgDll);
}
//---------------------------------------------------------------------------
