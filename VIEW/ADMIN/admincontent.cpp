#include<VIEW/ADMIN/admincontent.h>

AdminContent::AdminContent(QWidget *parent, const Admin *model_) :
    QWidget(parent), model(model_)
{
    selected_user="";

    search_Box=new QLineEdit(this);
    search_Box->setPlaceholderText("Cerca utenti per username, nome o cognome");
    search_label=new QLabel("Ricerca: ",this);

    table=new QTableWidget(this);
    table->setColumnCount(4);
    table->setRowCount(0);

    QStringList tabHeader;
    tabHeader<<"Username"<<"Account"<<"Nome"<<"Cognome";
    table->setHorizontalHeaderLabels(tabHeader);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    for(int i=0; i<table->columnCount(); i++)
        table->horizontalHeader()->setSectionResizeMode(i,QHeaderView::Stretch);
    table->setMinimumWidth(419);

    insert_User=new AdminInsert(this);

    selected_text_label=new QLabel("Utente selezionato:",this);
    selected_user_label=new QLabel("",this);
    selected_user_label->setStyleSheet("font-weight: bold; border: 1px solid grey");
    selected_user_label->setAlignment(Qt::AlignCenter);
    selected_user_label->setMinimumHeight(30);
    remove_user=new QPushButton("Rimuovi utente",this);
    remove_user->setMaximumWidth(350);
    show_info=new QPushButton("Dettagli utente",this);
    show_info->setMaximumWidth(350);

    change_Type_User=new AdminChange(this);

    connect(search_Box,SIGNAL(textEdited(QString)),this,SLOT(searchUser(QString)));
    connect(remove_user,SIGNAL(clicked()),this,SLOT(removeUser()));
    connect(change_Type_User,SIGNAL(changeTypeClicked(QString)),this,SLOT(changeType(QString)));
    connect(insert_User,SIGNAL(insertUserClicked(QString,QString,QString,int)),this,SIGNAL(insertUserClicked(QString,QString,QString,int)));
    connect(show_info,SIGNAL(clicked()),this,SLOT(showInfoSelection()));

    //table connect
    connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(setSelectedUser(int)));
    connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(enableButtons()));
    connect(table,SIGNAL(cellClicked(int,int)),change_Type_User,SLOT(enableButton()));
    connect(table,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(showInfoSelection()));


    layout_Search=new QHBoxLayout();
    layout_Search->addWidget(search_label);
    layout_Search->addWidget(search_Box);

    layout_Table=new QVBoxLayout();
    layout_Table->addLayout(layout_Search);
    layout_Table->addWidget(table);

    layout_Buttons=new QVBoxLayout();
    layout_Buttons->addSpacing(5);
    layout_Buttons->addWidget(selected_text_label);
    layout_Buttons->addSpacing(5);
    layout_Buttons->addWidget(selected_user_label);
    layout_Buttons->addSpacing(5);
    layout_Buttons->addWidget(show_info);
    layout_Buttons->addWidget(remove_user);
    layout_Buttons->addSpacing(15);
    layout_Buttons->addWidget(change_Type_User);
    layout_Buttons->addStretch(1);
    layout_Buttons->addWidget(insert_User);
    layout_Buttons->addStretch(1);

    layout=new QHBoxLayout(this);
    layout->addLayout(layout_Table);
    layout->addSpacing(10);
    layout->addLayout(layout_Buttons);

    buildTable();
    disableButtons();

    setLayout(layout);
}

void AdminContent::disableButtons(){
    remove_user->setDisabled(true);
    show_info->setDisabled(true);
}

void AdminContent::enableButtons(){
    remove_user->setEnabled(true);
    show_info->setEnabled(true);
}

void AdminContent::showInfoSelection(){
    ShowInfoView* profile=new ShowInfoView(0,selected_user,model->getUtente(selected_user));
    profile->setWindowTitle("Profilo di: "+selected_user);
    profile->show();
}

