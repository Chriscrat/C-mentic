#include "windowcmentic.h"
#include "ui_windowcmentic.h"
#include <QMessageBox>

WindowCmentic::WindowCmentic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WindowCmentic)
{
    ui->setupUi(this);
    connect(ui->btnQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(ui->btnStart, SIGNAL(clicked()), this, SLOT(afficher()));
}

WindowCmentic::~WindowCmentic()
{
    delete ui;
}

void WindowCmentic::afficher()
{
    QMessageBox msgBox;
    msgBox.setText(ui->txTest->toPlainText());
    msgBox.exec();
}
