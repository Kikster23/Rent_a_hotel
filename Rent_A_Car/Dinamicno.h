#ifndef DINAMICNO_H
#define DINAMICNO_H

#ifdef DINAMICNO_EXPORTS
#define DINAMICNO_API __declspec(dllexport)
#else
#define DINAMICNO_API __declspec(dllimport)
#endif

#include <string>

class DINAMICNO_API ProvjeraHotela
{
private:
    std::string cijena;
    std::string wifi;
    std::string jacuzzi;

public:
    ProvjeraHotela(const std::string& cij, const std::string& wi, const std::string& ja);
    ~ProvjeraHotela();
    bool provjeraWifi();
    bool provjeraJacuzzi();
};

#endif
