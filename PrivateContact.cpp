#include "PrivateContact.h"
#include <QDebug>

PrivateContact::PrivateContact(QString lN, QString fN, Sex se, Address cAdd, QString cBd)
    :Contact(lN, fN, se)
{
    //ctor
    this->setContactAddress(cAdd);
    this->setBirthdate(cBd);
}

PrivateContact::~PrivateContact()
{
    //dtor
    qDebug() << "Destruction du contact privé" <<endl;
}

