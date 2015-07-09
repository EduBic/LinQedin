 #ifndef ADMINCONTENT_H
#define ADMINCONTENT_H

#include <QWidget>
#include<QTableWidget>
#include<QPushButton>
#include<QTextEdit>
#include<QLabel>
#include<QTabWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QRadioButton>
#include<QLineEdit>
#include <QHeaderView>
#include<QTableWidget>
#include<QMessageBox>
#include<QItemSelectionModel>
#include<QHeaderView>

#include<VIEW/ADMIN/admininsert.h>
#include<VIEW/ADMIN/adminchange.h>
#include<VIEW/showinfoview.h>
#include<MDATA/admin.h>

class AdminContent : public QWidget
{
    Q_OBJECT
public:
    explicit AdminContent(QWidget *parent = 0, const Admin* model_ =0);
    ~AdminContent();

    void buildTableSearch(const std::list<const Utente *> &results);
    void reBuildTable();
    void reBuildTableInsert();
    void reBuildTableRemove();

signals:
    void changeTypeClicked(const QString& type, const QString& user);
    void insertUserClicked(const QString& user, const QString& firstname, const QString& lastname,int);
    void searchUserClicked(const QString& user);
    void removeUserClicked(const QString& user);

private slots:
    void enableButtons();

    void showInfoSelection();

    void searchUser(const QString& user);
    void removeUser();
    void setSelectedUser(int r);

    void changeType(const QString &type);

private:
    void buildTable();
    void refreshTable();
    void disableButtons();
    void updateLabel();

    const Admin* model;

    QLabel* search_label;
    QLineEdit* search_Box;
    QTableWidget* table;
    QString selected_user;
    QLabel* selected_text_label;
    QLabel* selected_user_label;
    QPushButton* remove_user;

    AdminInsert* insert_User;
    AdminChange* change_Type_User;
    QPushButton* show_info;

    QHBoxLayout* layout_Search;
    QVBoxLayout* layout_Buttons;
    QVBoxLayout* layout_Table;

    QHBoxLayout* layout;
};

#endif // ADMINCONTENT_H
