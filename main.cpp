#include "mainwindow.h"
//#include "task.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Task w;
    MainWindow w;
    w.show();

    return a.exec();
}
