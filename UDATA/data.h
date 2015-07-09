#ifndef DATA_H
#define DATA_H

class Data{
private:
    int giorno;
    int mese;
    int anno;

    void controlloData();
public:
    Data(int =1, int =1, int =1920);
    //Data(const int& =1, const int& =1, const int& =1920);
    Data(const Data&);

    int getGiorno() const;
    int getMese() const;
    int getAnno() const;

    void setGiorno(int);
    void setMese(int);
    void setAnno(int);
    void setData(int,int,int);
};

#endif // DATA_H
