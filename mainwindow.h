#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExpValidator>
#include <QSqlDatabase>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addContactButton_clicked();

    void on_pbPrivate_stateChanged(int state);

    void on_pbPro_stateChanged(int state);

    void on_txtName_textEdited(const QString &arg1);

    void on_actionQuitter_triggered();

private:
    Ui::MainWindow *ui;
    void setTableFilters(bool privFilter, bool proFilter);
};
#endif // MAINWINDOW_H
