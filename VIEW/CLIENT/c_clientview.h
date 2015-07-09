#ifndef C_CLIENTVIEW_H
#define C_CLIENTVIEW_H

#include <QObject>

#include "../../MDATA/client.h"
#include "clientview.h"
#include "c_clientprofile.h"
#include "c_clientsearch.h"
#include "c_clientweb.h"

class C_ClientView : public QObject
{
    Q_OBJECT
public:
    explicit C_ClientView(QObject *parent = 0, Client* model_ =0, ClientView* view_ =0);
    ~C_ClientView();

signals:

public slots:

private:
    Client* model;
    ClientView* view;

    C_ClientProfile* clientprofile;
    C_ClientWeb* clientweb;
    C_ClientSearch* clientsearch;

};

#endif // C_CLIENTVIEW_H
