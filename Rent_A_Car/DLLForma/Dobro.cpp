//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Dobro.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDLLForm2 *DLLForm2;
//---------------------------------------------------------------------------
__fastcall TDLLForm2::TDLLForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDLLForm2::FormCreate(TObject *Sender)
{
	HINSTANCE jpgDll;
    if((jpgDll = LoadLibrary(L"DLLForma.dll"))==NULL) {
        ShowMessage("Cannot load mydll.dll!");
        return;
    }
    TResourceStream* rs = new TResourceStream((int)jpgDll, "succes", RT_RCDATA);
    Image1->Picture->LoadFromStream(rs);
    delete rs;
    FreeLibrary(jpgDll);
}
//---------------------------------------------------------------------------
