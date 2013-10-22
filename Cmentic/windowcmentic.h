#ifndef WINDOWCMENTIC_H
#define WINDOWCMENTIC_H
#include <QWidget>
#include <QString>
#include <vector>

using namespace std;

namespace Ui
{
    class WindowCmentic;
}

class WindowCmentic : public QWidget
{
    Q_OBJECT
    
    public:
        explicit WindowCmentic(QWidget *parent = 0);
        ~WindowCmentic();

    public slots:
       void getText();


    private:
        Ui::WindowCmentic *ui;

};

#endif // WINDOWCMENTIC_H
