#include "Contact.h"

int Contact::counter = 0;

Contact::Contact(string lastName, string firstName, Sex sex)
{
    id = counter++;
    this->setLastName(lastName);
    this->setFirstName(firstName);
    this->setSex(sex);

}

Contact::~Contact()
{
    cout << "Destruction du contact" << endl;

}

void Contact::setLastName(string name)
{
    //TODo: A refaire en QT
    string newName = name.substr(0,30);
    for(char &c : newName) {
        c = toupper(c);
    }
    lastName = newName;
}

void Contact::setFirstName(string name)
{
    //TODo: A refaire en QT
    string newName = name.substr(0,30);
    for(char &c : newName) {
        c = tolower(c);
    }
    newName[0] = toupper(newName[0]);
    firstName = newName;
}

