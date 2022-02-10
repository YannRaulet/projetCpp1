#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

using namespace std;

class Address
{
    public:
        Address();
        virtual ~Address();

        string Getstreet() { return street; }
        void Setstreet(string val) { street = val; }
        string Getcomplement() { return complement; }
        void Setcomplement(string val) { complement = val; }
        string GetpostalCode() { return postalCode; }
        void SetpostalCode(string val) { postalCode = val; }
        string Getcity() { return city; }
        void Setcity(string val) { city = val; }

    protected:

    private:
        string street;
        string complement;
        string postalCode;
        string city;
};

#endif // ADDRESS_H
