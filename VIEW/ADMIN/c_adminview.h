#ifndef C_ADMINVIEW_H
#define C_ADMINVIEW_H

#include <QObject>
#include"adminview.h"

#include<VIEW/ADMIN/c_admincontent.h>
#include<MDATA/admin.h>

class C_AdminView : public QObject
{
    Q_OBJECT
public:
    explicit C_AdminView(QObject *parent = 0, Admin* model_ =0, AdminView* view_ =0);
    ~C_AdminView();

signals:

public slots:

private:
    Admin* model;
    AdminView* view;

    C_AdminContent* c_admincontent;

};

#endif // C_ADMINVIEW_H
