#include "Contact.h"
#include <QDebug>

int Contact::counter = 0;

Contact::Contact(QString lastName, QString firstName, Sex sex)
{
    id = counter++;
    this->setLastName(lastName);
    this->setFirstName(firstName);
    this->setSex(sex);
}

Contact::~Contact()
{
    qDebug() << "Destruction du contact" << endl;

}

void Contact::setLastName(QString name)
{
    //TODo: A refaire en QT
    QString newName = name;
    newName.truncate(30);
    for(QChar &c : newName) {
        c = c.toUpper();
    }
    lastName = newName;
}

void Contact::setFirstName(QString name)
{
    //TODo: A refaire en QT
    QString newName = name;
    newName.truncate(30);
    for(QChar &c : newName) {
        c = c.toLower();
    }
    newName[0] = newName[0].toUpper();
    firstName = newName;
}
