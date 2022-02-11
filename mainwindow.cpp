#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajoutcontactdialog.h"

#include <QSqlDatabase>

#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../projetCpp1/dbContacts.db");
    db.open();
    QSqlTableModel *model = new QSqlTableModel();
    model->setTable("contacts");
    model->select();
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    QSqlDatabase::database().close();
    delete ui->tableView->model();
    delete ui;
}

void MainWindow::on_pbPrivate_clicked()
{
    QSqlTableModel *model = dynamic_cast<QSqlTableModel *>(ui->tableView->model());
    if(model != nullptr) {
        model->setFilter("entreprise is null");
        model->select();
    }
    ui->tableView->hideColumn(4);
}

void MainWindow::on_pbPro_clicked()
{
    QSqlTableModel *model = dynamic_cast<QSqlTableModel *>(ui->tableView->model());
    if(model != nullptr) {
        model->setFilter("entreprise is not null");
        model->select();
    }
    ui->tableView->showColumn(4);
}

void MainWindow::on_searchButton_clicked()
{

    QString text = ui->txtName->text();
    QString errors="";

    if (text.isEmpty())
    {
        errors.append(" Veuillez entrer un nom \n");
        ui->labelMessage->setStyleSheet("color: red");
    }

    if(errors.isEmpty())
    {
        QRegExp expr("[a-z A-Z]*");

        if(expr.exactMatch(text)==false)
        {
            errors.append(" Merci de ne rentrer que des lettres \n");
            ui->labelMessage->setStyleSheet("color: red");
        }
        else
        {

            QSqlTableModel *model = dynamic_cast<QSqlTableModel *>(ui->tableView->model());
            if(model != nullptr) {
                model->setFilter("Nom like '" + ui->txtName->text() + "%'");
                model->select();
            }
        }
    }
    if(!errors.isEmpty())
    {
        ui->labelMessage->setText(errors);
    }
}

void MainWindow::on_addContactButton_clicked()
{
    AjoutContactDialog dial;
    dial.exec();
    QSqlTableModel *model = dynamic_cast<QSqlTableModel *>(ui->tableView->model());
    if(model != nullptr) {
        model->select();
    }
}

