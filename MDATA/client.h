#ifndef CLIENT_H
#define CLIENT_H

#include<MDATA/database.h>

class Client{
private:
    Utente* utente;
    const DataBase* pdb;
public:
    Client(const QString &user, DataBase *db);

    std::list<const Utente*> cercaUser(const QString& text, const QString category);
    Utente* getUtente(const QString& user) const;
    Utente* getClientUtente() const;
    bool existUser(const QString& user) const;

    QString getTypeUser() const;
    void modProfilo(const QString& name, const QString& surname, bool sex, const QDate& date, const QString &address, const QString &town, const QString &region, const QString& country, const QString& language, const QString& profession, const QString& number, const QString& mail, const std::vector<QString> &titles, const std::vector<QString> &experiences);
    void insRete(const QString& user);
    void rimRete(const QString& user);
    bool webEmpty() const;

    Rete::web_iterator beginWeb();
    Rete::web_iterator endWeb();
    Rete::web_const_iterator beginWeb() const;
    Rete::web_const_iterator endWeb() const;

};

#endif // CLIENT_H
