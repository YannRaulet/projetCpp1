#include "Contact.h"
#include "PrivateContact.h"
#include "ProfessionnalContact.h"
#include "ajoutcontactdialog.h"
#include "ui_ajoutcontactdialog.h"
#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

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
    connect(ui->companyInput, SIGNAL(textChanged(QString)), this, SLOT(on_companyInput_textChanged()));
    connect(ui->mailInput, SIGNAL(textChanged(QString)), this, SLOT(on_mailInput_textChanged()));
    connect(ui->addressInput, SIGNAL(textChanged(QString)), this, SLOT(on_addressInput_textChanged()));
    connect(ui->postalcodeInput, SIGNAL(textChanged(QString)), this, SLOT(on_addressInput_textChanged()));
    connect(ui->cityInput, SIGNAL(textChanged(QString)), this, SLOT(on_cityInput_textChanged()));
    connect(ui->sexCBox, SIGNAL(currentIndexChanged(int)), this, SLOT(checkAddButtonActivation()));
    connect(ui->birthdateInput, SIGNAL(dateChanged(QDate)), this, SLOT(checkAddButtonActivation()));
    connect(ui->complementInput, SIGNAL(textChanged(QString)), this, SLOT(checkAddButtonActivation()));
    checkAddButtonActivation();
}

AjoutContactDialog::~AjoutContactDialog()
{
    delete ui;
    delete cpValidator;
}

void AjoutContactDialog::checkAddButtonActivation() {
    bool ok = isLastNameValid() && isFirstNameValid() && isAddressValid() && isCityValid() && isPostalCodeValid();
    if(ui->privateRButton->isChecked()) {
        ok = ok && isBirthDateValid();
    }
    else {
        ok = ok && isCompanyNameValid() && isMailValid();
    }
    ui->addButton->setEnabled(ok);

}

void AjoutContactDialog::on_addButton_clicked()
{
    Sex s = ui->sexCBox->currentIndex() == 0 ? Sex::M : Sex::F;
    Address a(ui->addressInput->text(),
              ui->complementInput->text(),
              ui->postalcodeInput->text(),
              ui->cityInput->text());

    Contact *toAdd = nullptr;
    if(ui->privateRButton->isChecked()) {
        toAdd = new PrivateContact(ui->lastnameInput->text(),
                               ui->firstnameInput->text(),
                               s,
                               a,
                               ui->birthdateInput->date());
    }
    else {
        toAdd = new ProfessionnalContact(ui->lastnameInput->text(),
                                     ui->firstnameInput->text(),
                                     s,
                                     a,
                                     ui->companyInput->text(),
                                     ui->mailInput->text());
    }
    bool ok = addContactToDb(toAdd);
    delete toAdd;
    QMessageBox msg(QMessageBox::Information, "Requete effectuée", "La requete a été effectuée", QMessageBox::Ok, this);
    msg.exec();
    if(ok) {
        this->close();
    }

}

bool AjoutContactDialog::addContactToDb(Contact *c) {
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery q(db);
    PrivateContact *privC = dynamic_cast<PrivateContact*>(c);
    ProfessionnalContact *profC = dynamic_cast<ProfessionnalContact*>(c);
    if(privC != nullptr) {
        q.prepare("INSERT INTO CONTACTS (Nom, Prenom, Sexe, rue, Complement, cp, Ville, dtNaissance) "
                  "VALUES (:nom, :prenom, :sex, :rue, :compl, :cp, :ville, :naissance);");
        q.bindValue(":nom", privC->getLastName());
        q.bindValue(":prenom", privC->getFirstName());
        q.bindValue(":sex", QChar(privC->getSex()));
        q.bindValue(":rue", privC->getContactAddress().getStreet());
        q.bindValue(":compl", privC->getContactAddress().getComplement());
        q.bindValue(":cp", privC->getContactAddress().getPostalCode());
        q.bindValue(":ville", privC->getContactAddress().getCity());
        q.bindValue(":naissance", privC->getBirthdate());
    }
    else if(profC != nullptr) {
        q.prepare("INSERT INTO CONTACTS (Nom, Prenom, Sexe, Entreprise, rue, Complement, cp, Ville, mail) "
                  "VALUES (:nom, :prenom, :sex, :entreprise, :rue, :compl, :cp, :ville, :mail);");
        q.bindValue(":nom", profC->getLastName());
        q.bindValue(":prenom", profC->getFirstName());
        q.bindValue(":sex", QChar(profC->getSex()));
        q.bindValue(":entreprise", profC->getCompanyName());
        q.bindValue(":rue", profC->getCompanyAddress().getStreet());
        q.bindValue(":compl", profC->getCompanyAddress().getComplement());
        q.bindValue(":cp", profC->getCompanyAddress().getPostalCode());
        q.bindValue(":ville", profC->getCompanyAddress().getCity());
        q.bindValue(":mail", profC->getCompanyMail());
    }
    else {
        return false;
    }
    return q.exec();

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
    checkAddButtonActivation();
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
    checkAddButtonActivation();
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
    checkAddButtonActivation();
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
    checkAddButtonActivation();
}

void AjoutContactDialog::on_companyInput_textChanged()
{
    if(isCompanyNameValid()) {
        ui->companyInput->setStyleSheet("border: 1px solid black;");
    }
    else {
        ui->companyInput->setStyleSheet("border: 1px solid red;");
    }
    checkAddButtonActivation();
}

void AjoutContactDialog::on_mailInput_textChanged()
{
    if(isMailValid()) {
        ui->mailInput->setStyleSheet("border: 1px solid black;");
    }
    else {
        ui->mailInput->setStyleSheet("border: 1px solid red;");
    }
    checkAddButtonActivation();
}


void AjoutContactDialog::on_addressInput_textChanged()
{
    if(isAddressValid()) {
        ui->addressInput->setStyleSheet("border: 1px solid black;");
    }
    else {
        ui->addressInput->setStyleSheet("border: 1px solid red;");
    }
    checkAddButtonActivation();
}


void AjoutContactDialog::on_postalcodeInput_textChanged()
{
    if(isPostalCodeValid()) {
        ui->postalcodeInput->setStyleSheet("border: 1px solid black;");
    }
    else {
        ui->postalcodeInput->setStyleSheet("border: 1px solid red;");
    }
    checkAddButtonActivation();
}


void AjoutContactDialog::on_cityInput_textChanged()
{
    if(isCityValid()) {
        ui->cityInput->setStyleSheet("border: 1px solid black;");
    }
    else {
        ui->cityInput->setStyleSheet("border: 1px solid red;");
    }
    checkAddButtonActivation();
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
    return ui->postalcodeInput->hasAcceptableInput();
}

bool AjoutContactDialog::isCityValid()
{
    return !ui->cityInput->text().isEmpty();
}



