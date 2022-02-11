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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbPrivate_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("/home/yann/Documents/formationCPlusPlus/projetCPP/projetCPP/dbContacts.db");
    db.setDatabaseName("../projetCPP/dbContacts.db");


    QSqlTableModel *model = new QSqlTableModel();

    model->setTable("contacts");
    model->setFilter("entreprise is null");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->hideColumn(4);
    //db.close();
}

void MainWindow::on_pbPro_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setDatabaseName("/home/yann/Documents/formationCPlusPlus/projetCPP/projetCPP/dbContacts.db");
    db.setDatabaseName("../projetCPP/dbContacts.db");


    QSqlTableModel *model = new QSqlTableModel();

    model->setTable("contacts");
    model->setFilter("entreprise is not null");
    model->select();

    ui->tableView->setModel(model);
    ui->tableView->showColumn(4);

    //db.close();
}
