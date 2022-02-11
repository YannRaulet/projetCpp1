#ifndef PROFESSIONNALCONTACT_H
#define PROFESSIONNALCONTACT_H

#include "Address.h"
#include "Contact.h"

#include <QString>


class ProfessionnalContact : public Contact
{
    public:
        ProfessionnalContact(QString lastName, QString firstName, Sex sex, Address address, QString companyName, QString companyMail);
        virtual ~ProfessionnalContact();

        QString getCompanyName() { return companyName; }
        void setCompanyName(QString val);
        Address getCompanyAddress() { return companyAddress; }
        void setCompanyAddress(Address val) { companyAddress = val; }
        QString getCompanyMail() { return companyMail; }
        void setCompanyMail(QString val) { companyMail = val; }

    protected:

    private:
        QString companyName;
        Address companyAddress;
        QString companyMail;
};

#endif // PROFESSIONNALCONTACT_H
