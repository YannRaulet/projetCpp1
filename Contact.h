#ifndef CONTACT_H
#define CONTACT_H


class Contact
{
    public:
        Contact();
        virtual ~Contact();

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        string GetlastName() { return lastName; }
        void SetlastName(string val) { lastName = val; }
        string GetfirstName() { return firstName; }
        void SetfirstName(string val) { firstName = val; }
        char Getsex() { return sex; }
        void Setsex(char val) { sex = val; }

    protected:

    private:
        int id;
        string lastName;
        string firstName;
        char sex;
};

#endif // CONTACT_H
