#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

enum Sex:char {M='M', F='F'};


class Contact
{
    public:
        Contact(QString, QString, Sex);

        virtual ~Contact();

        int getId() { return id; }
        QString getLastName() { return lastName; }
        QString getFirstName() { return firstName; }
        Sex getSex() { return sex; }
        void setSex(Sex vSex) { sex = vSex; }

        void setLastName(QString);
        void setFirstName(QString);

    private:
        static int counter;
        int id;
        QString lastName;
        QString firstName;
        Sex sex;
};

#endif // CONTACT_H
