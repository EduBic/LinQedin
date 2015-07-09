#ifndef ADMINVIEW_H
#define ADMINVIEW_H

#include <QWidget>
#include<QPushButton>
#include<QLabel>
#include<QHBoxLayout>
#include<QApplication>
#include<QDesktopWidget>
#include<QIcon>

#include<VIEW/ADMIN/admincontent.h>
#include<VIEW/ADMIN/adminmenu.h>
#include<MDATA/admin.h>

class AdminView : public QWidget
{
    Q_OBJECT
public:
    explicit AdminView(QWidget *parent = 0, const Admin* model_ =0);
    ~AdminView();

    AdminContent* getAdminContent(); //per C_AdminContent

   void centerWidget();

signals:
    void disconnectAdminView();

private:
    const Admin* model;

    AdminMenu* menu;
    AdminContent* content;
    QHBoxLayout* layout;

};

#endif // ADMINVIEW_H
