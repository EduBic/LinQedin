#ifndef RISRICBASIC_H
#define RISRICBASIC_H

#include "utente.h"

class RisRicBasic{
private:
    const Utente* utente;
public:
    RisRicBasic(Utente* u);

    Info1 getInfo1() const;
};

#endif // RISRICBASIC_H
