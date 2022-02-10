#include "ProfessionnalContact.h"
#include <QDebug>

ProfessionnalContact::ProfessionnalContact(QString lN, QString fN, Sex se, QString cN, Address pAdd, QString cMail)
    :Contact(lN, fN, se)
{
    //ctor
    this->setCompanyName(cN);
    this->setCompanyAddress(pAdd);
    this->setCompanyMail(cMail);
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



