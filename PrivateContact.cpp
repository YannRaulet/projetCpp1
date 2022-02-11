#include "PrivateContact.h"
#include <QDebug>

PrivateContact::PrivateContact(QString lastName, QString firstName, Sex sex, Address address, QDate birthdate)
    :Contact(lastName, firstName, sex)
{
    //ctor
    this->setContactAddress(address);
    this->setBirthdate(birthdate);
}

PrivateContact::~PrivateContact()
{
    //dtor
    qDebug() << "Destruction du contact privé" <<endl;
}

