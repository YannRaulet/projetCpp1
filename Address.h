#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

class Address
{
    public:
        Address();
        virtual ~Address();

        string getStreet() { return street; }
        void setStreet(string val) { street = val; }
        string getComplement() { return complement; }
        void setComplement(string val) { complement = val; }
        string getPostalCode() { return postalCode; }
        void setPostalCode(string val) { postalCode = val; }
        string getCity() { return city; }
        void setCity(string val) { city = val; }

    protected:

    private:
        string street;
        string complement;
        string postalCode;
        string city;
};

#endif // ADDRESS_H
