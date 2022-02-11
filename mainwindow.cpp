#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajoutcontactdialog.h"

#include <QSqlDatabase>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../dbContacts.db");
    db.open();
    AjoutContactDialog a;
    a.exec();
}

MainWindow::~MainWindow()
{
    QSqlDatabase::database().close();
    delete ui;
}

