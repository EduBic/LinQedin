#ifndef ADMINCHANGE_H
#define ADMINCHANGE_H

#include<QWidget>
#include<QGroupBox>
#include<QPushButton>
#include<QRadioButton>
#include<QLabel>
#include<QGridLayout>


class AdminChange : public QGroupBox
{
    Q_OBJECT
public:
    explicit AdminChange(QWidget *parent = 0);
    ~AdminChange();

signals:
    void changeTypeClicked(const QString& type); //connect con AdminContent

public slots:
    void enableButton();

private slots:
    void changeType(); // passa il dato check al padre AdminContent

private:
    QRadioButton* basic;
    QRadioButton* business;
    QRadioButton* executive;
    QPushButton* change;

    QGridLayout* layout;

};

#endif // ADMINCHANGE_H
