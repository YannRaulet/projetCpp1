#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ajoutcontactdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    AjoutContactDialog a;
    a.exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

