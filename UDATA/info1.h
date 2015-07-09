#ifndef INFO1_H
#define INFO1_H

#include<QDate>
#include<QString>

#include<UDATA/residenza.h>

class Info1{
private:
    QString nome;
    QString cognome;
    bool sesso;
    QDate dataNascita;
    QString paese;
public:
    Info1(const QString &nm ="Unknown", const QString &cg ="Unknown", const bool sx =0, const QDate &dt =QDate(1970,1,1), const QString& ps ="");

    const QString& getNome() const;
    const QString& getCognome() const;
    bool getSesso() const;
    QString getSessoString() const;
    QString getDataString() const;
    const QDate& getData() const;
    const QString& getPaese() const;

    void setNome(const QString& nm);
    void setCognome(const QString& cgn);
    void setSesso(bool s);
    void setData(const QDate& dt);
    void setPaese(const QString& ps);

    static Info1 readInfo1(QXmlStreamReader& );


};

#endif // INFO1_H
