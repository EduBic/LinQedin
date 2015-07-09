#ifndef LUOGO_H
#define LUOGO_H

#include <QString>

class Luogo{
private:
    QString comune;
    QString regione;
public:
    Luogo(QString ="Non definito", QString ="Non definito");
    //Luogo(QString& ="Non definito", QString& ="Non definito")

    QString getComune() const;
    QString getRegione() const;
    void setComune(QString c);
    void setRegione(QString r);
    void setLuogo(QString, QString);
};

#endif // LUOGO_H
