#ifndef PROFESSIONNALCONTACT_H
#define PROFESSIONNALCONTACT_H


class ProfessionnalContact
{
    public:
        ProfessionnalContact();
        virtual ~ProfessionnalContact();

        string GetcompanyName() { return companyName; }
        void SetcompanyName(string val) { companyName = val; }
        Address GetcompanyAddress() { return companyAddress; }
        void SetcompanyAddress(Address val) { companyAddress = val; }
        string GetcompanyMail() { return companyMail; }
        void SetcompanyMail(string val) { companyMail = val; }

    protected:

    private:
        string companyName;
        Address companyAddress;
        string companyMail;
};

#endif // PROFESSIONNALCONTACT_H
