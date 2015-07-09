#include<UDATA/rete.h>

Rete::Rete(const std::list<QString> &rt): web(rt) {}

const std::list<QString> &Rete::getWeb() const {return web;}

Rete::web_iterator Rete::begin(){
    return web.begin();
}

Rete::web_iterator Rete::end(){
    return web.end();
}

Rete::web_const_iterator Rete::begin() const{
    return web.begin();
}

Rete::web_const_iterator Rete::end() const{
    return web.end();
}

bool Rete::isEmpty() const{
    return web.empty();
}

void Rete::insContatto(const QString& user){
    if(!contattoInRete(user))
        web.push_back(user);
}

bool Rete::contattoInRete(const QString &user){
    bool contenuto(false);
    std::list<QString>::const_iterator itRete=web.begin();
    while(!contenuto && (itRete!=web.end())){
       if(*itRete==user){ //il contatto è già in rete;
         contenuto=true;
       }
       itRete++;
    }
    return contenuto;
}

void Rete::rimContatto(const QString &user){
    web.remove(user);
    std::cout<<"Dimensione rete: "<<web.size()<<std::endl;
}


//METODO LETTURA
Rete* Rete::readRete(QXmlStreamReader& xmlReader){
    std::list<QString> contatti;
    while(!xmlReader.isEndElement() || !(xmlReader.name()=="rete")){
        if(xmlReader.isStartElement()){
            if(xmlReader.name()=="contatto"){
                {contatti.push_back(xmlReader.readElementText());}
            }
        }
        xmlReader.readNext();
    }
    return new Rete(contatti);
}
