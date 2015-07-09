#include<UTENTE/ubasic.h>

UBasic::UBasic(Profilo *p, Rete *r, Login* l): Utente(p,r,l) {}

QString UBasic::toString() const{
    return "Basic";
}

QString UBasic::info() const{
        QString info_txt;
        info_txt.append("L'account <span style='font-style: italic'>Basic</span> è abilitato a effettuare la ricerca soltanto per username, nome e <br/>cognome.<br/><br/>");
        info_txt.append("Le tue possibilità di ricerca non ti soddisfano? <br/>");
        info_txt.append("Contatta l'amministratore e potenzia le tue ricerche!");
        return info_txt;
}

void UBasic::writeTipo(QXmlStreamWriter& xmlWriter) const{
    xmlWriter.writeTextElement("tipo", "0");
}

bool UBasic::ricerca(const Utente* user, const QString& text, const QString &category) const{
    std::cout<<std::endl<<"ricerca del basic!! "<<user->getLogin()->getUsername().toStdString()<<std::endl;

    if((category=="Tutto" || category=="Username") &&
            (user->getUsername().contains(text, Qt::CaseInsensitive))){
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
    else
        return false;
}

