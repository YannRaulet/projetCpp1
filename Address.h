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
    Address(QString street, QString complement, QString postalCode, QString city);
    Address() = default;
    virtual ~Address();

    QString getStreet() const { return street; }
    void setStreet(QString val) { street = val; }
    QString getComplement() const { return complement; }
    void setComplement(QString val) { complement = val; }
    QString getPostalCode() const { return postalCode; }
    void setPostalCode(QString val) { postalCode = val; }
    QString getCity() const { return city; }
    void setCity(QString val) { city = val; }


};

#endif // ADDRESS_H
