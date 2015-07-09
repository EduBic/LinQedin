#ifndef NEWELEMENT_H
#define NEWELEMENT_H

#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QLineEdit>
#include<QMessageBox>

class NewElement : public QDialog
{
    Q_OBJECT
public:
    explicit NewElement(QWidget *parent = 0, const QString& title_ ="no titles");
    ~NewElement();

    QString getElement();

signals:
    void addElement();

public slots:
    void addElementVerify();

private:
    QLabel* title;
    QLineEdit* newElem;
    QPushButton* accept;
    QPushButton* cancel;

    QHBoxLayout* layoutButton;
    QVBoxLayout* layout;

};

#endif // NEWELEMENT_H
