#ifndef UTENTE_H
#define UTENTE_H

#include<QXmlStreamWriter>

#include "UDATA/profilo.h"
#include "UDATA/rete.h"
#include "UDATA/login.h"

class DataBase;

class Utente{
private:
    Profilo* pr;
    Rete* rete;
    Login* lg;

public:
    Utente(Profilo* p =0, Rete* r =0, Login* l =0);

    Profilo* getProfilo() const;
    Rete* getRete() const;
    Login* getLogin() const;
    void setProfilo(const QString &name, const QString &surname, bool sex, const QDate &date, const Residenza& res, const QString &country, const QString &language, const QString &profession, const QString &number, const QString &mail, const std::vector<QString> &titles, const std::vector<QString> &experiences);

    //Metodi get info from utente
      const QString &getUsername() const;
      const QString& getNome()const;
      const QString& getCognome()const;
      bool getSesso() const;
      QString getSessoString()const;
      const QDate &getData()const;
      QString getDataString()const;
      const QString& getPaese()const;
      const Residenza& getResidenza()const;
      const QString& getProfessione()const;
      const QString& getLingue()const;
      const QString& getNumero()const;
      const QString& getMail()const;
      const std::vector<QString>& getTitoli()const;
      const std::vector<QString>& getEsperienze()const;

    virtual QString toString() const =0;
    virtual QString info() const =0;
    virtual void writeTipo(QXmlStreamWriter& xmlWriter) const =0;
    virtual bool ricerca(const Utente* user, const QString& text, const QString& category) const =0;

    virtual ~Utente();
};

#endif // UTENTE_H
