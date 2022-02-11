#ifndef AJOUTCONTACTDIALOG_H
#define AJOUTCONTACTDIALOG_H

#include "Contact.h"

#include <QDialog>
#include <QRegExpValidator>

namespace Ui {
class AjoutContactDialog;
}

class AjoutContactDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AjoutContactDialog(QWidget *parent = nullptr);
    ~AjoutContactDialog();

private slots:
    void on_privateRButton_clicked();

    void on_professionnalRButton_clicked();

    void on_lastnameInput_textChanged(const QString &);

    void on_firstnameInput_textChanged(const QString &);

    void on_mailInput_textChanged();

    void on_addressInput_textChanged();

    void on_postalcodeInput_textChanged();

    void on_cityInput_textChanged();

    void on_companyInput_textChanged();


    void checkAddButtonActivation();
    void on_addButton_clicked();

private:
    Ui::AjoutContactDialog *ui;
    int verticalLength;
    QRegExpValidator *cpValidator;

    bool isLastNameValid();
    bool isFirstNameValid();
    bool isBirthDateValid();
    bool isCompanyNameValid();
    bool isMailValid();
    bool isAddressValid();
    bool isPostalCodeValid();
    bool isCityValid();
    bool addContactToDb(Contact *c);
};

#endif // AJOUTCONTACTDIALOG_H
