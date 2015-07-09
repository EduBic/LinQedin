#ifndef C_ADMINCONTENT_H
#define C_ADMINCONTENT_H

#include <QObject>

#include<iostream>

#include<MDATA/admin.h>
#include<VIEW/ADMIN/admincontent.h>

class C_AdminContent : public QObject
{
    Q_OBJECT
public:
    explicit C_AdminContent(QObject *parent = 0, Admin* model =0, AdminContent* view_=0);
    //~C_AdminContent();  non ha figli creati

signals:

public slots:
    void changeTypeUser(const QString& type, const QString& user);
    void insertUser(const QString& user, const QString& firstname, const QString& lastname, int type);
    void searchUser(const QString& text);
    void removeUser(const QString& user);

private:
    Admin* model;
    AdminContent* view;
};

#endif // C_ADMINCONTENT_H
