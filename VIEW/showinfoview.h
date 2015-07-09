#ifndef SHOWINFOVIEW_H
#define SHOWINFOVIEW_H

#include <QWidget>
#include<QTextEdit>
#include<QScrollArea>
#include<QVBoxLayout>
#include<QApplication>
#include<QDesktopWidget>
#include<QLabel>
#include<QApplication>
#include<QPushButton>

#include<VIEW/profileview.h>

class ProfileView;
class Utente;

class ShowInfoView : public QWidget
{
    Q_OBJECT
public:
    explicit ShowInfoView(QWidget *parent = 0, const QString& userName ="", const Utente* user =0);
    ~ShowInfoView();

signals:

public slots:

private:
    void centerWidget();

    QLabel* title;
    ProfileView* profile;
    QScrollArea* scroll;
    QPushButton* exit;

    QVBoxLayout* layout;
};

#endif // SHOWINFOVIEW_H
