#include "windowcmentic.h"
#include <QApplication>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WindowCmentic interface;
    interface.show();
    return a.exec();
}
