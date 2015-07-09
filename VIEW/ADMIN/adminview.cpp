#include<VIEW/ADMIN/adminview.h>

AdminView::AdminView(QWidget *parent, const Admin *model_) :
    QWidget(parent), model(model_)
{
    menu=new AdminMenu(this);
    content=new AdminContent(this, model);

    connect(menu,SIGNAL(disconnectAdmin()),this,SIGNAL(disconnectAdminView()));

    layout=new QHBoxLayout(this);

    layout->addWidget(menu);
    layout->addWidget(content);

    setWindowIcon(QIcon("icon.png"));
    setWindowTitle("LinQedin Admin");
    setWhatsThis("LinQedin Admin");
    setLayout(layout);

    //centerWidget();
}


AdminContent* AdminView::getAdminContent(){
    return content;
}

void AdminView::centerWidget(){
    int WIDTH = 500;
    int HEIGHT = 500;

    QDesktopWidget *desktop = QApplication::desktop();

    int screenWidth = desktop->width();
    int screenHeight = desktop->height();
    int x=(screenWidth - WIDTH) / 2;
    int y=(screenHeight - HEIGHT) / 2;

    resize(WIDTH, HEIGHT);
    move( x, y );

    adjustSize();
}

AdminView::~AdminView(){
    delete menu;
    delete content;

    delete layout;
}
