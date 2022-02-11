#include "Address.h"

Address::Address(QString street, QString complement, QString postalCode, QString city)
{
    setStreet(street);
    setComplement(complement);
    setPostalCode(postalCode);
    setCity(city);
}

Address::~Address()
{
    //dtor
}

