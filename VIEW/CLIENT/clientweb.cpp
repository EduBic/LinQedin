#include<VIEW/CLIENT/clientweb.h>

ClientWeb::ClientWeb(QWidget *parent, const Client* model_) :
    QWidget(parent), model(model_)
{

    title=new QLabel("La tua rete contatti",this);
    title->setFont(QFont("Helvetica [Cronyx]", 16, QFont::Bold));
    title->setStyleSheet("font-variant: small-caps;");

    selected_user="";

    table_Contact=new QTableWidget(0,3,this);
    table_Contact->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table_Contact->setSelectionMode(QAbstractItemView::SingleSelection);
    table_Contact->setSelectionBehavior(QAbstractItemView::SelectRows);
    for(int i=0; i<table_Contact->columnCount(); i++)
        table_Contact->horizontalHeader()->setSectionResizeMode(i,QHeaderView::Stretch);
    table_Contact->setMinimumWidth(319);
    QStringList tabHeader;
    tabHeader<<"Username"<<"Nome"<<"Cognome";
    table_Contact->setHorizontalHeaderLabels(tabHeader);

    remove_Contact=new QPushButton("Rimuovi",this);
    show_Contact=new QPushButton("Informazioni contatto",this);
    disableButtons();

    //connect
    connect(show_Contact,SIGNAL(clicked()),this,SLOT(showInfoSelection()));
    connect(remove_Contact,SIGNAL(clicked()),this,SLOT(removeContactWarning()));
    //connect table
    connect(table_Contact,SIGNAL(cellClicked(int,int)),this,SLOT(setSelectedUser(int)));
    connect(table_Contact,SIGNAL(cellClicked(int,int)),this,SLOT(enableButtons()));
    connect(table_Contact,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(showInfoSelection()));

    layout_Button=new QHBoxLayout();
    layout_Button->addWidget(remove_Contact);
    layout_Button->addWidget(show_Contact);

    layout=new QVBoxLayout(this);
    layout->addWidget(title);
    layout->addSpacing(10);
    layout->addWidget(table_Contact);
    layout->addLayout(layout_Button);
    layout->addStretch(1);

    setLayout(layout);

    buildTable();
}

void ClientWeb::buildTable(){
    if(!(model->webEmpty())){
        int row=0;
        for(Rete::web_const_iterator it=model->beginWeb(); it!=model->endWeb(); ++it){
            if(model->existUser(*it)){
                table_Contact->setRowCount(row+1);
                QTableWidgetItem *username = new QTableWidgetItem(*it);
                QTableWidgetItem *nome = new QTableWidgetItem(model->getUtente(*it)->getNome());
                QTableWidgetItem *cognome = new QTableWidgetItem(model->getUtente(*it)->getCognome());
                table_Contact->setItem(row,0,username);
                table_Contact->setItem(row,1,nome);
                table_Contact->setItem(row,2,cognome);
                row++;
            }
            else{
                table_Contact->setRowCount(row);
                std::cout<<"Dovrei eliminare il contatto: "<<(*it).toStdString()<<std::endl;//
            }
        }
    }
    else{
        selected_user="";
        table_Contact->setRowCount(0);
        std::cout<<"La rete contatti è vuota"<<std::endl;//
    }
}

void ClientWeb::reBuildTable(){
    table_Contact->clearSelection();
    if(!(model->webEmpty())){
        int row=0;
        for(Rete::web_const_iterator it=model->beginWeb(); it!=model->endWeb(); ++it){
            if(model->existUser(*it)){
                table_Contact->setRowCount(row+1);
                QString username_=*it;
                std::cout<<"Popolo rete con: "<<username_.toStdString()<<std::endl;

                QTableWidgetItem *username = new QTableWidgetItem(*it);
                QTableWidgetItem *nome = new QTableWidgetItem(model->getUtente(*it)->getProfilo()->getInfo1().getNome());
                QTableWidgetItem *cognome = new QTableWidgetItem(model->getUtente(*it)->getProfilo()->getInfo1().getCognome());
                table_Contact->setItem(row,0,username);
                table_Contact->setItem(row,1,nome);
                table_Contact->setItem(row,2,cognome);
                row++;
            }
            else{ //elimina automaticamente eventuali contati non esistenti
                    emit removeContact(*it); //WARNING!!!
                    it--;
                    table_Contact->setRowCount(row);
            }
        }
        std::cout<<"Righe table contatti: "<<row<<std::endl;//
    }
    else{
        selected_user="";
        table_Contact->setRowCount(0);
        std::cout<<"La rete contatti è vuota"<<std::endl;//
    }
}

void ClientWeb::showInfoSelection(){
    ShowInfoView* profile=new ShowInfoView(0,selected_user,model->getUtente(selected_user));
    profile->setWindowTitle("Profilo di: "+selected_user);
    profile->show();
}

void ClientWeb::removeContactWarning(){
    QMessageBox warning;
    warning.setIcon(QMessageBox::Question);
    warning.setWindowTitle("Rimuovi contatto");
    warning.setText("Vuoi veramente rimuovere dalla tua rete <b>"+selected_user+"</b>?");
    warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    warning.setDefaultButton(QMessageBox::Cancel);
    int ret = warning.exec();
    if(ret==QMessageBox::Yes) {
        emit removeContactClicked(selected_user);
    }
}

void ClientWeb::setSelectedUser(int r){
    selected_user=table_Contact->item(r,0)->text();
    //selected_user_label->setText("Informazioni di: <b>"+selected_user+"</b>");
    enableButtons();
}

void ClientWeb::disableButtons(){
    remove_Contact->setDisabled(true);
    show_Contact->setDisabled(true);
}

void ClientWeb::enableButtons(){
    remove_Contact->setEnabled(true);
    show_Contact->setEnabled(true);
}

ClientWeb::~ClientWeb(){
    delete title;
    delete table_Contact;
    delete remove_Contact;
    delete show_Contact;

    delete layout_Button;
    delete layout;
}
