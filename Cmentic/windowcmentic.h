#ifndef WINDOWCMENTIC_H
#define WINDOWCMENTIC_H

#include <QWidget>
#include <QString>

namespace Ui {
class WindowCmentic;
}

class WindowCmentic : public QWidget
{
    Q_OBJECT
    
public:
    explicit WindowCmentic(QWidget *parent = 0);
    ~WindowCmentic();


public slots:
    void afficher();
    
private:
    Ui::WindowCmentic *ui;
};

#endif // WINDOWCMENTIC_H
