#include "windowcmentic.h"
#include "moteursemantique.h"
#include "ui_windowcmentic.h"
#include <QMessageBox>
#include <vector>
#include <iostream>
using namespace  std;

WindowCmentic::WindowCmentic(QWidget *parent) : QWidget(parent),ui(new Ui::WindowCmentic)
{
    ui->setupUi(this);
    connect(ui->btnQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
    //Lors d'un clic sur btnStart, on appelle la méthode afficher()
    connect(ui->btnStart, SIGNAL(clicked()), this, SLOT(getText()));
}

WindowCmentic::~WindowCmentic()
{
    delete ui;
}

void WindowCmentic::getText()
{
    vector<string> contenuTextbox;
    contenuTextbox.push_back(ui->texteOriginal->toPlainText().toLower().toStdString());
    contenuTextbox.push_back(ui->texteSoupconne->toPlainText().toLower().toStdString());
    moteurSemantique *ms = new moteurSemantique();
    ms->startMoteurSemantique(ui->texteOriginal,  ui->texteSoupconne, ui->texteResult, ui->doubleSpinBox, ui->scoreCP, ui->scoreS, ui->scoreV, ui->scoreT);
}


