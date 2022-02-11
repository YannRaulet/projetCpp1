#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../projetCPP/dbContacts.db");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbPrivate_clicked()
{
    QSqlTableModel *model = new QSqlTableModel();

    model->setTable("contacts");
    model->setFilter("entreprise is null");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(4);
}

void MainWindow::on_pbPro_clicked()
{
    QSqlTableModel *model = new QSqlTableModel();

    model->setTable("contacts");
    model->setFilter("entreprise is not null");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->showColumn(4);
}

void MainWindow::on_searchButton_clicked()
{

}
