#include "windowcmentic.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WindowCmentic w;
    w.show();
    
    return a.exec();
}
