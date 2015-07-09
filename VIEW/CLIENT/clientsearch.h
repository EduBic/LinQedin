#ifndef CLIENTSEARCH_H
#define CLIENTSEARCH_H

#include <QWidget>
#include<QLabel>
#include<QTextEdit>
#include<QLineEdit>
#include<QTableWidget>
#include<QPushButton>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QStringList>
#include<QHeaderView>
#include<QComboBox>

#include<iostream>

#include "../showinfoview.h"
#include "MDATA/client.h"

class ClientSearch : public QWidget
{
    Q_OBJECT
public:
    explicit ClientSearch(QWidget *parent = 0, const Client *model_ =0);
    ~ClientSearch();

    void buildTableSearch(const std::list<const Utente*> &results);

signals:
    void addContactClicked(const QString& user);
    void searchClicked(const QString&,const QString&);
    void updateWeb();

private slots:
    void showInfoSelection();
    void search();
    void addContact();
    void selectText();
    void disableButtons();
    void enableButtons();
    void setSelectedUser(int r);
    void setSelectedSearch(const QString& type);

private:
    void refreshTable();

    const Client* model;

    QLabel* title;
    QString selected_user;
    QString selected_search;

    QLabel* title_Search;
    QLineEdit* text_Search;
    QComboBox* type_Search;
    QPushButton* button_Search;

    QTableWidget* table;

    QPushButton* add;
    QPushButton* detail;

    QLabel* info;

    QHBoxLayout* layout_search;
    QHBoxLayout* layout_buttons;

    QVBoxLayout* layout;

};

#endif // CLIENTSEARCH_H
