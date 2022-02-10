#ifndef PRIVATECONTACT_H
#define PRIVATECONTACT_H


class PrivateContact
{
    public:
        PrivateContact();
        virtual ~PrivateContact();

        Address GetcontactAddress() { return contactAddress; }
        void SetcontactAddress(Address val) { contactAddress = val; }
        string Getbirthdate() { return birthdate; }
        void Setbirthdate(string val) { birthdate = val; }

    protected:

    private:
        Address contactAddress;
        string birthdate;
};

#endif // PRIVATECONTACT_H
