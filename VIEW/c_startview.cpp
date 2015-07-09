#include<VIEW/c_startview.h>

C_StartView::C_StartView(QObject *parent, Admin *admin_, Client *client_, DataBase *db, StartView *view_) :
    QObject(parent), linQedinAdmin(admin_), linQedinClient(client_), database(db), view(view_)
{
    view->show();

    c_client=0;
    c_admin=0;

    connect(view,SIGNAL(createC_ClientView()),this, SLOT(createC_ClientView()));
    connect(view,SIGNAL(createC_AdminView()),this,SLOT(createC_AdminView()));
    connect(view,SIGNAL(deleteControllers()),this,SLOT(deleteControllers()));
    connect(view,SIGNAL(deleteModel()),this,SLOT(deleteModel()));

    connect(view,SIGNAL(createClientModel(QString)),this,SLOT(createClientModel(QString)));
    connect(view,SIGNAL(createAdminModel()),this,SLOT(createAdminModel()));
}

void C_StartView::createC_ClientView(){
    c_client=new C_ClientView(this,linQedinClient,view->getClientView());
}

void C_StartView::createC_AdminView(){
    c_admin=new C_AdminView(this,linQedinAdmin,view->getAdminView());
}

void C_StartView::createAdminModel(){
    linQedinAdmin=new Admin(database);
    view->setAdminModel(linQedinAdmin);
}

void C_StartView::createClientModel(const QString &user){
    if(database->matchUtente(user)){
        linQedinClient=new Client(user,database);
        view->setClientModel(linQedinClient);
        }
    else
        view->noMatchUser();
}


void C_StartView::deleteControllers(){
    delete c_admin;
    delete c_client;
    c_client=0;
    c_admin=0;
}

void C_StartView::deleteModel(){
    delete linQedinAdmin;
    delete linQedinClient;
    linQedinAdmin=0;
    linQedinClient=0;
    view->setAdminModel(0);
    view->setClientModel(0);
}
