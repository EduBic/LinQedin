#include<VIEW/showinfoview.h>

ShowInfoView::ShowInfoView(QWidget *parent, const QString &userName, const Utente *user) :
    QWidget(parent)
{
    title=new QLabel("Profilo di <b>"+userName+"</b>",this);
    title->setFont(QFont("Helvetica [Cronyx]", 13, QFont::Normal));

    profile=new ProfileView(this,user);

    scroll=new QScrollArea(this);
        scroll->setWidgetResizable(true);
        scroll->setAlignment(Qt::AlignHCenter);
        scroll->adjustSize();
        scroll->setMinimumWidth(540);
    scroll->setWidget(profile);

    exit=new QPushButton("Chiudi",this);
    exit->setFixedSize(200,30);
    connect(exit,SIGNAL(clicked()),this,SLOT(deleteLater()));

    layout=new QVBoxLayout(this);
    layout->addWidget(title);
    layout->addWidget(scroll);
    layout->addWidget(exit,0,Qt::AlignCenter);

    setLayout(layout);
    centerWidget();
}

void ShowInfoView::centerWidget(){
    int WIDTH = 250;
    int HEIGHT = 250;

    QDesktopWidget *desktop = QApplication::desktop();

    int screenWidth = desktop->width();
    int screenHeight = desktop->height();
    int x=(screenWidth - WIDTH) / 2;
    int y=(screenHeight - HEIGHT) / 2;

    this->resize(WIDTH, HEIGHT);
    this->move( x, y );

    adjustSize();
}

ShowInfoView::~ShowInfoView(){
    delete title;
    delete profile;
    delete scroll;
    delete exit;

    delete layout;
}