void AdminContent::searchUser(const QString& user){
    emit searchUserClicked(user);
}

void AdminContent::removeUser(){
    QMessageBox warning;
    warning.setIcon(QMessageBox::Question);
    warning.setWindowTitle("Rimuovi utente");
    warning.setText("Hai selezionato l'utente: <b>"+selected_user+"</b>");
    warning.setInformativeText("Vuoi veramente eliminare questo utente?");
    warning.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    warning.setDefaultButton(QMessageBox::Cancel);
    int ret = warning.exec();
    if(ret==QMessageBox::Yes) {
        emit removeUserClicked(selected_user);
    }
}

void AdminContent::setSelectedUser(int r){
    selected_user=table->item(r,0)->text();
    enableButtons();
    updateLabel();
}

void AdminContent::updateLabel(){
    selected_user_label->setText(selected_user);
}

void AdminContent::refreshTable(){
    selected_user="";
    updateLabel();
    table->clearContents();
    table->setRowCount(0);
}

void AdminContent::buildTable(){
    refreshTable();
    if(!(model->dbEmpty())){
        int row=0;
        for(DataBase::db_const_iterator it=model->begin(); it!=model->end(); ++it){
            table->setRowCount(row+1);
            std::cout<<"username da inserire in table: "<<it->first.toStdString()<<std::endl;
            QTableWidgetItem *username = new QTableWidgetItem(it->second->getUsername());
            QTableWidgetItem *account = new QTableWidgetItem(it->second->toString());
            QTableWidgetItem *nome = new QTableWidgetItem(it->second->getNome());
            QTableWidgetItem *cognome = new QTableWidgetItem(it->second->getCognome());
            table->setItem(row,0,username);
            table->setItem(row,1,account);
            table->setItem(row,2,nome);
            table->setItem(row,3,cognome);
            row++;
        }
    }
    else{
        std::cout<<"tabella vuota"<<std::endl;
    }
}

void AdminContent::reBuildTable(){
    QModelIndexList selectedList = table->selectionModel()->selectedRows();
    int selected_row=selectedList.at(0).row();
    searchUser(search_Box->text());
    table->selectRow(selected_row);
    emit table->cellClicked(selected_row,0);
}

void AdminContent::buildTableSearch(const std::list<const Utente*> &results){
    refreshTable();
    if(!(results.empty())){
        int row=0;
        for(std::list<const Utente*>::const_iterator it=results.begin(); it!=results.end(); ++it){
            table->setRowCount(row+1);
            QTableWidgetItem *username = new QTableWidgetItem((*it)->getLogin()->getUsername());
            QTableWidgetItem *account = new QTableWidgetItem((*it)->toString());
            QTableWidgetItem *nome = new QTableWidgetItem((*it)->getProfilo()->getInfo1().getNome());
            QTableWidgetItem *cognome = new QTableWidgetItem((*it)->getProfilo()->getInfo1().getCognome());
            table->setItem(row,0,username);
            table->setItem(row,1,account);
            table->setItem(row,2,nome);
            table->setItem(row,3,cognome);
            row++;
        }
    }
}

void AdminContent::reBuildTableInsert(){
    search_Box->clear();
    buildTable();
    table->clearSelection();
}

void AdminContent::reBuildTableRemove(){
    searchUser(search_Box->text());
    if(!(model->dbEmpty()) && (table->rowCount())){
        emit table->cellClicked(0,0);
        }
}

//FIGLI
void AdminContent::changeType(const QString& type){
    emit changeTypeClicked(type,selected_user);
}

AdminContent::~AdminContent(){
    delete search_label;
    delete search_Box;
    delete table;
    delete selected_text_label;
    delete selected_user_label;
    delete remove_user;

    delete insert_User;
    delete change_Type_User;
    delete show_info;

    delete layout_Search;
    delete layout_Buttons;
    delete layout_Table;

    delete layout;
}



