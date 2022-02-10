#ifndef PRIVATECONTACT_H
#define PRIVATECONTACT_H

#include "Address.h"
#include "Contact.h"

#include <QString>


class PrivateContact : public Contact
{
    public:
        PrivateContact(QString, QString, Sex, Address, QString);
        virtual ~PrivateContact();

        Address getContactAddress() { return contactAddress; }
        void setContactAddress(Address val) { contactAddress = val; }
        QString getBirthdate() { return birthdate; }
        void setBirthdate(QString val) { birthdate = val; }

    private:
        Address contactAddress;
        QString birthdate;
};

#endif // PRIVATECONTACT_H
