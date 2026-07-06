//---------------------------------------------------------------------------
#pragma hdrstop

#include "staticno.h"
PrijavaKorisnik::PrijavaKorisnik(String e, String o) {
    email = e;
	oib = o;
}

bool PrijavaKorisnik::ProvjeraEmail() {
    String suffix = "@gmail.com";
    int n = suffix.Length();
    if (email.Length() >= n && email.SubString(email.Length() - n + 1, n) == suffix)
        return true;
    return false;
}

bool PrijavaKorisnik::ProvjeraOIB11() {
	return oib.Length() == 11;
}

bool PrijavaKorisnik::ProvjeraOIBBrojevi() {
	for (int i = 1; i <= oib.Length(); ++i) {
        if (!isdigit(oib[i])) {
            return false;
        }
    }
    return true;
}
