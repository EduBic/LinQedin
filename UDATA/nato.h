#ifndef NATO_H
#define NATO_H

#include "data.h"
#include "luogo.h"
#include<QDate>

class Nato{
private:
    QDate data;
    Luogo luogo;
public:
    //Nato(int,int,int,QString,QString);
    Nato(QDate, Luogo);
    //Nato(const Data&, const Luogo&);

    //Data getData() const;
    //Luogo getLuogo() const;
    //void setData(int,int,int);
    //void setLuogo(QString, QString);
};

#endif // NATO_H
