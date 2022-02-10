#include "ProfessionnalContact.h"

ProfessionnalContact::ProfessionnalContact(string lN, string fN, char se, string cN, Adress pAdd, string cMail)
    :Contact(lN, fN, se)
{
    //ctor
    this->SetcompanyName(cN);
    this->SetcompanyAddress(pAdd);
    this->SetcompanyMail(cMail)
}

ProfessionnalContact::~ProfessionnalContact()
{
    //dtor
    cout << "Destruction du contact professionnel" << endl;
}



void ProfessionnalContact::informations()
{

}
