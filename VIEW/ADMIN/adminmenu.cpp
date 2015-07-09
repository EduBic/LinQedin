#include<VIEW/ADMIN/adminmenu.h>

AdminMenu::AdminMenu(QWidget *parent) :
    QFrame(parent)
{
    setFrameStyle(QFrame::Panel | QFrame::Raised);
    setFixedWidth(300);

    title=new QLabel("Admin Interface", this);
    title->setFont(QFont("Helvetica [Cronyx]", 28, QFont::Bold));
    title->setStyleSheet("font-variant: small-caps");

    QString istruzioni=
            "Guida all'uso:\n\n"
            "Selezionare un utente dalla tabella e sce-\n"
            "gliere l'operazione desiderata attraverso\n"
            "i comandi disponibili:\n\n"
            "-Promuovi utente: cambia la tipologia di \n"
            "utente così da permettergli di utilizzare \n"
            "più funzionalità del programma.\n\n"
            "-Rimuovi utente: elimina definitivamente\n"
            "l'utente selezionato dal database.\n\n"
            "-Aggiungi utente: aggiunge un nuovo \nutente "
            "con le informazioni essenziali.\n\n";
    info=new QLabel(istruzioni, this);

    disconnect=new QPushButton("Disconnetti",this);
    disconnect->setToolTip("Esci dal pannello gestione database\ne torna alla pagina di login");
    disconnect->setToolTipDuration(3000);
    connect(disconnect,SIGNAL(clicked()),this,SIGNAL(disconnectAdmin()));

    exit=new QPushButton("Esci",this);
    exit->setToolTip("Chiudi LinQuedin");
    exit->setToolTipDuration(3000);
    connect(exit,SIGNAL(clicked()),qApp,SLOT(quit()));


    layout=new QVBoxLayout(this);
    layout->addSpacing(10);
    layout->addWidget(title);
    layout->addWidget(info);
    layout->addStretch(1);
    layout->addWidget(disconnect);
    layout->addWidget(exit);
    layout->addStretch(1);

    setLayout(layout);
}

AdminMenu::~AdminMenu(){
    delete title;
    delete info;
    delete disconnect;
    delete exit;

    delete layout;
}
