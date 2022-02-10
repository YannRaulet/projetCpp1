#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

using namespace std;

enum Sex:char {M='M', F='F'};

class Contact
{
    public:
        Contact(string lastName, string firstName, Sex sex);
        virtual ~Contact();

        int getId() { return id; }
        string getLastName() { return lastName; }
        string getFirstName() { return firstName; }
        Sex getSex() { return sex; }
        void setSex(Sex vSex) { sex = vSex; }

        void setLastName(string);
        void setFirstName(string);

        virtual void informations() = 0;

    private:
        static int counter;
        int id;
        string lastName;
        string firstName;
        Sex sex;
};

#endif // CONTACT_H
