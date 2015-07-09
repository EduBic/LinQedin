#ifndef ADMINMENU_H
#define ADMINMENU_H

#include <QFrame>
#include<QLabel>
#include<QPushButton>
#include<QVBoxLayout>
#include<QApplication>

#include<MDATA/admin.h>

class AdminMenu : public QFrame
{
    Q_OBJECT
public:
    explicit AdminMenu(QWidget *parent = 0);
    ~AdminMenu();

signals:
    void disconnectAdmin();

private:
    QLabel* title;
    QLabel* info;
    QPushButton* disconnect;
    QPushButton* exit;

    QVBoxLayout* layout;
};

#endif // ADMINMENU_H
