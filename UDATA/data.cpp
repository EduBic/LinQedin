#include "data.h"

Data::Data(int g, int m, int a): giorno(g), mese(m), anno(a) { controlloData();}
//Data::Data(const int& g, const int& m, const int& a): giorno(g), mese(m), anno(a) {controlloData();}
Data::Data(const Data& d): giorno(d.giorno), mese(d.mese), anno(d.anno) { controlloData();}

int Data::getGiorno() const{
    return giorno;
}
int Data::getMese() const{
    return mese;
}
int Data::getAnno() const{
    return anno;
}

void Data::setGiorno(int g){
     giorno=g;
     controlloData();
}

void Data::setMese(int m){
    mese=m;
    controlloData();
}

void Data::setAnno(int a){
    anno=a;
    controlloData();
}

void Data::setData(int g,int m, int a){
    giorno=g;
    mese=m;
    anno=a;
    controlloData();
}


void Data::controlloData(){
    if(anno<1920) anno=1920;
    if(mese<1 || mese>12) mese=1;

    if(mese==4 || mese==6 || mese==9 || mese==11){
      if(giorno<1 || giorno>30) giorno=1;
    }
    else
        if(mese==2){
            if(anno%4==0) //bisestile
                {if(giorno<1 || giorno>29) giorno=1;}
            else          //non bisestile
                {if(giorno<1 || giorno>=29) giorno=1;}
        }
        else{
            if(giorno<1 || giorno >31) giorno=1;
        }
}
