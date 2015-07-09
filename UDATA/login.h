#ifndef LOGIN_H
#define LOGIN_H

#include<QXmlStreamReader>
#include<QString>

class Login{
private:
    QString username;

public:
    Login(QString user);

    const QString& getUsername() const;

    static Login* readLogin(QXmlStreamReader& ); //metodo non utilizzato

};

#endif // LOGIN_H
