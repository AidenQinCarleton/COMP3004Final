#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "profileeditor.h"
#include "profileselector.h"
#include "profileviewer.h"
#include "deviceviewer.h"
#include "globals.h"
#include "app.h"
#include "exam.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    globals::app = new App();


    ui->setupUi(this);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(100);

    globals::app->addProgressBar(ui->progressBar);

    globals::pagesWidget = ui->windows;
    ProfileSelector* profileSelector = new ProfileSelector(this);
    ProfileEditor* profileEditor = new ProfileEditor(this, profileSelector);
    profileSelector->setEditor(profileEditor);

    ProfileViewer* profileViewer = new ProfileViewer(this);
    DeviceViewer* deviceViewer = new DeviceViewer(this);
    Exam* exam = new Exam(this);

    pages::profileSelector = ui->windows->addWidget(profileSelector);
    pages::profileEditor = ui->windows->addWidget(profileEditor);
    pages::profileViewer = ui->windows->addWidget(profileViewer);
    pages::exam = ui->windows->addWidget(exam);
    pages::deviceViewer = ui->windows->addWidget(deviceViewer);


    connect(ui->menuprofiles, &QMenu::aboutToShow, this, [this, profileSelector](){
        profileSelector->updateProfileDisplay();
        globals::app->setCurrentProfile(-1);
        ui->windows->setCurrentIndex(pages::profileSelector);
    });

    connect(ui->menuresults, &QMenu::aboutToShow, this, [this, profileViewer](){
        if (globals::app->loggedIn()) {
            profileViewer->SetCurrProfile();
            //profileViewer->ClearGraph();
            ui->windows->setCurrentIndex(pages::profileViewer);
        } else {
            message.setText("not logged in ");
            message.setInformativeText("log into a profile to use profile results feature");
            message.exec();
        }
    });
    //for exam taking
    connect(ui->menuexam, &QMenu::aboutToShow, this, [this, exam](){
        if (globals::app->loggedIn()) {
            exam->reset();
            ui->windows->setCurrentIndex(pages::exam);
        } else {
            message.setText("not logged in ");
            message.setInformativeText("log into a profile to use exam feature");
            message.exec();
        }
    });
    //for device
    connect(ui->menudevice, &QMenu::aboutToShow, this, [this](){
        ui->windows->setCurrentIndex(pages::deviceViewer);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    delete globals::app;
}

