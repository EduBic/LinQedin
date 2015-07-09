#ifndef C_CLIENTPROFILE_H
#define C_CLIENTPROFILE_H

#include<QObject>
#include<QString>

#include "../../MDATA/client.h"
#include "clientprofile.h"

class C_ClientProfile : public QObject
{
    Q_OBJECT
public:
    explicit C_ClientProfile(QObject *parent = 0, Client *model_ =0, ClientProfile* view_ =0);

signals:

private slots:
    void applyModify();

private:
    Client* model;
    ClientProfile* view;

};

#endif // C_CLIENTPROFILE_H
