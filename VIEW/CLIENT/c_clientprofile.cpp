#include<VIEW/CLIENT/c_clientprofile.h>

C_ClientProfile::C_ClientProfile(QObject *parent, Client *model_, ClientProfile *view_):
    QObject(parent), model(model_), view(view_)
{
    connect(view,SIGNAL(applyModify()),this,SLOT(applyModify()));
}

void C_ClientProfile::applyModify(){
    std::cout<<"Raccolgo i dati nelle form"<<std::endl;
    QString name=view->getProfileView()->getName();
    QString surname=view->getProfileView()->getSurname();
    bool sex=view->getProfileView()->getSex();
    QDate date=view->getProfileView()->getDate();
    QString address=view->getProfileView()->getResAddress();
    QString town=view->getProfileView()->getResTown();
    QString region=view->getProfileView()->getResRegion();
    QString country=view->getProfileView()->getCountry();
    QString language=view->getProfileView()->getLanguage();
    QString profession=view->getProfileView()->getProfession();
    QString number=view->getProfileView()->getNumber();
    QString mail=view->getProfileView()->getMail();
    std::vector<QString> titles=view->getProfileView()->getTitles();
    std::vector<QString> experiences=view->getProfileView()->getExperiences();

    QRegExp re("^[1-9]{1,1}[0-9]{9,9}$");

    if(name.isEmpty() || name.isNull() || surname.isEmpty() || surname.isNull()){
        view->applyModifyError("E' necessario aver compilato \ni campi nome, cognome.");
    }
    else if((re.indexIn(number)<0) && (!number.isEmpty())){
        view->applyModifyError("Il campo numero deve contenere \nun numero di 10 cifre valido.");
    }
    else{
        model->modProfilo(name,surname,sex,date,address,town,region,country,language,profession,number,mail,titles,experiences);
        view->applyModifySuccess();
        std::cout<<"Profilo modificato"<<std::endl;
    }
}
