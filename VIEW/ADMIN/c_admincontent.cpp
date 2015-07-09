#include<VIEW/ADMIN/c_admincontent.h>

C_AdminContent::C_AdminContent(QObject *parent, Admin *model, AdminContent* view_) :
    QObject(parent), model(model), view(view_)
{
    connect(view,SIGNAL(changeTypeClicked(QString,QString)),this,SLOT(changeTypeUser(QString,QString)));
    connect(view,SIGNAL(insertUserClicked(QString,QString,QString,int)),this,SLOT(insertUser(QString,QString,QString,int)));
    connect(view,SIGNAL(searchUserClicked(QString)),this,SLOT(searchUser(QString)));
    connect(view,SIGNAL(removeUserClicked(QString)),this,SLOT(removeUser(QString)));
}

void C_AdminContent::changeTypeUser(const QString& type, const QString& user){
    if(type.contains("executive",Qt::CaseSensitive)){
        std::cout<<std::endl<<type.contains("executive",Qt::CaseSensitive)<<std::endl<<std::endl;
        std::cout<<user.toStdString()<<" diventa executive"<<std::endl;
        model->proUtente(user,2);}
    else if(type.contains("business",Qt::CaseSensitive)){
            std::cout<<user.toStdString()<<" diventa business"<<std::endl;
            model->proUtente(user,1);}
        else if(type.contains("basic",Qt::CaseSensitive)){
            std::cout<<user.toStdString()<<" diventa basic"<<std::endl;
            model->proUtente(user,0);}

    view->reBuildTable();
}

void C_AdminContent::insertUser(const QString& user, const QString &firstname, const QString &lastname, int type){
    if(!model->matchUser(user)){
        model->aggUtente(user, type, firstname, lastname);
        view->reBuildTableInsert();
        std::cout<<"Inserisco: "<<user.toStdString()<<" "<<firstname.toStdString()<<" "<<lastname.toStdString()<<std::endl;//
    }
    else{
        QMessageBox warning;
        warning.setIcon(QMessageBox::Critical);
        warning.setWindowTitle("Inserisci utente");
        warning.setText("Impossibile inserire l'utente");
        warning.setInformativeText("L'username inserito è già in uso.");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();
    }
}

void C_AdminContent::searchUser(const QString& text){
    std::list<const Utente*> risultati=model->search(text);
    view->buildTableSearch(risultati);
}

void C_AdminContent::removeUser(const QString &user){
    if(model->matchUser(user)){
        model->rimUtente(user);
        std::cout<<"eliminato: "<<user.toStdString()<<std::endl;//
        view->reBuildTableRemove();
    }
    else{
        QMessageBox warning;
        warning.setIcon(QMessageBox::Critical);
        warning.setWindowTitle("Rimuovi utente");
        warning.setText("Impossibile eliminare l'utente");
        warning.setInformativeText("L'utente selezionato non esite.");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();
    }
}
