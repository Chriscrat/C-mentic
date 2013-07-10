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
    /*vector<string> contenuTextes = interface.getText();

    cout<<"hello"<<endl;
    for(size_t i=0;i<contenuTextes.size(); i++)
    {
        cout<<contenuTextes[i]<<endl;
    }*/

    return a.exec();
}
