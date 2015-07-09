#include<VIEW/CLIENT/c_clientweb.h>

C_ClientWeb::C_ClientWeb(QObject *parent, Client *model_, ClientWeb *view_) :
    QObject(parent), model(model_), view(view_)
{
    connect(view,SIGNAL(removeContactClicked(QString)),this,SLOT(removeContactClicked(QString)));
    connect(view,SIGNAL(removeContact(QString)),this,SLOT(removeContact(QString)));
}

void C_ClientWeb::removeContactClicked(const QString &contact){
    std::cout<<"Rimosso contatto from click: "<<contact.toStdString()<<std::endl;
    model->rimRete(contact);
    view->reBuildTable();
}

void C_ClientWeb::removeContact(const QString & contact){
    std::cout<<"Rimosso contatto from build: "<<contact.toStdString()<<std::endl;
    model->rimRete(contact);
}
