#ifndef CLIENTWEB_H
#define CLIENTWEB_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
#include<QTableWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QMessageBox>
#include<QHeaderView>
#include<QString>

#include "../showinfoview.h"
#include "MDATA/client.h"

class ClientWeb : public QWidget
{
    Q_OBJECT
public:
    explicit ClientWeb(QWidget *parent = 0, const Client* model_ =0);
    ~ClientWeb();

    void reBuildTable();

signals:
    void removeContactClicked(const QString& contact);
    void removeContact(const QString& contact);

private slots:
    void buildTable();
    void showInfoSelection();
    void removeContactWarning();

    void disableButtons();
    void enableButtons();
    void setSelectedUser(int r);

private:
    const Client* model;

    QLabel* title;
    QString selected_user;

    QTableWidget* table_Contact;

    QPushButton* remove_Contact;
    QPushButton* show_Contact;

    QHBoxLayout* layout_Button;
    QVBoxLayout* layout;


};

#endif // CLIENTWEB_H
