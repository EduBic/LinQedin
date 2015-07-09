#include<UDATA/info3.h>

Info3::Info3(const std::vector<QString>& x): xps(x) {}
const std::vector<QString> &Info3::getXps() const {return xps;}

void Info3::setEsperienze(const std::vector<QString>& esp){xps=esp;}

bool Info3::matchEsperienze(const QString &text) const{
    for(std::vector<QString>::const_iterator it=xps.begin(); it!=xps.end(); it++){
        if((*it).contains(text, Qt::CaseInsensitive))
            return true;
    }
    return false;
}

//METODO LETTURA IN DB
Info3 Info3::readInfo3(QXmlStreamReader& xmlReader){
    std::vector<QString> xps;
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="info3")){
        if(xmlReader.isStartElement()){
            if(xmlReader.name()=="esperienza"){xps.push_back(xmlReader.readElementText());}
        }
        xmlReader.readNext();
    }
    return Info3(xps);
}

