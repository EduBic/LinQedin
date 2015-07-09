#ifndef RISRICBUSINESS_H
#define RISRICBUSINESS_H

#include "utente.h"

class RisRicBusiness{
private:
    const Utente* utente;
public:
    RisRicBusiness(Utente *u);

    Info1 getInfo1() const;
    Info2 getInfo2() const;
};

#endif // RISRICBUSINESS_H
