#ifndef C_CLIENTSEARCH_H
#define C_CLIENTSEARCH_H

#include <QObject>

#include<iostream>

#include "../../MDATA/client.h"
#include "clientsearch.h"

class C_ClientSearch : public QObject
{
    Q_OBJECT
public:
    explicit C_ClientSearch(QObject *parent = 0, Client* model_ =0, ClientSearch* view_ =0);

signals:

public slots:
    void addContact(const QString& user);
    void searchUser(const QString& text,const QString& category);

private:
    Client* model;
    ClientSearch* view;

};

#endif // C_CLIENTSEARCH_H
