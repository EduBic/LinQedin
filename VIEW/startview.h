#ifndef STARTVIEW_H
#define STARTVIEW_H

#include <QWidget>
#include<QPushButton>
#include<QVBoxLayout>
#include<QApplication>
#include<QLabel>
#include<QIcon>
#include<QMainWindow>
#include<QDesktopWidget>

#include<VIEW/CLIENT/clientview.h>
#include<VIEW/ADMIN/adminview.h>
#include<VIEW/mainview.h>
#include<MDATA/admin.h>
#include<MDATA/client.h>
#include<VIEW/c_startview.h>


class StartView : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartView(QGroupBox *parent = 0);

    ClientView* getClientView();
    AdminView* getAdminView();

    void setAdminModel(const Admin* model_);
    void setClientModel(const Client* model_);
    void noMatchUser();

signals:
    void createC_ClientView();
    void createC_AdminView();
    void deleteControllers();

    void createClientModel(const QString&);
    void createAdminModel();
    void deleteModel();

private slots:
    void createAdmin();
    void createClient(const QString& user);
    void backInTime();

private:
    void centerWidget();
    void createMain();

    MainView* main_view;
    ClientView* client_view;
    AdminView* admin_view;

    const Client* client_model; //puntatori read-only
    const Admin* admin_model;
};

#endif // STARTVIEW_H
