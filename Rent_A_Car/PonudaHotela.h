//---------------------------------------------------------------------------

#ifndef PonudaHotelaH
#define PonudaHotelaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdHTTP.hpp>
#include <IdIntercept.hpp>
#include <IdInterceptThrottler.hpp>
#include <IdIOHandler.hpp>
#include <IdIOHandlerSocket.hpp>
#include <IdIOHandlerStack.hpp>
#include <IdSSL.hpp>
#include <IdSSLOpenSSL.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include <Vcl.ComCtrls.hpp>
#include<map>
//---------------------------------------------------------------------------
class TForm13 : public TForm
{
__published:	// IDE-managed Components
	TButton *Brzina1;
	TButton *Brzina2;
	TButton *Preuzmi;
	TButton *BezOgranicenja;
	TProgressBar *ProgressBar1;
	TLabel *LabelPostotak;
	TButton *Povratak;
	TIdInterceptThrottler *IdInterceptThrottler1;
	TIdHTTP *Internet;
	TIdSSLIOHandlerSocketOpenSSL *IdSSLIOHandlerSocketOpenSSL1;
	void __fastcall PovratakClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Brzina1Click(TObject *Sender);
	void __fastcall Brzina2Click(TObject *Sender);
	void __fastcall BezOgranicenjaClick(TObject *Sender);
	void __fastcall InternetWorkBegin(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCountMax);
	void __fastcall InternetWork(TObject *ASender, TWorkMode AWorkMode, __int64 AWorkCount);
	void __fastcall PreuzmiClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);


private:	// User declarations
public:		// User declarations
std::map<String, std::map<String, String>> translation;
	__fastcall TForm13(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm13 *Form13;
//---------------------------------------------------------------------------
#endif
