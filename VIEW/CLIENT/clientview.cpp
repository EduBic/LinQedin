#include<VIEW/CLIENT/clientview.h>

ClientView::ClientView(QWidget *parent, const QString& user, const Client *model_) :
    QWidget(parent), model(model_), user_login(user)
{

    menu=new ClientMenu(this,user,model->getTypeUser());
    profile=new ClientProfile(this, model);
    web=new ClientWeb(this, model);
    search=new ClientSearch(this, model);

    connect(menu,SIGNAL(showProfile()), this, SLOT(showProfile()));
    connect(menu,SIGNAL(showWeb()), this, SLOT(showWeb()));
    connect(menu,SIGNAL(showSearch()), this, SLOT(showSearch()));
    connect(menu,SIGNAL(disconnectUser()),this,SIGNAL(disconnectUserView()));
    connect(search,SIGNAL(updateWeb()),web,SLOT(buildTable()));

    layout=new QHBoxLayout(this);
    layout->addWidget(menu);
    layout->addWidget(profile);
    layout->addWidget(web);
    layout->addWidget(search);

    web->hide();
    search->hide();

    setWindowIcon(QIcon("icon.png"));
    setWindowTitle("LinQedin Client - Profilo");
    setWhatsThis("LinQedin Client");
    setLayout(layout);

    //centerWidget();
}


void ClientView::showProfile(){
    web->hide();
    search->hide();
    profile->show();

    setWindowTitle("LinQedin Client - Profilo");
}

void ClientView::showWeb(){
    profile->hide();
    search->hide();
    web->show();

    setWindowTitle("LinQedin Client - Rete");
}

void ClientView::showSearch(){
    profile->hide();
    web->hide();
    search->show();

    setWindowTitle("LinQedin Client - Ricerca");
}

ClientProfile *ClientView::getClientProfile() const{
    return profile;
}

ClientWeb* ClientView::getClientWeb() const{
    return web;
}

ClientSearch* ClientView::getClientSearch() const{
    return search;
}

void ClientView::centerWidget(){
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

ClientView::~ClientView(){
    delete menu;
    delete profile;
    delete web;
    delete search;
}


