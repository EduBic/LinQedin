#ifndef DATABASE_H
#define DATABASE_H

#include<map>
#include<iostream>
#include<typeinfo>
#include<QFile>
#include<QXmlStreamWriter>
#include<QXmlStreamReader>
#include<QString>

#include<UTENTE/ubasic.h>
#include<UTENTE/ubusiness.h>
#include<UTENTE/uexecutive.h>


class DataBase{
private:
    static QString filename;
    std::map<QString,Utente*> db; //Username e Utente*

public:
    typedef std::map<QString, Utente*>::iterator db_iterator;
    typedef std::map<QString, Utente*>::const_iterator db_const_iterator;

    DataBase();
    ~DataBase();

    db_iterator begin();
    db_iterator end();
    db_const_iterator begin() const;
    db_const_iterator end() const;

    void Load();
    void Close();
    bool vuoto() const;

    void distUtente(const QString& user);
    void creaUtente(const QString& user, int tipo, const QString &nome, const QString &cognome);
    bool matchUtente(const QString& user) const;
    Utente* findUtente(const QString& user) const;
    void proUtente(const QString& user, const int tipo);

    //per Test
    void stampaUtente(const Utente* u) const;

};

#endif // DATABASE_H
