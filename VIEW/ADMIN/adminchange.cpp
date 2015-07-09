#include<VIEW/ADMIN/adminchange.h>

AdminChange::AdminChange(QWidget *parent) :
    QGroupBox(parent)
{
    change=new QPushButton("Cambia Tipologia",this);
    change->setToolTip("Cambia il tipo \ndell'utente selezionato");
    change->setToolTipDuration(3000);
    change->setDisabled(true);
    basic=new QRadioButton("Basic",this);
    basic->setDisabled(true);
    business=new QRadioButton("Business",this);
    business->setDisabled(true);
    executive=new QRadioButton("Executive",this);
    executive->setDisabled(true);

    connect(change,SIGNAL(clicked()),this,SLOT(changeType()));

    layout=new QGridLayout(this);
    layout->addWidget(change,0,0,1,6);
    layout->addWidget(basic,1,0,1,2);
    layout->addWidget(business,1,2,1,2);
    layout->addWidget(executive,1,4,1,2);

    setLayout(layout);
    setMaximumWidth(350);
}

void AdminChange::changeType(){
    if(basic->isChecked()){
       emit changeTypeClicked("basic");
    }
    else if(business->isChecked()){
       emit changeTypeClicked("business");
    }
    else //if(executive->isChecked()){
       emit changeTypeClicked("executive");
    //}
}

void AdminChange::enableButton(){
    change->setEnabled(true);
    basic->setEnabled(true);
    business->setEnabled(true);
    executive->setEnabled(true);
    basic->setChecked(true);
}

AdminChange::~AdminChange(){
    delete change;
    delete basic;
    delete business;
    delete executive;

    delete layout;
}
