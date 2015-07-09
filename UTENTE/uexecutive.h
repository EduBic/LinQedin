#ifndef UEXECUTIVE_H
#define UEXECUTIVE_H

#include "utente.h"

class UExecutive: public Utente{
public:
    UExecutive(Profilo *p =0, Rete *r =0, Login *l =0);

    virtual QString toString() const;

    virtual QString info() const;
    virtual void writeTipo(QXmlStreamWriter& xmlWriter) const;
    virtual bool ricerca(const Utente* user, const QString& text, const QString& category) const;
};

#endif // UEXECUTIVE_H
