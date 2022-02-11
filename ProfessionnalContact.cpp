#include "ProfessionnalContact.h"
#include <QDebug>

ProfessionnalContact::ProfessionnalContact(QString lastName, QString firstName, Sex sex, Address address, QString companyName, QString companyMail)
    :Contact(lastName, firstName, sex)
{
    //ctor
    this->setCompanyName(companyName);
    this->setCompanyAddress(address);
    this->setCompanyMail(companyMail);
}

ProfessionnalContact::~ProfessionnalContact()
{
    //dtor
    qDebug() << "Destruction du contact professionnel" << endl;
}


void ProfessionnalContact::setCompanyName(QString cName)
{
    QString newCompanyName = cName;
    newCompanyName.truncate(50);
    for(QChar &c : newCompanyName) {
        c = c.toUpper();
    }
    companyName = newCompanyName;
}



