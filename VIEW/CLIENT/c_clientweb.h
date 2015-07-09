#ifndef C_CLIENTWEB_H
#define C_CLIENTWEB_H

#include <QObject>

#include<iostream>

#include "../../MDATA/client.h"
#include "clientweb.h"

class C_ClientWeb : public QObject
{
    Q_OBJECT
public:
    explicit C_ClientWeb(QObject *parent = 0, Client* model_ =0, ClientWeb* view_ =0);

signals:

public slots:
    void removeContactClicked(const QString& contact);
    void removeContact(const QString &contact);

private:
    Client* model;
    ClientWeb* view;

};

#endif // C_CLIENTWEB_H
