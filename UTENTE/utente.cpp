#include<UTENTE/utente.h>

Utente::Utente(Profilo *p, Rete* r, Login * l): pr(p), rete(r), lg(l) {}

Profilo* Utente::getProfilo() const {return pr;}

Rete* Utente::getRete() const {return rete;}

Login* Utente::getLogin() const {return lg;}

void Utente::setProfilo(const QString& name,const QString& surname, bool sex, const QDate& date, const Residenza& res, const QString& country,
                        const QString& language, const QString& profession, const QString& number, const QString& mail,
                        const std::vector<QString>& titles, const std::vector<QString> & experiences){
    pr->setInfo1(name,surname,sex,date, country);
    pr->setInfo2(res,language,profession, number,mail,titles);
    pr->setInfo3(experiences);
}

const QString &Utente::getUsername() const{return lg->getUsername();}
const QString &Utente::getNome() const{return pr->getInfo1().getNome();}
const QString &Utente::getCognome() const{return pr->getInfo1().getCognome();}
bool Utente::getSesso() const{return pr->getInfo1().getSesso();}
QString Utente::getSessoString() const{return pr->getInfo1().getSessoString();}
const QDate &Utente::getData() const{return pr->getInfo1().getData();}
QString Utente::getDataString() const{return pr->getInfo1().getDataString();}
const QString &Utente::getPaese() const{return pr->getInfo1().getPaese();}
const Residenza &Utente::getResidenza() const{return pr->getInfo2().getResidenza();}
const QString &Utente::getProfessione() const{return pr->getInfo2().getProfessione();}
const QString &Utente::getLingue() const{return pr->getInfo2().getLingue();}
const QString &Utente::getNumero() const{return pr->getInfo2().getNumero();}
const QString &Utente::getMail() const{return pr->getInfo2().getMail();}
const std::vector<QString> &Utente::getTitoli() const{return pr->getInfo2().getTitoli();}
const std::vector<QString> &Utente::getEsperienze() const{return pr->getInfo3().getXps();}

Utente::~Utente(){
    delete pr;
    delete rete;
    delete lg;
}
