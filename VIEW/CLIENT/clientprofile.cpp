#include<VIEW/CLIENT/clientprofile.h>

ClientProfile::ClientProfile(QWidget *parent, const Client *model_) :
    QWidget(parent), model(model_), scroll_area(new QScrollArea), profile(new ProfileView(this,model->getClientUtente()))
{
    title=new QLabel("Il tuo profilo",this);
    title->setFont(QFont("Helvetica [Cronyx]", 16, QFont::Bold));
    title->setStyleSheet("font-variant: small-caps; border-bottom:1px solid black;");

    scroll_area->setWidget(profile);
    scroll_area->setWidgetResizable(true);
    scroll_area->setAlignment(Qt::AlignHCenter);
    scroll_area->adjustSize();
    scroll_area->setMinimumWidth(560);

    cancel=new QPushButton("Annulla",this);
    cancel->setToolTip("Annulla le modifiche effettuate");
    cancel->setToolTipDuration(3000);
    cancel->hide();
    modify=new QPushButton("Modifica",this);
    modify->setText("Modifica");
    modify->setToolTip("Modifica i dati del tuo profilo");
    modify->setToolTipDuration(3000);

    connect(modify,SIGNAL(clicked()),this,SLOT(modifyClicked()));
    connect(cancel,SIGNAL(clicked()),this,SLOT(cancelClicked()));

    layout_button=new QHBoxLayout();
    layout_button->addWidget(cancel,Qt::AlignCenter);
    layout_button->addWidget(modify,Qt::AlignCenter);

    layout=new QVBoxLayout(this);
    layout->addWidget(title);
    layout->addWidget(scroll_area);
    layout->addSpacing(5);
    layout->addLayout(layout_button);

    setLayout(layout);
}

ProfileView* ClientProfile::getProfileView(){
    return profile;
}

void ClientProfile::modifyClicked(){
    cancel->show();

    profile->enableModify();

    modify->setText("Applica");
    modify->setToolTip("Applica le modifiche \neffettuate al tuo profilo");
    modify->setToolTipDuration(3000);

    disconnect(modify,SIGNAL(clicked()),this,SLOT(modifyClicked()));
    connect(modify,SIGNAL(clicked()),this,SLOT(applyClicked()));
}

void ClientProfile::applyClicked(){
    emit applyModify();
}

void ClientProfile::cancelClicked(){
    cancel->hide();

    profile->disableModify();

    modify->setText("Modifica");
    modify->setToolTip("Modifica i dati del tuo profilo");
    modify->setToolTipDuration(3000);

    disconnect(modify,SIGNAL(clicked()),this,SLOT(applyClicked()));
    connect(modify,SIGNAL(clicked()),this,SLOT(modifyClicked()));
}

void ClientProfile::applyModifyError(const QString& error) const{
    QMessageBox warning;
    warning.setIcon(QMessageBox::Warning);
    warning.setWindowTitle("Applica modifiche");
    warning.setText(error);
    warning.setStandardButtons(QMessageBox::Ok);
    warning.setDefaultButton(QMessageBox::Ok);
    warning.exec();
}

void ClientProfile::applyModifySuccess(){
    cancel->hide();
    profile->disableModify();

    modify->setText("Modifica");
    modify->setToolTip("Modifica i dati del tuo profilo");
    modify->setToolTipDuration(3000);

    disconnect(modify,SIGNAL(clicked()),this,SLOT(applyClicked()));
    connect(modify,SIGNAL(clicked()),this,SLOT(modifyClicked()));
}

ClientProfile::~ClientProfile(){
    delete title;
    delete profile;
    delete scroll_area;
    delete modify;
    delete cancel;

    delete layout_button;
    delete layout;
}
