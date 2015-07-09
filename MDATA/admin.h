#ifndef ADMIN_H
#define ADMIN_H

#include <list>

#include<MDATA/database.h>

class Admin{
private:
    DataBase *pdb;

public:
    Admin(DataBase *db);

    void rimUtente(const QString& user);
    void aggUtente(const QString& user, int tipo, const QString &nome, const QString &cognome);
    void proUtente(const QString& user, int tipo);
    Utente* getUtente(const QString& user) const;
    bool matchUser(const QString& user) const;
    std::list<const Utente *> search(const QString& text) const;
    bool dbEmpty() const;

    DataBase::db_iterator begin();
    DataBase::db_iterator end();
    DataBase::db_const_iterator begin() const;
    DataBase::db_const_iterator end() const;
};

#endif // ADMIN_H
