#include<UDATA/login.h>

Login::Login(QString user): username(user){}

const QString &Login::getUsername() const{
    return username;
}

//METODO LETTURA IN DB
Login* Login::readLogin(QXmlStreamReader& xmlReader){
    return new Login(xmlReader.readElementText());
}
