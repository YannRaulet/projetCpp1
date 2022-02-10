#ifndef CONTACT_H
#define CONTACT_H


class Contact
{
    public:
        Contact();
        virtual ~Contact();

        int getId() { return id; }
        string getLastName() { return lastName; }
        void setLastName(string val) { lastName = val; }
        string getFirstName() { return firstName; }
        void setfirstName(string val) { firstName = val; }
        char getSex() { return sex; }
        void setSex(char val) { sex = val; }

    private:
        int id;
        string lastName;
        string firstName;
        char sex;
};

#endif // CONTACT_H
