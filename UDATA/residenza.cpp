#include<UDATA/residenza.h>

Residenza::Residenza(const QString &com, const QString &reg, const QString &ind):
    comune(com), regione(reg), indirizzo(ind) {}

QString Residenza::getComune() const{return comune;}
QString Residenza::getRegione() const{return regione;}
QString Residenza::getIndirizzo() const{return indirizzo;}


Residenza Residenza::readResidenza(QXmlStreamReader& xmlReader){
    QString comune="Unknown";
    QString regione="Unknown";
    QString indirizzo="Unknown";
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="residenza")){
            if(xmlReader.isStartElement()){
                if(xmlReader.name()=="comune"){comune=xmlReader.readElementText();}
                else if(xmlReader.name()=="regione"){regione=xmlReader.readElementText();}
                else if(xmlReader.name()=="indirizzo"){indirizzo=xmlReader.readElementText();}
            }
            xmlReader.readNext();
    }
    return Residenza(comune,regione,indirizzo);
}

