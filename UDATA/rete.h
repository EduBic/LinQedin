#ifndef RETE_H
#define RETE_H

#include<list>
#include<QString>
#include<iostream>
#include<QXmlStreamReader>

class Rete{
private:
    std::list<QString> web;

public:
    typedef std::list<QString>::iterator web_iterator;
    typedef std::list<QString>::const_iterator web_const_iterator;

    Rete(const std::list<QString>& rt =std::list<QString>());

    web_iterator begin();
    web_iterator end();
    web_const_iterator begin() const;
    web_const_iterator end() const;

    const std::list<QString>& getWeb() const;
    bool isEmpty() const;
    void insContatto(const QString& user);
    void rimContatto(const QString& user);
    bool contattoInRete(const QString& user);

    static Rete* readRete(QXmlStreamReader& );
    //la fun non si preoccupa dell'esistenza username (dovrà farlo quella che li aggiunge)

};

#endif // RETE_H
