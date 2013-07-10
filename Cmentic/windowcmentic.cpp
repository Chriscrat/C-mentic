#include "windowcmentic.h"
#include "connexion.h"
#include <QMessageBox>
#include <vector>
#include <iostream>
#include "moteursemantique.h"

using namespace  std;

WindowCmentic::WindowCmentic(QWidget *parent) : QWidget(parent),ui(new Ui::WindowCmentic)
{
    ui->setupUi(this);
    connect(ui->btnQuit, SIGNAL(clicked()), qApp, SLOT(quit()));
    //>Lors d'un clic sur btnStart, on appelle mthd afficher()
    connect(ui->btnStart, SIGNAL(clicked()), this, SLOT(getText()));
}

WindowCmentic::~WindowCmentic()
{
    delete ui;
}

vector<string> WindowCmentic::getText()
{
    QMessageBox msgBox;
    msgBox.setText(ui->txTest->toPlainText());
    Connexion *con = new Connexion();
    msgBox.exec();
    vector<string> contenuTextbox;
    contenuTextbox.push_back(ui->texteOriginal->toPlainText().toLower().toStdString());
    contenuTextbox.push_back(ui->texteSoupconne->toPlainText().toLower().toStdString());
    return contenuTextbox;
}

void WindowCmentic::startMoteurSemantique()
{
    //ALGO SERA DEROULE ICI
    MoteurSemantique ms;
        //deleteDoublonsWord(phraseTest);

        string texteOriginal = "verbes troisieme groupe verbes irreguliers.";
        string texteSoupconPlagiat = "en font aussi partie verbes irreguliers. Conjuguer des verbes c'est cool.";
        vector< vector<string> > listeTexteOriginal;
        vector< vector<string> > listeTexteSoupconPlagiat;

        //Methode pour retirer les mot de liaison : ICI

        ms.decomposerTexte("blabla");
        listeTexteOriginal = ms.decomposerTexte(texteOriginal);
        listeTexteSoupconPlagiat = ms.decomposerTexte(texteSoupconPlagiat);

        int nbPlagiatTotal = 0;

        //ligne
        for(size_t i=0; i<listeTexteOriginal.size(); i++)
        {
            //ligne
            for(size_t j=0; j<listeTexteSoupconPlagiat.size(); j++)
            {
                int nbPlagiat = 0;
                //mot
                for(size_t k=0; k<listeTexteOriginal[i].size(); k++)
                {
                    //mot
                    for(size_t l=0; l<listeTexteSoupconPlagiat[j].size(); l++)
                    {
                        if(listeTexteOriginal[i][k] == listeTexteSoupconPlagiat[j][l])
                        {
                            cout<<"phrase"<<i+1<<"original: "<<listeTexteOriginal[i][k]<<endl;
                            cout<<"phrase"<<j+1<<"plagiat: "<<listeTexteSoupconPlagiat[j][l]<<endl;
                            //cout<<"plagiat sur la phrase"<<j+1<<endl;
                            nbPlagiat++;
                            nbPlagiatTotal++;
                        }
                        else
                        {
                            /*cout<<"phrase"<<i+1<<"original: "<<listeTexteOriginal[i][k]<<endl;
                            cout<<"phrase"<<j+1<<"plagiat: "<<listeTexteSoupconPlagiat[j][l]<<endl;
                            cout<<"pas de plagiat"<<endl;
                            cout<<endl;*/
                        }
                    }
                }
                cout<<"plagiat en ligne"<<j+1<<":"<<nbPlagiat<<endl;
            }
        }
        cout<<"Au total:"<<nbPlagiatTotal<<" plagiats ont ete releves."<<endl;
}

