#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QGroupBox>
#include<QLabel>
#include<QPushButton>
#include<QVBoxLayout>
#include<QApplication>
#include<VIEW/clientlogin.h>

class MainView : public QGroupBox
{
    Q_OBJECT
public:
    explicit MainView(QWidget *parent = 0);

signals:
    void openClientView(const QString& user);
    void openAdminView();

private:
    QLabel* title;
    ClientLogin* client;
    QPushButton* admin;
    QPushButton* exit;

    QVBoxLayout* layout;

};

#endif // MAINVIEW_H
