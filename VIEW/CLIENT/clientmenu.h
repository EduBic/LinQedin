#ifndef CLIENTMENU_H
#define CLIENTMENU_H

#include <QWidget>
#include<QFrame>
#include<QPushButton>
#include<QLabel>
#include<QVBoxLayout>
#include<QString>
#include<QPixmap>
#include<QApplication>
#include<QGraphicsDropShadowEffect>

#include<iostream>

class ClientMenu : public QFrame
{
    Q_OBJECT
public:
    explicit ClientMenu(QWidget *parent = 0, const QString &user ="Client Interface", const QString &type ="Basic");
    ~ClientMenu();

signals:
    void showProfile();
    void showWeb();
    void showSearch();

    void disconnectUser();

public slots:


private:
    QLabel* title;
    QLabel* image;
    QLabel* account;
    QPixmap* pix;
    QGraphicsDropShadowEffect* effect;
    QLabel* username;
    QPushButton* show_Profile;
    QPushButton* show_Web;
    QPushButton* show_Search;
    QLabel* info;
    QPushButton* disconnect;
    QPushButton* exit;

    QVBoxLayout* layout;

};

#endif // CLIENTMENU_H
