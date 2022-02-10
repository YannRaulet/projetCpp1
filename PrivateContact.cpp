#include "PrivateContact.h"

PrivateContact::PrivateContact(string lN, string fN, char se, Address cAdd, string cBd)
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

