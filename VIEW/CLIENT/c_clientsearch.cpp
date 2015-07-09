#include<VIEW/CLIENT/c_clientsearch.h>

C_ClientSearch::C_ClientSearch(QObject *parent, Client *model_, ClientSearch *view_) :
    QObject(parent), model(model_), view(view_)
{
    connect(view,SIGNAL(addContactClicked(QString)),this,SLOT(addContact(QString)));
    connect(view,SIGNAL(searchClicked(QString,QString)),this,SLOT(searchUser(QString,QString)));
}

void C_ClientSearch::addContact(const QString& user){
    if(model->getClientUtente()->getRete()->contattoInRete(user)){
        QMessageBox warning;
        warning.setIcon(QMessageBox::Information);
        warning.setWindowTitle("Aggiungi contatto");
        warning.setText("Il contatto è già nella tua rete.");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();
    }

    else{
        model->insRete(user);
        emit view->updateWeb();
        QMessageBox warning;
        warning.setIcon(QMessageBox::Information);
        warning.setWindowTitle("Aggiungi contatto");
        warning.setText("Contatto aggiunto!");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();
    }
}

void C_ClientSearch::searchUser(const QString &text, const QString& category){
    std::cout<<"Cerco pattern matching su: "<<text.toStdString()<<" categoria: "<<category.toStdString()<<std::endl;//
    if(!text.isEmpty() && !text.isNull()){
        std::list<const Utente*> risultati=model->cercaUser(text,category);
        view->buildTableSearch(risultati);
    }
}
