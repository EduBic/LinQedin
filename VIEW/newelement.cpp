#include<VIEW/newelement.h>

NewElement::NewElement(QWidget *parent, const QString &title_) :
    QDialog(parent)
{
    title=new QLabel("Inserisci nuovi/e "+title_);
    newElem=new QLineEdit(this);
    newElem->setMinimumWidth(240);
    accept=new QPushButton("Aggiungi",this);
    cancel=new QPushButton("Annulla",this);

    connect(cancel,SIGNAL(clicked()),this,SLOT(close()));
    connect(accept,SIGNAL(clicked()),this,SLOT(addElementVerify()));

    layoutButton=new QHBoxLayout();
    layoutButton->addWidget(cancel);
    layoutButton->addSpacing(10);
    layoutButton->addWidget(accept);

    layout=new QVBoxLayout(this);
    layout->addWidget(title);
    layout->addWidget(newElem);
    layout->addLayout(layoutButton);

    setLayout(layout);
    setWindowTitle("Aggiungi elemento");
}

QString NewElement::getElement(){return newElem->text();}

void NewElement::addElementVerify(){
    if(newElem->text().isEmpty() || newElem->text().isNull()){
        QMessageBox warning;
        warning.setIcon(QMessageBox::Warning);
        warning.setWindowTitle("Aggiungi elemento");
        warning.setText("Impossibile inserire elementi vuoti.");
        warning.setInformativeText("Riempi l'area di testo o premi il pulsante annulla");
        warning.setStandardButtons(QMessageBox::Ok);
        warning.setDefaultButton(QMessageBox::Ok);
        warning.exec();
    }
    else{
        emit addElement();
        newElem->clear();
        close();
    }
}

NewElement::~NewElement(){
    delete title;
    delete cancel;
    delete newElem;
    delete accept;
    delete layoutButton;
    delete layout;
}
