//#include "squareparody.h"
#include "mainscene.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainScene w;
    w.resize(700, 650);
    w.show();
    return a.exec();
}
