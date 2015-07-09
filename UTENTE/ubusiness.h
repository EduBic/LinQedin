#ifndef UBUSINESS_H
#define UBUSINESS_H

#include "utente.h"

class UBusiness: public Utente{
public:
    UBusiness(Profilo *p =0, Rete *r =0, Login *l =0);

    virtual QString toString() const;

    virtual QString info() const;
    virtual void writeTipo(QXmlStreamWriter& xmlWriter) const;
    virtual bool ricerca(const Utente* user, const QString& text, const QString &category) const;
};

#endif // UBUSINESS_H
