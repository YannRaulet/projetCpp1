#include "Contact.h"

Contact::Contact(string lN, string fN, char se)
{
    //ctor
    this-> setLastName(lN);
    this->setfirstName(fN);
    this->setSex(se);

}

Contact::~Contact()
{
    //dtor
    cout << "Destruction du contact" << endl;

}

