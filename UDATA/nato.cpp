#include "nato.h"

//Nato::Nato(int g, int m, int a, QString c, QString r): data(g,m,a), luogo(c,r) {}

Nato::Nato(QDate d, Luogo l): data(d), luogo(l) {}

//Nato::Nato(const Data &d, const Luogo &l): data(d), luogo(l) {}

/*Data Nato::getData() const{
    return data;
}

Luogo Nato::getLuogo() const{
    return luogo;
}

void Nato::setData(int g, int m, int a){
    data.setGiorno(g);
    data.setMese(m);
    data.setGiorno(g);
    data.setData(g,m,a);
}

void Nato::setLuogo(QString c, QString r){
    luogo.setLuogo(c,r);
}


void Nato::setData(Data& d){
    data.(d);
}

void Nato::setLuogo(Luogo& l){
    luogo(l);
}
*/
