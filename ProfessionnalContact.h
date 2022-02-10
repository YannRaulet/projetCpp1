#ifndef PROFESSIONNALCONTACT_H
#define PROFESSIONNALCONTACT_H

#include "Address.h"
#include "Contact.h"

#include <iostream>

using namespace std;

class ProfessionnalContact : public Contact
{
    public:
        ProfessionnalContact(string, string, Sex, string, Address, string);
        virtual ~ProfessionnalContact();

        string getCompanyName() { return companyName; }
        void setCompanyName(string val);
        Address getCompanyAddress() { return companyAddress; }
        void setCompanyAddress(Address val) { companyAddress = val; }
        string getCompanyMail() { return companyMail; }
        void setCompanyMail(string val) { companyMail = val; }

    protected:

    private:
        string companyName;
        Address companyAddress;
        string companyMail;
};

#endif // PROFESSIONNALCONTACT_H
