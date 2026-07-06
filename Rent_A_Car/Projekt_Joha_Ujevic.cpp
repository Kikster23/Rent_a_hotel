//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("PregledRezervacija.cpp", Form7);
USEFORM("PregledRecepcija.cpp", Form9);
USEFORM("PregledLogova.cpp", Form8);
USEFORM("PregledKorisnika.cpp", Form5);
USEFORM("Registracija.cpp", Form2);
USEFORM("Login.cpp", Form1);
USEFORM("InfoRecepcije.cpp", Form12);
USEFORM("MainAdmin.cpp", Form4);
USEFORM("PregledHotela.cpp", Form6);
USEFORM("PonudaHotela.cpp", Form13);
USEFORM("NovaRezervacija.cpp", Form10);
USEFORM("MojeRezervacije.cpp", Form11);
USEFORM("MainKorisnik.cpp", Form3);
USEFORM("Postavke.cpp", Form14);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm2), &Form2);
		Application->CreateForm(__classid(TForm3), &Form3);
		Application->CreateForm(__classid(TForm4), &Form4);
		Application->CreateForm(__classid(TForm5), &Form5);
		Application->CreateForm(__classid(TForm6), &Form6);
		Application->CreateForm(__classid(TForm7), &Form7);
		Application->CreateForm(__classid(TForm8), &Form8);
		Application->CreateForm(__classid(TForm9), &Form9);
		Application->CreateForm(__classid(TForm10), &Form10);
		Application->CreateForm(__classid(TForm11), &Form11);
		Application->CreateForm(__classid(TForm12), &Form12);
		Application->CreateForm(__classid(TForm13), &Form13);
		Application->CreateForm(__classid(TForm14), &Form14);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
