#include "ajoutcontactdialog.h"
#include "ui_ajoutcontactdialog.h"
#include <QDebug>

AjoutContactDialog::AjoutContactDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjoutContactDialog)
{
    ui->setupUi(this);
    cpValidator = new QRegExpValidator(QRegExp("^[0-9]{5}$"), this);
    ui->postalcodeInput->setValidator(cpValidator);
    ui->birthdateInput->setMaximumDate(QDate::currentDate());
    ui->birthdateInput->setDate(QDate::currentDate());
    verticalLength = ui->sexCBox->y() - ui->lastnameInput->y();
    on_privateRButton_clicked();
}

AjoutContactDialog::~AjoutContactDialog()
{
    delete ui;
    delete cpValidator;
}

void AjoutContactDialog::on_privateRButton_clicked()
{
    ui->frameAddress->move(ui->frameAddress->x(), ui->lastnameInput->y() + verticalLength * 2);
    ui->birthdateLabel->show();
    ui->birthdateInput->show();
    ui->mailInput->hide();
    ui->mailLabel->hide();
    ui->companyInput->hide();
    ui->companyLabel->hide();
}


void AjoutContactDialog::on_professionnalRButton_clicked()
{
    //QLineEdit
    ui->frameAddress->move(ui->frameAddress->x(), ui->lastnameInput->y() + verticalLength * 4);
    ui->mailLabel->show();
    ui->mailInput->show();
    ui->companyInput->show();
    ui->companyLabel->show();
    ui->birthdateInput->hide();
    ui->birthdateLabel->hide();
}


void AjoutContactDialog::on_lastnameInput_textChanged(const QString &lName)
{
    ui->lastnameInput->setText(lName.toUpper());
    if(isLastNameValid()) {
        ui->lastnameInput->setStyleSheet("border: 1px solid black;");
    }
    else {
        ui->lastnameInput->setStyleSheet("border: 1px solid red;");
    }
}


void AjoutContactDialog::on_firstnameInput_textChanged(const QString &fName)
{
    if(fName != "") {
        QString qs = fName.toLower();
        qs[0] = qs[0].toUpper();
        ui->firstnameInput->setText(qs);
        ui->firstnameInput->setStyleSheet("border: 1px solid black;");
    }
    else {
        ui->firstnameInput->setStyleSheet("border: 1px solid red;");
    }
}

bool AjoutContactDialog::isLastNameValid()
{
    return !ui->lastnameInput->text().isEmpty();
}

bool AjoutContactDialog::isFirstNameValid()
{
    return !ui->lastnameInput->text().isEmpty();
}

bool AjoutContactDialog::isBirthDateValid()
{
    QDate d = ui->birthdateInput->date();
    return d.isValid() && d >= QDate(1900, 1, 1) && d <= QDate::currentDate();
}

bool AjoutContactDialog::isCompanyNameValid()
{
    return !ui->companyInput->text().isEmpty();
}

bool AjoutContactDialog::isMailValid()
{
    return QRegExp("^[A-Za-z0-9\\.]+@[A-Za-z0-9\\.]+$").exactMatch(ui->mailInput->text());
}

bool AjoutContactDialog::isAddressValid()
{
    return !ui->addressInput->text().isEmpty();
}

bool AjoutContactDialog::isPostalCodeValid()
{
    return ui->mailInput->hasAcceptableInput();
}

bool AjoutContactDialog::isCityValid()
{
    return !ui->cityInput->text().isEmpty();
}




void AjoutContactDialog::on_companyInput_textChanged(const QString &cName)
{
    if(cName.isEmpty()) {
        ui->companyInput->setStyleSheet("border: 1px solid red;");
    }
    else {
        ui->companyInput->setStyleSheet("border: 1px solid black;");
    }
}

