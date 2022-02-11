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
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

MainWindow::~MainWindow()
{
    QSqlDatabase::database().close();
    delete ui->tableView->model();
    delete ui;
}

void MainWindow::setTableFilters(bool privFilter, bool proFilter) {
    QString filter = "";
    if(privFilter != proFilter) { //L'un est a true et l'autre a false
        QString isNot = proFilter ? "is not " : "is ";
        filter = "entreprise " + isNot + "null";
    }
    if(QRegExp("[a-z A-Z]*").exactMatch(ui->txtName->text()))
    {
        filter += filter.isEmpty() ? "" : " and ";
        filter += "Nom like '" + ui->txtName->text() + "%'";
    }
    QSqlTableModel *model = dynamic_cast<QSqlTableModel *>(ui->tableView->model());
    if(model != nullptr) {
        model->setFilter(filter);
        model->select();
    }
    if(privFilter && !proFilter) {
        ui->tableView->hideColumn(4);
    }
    else {
        ui->tableView->showColumn(4);
    }
}

void MainWindow::on_pbPrivate_stateChanged(int state)
{
    setTableFilters(state == Qt::Checked, ui->pbPro->checkState() == Qt::Checked);
}

void MainWindow::on_pbPro_stateChanged(int state)
{
    setTableFilters(ui->pbPrivate->checkState() == Qt::Checked, state == Qt::Checked);
}

void MainWindow::on_txtName_textEdited(const QString &txtName)
{

    if(QRegExp("[a-z A-Z]*").exactMatch(txtName))
    {
        ui->labelMessage->hide();
        setTableFilters(ui->pbPrivate->checkState() == Qt::Checked, ui->pbPro->checkState() == Qt::Checked);
    }
    else
    {
        ui->labelMessage->show();
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
