#include<MDATA/database.h>
#include<VIEW/startview.h>
#include<VIEW/c_startview.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataBase data;
    StartView view;
    C_StartView controller(0,0,0,&data,&view);

    return a.exec();
}
