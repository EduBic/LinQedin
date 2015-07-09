#ifndef C_STARTVIEW_H
#define C_STARTVIEW_H

#include <QObject>

#include<VIEW/startview.h>
#include<MDATA/admin.h>
#include<MDATA/client.h>
#include<VIEW/ADMIN/c_adminview.h>
#include<VIEW/CLIENT/c_clientview.h>

class StartView;

class C_StartView : public QObject
{
    Q_OBJECT
public:
    explicit C_StartView(QObject *parent = 0, Admin *admin_ =0, Client *client_ =0, DataBase* db =0, StartView* view_ =0);

signals:

public slots:
    void createC_ClientView();
    void createC_AdminView();
    void createClientModel(const QString &user);
    void createAdminModel();

    void deleteControllers();
    void deleteModel();

private:
    Admin* linQedinAdmin;
    Client* linQedinClient;
    DataBase* database;

    StartView* view;

    C_AdminView* c_admin;
    C_ClientView* c_client;

};

#endif // C_STARTVIEW_H
