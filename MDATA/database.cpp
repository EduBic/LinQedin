#include<MDATA/database.h>

QString DataBase::filename="../LinQedin/DataBase.xml";

DataBase::DataBase() {
    Load();
}

DataBase::~DataBase(){
    Close();
    for(db_const_iterator it=db.begin(); it!=db.end(); it++){
        distUtente(it->first);
    }
}

DataBase::db_iterator DataBase::begin(){
    return  db.begin();
}

DataBase::db_iterator DataBase::end(){
    return  db.end();
}

DataBase::db_const_iterator DataBase::begin() const{
    return db.begin();
}

DataBase::db_const_iterator DataBase::end() const{
    return db.end();
}

bool DataBase::vuoto() const{
    return db.empty();
}

void DataBase::distUtente(const QString& user){
    delete db.find(user)->second;
    db.erase(user);
}

void DataBase::creaUtente(const QString &user, int tipo, const QString &nome, const QString &cognome){
    if(!matchUtente(user)){
        Profilo* p=new Profilo(Info1(nome, cognome), Info2(), Info3());
        Rete* r=new Rete(std::list<QString>());
        Login* l=new Login(user);
        if(tipo==2)
            db[user]=new UExecutive(p,r,l);
        else if(tipo==1)
            db[user]=new UBusiness(p,r,l);
        else //tipo=0;
            db[user]=new UBasic(p,r,l);
    }
}

bool DataBase::matchUtente(const QString &user) const{
    if(db.find(user)!=db.end())
        return true;
    else
        return false;
}

void DataBase::proUtente(const QString &user, const int tipo){
    if(matchUtente(user)){
        //prelevo i dati e distruggo soltanto il nodo nel db;
        Utente* old=db[user];
        Profilo* p=old->getProfilo();
        Rete* r=old->getRete();
        Login* l=old->getLogin();
        db.erase(user);

        if(tipo==2)
            db[user]=new UExecutive(p,r,l);
        else if(tipo==1)
            db[user]=new UBusiness(p,r,l);
        else if(tipo==0)
            db[user]=new UBasic(p,r,l);

        old=0;
        p=0;
        r=0;
        l=0;
    }
}

Utente* DataBase::findUtente(const QString &user) const{
    if(matchUtente(user)){
        return db.find(user)->second;
    }
    else{
        return 0;
    }
}

void DataBase::stampaUtente(const Utente *u) const{
    std::cout<<std::endl<<u->getUsername().toStdString()<<std::endl;
    std::cout<<u->getNome().toStdString();
    std::cout<<" "<<u->getCognome().toStdString()<<std::endl<<std::endl;
}

void DataBase::Close(){

     QFile file(filename);
     file.open(QIODevice::WriteOnly);

     QXmlStreamWriter xmlWriter(&file);
     xmlWriter.setAutoFormatting(true);
     xmlWriter.writeStartDocument();

     xmlWriter.writeStartElement("database");

     std::map<QString,Utente*>::const_iterator it=db.begin();
     for( ; it!=db.end(); ++it){

     xmlWriter.writeStartElement("utente");

     xmlWriter.writeTextElement("username", (it->first));

     (it->second)->writeTipo(xmlWriter);  //scrittura polimorfica del tipo;

     xmlWriter.writeStartElement("profilo");

     xmlWriter.writeStartElement("info1");
     xmlWriter.writeTextElement("nome", it->second->getNome());
     xmlWriter.writeTextElement("cognome", it->second->getCognome());
     xmlWriter.writeTextElement("sesso",it->second->getSessoString());
     xmlWriter.writeTextElement("data", it->second->getDataString());
     xmlWriter.writeTextElement("paese", it->second->getPaese());
     xmlWriter.writeEndElement(); //info1

     xmlWriter.writeStartElement("info2");
     xmlWriter.writeStartElement("residenza");
        xmlWriter.writeTextElement("comune", it->second->getResidenza().getComune());
        xmlWriter.writeTextElement("regione", it->second->getResidenza().getRegione());
        xmlWriter.writeTextElement("indirizzo", it->second->getResidenza().getIndirizzo());
     xmlWriter.writeEndElement(); //residenza
     xmlWriter.writeTextElement("professione", it->second->getProfessione());
     xmlWriter.writeTextElement("lingue", it->second->getLingue());

     xmlWriter.writeTextElement("numero", it->second->getNumero());
     xmlWriter.writeTextElement("mail", it->second->getMail());
     std::vector<QString> titoli=(it->second->getTitoli());
        std::vector<QString>::const_iterator it2=titoli.begin();
        for( ; it2<titoli.end(); it2++){
            xmlWriter.writeTextElement("titolo", *it2);
        }
     xmlWriter.writeEndElement(); //info2

     xmlWriter.writeStartElement("info3");
     std::vector<QString> esperienze=(it->second->getEsperienze());
        std::vector<QString>::const_iterator it3=esperienze.begin();
        for( ; it3<esperienze.end(); it3++){
            xmlWriter.writeTextElement("esperienza", *it3);
        }
     xmlWriter.writeEndElement(); //info3

     xmlWriter.writeEndElement(); //profilo


     xmlWriter.writeStartElement("rete");
     if(it->second->getRete()){
        std::list<QString> contatti=(it->second->getRete()->getWeb());
        std::list<QString>::const_iterator itRete=contatti.begin();
        for( ; itRete!=contatti.end(); itRete++){
            std::map<QString, Utente*>::const_iterator itMap=db.find(*itRete);
            if(itMap!=db.end())
                xmlWriter.writeTextElement("contatto", *itRete);
            }
     }
     xmlWriter.writeEndElement(); //rete

     xmlWriter.writeEndElement(); // utente

     }

     xmlWriter.writeEndElement(); // database

     xmlWriter.writeEndDocument();

     file.close();

     //std::cout<<std::endl<<"database written"<<std::endl;
}

void DataBase::Load(){
    //variabili temporanee
    QString username="Unknown";
    int tipo=0;
    Profilo* p=0;
    Rete* r=0;
    Login* l=0;

    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text)){
        std::cout << "Error: Cannot read file"<< std::endl;
    }
    QXmlStreamReader xmlReader(&file);
    xmlReader.readNext();

    while(!xmlReader.atEnd())
    {
        if(xmlReader.isStartElement())  //legge apertura Tag
        {
            if(xmlReader.name()=="database" || xmlReader.name()=="utente")
            {
               xmlReader.readNext();
            }
            else if(xmlReader.name()=="username"){
                username=xmlReader.readElementText();
                l=new Login(username);
            }
            else if(xmlReader.name()=="tipo")
            {
                tipo=xmlReader.readElementText().toInt();
            }
            else if(xmlReader.name()=="profilo")
            {
                p=Profilo::readProfilo(xmlReader);
            }
            else if(xmlReader.name()=="rete")
            {
                r=Rete::readRete(xmlReader);
            }
            else std::cout<<"we got a problem "; //FLAG di allarme;
        }
        else
        {
            if(xmlReader.isEndElement() && xmlReader.name()=="utente"){ //leggo </utente> //costruisco utente

                    if(tipo==1){
                        db[username]=new UBusiness(p,r,l);
                    }
                    else if(tipo==2){
                        db[username]=new UExecutive(p,r,l);
                    }
                    else{ //tipo==0
                        db[username]=new UBasic(p,r,l);
                    }
                    tipo=0;
                    username="Unknown";

                xmlReader.readNext();
            }
            else //leggo vuoto o EndElement!="utente"
                xmlReader.readNext();
        }
   }
    //std::cout<<std::endl<<std::endl<<"database read"<<std::endl;
    file.close();
}
