#include "dinamicno.h"
#include <cstdlib>

ProvjeraHotela::ProvjeraHotela(const std::string& cij, const std::string& wi, const std::string& ja)
    : cijena(cij), wifi(wi), jacuzzi(ja)
{
}

ProvjeraHotela::~ProvjeraHotela() = default;

bool ProvjeraHotela::provjeraWifi() {
    if (wifi == "Da") {
        int c = std::stoi(cijena);
        if (c < 100) {
            return false;
        }
    }
    return true;
}

bool ProvjeraHotela::provjeraJacuzzi() {
    if (jacuzzi == "Da") {
        int c = std::stoi(cijena);
        if (c < 200) {
            return false;
        }
    }
    return true;
}
