#include "cyx_file_check.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Cyx_File_Check w;
    w.show();

    return a.exec();
}
