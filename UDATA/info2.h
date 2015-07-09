#ifndef INFO2_H
#define INFO2_H

#include<QXmlStreamReader>
#include<QString>
#include<vector>

#include<UDATA/residenza.h>


class Info2{
private:
    Residenza res;
    QString profession;
    QString lingue;
    QString numero;
    QString mail;
    std::vector<QString> titoli;

public:
    Info2(const Residenza& rs=Residenza(), const QString& pro="", const QString& lng="",
          const QString& num ="", const QString& mail ="", const std::vector<QString> &x =std::vector<QString>());

    const std::vector<QString>& getTitoli() const;
    const QString& getNumero() const;
    const QString& getMail() const;
    const Residenza& getResidenza() const;
    const QString& getProfessione() const;
    const QString& getLingue() const;

    void setResidenza(const Residenza& rs);
    void setProfessione(const QString& prof);
    void setLingue(const QString& lg);
    void setTitoli(const std::vector<QString> &tls);
    void setNumero(const QString& nm);
    void setMail(const QString& ml);

    bool matchTitolo(const QString& text) const;

    static Info2 readInfo2(QXmlStreamReader& );
};

#endif // INFO2_H
