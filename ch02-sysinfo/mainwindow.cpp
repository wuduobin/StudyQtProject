#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <sysinfo.h>
#include <QLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
    , ui{new Ui::MainWindow}
    , mCpuWidget{this}
    , mMemoryWidget{this}
{
    ui->setupUi(this);
    SysInfo::instance().init();
    ui->layout->addWidget(&mCpuWidget);
    ui->layout->addWidget(&mMemoryWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

