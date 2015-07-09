#include<VIEW/profileview.h>

ProfileView::ProfileView(QWidget *parent, const Utente *model_) :
    QWidget(parent), model(model_)
{
    firstname=new QLabel("Nome:",this);
    lastname=new QLabel("Cognome:",this);
    date=new QLabel("Data di Nascita:",this);
    sex=new QLabel("Sesso:",this);
    res_address=new QLabel("Indirizzo civico: ",this);
    res_town=new QLabel("Città: ",this);
    res_region=new QLabel("Regione: ",this);
    country=new QLabel("Nazione:",this);
    profession=new QLabel("Professione:", this);
    language=new QLabel("Lingue:",this);
    number=new QLabel("Telefono:",this);
    email=new QLabel("Email:",this);

    box_firstname=new QLineEdit(this);
    box_lastname=new QLineEdit(this);
    box_date=new QLineEdit(this);
        box_date->setReadOnly(true);
    box_sex=new QComboBox(this);
        QStringList sex_;
        sex_<<"Maschio"<<"Femmina";
        box_sex->addItems(sex_);
    box_res_town=new QLineEdit(this);
    box_res_region=new QLineEdit(this);
    box_res_address=new QLineEdit(this);
    box_country=new QLineEdit(this);
    box_profession=new QLineEdit(this);
    box_language=new QLineEdit(this);
    box_number=new QLineEdit(this);
    box_email=new QLineEdit(this);

    titles_table=new TableRemIns(this, "Titoli di Studio");
    experiences_table=new TableRemIns(this, "Esperienze");

    box_date_calendar=new QCalendarWidget(this);
    box_date_calendar->setDisabled(true);
    box_date_calendar->setToolTip("Seleziona il mese, l'anno e il giorno \nper aggiornare la tua data");
    box_date_calendar->setToolTipDuration(3000);
    connect(box_date_calendar,SIGNAL(clicked(QDate)),this,SLOT(updateDate()));
    connect(box_date_calendar,SIGNAL(selectionChanged()),this,SLOT(updateDate()));

    showProfileUser();
    disableModify();

    //Layout
    layout=new QGridLayout(this);
    createLayout();

    setLayout(layout);
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //centerWidget();
}

//metodi get per ClientProfile
QString ProfileView::getName(){return box_firstname->text();}
QString ProfileView::getSurname(){return box_lastname->text();}
bool ProfileView::getSex(){
    if(box_sex->currentIndex()==1)
        return true; //maschio
    else
        return false; //femmina
}
QDate ProfileView::getDate(){return box_date_calendar->selectedDate();}
QString ProfileView::getResAddress(){return box_res_address->text();}
QString ProfileView::getResTown(){return box_res_town->text();}
QString ProfileView::getResRegion(){return box_res_region->text();}
QString ProfileView::getCountry(){return box_country->text();}
QString ProfileView::getProfession(){return box_profession->text();}
QString ProfileView::getLanguage(){return box_language->text();}
QString ProfileView::getNumber(){return box_number->text();}
QString ProfileView::getMail(){return box_email->text();}
std::vector<QString> ProfileView::getTitles(){return titles_table->getElements();}
std::vector<QString> ProfileView::getExperiences(){return experiences_table->getElements();}

void ProfileView::createLayout(){
    //impostazioni layout
    layout->setColumnMinimumWidth(0,20);
    layout->setColumnMinimumWidth(3,20);
    layout->setRowMinimumHeight(0,5);
    layout->setRowMinimumHeight(10,20);
    layout->setRowMinimumHeight(19,20);
    layout->setRowMinimumHeight(28,20);

    //widget
    layout->addWidget(firstname,1,1);
        layout->addWidget(box_firstname,1,2);
    layout->addWidget(lastname,2,1);
        layout->addWidget(box_lastname,2,2);
    layout->addWidget(sex,3,1);
        layout->addWidget(box_sex,3,2);
    layout->addWidget(date,4,1);
        layout->addWidget(box_date,4,2);
    layout->addWidget(box_date_calendar,5,1,4,2);

    layout->addWidget(res_address,11,1);
    layout->addWidget(res_town,12,1);
    layout->addWidget(res_region,13,1);
        layout->addWidget(box_res_address,11,2);
        layout->addWidget(box_res_town,12,2);
        layout->addWidget(box_res_region,13,2);
    layout->addWidget(country,14,1);
        layout->addWidget(box_country,14,2);
    layout->addWidget(language,15,1);
        layout->addWidget(box_language,15,2);
    layout->addWidget(profession,16,1);
        layout->addWidget(box_profession,16,2);
    layout->addWidget(number,17,1);
        layout->addWidget(box_number,17,2);
    layout->addWidget(email,18,1);
        layout->addWidget(box_email,18,2);

    layout->addWidget(titles_table,20,1,4,2);
    layout->addWidget(experiences_table,24,1,4,2);
}

