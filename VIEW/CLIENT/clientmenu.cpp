#include<VIEW/CLIENT/clientmenu.h>

ClientMenu::ClientMenu(QWidget *parent, const QString& user, const QString& type) :
    QFrame(parent)
{
    this->setFrameStyle(QFrame::Panel | QFrame::Raised);
    this->setFixedWidth(300);

    title=new QLabel(user, this);
    title->setFont(QFont("Helvetica [Cronyx]", 28, QFont::Bold));
    title->setStyleSheet("font-variant: small-caps; text-align: center;");

    image=new QLabel("CIAO",this);
    pix=new QPixmap("../LinQedin/user.gif","gif");
    image->setScaledContents(true);
    image->setPixmap(*pix);
    image->setFixedSize(170,125);

    effect = new QGraphicsDropShadowEffect(this);
    effect->setOffset(2,2);
    effect->setBlurRadius(4);
    image->setGraphicsEffect(effect);

    account=new QLabel("Tipo account: <span style=\"color: #0000CC; font-style: italic\">"+type+"</span>",this);

    QString istruzioni=
            "Benvenuto!\n\n"
            "LinQedin ti augura una buona \n"
            "giornata e un buon lavoro.";
    info=new QLabel(istruzioni, this);
    info->setFixedSize(300,150);

    show_Profile=new QPushButton("Mostra profilo", this);
    show_Web=new QPushButton("Mostra rete", this);
    show_Search=new QPushButton("Ricerca", this);

    disconnect=new QPushButton("Disconnetti",this);
    disconnect->setToolTip("Esci dal pannello gestione\ne torna alla pagina di login");
    disconnect->setToolTipDuration(3000);
    exit=new QPushButton("Esci",this);
    exit->setToolTip("Chiudi LinQuedin");
    exit->setToolTipDuration(3000);

    connect(show_Profile,SIGNAL(clicked()),this, SIGNAL(showProfile()));
    connect(show_Web,SIGNAL(clicked()),this, SIGNAL(showWeb()));
    connect(show_Search,SIGNAL(clicked()),this, SIGNAL(showSearch()));
    connect(disconnect,SIGNAL(clicked()),this,SIGNAL(disconnectUser()));
    connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));

    layout=new QVBoxLayout(this);
    layout->addWidget(title);
    layout->setAlignment(title,Qt::AlignCenter);
    layout->setSpacing(10);
    layout->addWidget(image);
    layout->setAlignment(image,Qt::AlignCenter);
    layout->addWidget(account,0,Qt::AlignCenter);
    layout->addSpacing(10);
    layout->addWidget(show_Profile);
    layout->addWidget(show_Web);
    layout->addWidget(show_Search);
    layout->addWidget(info);
    layout->addStretch(1);
    layout->addWidget(disconnect);
    layout->addWidget(exit);
    layout->addStretch(1);

    setLayout(layout);
}

ClientMenu::~ClientMenu(){
    delete title;
    delete image;
    delete pix;
    delete info;
    delete show_Profile;
    delete show_Search;
    delete show_Web;
    delete disconnect;
    delete exit;

    delete layout;
}
