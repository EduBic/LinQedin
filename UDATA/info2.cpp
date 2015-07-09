#include<UDATA/info2.h>

Info2::Info2(const Residenza &rs, const QString &pro, const QString &lng,
             const QString &num, const QString &mail, const std::vector<QString> &x):
        res(rs), profession(pro), lingue(lng), numero(num), mail(mail), titoli(x) {}

const std::vector<QString> &Info2::getTitoli() const {
    return titoli;
}
const QString &Info2::getNumero() const{return numero;}
const QString &Info2::getMail() const{return mail;}
const Residenza &Info2::getResidenza() const{return res;}
const QString &Info2::getProfessione() const{return profession;}
const QString &Info2::getLingue() const{return lingue;}

void Info2::setResidenza(const Residenza &rs){res=rs;}
void Info2::setProfessione(const QString & prof){profession=prof;}
void Info2::setLingue(const QString& lg){lingue=lg;}
void Info2::setTitoli(const std::vector<QString>& tls){titoli=tls;}
void Info2::setNumero(const QString &nm){numero=nm;}
void Info2::setMail(const QString &ml){mail=ml;}

bool Info2::matchTitolo(const QString& text) const{
    for(std::vector<QString>::const_iterator it=titoli.begin(); it!=titoli.end(); it++){
        if((*it).contains(text, Qt::CaseInsensitive))
            return true;
    }
    return false;
}

//METODO LETTURA IN DB
Info2 Info2::readInfo2(QXmlStreamReader& xmlReader){
    Residenza residenza;
    QString professione="Unknown";
    QString lingue="Unkown";
    QString numero="Unknown";
    QString mail="Unknown";
    std::vector<QString> titoli;
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="info2")){
            if(xmlReader.isStartElement()){
                if(xmlReader.name()=="residenza"){residenza=Residenza::readResidenza(xmlReader);}
                else if(xmlReader.name()=="professione"){professione=xmlReader.readElementText();}
                else if(xmlReader.name()=="lingue"){lingue=xmlReader.readElementText();}
                else if(xmlReader.name()=="numero"){numero=xmlReader.readElementText();}
                else if(xmlReader.name()=="mail"){mail=xmlReader.readElementText();}
                else if(xmlReader.name()=="titolo"){titoli.push_back(xmlReader.readElementText());}
            }
            xmlReader.readNext();
    }
    return Info2(residenza, professione, lingue, numero, mail, titoli);
}
