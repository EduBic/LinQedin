#include<VIEW/clientlogin.h>

ClientLogin::ClientLogin(QWidget *parent) :
    QFrame(parent)
{
    setFrameStyle(QFrame::Panel | QFrame::Raised);
    setFrameShadow(QFrame::Plain);
    setFixedSize(320,160);

    setStyleSheet("ClientLogin{ background-color: grey; border: 1px solid #FFF;}");

    label=new QLabel("Inserisci il tuo UserName: ",this);
    label->setStyleSheet("color: white; font: 18pt;");
    textedit=new QLineEdit(this);
    textedit->setPlaceholderText("inserisci qui l'username");
    textedit->setFixedSize(180,30);
    button=new QPushButton("Login",this);
    button->setDisabled(true);

    setLogin();

    connect(button,SIGNAL(clicked()),this,SLOT(getLogin()));
    connect(textedit,SIGNAL(returnPressed()),this,SLOT(getLogin()));

    layout=new QVBoxLayout(this);
    layout->addWidget(label);
    layout->addWidget(textedit,0,Qt::AlignCenter);
    layout->addWidget(button,0,Qt::AlignRight);

    button->setToolTip(tr("Esegui il login"));
    button->setToolTipDuration(3000);

    setLayout(layout);
}

void ClientLogin::getLogin(){
    if(!textedit->text().isEmpty() && !textedit->text().isNull()){
        emit openClient(textedit->text());
        setLogin();
    }
    else{
        QMessageBox warning;
        warning.setIcon(QMessageBox::Information);
        warning.setText("UserName non valido");
        warning.exec();
    }
}

void ClientLogin::selectText(){
    textedit->setStyleSheet("color: #404040;");
    button->setEnabled(true);
    disconnect(textedit,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(selectText()));
}

void ClientLogin::setLogin(){
    button->setDisabled(true);
    textedit->clear();
    textedit->setStyleSheet("color: #808080;");
    connect(textedit,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(selectText()));
}
