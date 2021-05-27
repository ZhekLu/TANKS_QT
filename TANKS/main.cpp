#include "tankswindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TanksWindow w;
    w.resize(700, 650);
    w.show();
    return a.exec();
}
