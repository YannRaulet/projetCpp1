#include "PrivateContact.h"

PrivateContact::PrivateContact(string lN, string fN, Sex se, Address cAdd, string cBd)
    :Contact(lN, fN, se)
{
    //ctor
    this->setContactAddress(cAdd);
    this->setBirthdate(cBd);
}

PrivateContact::~PrivateContact()
{
    //dtor
    cout << "Destruction du contact privé" <<endl;
}

void PrivateContact::informations()
{

}
