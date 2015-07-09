#include<VIEW/startview.h>

StartView::StartView(QGroupBox *parent)
    : QMainWindow(parent), main_view(0), client_view(0), admin_view(0), client_model(0), admin_model(0)
{   
    createMain(); //schermata iniziale

    setWindowIcon(QIcon("../LinQedin/icon.png"));
    setWhatsThis("LinQedin");
    setWindowTitle("LinQedin");
    showMaximized();
}

void StartView::createAdmin(){
    emit createAdminModel(); //crea e setta il model
    admin_view=new AdminView(this,admin_model); //creo view
    connect(admin_view,SIGNAL(disconnectAdminView()),this,SLOT(backInTime()));
    emit createC_AdminView(); //creo controller
    setCentralWidget(admin_view); //setto la nuova vista
}

void StartView::createClient(const QString &user){
    emit createClientModel(user); //setta il model
    if(client_model){ //se il model è stato creato il login ha avuto successo
        client_view=new ClientView(this,user,client_model); //creo view client
        connect(client_view,SIGNAL(disconnectUserView()),this,SLOT(backInTime()));

        emit createC_ClientView(); //creo controller client
        setCentralWidget(client_view);
    }
}

void StartView::createMain(){
    main_view=new MainView(this);
    connect(main_view,SIGNAL(openAdminView()),this,SLOT(createAdmin()));
    connect(main_view,SIGNAL(openClientView(QString)),this,SLOT(createClient(QString)));
    setCentralWidget(main_view);
}

void StartView::backInTime(){
    createMain();
    emit deleteControllers(); //distrugge i controller delle view
    delete admin_view;
    delete client_view;
    client_view=0;
    admin_view=0;

    emit deleteModel(); //distrugge i model
}

void StartView::setClientModel(const Client * client_){
    client_model=client_;
}

void StartView::setAdminModel(const Admin * admin_){
    admin_model=admin_;
}

void StartView::noMatchUser(){
    QMessageBox warning;
    warning.setIcon(QMessageBox::Information);
    warning.setText("UserName non valido");
    warning.exec();
}

ClientView* StartView::getClientView(){
    return client_view;
}

AdminView* StartView::getAdminView(){
    return admin_view;
}

void StartView::centerWidget(){
    int width = frameGeometry().width();
    int height = frameGeometry().height();

    QDesktopWidget wid;

    int screenWidth = wid.screen()->width();
    int screenHeight = wid.screen()->height();

    setGeometry((screenWidth/2)-(width/2),(screenHeight/2)-(height/2),width,height);
}

