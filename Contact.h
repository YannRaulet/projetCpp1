#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
using namespace std;

class Contact
{
    public:
        Contact(string, string, char);
        virtual ~Contact();

        int getId() { return id; }
        string getLastName() { return lastName; }
        void setLastName(string val) { lastName = val; }
        string getFirstName() { return firstName; }
        void setfirstName(string val) { firstName = val; }
        char getSex() { return sex; }
        void setSex(char val) { sex = val; }

        virtual void informations() = 0;

    private:
        int id;
        string lastName;
        string firstName;
        char sex;
};

#endif // CONTACT_H
