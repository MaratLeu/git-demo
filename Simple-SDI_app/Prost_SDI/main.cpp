#include "SDIProgram.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SDIProgram w;
    w.showFullScreen();
    return a.exec();
}
