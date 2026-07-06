//---------------------------------------------------------------------------

#ifndef staticnoH
#define staticnoH
#include <System.hpp>

class PrijavaKorisnik {
public:
    String email;
	String oib;

	PrijavaKorisnik(String e, String o);

    bool ProvjeraEmail();
	bool ProvjeraOIB11();
    bool ProvjeraOIBBrojevi();
};
#endif
