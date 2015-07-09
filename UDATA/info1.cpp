#include<UDATA/info1.h>

Info1::Info1(const QString& nm, const QString& cg, const bool sx, const QDate &dt, const QString& ps):
    nome(nm), cognome(cg), sesso(sx), dataNascita(dt), paese(ps) {}

const QString &Info1::getNome() const{return nome;}
const QString &Info1::getCognome() const{return cognome;}
bool Info1::getSesso() const{return sesso;}
QString Info1::getSessoString() const{
        if(sesso) return "F";
        else return "M";
}
QString Info1::getDataString() const{return dataNascita.toString("d/M/yyyy");}
const QDate &Info1::getData() const{return dataNascita;}
const QString &Info1::getPaese() const{return paese;}

void Info1::setNome(const QString& nm){nome=nm;}
void Info1::setCognome(const QString & cgn){cognome=cgn;}
void Info1::setSesso(bool s){sesso=s;}
void Info1::setData(const QDate& dt){dataNascita=dt;}
void Info1::setPaese(const QString & ps){paese=ps;}


//METODO LETTURA IN DB
Info1 Info1::readInfo1(QXmlStreamReader& xmlReader){
    QString nome="Unknown";
    QString cognome="Unknown";
    bool sesso=0; //maschio per default
    QString dataNascita="1/1/1910";
    QString paese="Unknown";
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="info1")){
            if(xmlReader.isStartElement()){
                if(xmlReader.name()=="nome"){nome=xmlReader.readElementText();}
                else if(xmlReader.name()=="cognome"){cognome=xmlReader.readElementText();}
                else if(xmlReader.name()=="sesso"){
                    if(xmlReader.readElementText()=="M") sesso=0; //è maschio?
                    else sesso=1;
                }
                else if(xmlReader.name()=="data"){dataNascita=xmlReader.readElementText();}
                else if(xmlReader.name()=="paese"){paese=xmlReader.readElementText();}
            }
            xmlReader.readNext();
    }
    QDate date(QDate::fromString(dataNascita,"d/M/yyyy"));
    return (Info1(nome,cognome,sesso,date,paese));
}
