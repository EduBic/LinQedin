#ifndef CLIENTPROFILE_H
#define CLIENTPROFILE_H

#include<QWidget>
#include<QScrollArea>
#include<QVBoxLayout>
#include<QPushButton>
#include<QHBoxLayout>
#include<QLabel>
#include<QString>

#include "../profileview.h"

#include "MDATA/client.h"

class ClientProfile : public QWidget
{
    Q_OBJECT
public:
    explicit ClientProfile(QWidget *parent = 0, const Client* model_ =0);
    ~ClientProfile();

    ProfileView* getProfileView();

    void applyModifyError(const QString& error) const;
    void applyModifySuccess();

signals:
    void applyModify();

private slots:
    void modifyClicked();
    void applyClicked();
    void cancelClicked();

private:
    const Client* model;

    QLabel* title;
    QScrollArea* scroll_area;
    ProfileView* profile;
    QPushButton* modify;
    QPushButton* cancel;

    QHBoxLayout* layout_button;
    QVBoxLayout* layout;

};

#endif // CLIENTPROFILE_H
