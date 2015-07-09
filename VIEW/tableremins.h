#ifndef TABLEREMINS_H
#define TABLEREMINS_H

#include <QWidget>
#include<QTableWidget>
#include<QPushButton>
#include<QLabel>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QDialog>
#include<QString>
#include<QHeaderView>
#include<vector>
#include<QStringList>
#include<QModelIndexList>
#include<QGroupBox>
#include<QLineEdit>

#include<VIEW/showinfoview.h>
#include<VIEW/newelement.h>

class TableRemIns : public QWidget
{
    Q_OBJECT
public:
    explicit TableRemIns(QWidget *parent = 0, const QString& header_ ="Sconosciuto");
    ~TableRemIns();

    std::vector<QString> getElements() const;
    void setElements(std::vector<QString> elements_); //copia per valore

    void disableTable();
    void enableTable();

signals:

private slots:
    void addDialog();
    void visualizeDialog();

    void addElement();
    void removeElement();
    void enableRemove();

private:
    void disableRemove();
    void createLayout();
    void buildTable();

    std::vector<QString> elements;
    QStringList tabHeader;

    QTableWidget* table;
    QPushButton* insert;
    QPushButton* remove;

    NewElement* add_Dialog;

    QVBoxLayout* buttons_layout;
    QHBoxLayout* layout;

};

#endif // TABLEREMINS_H
