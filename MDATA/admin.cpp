#include<MDATA/admin.h>

Admin::Admin(DataBase* db){
    pdb=db;
}

Utente* Admin::getUtente(const QString &user) const{
    return pdb->findUtente(user);
}


void Admin::rimUtente(const QString &user){
    pdb->distUtente(user);
}

void Admin::aggUtente(const QString& user, int tipo, const QString &nome, const QString &cognome){
        pdb->creaUtente(user, tipo, nome, cognome);
}

void Admin::proUtente(const QString &user, int tipo){
    pdb->proUtente(user, tipo);
}

bool Admin::matchUser(const QString& user) const{
    return pdb->matchUtente(user);
}

bool Admin::dbEmpty() const{
    return pdb->vuoto();
}

std::list<const Utente*> Admin::search(const QString& text) const{
    std::list<const Utente*> risultati;

    for(DataBase::db_const_iterator it=pdb->begin(); it!=pdb->end(); ++it){
        if((it->first.contains(text, Qt::CaseInsensitive))){
                risultati.push_back(it->second);
        }
        else if((it->second->getNome().contains(text, Qt::CaseInsensitive))){
                risultati.push_back(it->second);
        }
        else if((it->second->getCognome().contains(text, Qt::CaseInsensitive))){
                risultati.push_back(it->second);
        }
        else if((it->second->toString().contains(text, Qt::CaseInsensitive))){
                risultati.push_back(it->second);
        }
    }
    return risultati;
}

DataBase::db_iterator Admin::begin(){
    return  pdb->begin();
}

DataBase::db_iterator Admin::end(){
    return  pdb->end();
}

DataBase::db_const_iterator Admin::begin() const{
    return pdb->begin();
}

DataBase::db_const_iterator Admin::end() const{
    return pdb->end();
}
