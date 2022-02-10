#include "ProfessionnalContact.h"

ProfessionnalContact::ProfessionnalContact(string lN, string fN, char se, string cN, Address pAdd, string cMail)
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
    cout << "Destruction du contact professionnel" << endl;
}


void ProfessionnalContact::setCompanyName(string cName)
{
    string newCompanyName = cName.substr(0,50);
    for(char &c : newCompanyName) {
        c = toupper(c);
    }
    companyName = newCompanyName;
}



