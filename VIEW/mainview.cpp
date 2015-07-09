#include<VIEW/mainview.h>

MainView::MainView(QWidget *parent) :
    QGroupBox(parent)
{
    this->setObjectName("start");
    this->setStyleSheet("MainView#start { background-image: url('../LinQedin/background.jpg'); background-repeat: no-repeat; background-attachment: fixed; background-position: top left}");

    title=new QLabel("Lin<span style=\"color: #00FF00\">Q</span>edin",this);
    title->setStyleSheet("font: 92pt; font-weight: bold; color: #FFF; ");

    exit=new QPushButton("Esci",this);

    admin=new QPushButton("Admin Interface",this);
    admin->setToolTip("Apri pannello gestione database");

    client=new ClientLogin(this);

    connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(admin,SIGNAL(clicked()),client,SLOT(setLogin()));
    connect(admin,SIGNAL(clicked()),this,SIGNAL(openAdminView()));
    connect(client,SIGNAL(openClient(QString)),this,SIGNAL(openClientView(QString)));

    layout=new QVBoxLayout(this);
    layout->addWidget(title,0,Qt::AlignCenter);
    layout->addSpacing(45);
    layout->addWidget(client,0,Qt::AlignCenter);
    layout->addStretch(1);
    layout->addWidget(admin);
    layout->addWidget(exit);

    setLayout(layout);
}
