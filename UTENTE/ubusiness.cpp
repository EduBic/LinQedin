#include<UTENTE/ubusiness.h>

UBusiness::UBusiness(Profilo* p, Rete* r, Login* l): Utente(p,r,l) {}

QString UBusiness::toString() const{
    return "Business";
}

QString UBusiness::info() const{
    QString info_txt;
    info_txt.append("L'account <span style='font-style: italic'>Business</span> è abilitato a effettuare la ricerca per username, nome, cognome,<br/>");
    info_txt.append("professione, nazionalità, lingue conosciute e titoli di studio.<br/><br/>");
    info_txt.append("Le tue possibilità di ricerca non ti soddisfano? <br/>");
    info_txt.append("Contatta l'amministratore e potenzia le tue ricerche!");
    return info_txt;
}

void UBusiness::writeTipo(QXmlStreamWriter& xmlWriter) const{
    xmlWriter.writeTextElement("tipo", "1");
}

bool UBusiness::ricerca(const Utente* user, const QString& text, const QString &category) const{
    std::cout<<std::endl<<"ricerca dell'Business!! "<<user->getLogin()->getUsername().toStdString()<<std::endl;


    if((category=="Tutto" || category=="Username") &&
            (user->getUsername()).contains(text, Qt::CaseInsensitive)){
            std::cout<<"Username Match"<<std::endl;
            return true;
    }
    else if((category=="Tutto" || category=="Nome") &&
            (user->getNome().contains(text, Qt::CaseInsensitive))){
            std::cout<<"Nome Match"<<std::endl;
            return true;
    }
    else if((category=="Tutto" || category=="Cognome") &&
            (user->getCognome().contains(text, Qt::CaseInsensitive))){
            std::cout<<"Cognome Match"<<std::endl;
            return true;
    }
    else if(category=="Tutto" &&
            (user->getPaese().contains(text, Qt::CaseInsensitive))){
            std::cout<<"Nazionalità Match"<<std::endl;
            return true;
    }
    else if(category=="Tutto" &&
            (user->getProfessione().contains(text, Qt::CaseInsensitive))){
            std::cout<<"Professione Match"<<std::endl;
            return true;
    }
    else if(category=="Tutto" &&
            (user->getLingue().contains(text, Qt::CaseInsensitive))){
            std::cout<<"Lingue Match"<<std::endl;
            return true;
    }
    else if(category=="Tutto" &&
            (user->getProfilo()->getInfo2().matchTitolo(text))){
            std::cout<<"Titoli Match"<<std::endl;
            return true;
    }
    else
        return false;
}
