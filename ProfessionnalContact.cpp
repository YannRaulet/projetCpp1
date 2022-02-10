#include "ProfessionnalContact.h"

ProfessionnalContact::ProfessionnalContact(string lN, string fN, Sex se, string cN, Address pAdd, string cMail)
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


void ProfessionnalContact::informations()
{

}


