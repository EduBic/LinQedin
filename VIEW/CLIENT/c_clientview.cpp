#include<VIEW/CLIENT/c_clientview.h>

C_ClientView::C_ClientView(QObject *parent, Client *model_, ClientView *view_) :
    QObject(parent), model(model_), view(view_)
{
    clientprofile=new C_ClientProfile(this,model,view->getClientProfile());
    clientweb=new C_ClientWeb(this,model,view->getClientWeb());
    clientsearch=new C_ClientSearch(this,model,view->getClientSearch());
}

C_ClientView::~C_ClientView(){
    delete clientprofile;
    delete clientweb;
    delete clientsearch;
}
