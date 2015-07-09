#include<VIEW/tableremins.h>

TableRemIns::TableRemIns(QWidget *parent, const QString &header_):
    QWidget(parent)
{
    table=new QTableWidget(this);
    insert=new QPushButton("Aggiungi",this);
    insert->setFocusPolicy(Qt::NoFocus);
    remove=new QPushButton("Rimuovi",this);
    remove->setFocusPolicy(Qt::NoFocus);

    tabHeader<<header_;
    table->setHorizontalHeaderLabels(tabHeader);
    table->setColumnCount(1);
    table->setMinimumWidth(251);
    table->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);

    add_Dialog=new NewElement(this,header_);

    connect(add_Dialog,SIGNAL(addElement()),this,SLOT(addElement()));
    connect(insert,SIGNAL(clicked()),this,SLOT(addDialog()));
    connect(remove,SIGNAL(clicked()),this,SLOT(removeElement()));
    connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(enableRemove()));

    setMinimumHeight(180);
    createLayout();
}

std::vector<QString> TableRemIns::getElements() const{
    return elements;
}

void TableRemIns::setElements(std::vector<QString> elements_){
    elements=elements_;
    buildTable();
}

void TableRemIns::createLayout(){
    buttons_layout=new QVBoxLayout();
    buttons_layout->addWidget(insert);
    buttons_layout->addWidget(remove);
    buttons_layout->addStretch(1);

    layout=new QHBoxLayout(this);
    layout->addWidget(table);
    layout->addSpacing(15);
    layout->addLayout(buttons_layout);

    setLayout(layout);
}

void TableRemIns::buildTable(){
    table->setHorizontalHeaderLabels(tabHeader);
    if(!(elements.empty())){
        int row=0;
        for(std::vector<QString>::const_iterator it=elements.begin(); it<elements.end(); ++it){
            table->setRowCount(row+1);
            QTableWidgetItem *elemento = new QTableWidgetItem(*it);
            table->setItem(row,0,elemento);
            row++;
        }
    }
    else{
        table->setRowCount(0);
    }
}

void TableRemIns::addDialog(){
    add_Dialog->show();
}

void TableRemIns::addElement(){
    elements.push_back(add_Dialog->getElement());
    buildTable();
}

void TableRemIns::removeElement(){
    QModelIndexList selectedList = table->selectionModel()->selectedRows();
    int selected_row=selectedList.at(0).row();
    elements.erase(elements.begin()+selected_row);
    buildTable();
    disableRemove();
}

void TableRemIns::visualizeDialog(){
}

void TableRemIns::disableTable(){
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionMode(QAbstractItemView::NoSelection);
    insert->setDisabled(true);
    remove->setDisabled(true);
    disconnect(table,SIGNAL(cellClicked(int,int)),this,SLOT(enableRemove()));
}

void TableRemIns::enableTable(){
    table->setSelectionBehavior(QAbstractItemView::SelectItems);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    insert->setEnabled(true);
    connect(table,SIGNAL(cellClicked(int,int)),this,SLOT(enableRemove()));
}

void TableRemIns::enableRemove(){
        remove->setEnabled(true);
}

void TableRemIns::disableRemove(){
    remove->setEnabled(false);
}


TableRemIns::~TableRemIns(){
    delete table;
    delete insert;
    delete remove;
    delete add_Dialog;

    delete buttons_layout;
    delete layout;
}
