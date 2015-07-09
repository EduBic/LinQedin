#ifndef INFO3_H
#define INFO3_H

#include<QXmlStreamReader>
#include<QString>
#include<vector>

class Info3{
private:
    std::vector<QString> xps;
public:
    Info3(const std::vector<QString> &x =std::vector<QString>());

    const std::vector<QString>& getXps() const;
    void setEsperienze(const std::vector<QString>& esp);
    bool matchEsperienze(const QString& text) const;

    static Info3 readInfo3(QXmlStreamReader& );
};

#endif // INFO3_H
