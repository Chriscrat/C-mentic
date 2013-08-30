#include "windowcmentic.h"
#include <QApplication>
#include <string>
#include <vector>
#include <iostream>
#include <qtextcodec.h>
#include <QTextCodec>
using namespace std;

int main(int argc, char *argv[])
{
    // UTF-8 Encoding

    QApplication a(argc, argv);
    WindowCmentic interface;
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
    interface.show();
    return a.exec();
}
