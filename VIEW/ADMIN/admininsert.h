#ifndef ADMININSERT_H
#define ADMININSERT_H

#include <QWidget>
#include<QGroupBox>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGridLayout>
#include<QLineEdit>
#include<QMessageBox>
#include<QComboBox>

class AdminInsert : public QFrame
{
    Q_OBJECT
public:
    explicit AdminInsert(QWidget *parent = 0);
    ~AdminInsert();

signals:
    void insertUserClicked(const QString&,const QString&,const QString&, int); //connect con AdminContent

private slots:
    void insertUser();
    void changeSelectedType(const QString &type);

private:
    void clearTextEdit();

    int selected_type;

    QLabel* title;
    QLabel* user;
    QLineEdit* text_User;
    QLabel* firstname;
    QLineEdit* text_Firstname;
    QLabel* lastname;
    QLineEdit* text_Lastname;
    QLabel* type;
    QComboBox* text_type;

    QPushButton* insert;

    QGridLayout* layout;
};

#endif // ADMININSERT_H
