#include "smartutente.h"

SmartUtente::SmartUtente(Utente *p): u(p) {}

Utente* SmartUtente::getUtente() const {return u;}