void ProfileView::disableModify(){
    box_firstname->setEnabled(false);
    box_lastname->setEnabled(false);
    box_sex->setEnabled(false);
    box_country->setEnabled(false);
    box_date->setEnabled(false);
    box_date_calendar->setEnabled(false);
    box_res_address->setEnabled(false);
    box_res_town->setEnabled(false);
    box_res_region->setEnabled(false);
    box_email->setEnabled(false);
    box_language->setEnabled(false);
    box_number->setEnabled(false);
    box_profession->setEnabled(false);
    experiences_table->disableTable();
    titles_table->disableTable();

    showProfileUser();
}

void ProfileView::enableModify(){
    box_firstname->setEnabled(true);
    box_lastname->setEnabled(true);
    box_country->setEnabled(true);
    box_date->setEnabled(true);
    box_date_calendar->setEnabled(true);
    box_res_address->setEnabled(true);
    box_res_town->setEnabled(true);
    box_res_region->setEnabled(true);
    box_email->setEnabled(true);
    box_language->setEnabled(true);
    box_number->setEnabled(true);
    box_profession->setEnabled(true);
    box_sex->setEnabled(true);
    titles_table->enableTable();
    experiences_table->enableTable();
}

void ProfileView::updateDate(){
    box_date->setText(box_date_calendar->selectedDate().toString("d-M-yyyy"));
}

void ProfileView::showProfileUser(){
    box_firstname->setText(model->getNome());
    box_lastname->setText(model->getCognome());
    box_date_calendar->setSelectedDate(model->getData());
    updateDate();
    if(model->getSesso()) //maschio
        box_sex->setCurrentIndex(1);
    else //femmina
        box_sex->setCurrentIndex(0);
    box_res_address->setText(model->getResidenza().getIndirizzo());
    box_res_town->setText(model->getResidenza().getComune());
    box_res_region->setText(model->getResidenza().getRegione());
    box_country->setText(model->getPaese());
    box_profession->setText(model->getProfessione());
    box_language->setText(model->getLingue());
    box_number->setText(model->getNumero());
    box_email->setText(model->getMail());
    titles_table->setElements(model->getTitoli());
    experiences_table->setElements(model->getEsperienze());
}

void ProfileView::centerWidget(){
    //position center;
        int WIDTH = 250;
        int HEIGHT = 250;

        QDesktopWidget *desktop = QApplication::desktop();

        int screenWidth = desktop->width();
        int screenHeight = desktop->height();
        int x=(screenWidth - WIDTH) / 2;
        int y=(screenHeight - HEIGHT) / 2;

        resize(WIDTH, HEIGHT);
        move( x, y );

        adjustSize();
}

ProfileView::~ProfileView(){
    delete firstname;
    delete box_firstname;
    delete lastname;
    delete box_lastname;
    delete sex;
    delete box_sex;
    delete res_address;
    delete box_res_address;
    delete res_town;
    delete box_res_town;
    delete res_region;
    delete box_res_region;
    delete country;
    delete box_country;
    delete date;
    delete box_date;
    delete box_date_calendar;
    delete profession;
    delete box_profession;
    delete number;
    delete box_number;
    delete email;
    delete box_email;
    delete language;
    delete box_language;
    delete titles_table;
    delete experiences_table;

    delete layout;
}

