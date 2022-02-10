#ifndef ADDRESS_H
#define ADDRESS_H

#include <QString>

class Address
{
private:
    QString street;
    QString complement;
    QString postalCode;
    QString city;

public:
    Address();
    virtual ~Address();

    QString getStreet() { return street; }
    void setStreet(QString val) { street = val; }
    QString getComplement() { return complement; }
    void setComplement(QString val) { complement = val; }
    QString getPostalCode() { return postalCode; }
    void setPostalCode(QString val) { postalCode = val; /*TODO:  A check en QT*/ }
    QString getCity() { return city; }
    void setCity(QString val) { city = val; }

};

#endif // ADDRESS_H
