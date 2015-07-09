#ifndef RESIDENZA_H
#define RESIDENZA_H

#include<QXmlStreamReader>

class Residenza{
private:
    QString comune;
    QString regione;
    QString indirizzo;
public:
    Residenza(const QString& com ="", const QString& reg ="", const QString& ind ="");

    QString getComune() const;
    QString getRegione() const;
    QString getIndirizzo() const;

    static Residenza readResidenza(QXmlStreamReader& );
};

#endif // RESIDENZA_H
