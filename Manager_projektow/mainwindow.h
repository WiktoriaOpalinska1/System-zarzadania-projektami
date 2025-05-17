#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "BusinessLogic/managerprojektow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSortButtonClicked();
    void showProjectsInTable(const std::vector<Project*>& projekty);

private:
    Ui::MainWindow *ui;
    ManagerProjektow managerProjektow;
};

#endif // MAINWINDOW_H
