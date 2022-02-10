#ifndef PRIVATECONTACT_H
#define PRIVATECONTACT_H

#include "Address.h"
#include "Contact.h"

class PrivateContact : public Contact
{
    public:
        PrivateContact(string, string, char, Address, string);
        virtual ~PrivateContact();

        Address getContactAddress() { return contactAddress; }
        void setContactAddress(Address val) { contactAddress = val; }
        string getBirthdate() { return birthdate; }
        void setBirthdate(string val) { birthdate = val; }

    private:
        Address contactAddress;
        string birthdate;
};

#endif // PRIVATECONTACT_H
