#include<VIEW/CLIENT/clientsearch.h>

ClientSearch::ClientSearch(QWidget *parent, const Client* model_) :
    QWidget(parent), model(model_), selected_user(""), selected_search("Tutto")
{
    title=new QLabel("Ricerca",this);
    title->setFont(QFont("Helvetica [Cronyx]", 16, QFont::Bold));
    title->setStyleSheet("font-variant: small-caps; border-bottom:1px solid black;");

    table=new QTableWidget(0,3,this);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    for(int i=0; i<table->columnCount(); i++)
        table->horizontalHeader()->setSectionResizeMode(i,QHeaderView::Stretch);
    table->setMinimumWidth(319);
    table->setMaximumHeight(250);
    QStringList tabHeader;
    tabHeader<<"Username"<<"Nome"<<"Cognome";
    table->setHorizontalHeaderLabels(tabHeader);

    title_Search=new QLabel("Cerca per: ");
    type_Search=new QComboBox(this);
    type_Search->setMinimumWidth(180);
    QStringList typeSearch;
    typeSearch<<"Tutto"<<"Username"<<"Nome"<<"Cognome";
    type_Search->addItems(typeSearch);
    text_Search=new QLineEdit(this);
    text_Search->setPlaceholderText("Cerca utenti ");
    text_Search->setStyleSheet("color: #808080;");

    button_Search=new QPushButton("Cerca!",this);
    button_Search->setMinimumWidth(150);
    add=new QPushButton("Aggiungi",this);
    detail=new QPushButton("Mostra dettagli",this);
    disableButtons();

    info=new QLabel(this);
    QString info_txt("Scrivi cosa stai cercando e premi INVIO.<br/>");
    info_txt.append("Nella tabella verranno mostrati i risultati che corrispondono alle parole cercate.<br/><br/>");
    info_txt.append(model->getClientUtente()->info());
    info->setText(info_txt);
    info->setMaximumWidth(600);

    connect(detail,SIGNAL(clicked()),this,SLOT(showInfoSelection()));
    connect(button_Search,SIGNAL(clicked()),this,SLOT(search()));
    connect(add,SIGNAL(clicked()),this,SLOT(addContact()));
    connect(text_Search,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(selectText()));
    connect(text_Search,SIGNAL(returnPressed()),this,SLOT(search()));
    connect(type_Search,SIGNAL(activated(QString)),this,SLOT(setSelectedSearch(QString)));
    //connect table
    connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(setSelectedUser(int)));
    connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(enableButtons()));
    connect(table,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(showInfoSelection()));

    layout_search=new QHBoxLayout();
    layout_search->addWidget(button_Search);
    layout_search->addWidget(text_Search);
    layout_search->addWidget(type_Search);

    layout_buttons=new QHBoxLayout();
    layout_buttons->addWidget(add);
    layout_buttons->addWidget(detail);

    layout=new QVBoxLayout(this);
    layout->addWidget(title);
    layout->addSpacing(10);
    layout->addLayout(layout_search);
    layout->addWidget(table);
    layout->addLayout(layout_buttons);
    layout->addSpacing(10);
    layout->addWidget(info);
    layout->addStretch(1);

    setLayout(layout);
}

void ClientSearch::showInfoSelection(){
    ShowInfoView* profile=new ShowInfoView(0,selected_user,model->getUtente(selected_user));
    profile->setWindowTitle("Profilo di: "+selected_user);
    profile->show();
}

void ClientSearch::refreshTable(){
    selected_user="";
    //updateLabel();
    table->clearContents();
    table->setRowCount(0);
}

void ClientSearch::buildTableSearch(const std::list<const Utente*> &results){
        refreshTable();
        if(!(results.empty())){
            int row=0;
            for(std::list<const Utente*>::const_iterator it=results.begin(); it!=results.end(); ++it){
                table->setRowCount(row+1);
                QTableWidgetItem *username = new QTableWidgetItem((*it)->getUsername());
                QTableWidgetItem *nome = new QTableWidgetItem((*it)->getNome());
                QTableWidgetItem *cognome = new QTableWidgetItem((*it)->getCognome());
                table->setItem(row,0,username);
                table->setItem(row,1,nome);
                table->setItem(row,2,cognome);
                row++;
            }
        }
}

void ClientSearch::setSelectedUser(int r){
    selected_user=table->item(r,0)->text();
    enableButtons();
}

void ClientSearch::setSelectedSearch(const QString& type){
    selected_search=type;
}

void ClientSearch::disableButtons(){
    add->setDisabled(true);
    detail->setDisabled(true);
}

void ClientSearch::enableButtons(){
    add->setEnabled(true);
    detail->setEnabled(true);
}

void ClientSearch::search(){
    text_Search->selectAll();
    emit searchClicked(text_Search->text(),selected_search);
}

void ClientSearch::selectText(){
    text_Search->selectAll();
    text_Search->setStyleSheet("color: #404040;");
    type_Search->setEnabled(true);
    button_Search->setEnabled(true);
    disconnect(text_Search,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(selectText()));
}

void ClientSearch::addContact(){
    emit addContactClicked(selected_user);
}

ClientSearch::~ClientSearch(){
    delete title;

    delete type_Search;
    delete button_Search;
    delete text_Search;

    delete table;

    delete add;
    delete detail;

    delete layout_search;
    delete layout_buttons;
    delete layout;
}

