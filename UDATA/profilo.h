#ifndef PROFILO_H
#define PROFILO_H

#include<UDATA/info1.h>
#include<UDATA/info2.h>
#include<UDATA/info3.h>

class Profilo{
private:
    Info1 base;
    Info2 lavorative;
    Info3 avanzate;
public:
    Profilo(const Info1 &i1, const Info2& i2, const Info3& i3);
    const Info1& getInfo1() const;
    const Info2& getInfo2() const;
    const Info3& getInfo3() const;

    void setInfo1(const QString& name, const QString& surname, bool sex, const QDate& date, const QString& country);
    void setInfo2(const Residenza &res, const QString& language, const QString& profession,
                  const QString& number, const QString& mail,const std::vector<QString>& titles);
    void setInfo3(const std::vector<QString> &experiences);

    static Profilo* readProfilo(QXmlStreamReader& );
};

#endif // PROFILO_H
