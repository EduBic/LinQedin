#include<MDATA/client.h>

Client::Client(const QString &user, DataBase* db){
    pdb=db;
    utente=pdb->findUtente(user);
}

//METODI UTENTE
std::list<const Utente *> Client::cercaUser(const QString &text,const QString category){
    std::list<const Utente *> results;
    for(DataBase::db_const_iterator it=pdb->begin(); it!=pdb->end(); it++){
        if(utente!=(it->second) && utente->ricerca(it->second,text,category))
            results.push_back(it->second);
    }
    return results;
}

QString Client::getTypeUser() const{
    return utente->toString();
}

Utente* Client::getUtente(const QString &user) const{
    return pdb->findUtente(user);
}

Utente* Client::getClientUtente() const{
    return utente;
}

bool Client::existUser(const QString& user) const{
    return pdb->matchUtente(user);
}

void Client::modProfilo(const QString& name,const QString& surname, bool sex, const QDate& date,
                        const QString& address, const QString& town, const QString& region,const QString& country,
                const QString& language, const QString& profession, const QString& number, const QString& mail,
                        const std::vector<QString>& titles, const std::vector<QString> & experiences){
    utente->setProfilo(name,surname, sex, date, Residenza(town,region,address), country, language, profession, number, mail, titles, experiences);
}

//METODI RETE
void Client::insRete(const QString& user){
    if(pdb->matchUtente(user)){
        utente->getRete()->insContatto(user);
    }
}

void Client::rimRete(const QString& user){
    utente->getRete()->rimContatto(user);
}

bool Client::webEmpty() const{
        return utente->getRete()->isEmpty();
}

Rete::web_iterator Client::beginWeb(){
    return utente->getRete()->begin();
}

Rete::web_iterator Client::endWeb(){
    return utente->getRete()->end();
}

Rete::web_const_iterator Client::beginWeb() const{
    return utente->getRete()->begin();
}
Rete::web_const_iterator Client::endWeb() const{
    return utente->getRete()->end();
}
