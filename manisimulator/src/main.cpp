#include "manisimulator.h"
#include <cmath>
#include <QPen>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    maniSimulator w;
    w.show();
    return a.exec();
}
