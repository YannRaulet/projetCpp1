#ifndef PRIVATECONTACT_H
#define PRIVATECONTACT_H

#include "Address.h"
#include "Contact.h"

#include <QDate>
#include <QString>


class PrivateContact : public Contact
{
    public:
        PrivateContact(QString lastName, QString firstName, Sex sex, Address address, QDate birthdate);
        virtual ~PrivateContact();

        Address getContactAddress() { return contactAddress; }
        void setContactAddress(Address val) { contactAddress = val; }
        QDate getBirthdate() { return birthdate; }
        void setBirthdate(QDate val) { birthdate = val; }

    private:
        Address contactAddress;
        QDate birthdate;
};

#endif // PRIVATECONTACT_H
