#include<VIEW/ADMIN/admininsert.h>

AdminInsert::AdminInsert(QWidget *parent) :
    QFrame(parent), selected_type(0)
{
    setFrameStyle(QFrame::Panel | QFrame::Raised);
    QSize sizeLine(200,28);

    title=new QLabel("Inserisci Nuovo Utente",this);
    title->setFont(QFont("Helvetica [Cronyx]", 14, QFont::Bold));
    title->setStyleSheet("font-variant: small-caps;");

    user=new QLabel("Username",this);
    text_User=new QLineEdit(this);
    text_User->setFixedSize(sizeLine);
    firstname=new QLabel("Nome",this);
    text_Firstname=new QLineEdit(this);
    text_Firstname->setFixedSize(sizeLine);
    lastname=new QLabel("Cognome",this);
    text_Lastname=new QLineEdit(this);
    text_Lastname->setFixedSize(sizeLine);
    type=new QLabel("Tipologia",this);
    text_type=new QComboBox(this);
    QStringList typeSearch;
    typeSearch<<"Basic"<<"Business"<<"Executive";
    text_type->addItems(typeSearch);
    text_type->setFixedSize(sizeLine);
    insert=new QPushButton("Aggiungi",this);
    insert->setToolTip("Inserisci il nuovo utente \n N.B. Tutti i campi devono essere riempiti");
    insert->setToolTipDuration(3000);

    connect(text_type,SIGNAL(currentIndexChanged(QString)),this,SLOT(changeSelectedType(QString)));
    connect(insert,SIGNAL(clicked()),this,SLOT(insertUser()));

    layout=new QGridLayout(this);

        layout->addWidget(title,0,0,1,2);
        layout->setRowMinimumHeight(1,10);
        layout->addWidget(user,2,0);
        layout->addWidget(text_User,2,1);
        layout->addWidget(type,3,0);
        layout->addWidget(text_type,3,1);
        layout->addWidget(firstname,4,0);
        layout->addWidget(text_Firstname,4,1);
        layout->addWidget(lastname,5,0);
        layout->addWidget(text_Lastname,5,1);
        layout->setRowMinimumHeight(6,10);
        layout->addWidget(insert,7,1);

    setLayout(layout);
    setMaximumWidth(350);
}

void AdminInsert::insertUser(){

    if(text_User->text().isEmpty() || text_User->text().isNull() ||
       text_Firstname->text().isEmpty() || text_Firstname->text().isNull() ||
       text_Lastname->text().isEmpty() || text_Lastname->text().isNull()){
        QMessageBox warning;
        warning.setIcon(QMessageBox::Critical);
        warning.setWindowTitle("Inserisci nuovo utente");
        warning.setText("E' necessario compilare tutti i campi.");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();
    }
    else{
        QMessageBox warning;
        warning.setIcon(QMessageBox::Question);
        warning.setWindowTitle("Inserisci nuovo utente");
        warning.setText("Sei sicuro di voler inserire l'utente: <b>"+text_User->text()+"</b>");
        warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        warning.setDefaultButton(QMessageBox::Cancel);
        int ret = warning.exec();
        if(ret==QMessageBox::Yes) {
            emit insertUserClicked(text_User->text(),text_Firstname->text(),text_Lastname->text(),selected_type);
            clearTextEdit();
        }
    }
}

void AdminInsert::changeSelectedType(const QString& type){
    if(type=="Basic")
        selected_type=0;
    else if(type=="Business")
        selected_type=1;
    else if(type=="Executive")
        selected_type=2;
}

void AdminInsert::clearTextEdit(){
    text_User->clear();
    text_Firstname->clear();
    text_Lastname->clear();
}

AdminInsert::~AdminInsert(){
    delete user;
    delete text_User;
    delete firstname;
    delete lastname;
    delete text_Firstname;
    delete text_Lastname;
    delete type;
    delete text_type;
    delete insert;

    delete layout;
}
