#ifndef AJOUTCONTACTDIALOG_H
#define AJOUTCONTACTDIALOG_H

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

    void on_lastnameInput_textChanged(const QString &arg1);

    void on_firstnameInput_textChanged(const QString &arg1);

    void on_companyInput_textChanged(const QString &arg1);

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


};

#endif // AJOUTCONTACTDIALOG_H
