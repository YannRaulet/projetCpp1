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
    ui->labelMessage->hide();
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

void MainWindow::on_txtName_textEdited(const QString &txtName)
{
    QRegExp expr("[a-z A-Z]*");

    if(expr.exactMatch(txtName)==false)
    {
        ui->labelMessage->show();
    }
    else
    {
        ui->labelMessage->hide();
        QSqlTableModel *model = dynamic_cast<QSqlTableModel *>(ui->tableView->model());
        if(model != nullptr) {
            model->setFilter("Nom like '" + ui->txtName->text() + "%'");
            model->select();
        }
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


void MainWindow::on_actionQuitter_triggered()
{
    this->close();
}
