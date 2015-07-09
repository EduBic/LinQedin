#ifndef CLIENTLOGIN_H
#define CLIENTLOGIN_H

#include <QWidget>
#include<QFrame>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QToolTip>
#include<QMessageBox>

class ClientLogin : public QFrame
{
    Q_OBJECT
public:
    explicit ClientLogin(QWidget *parent = 0);

signals:
    void openClient(const QString& user);

public slots:
    void setLogin();
    void getLogin();
    void selectText();

private:
    QLabel* label;
    QLineEdit* textedit;
    QPushButton* button;

    QVBoxLayout* layout;
};

#endif // CLIENTLOGIN_H
