#ifndef PROFILEVIEW_H
#define PROFILEVIEW_H

#include <QWidget>
#include<QPushButton>
#include<QLabel>
#include<QScrollBar>
#include<QScrollArea>
#include<QVBoxLayout>
#include<QTextEdit>
#include<QGridLayout>
#include<QTextEdit>
#include<QCalendarWidget>
#include<QLineEdit>
#include<QDesktopWidget>
#include<QApplication>
#include<QDate>
#include<QComboBox>
#include<QMessageBox>

#include<VIEW/tableremins.h>
#include<UTENTE/utente.h>

class TableRemIns;

class ProfileView : public QWidget
{
    Q_OBJECT
public:
    explicit ProfileView(QWidget *parent = 0, const Utente *model_ =0);
    ~ProfileView();

    QString getName();
    QString getSurname();
    bool getSex();
    QDate getDate();
    QString getResAddress();
    QString getResTown();
    QString getResRegion();
    QString getCountry();
    QString getProfession();
    QString getLanguage();
    QString getNumber();
    QString getMail();
    std::vector<QString> getTitles();
    std::vector<QString> getExperiences();

    void disableModify();
    void enableModify();

private slots:
    void updateDate();


private:
    void centerWidget();
    void createLayout();
    void showProfileUser();

    const Utente* model;

    QLabel* firstname;
    QLineEdit* box_firstname;
    QLabel* lastname;
    QLineEdit* box_lastname;
    QLabel* sex;
    QComboBox* box_sex;
    QLabel* date;
    QLineEdit* box_date;
    QLabel* res_address;
    QLabel* res_town;
    QLabel* res_region;
    QLineEdit* box_res_town;
    QLineEdit* box_res_region;
    QLineEdit* box_res_address;
    QLabel* country;
    QLineEdit* box_country;
    QLabel* profession;
    QLineEdit* box_profession;
    QLabel* language;
    QLineEdit* box_language;
    QLabel* number;
    QLineEdit* box_number;
    QLabel* email;
    QLineEdit* box_email;

    TableRemIns* titles_table;
    TableRemIns* experiences_table;

    QCalendarWidget* box_date_calendar;

    QGridLayout* layout;
};

#endif // PROFILEVIEW_H
