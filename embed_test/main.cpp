#include <QApplication>
#include <QDebug>
#include "cyx_manager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Cyx_Manager manager;
    manager.show();

    qDebug() << QApplication::applicationName();
    qDebug() << QApplication::applicationFilePath();

    return a.exec();
}
