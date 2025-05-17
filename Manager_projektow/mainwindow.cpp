#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "BusinessLogic/managerprojektow.h"

#include <QString>
#include <QTextEdit>
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ManagerProjektow manager;

    QString allProjects;

    for (auto* p : manager.getProjekty()) {
        allProjects += QString::fromStdString(p->toString());
        allProjects += "\n-------------------\n";
    }

    auto projekty = managerProjektow.getProjekty();
    showProjectsInTable(projekty);
    ui->projectTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    connect(ui->sortButton, &QPushButton::clicked, this, &MainWindow::onSortButtonClicked);

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onSortButtonClicked() {
    auto projekty = managerProjektow.getProjekty();

    std::sort(projekty.begin(), projekty.end(), [this](Project* a, Project* b) {
        return (ui->sortComboBox->currentText() == "A-Z")
        ? a->getName() < b->getName()
                       : a->getName() > b->getName();
    });

    showProjectsInTable(projekty);  // ← zamiast wypisywania do QTextEdit
}

void MainWindow::showProjectsInTable(const std::vector<Project*>& projekty) {
    ui->projectTableWidget->clear();
    ui->projectTableWidget->setColumnCount(7);
    ui->projectTableWidget->setRowCount(static_cast<int>(projekty.size()));

    ui->projectTableWidget->setHorizontalHeaderLabels({
        "Nazwa", "Technologie", "Stan", "Czas pracy", "Repozytorium", "Współautorzy", "Obowiązki"
    });

    for (int row = 0; row < projekty.size(); ++row) {
        Project* p = projekty[row];

        ui->projectTableWidget->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(p->getName())));

        QString techList;
        for (const auto& t : p->getTechnologies())
            techList += QString::fromStdString(t) + ", ";
        if (!techList.isEmpty()) techList.chop(2);
        ui->projectTableWidget->setItem(row, 1, new QTableWidgetItem(techList));

        ui->projectTableWidget->setItem(row, 2, new QTableWidgetItem(QString::fromStdString(p->getStatus())));

        ui->projectTableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(p->getWorkTime())));

        ui->projectTableWidget->setItem(row, 4, new QTableWidgetItem(QString::fromStdString(p->getRepositoryLink())));

        TeamProject* team = dynamic_cast<TeamProject*>(p);
        if (team) {
            QString authors;
            for (const auto& a : team->getCollaborators())
                authors += QString::fromStdString(a) + ", ";
            if (!authors.isEmpty()) authors.chop(2);
            ui->projectTableWidget->setItem(row, 5, new QTableWidgetItem(authors));

            ui->projectTableWidget->setItem(row, 6, new QTableWidgetItem(QString::fromStdString(team->getResponsibilities())));
        } else {

            ui->projectTableWidget->setItem(row, 5, new QTableWidgetItem("-"));
            ui->projectTableWidget->setItem(row, 6, new QTableWidgetItem("-"));
        }
    }
}
