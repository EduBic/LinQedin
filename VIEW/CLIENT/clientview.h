#ifndef CLIENTVIEW_H
#define CLIENTVIEW_H

#include <QWidget>
#include<QHBoxLayout>
#include<QLabel>
#include<QGroupBox>
#include<QApplication>
#include<QDesktopWidget>
#include<QIcon>

#include "clientmenu.h"
#include "clientsearch.h"
#include "clientweb.h"
#include "clientprofile.h"

#include "MDATA/client.h"

class ClientView : public QWidget
{
    Q_OBJECT
public:
    explicit ClientView(QWidget *parent = 0, const QString& user ="Anonimo", const Client* model_ =0);
    ~ClientView();

    //get per controller
    ClientProfile* getClientProfile() const;
    ClientWeb* getClientWeb() const;
    ClientSearch* getClientSearch() const;

signals:
    void disconnectUserView();

public slots:
    void showProfile();
    void showWeb();
    void showSearch();

private:
    void centerWidget();

    const Client* model;

    QString user_login;

    QLabel* username;
    ClientMenu* menu;
    ClientProfile* profile;
    ClientWeb* web;
    ClientSearch* search;

    QHBoxLayout* layout;
};

#endif // CLIENTVIEW_H
