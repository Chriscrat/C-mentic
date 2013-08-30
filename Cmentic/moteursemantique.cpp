#include "windowcmentic.h"
#include "moteursemantique.h"
#include "ui_windowcmentic.h"
#include "connexion.h"
#include <vector>
#include <iostream>
#include <string>
#include <QMessageBox>

using namespace std;

    QString result="";

moteurSemantique::moteurSemantique()
{
    con = new Connexion();

}

vector< vector<string> > moteurSemantique::decomposerTexte(std::string texte)
{
    //DECOMPOSITION DES PHRASES EN VECTOR 2 DIMENSIONS
    //1ERE DIMENSION : LIGNES
    //2EME DIMENSION : MOT

    string delimiter1 = ".";
    string delimiter3 = " ";
    string token0;
    string token1;
    string phraseASuivre;

    size_t pos = 0;
    size_t posA = 0;
    size_t posB = 0;
    size_t posC = 0;

    vector< vector<string> > listePhrases;
    vector<string> phrase;

    //std::string::npos => jusqu'à la fin de la chaine
    //Ici, on décompose les phrases que l'on ajoute à un vector a 2 dimensions
    //Les lignes = phrases, colonne = mot

    while ((pos = texte.find(delimiter1)) != -1)
    {
        posA = 0;
        posB = 0;
        //On vide la phrase coourante pour ne garder que la nouvelle
        phrase.clear();
        posC = 0;
        token0 = texte.substr(posC, pos);
        //supppression doublons ici

        try
        {
            phraseASuivre = texte.substr(pos+2);
        }
        catch(exception e)
        {
            phraseASuivre.clear();
        }

        while ((posA = token0.find(delimiter3)) != std::string::npos)
        {
            token1 = token0.substr(posB, posA);
            phrase.push_back(token1);
            token0.erase(0, posA + delimiter3.length());
            posB = 0;
        }
        phrase.push_back(token0);
        listePhrases.push_back(phrase);
        token0.erase(0, pos + delimiter3.length());
        posC = pos+2;
        texte = phraseASuivre;
    }
    return listePhrases;
}

void moteurSemantique::startMoteurSemantique(QTextEdit *&TextEditOriginal,QTextEdit *&TextEditSoupcon, QTextEdit *&texteResult, QDoubleSpinBox *&seuil, QLabel *&scoreCP, QLabel *&scoreS, QLabel *&scoreV, QLabel *&scoreT)
{
    bool estPlagie=false;
    float scoreCopyPaste, scoreTestSynonyme, scoreTestVerbe;
    scoreCopyPaste = testCopyPaste(TextEditOriginal,TextEditSoupcon);
    scoreTestSynonyme = testSynonyme(TextEditOriginal,TextEditSoupcon);
    scoreTestVerbe = testVerbe(TextEditOriginal,TextEditSoupcon);

    double seuilPlagiat = seuil->value();
    float scorePlagiat = (scoreCopyPaste + scoreTestSynonyme + scoreTestVerbe) / 3;

    cout << "Recapitulatif des scores de plagiat " << endl;
    cout << " - Par copier/coller : " << scoreCopyPaste << "%" << endl;
    cout << " - Par emploi de synonyme : " << scoreTestSynonyme << "%" << endl;
    cout << " - Par changement des temps : " << scoreTestVerbe << "%" << endl;
    cout << "Ce qui équivaut à un total de " << scorePlagiat << "% de texte susceptible d'etre plagie" << endl;

    QString sCP, sS, sV, sT;
    sCP.setNum(scoreCopyPaste,'f');
    sS.setNum(scoreTestSynonyme,'f');
    sV.setNum(scoreTestVerbe,'f');
    sT.setNum(scorePlagiat,'f');

    scoreCP->setText(sCP+"%");
    scoreS->setText(sS+"%");
    scoreV->setText(sV+"%");
    scoreT->setText(sT+"%");
    colorPlagiat(texteResult);

    if(scorePlagiat>seuilPlagiat)
        estPlagie=true;

    QMessageBox msgBox;
    msgBox.setText("Le texte analyse s'avere être un plagiat");
    if(!estPlagie)
    {
         msgBox.setText("Ce texte est authentique");
    }
    msgBox.exec();
}

float moteurSemantique::testCopyPaste(QTextEdit *&TextEditOriginal,QTextEdit *&TextEditSoupcon)
{
    float scorePlagiat=0.0;
    int nbMot=0;
    string texteOriginal = TextEditOriginal->toPlainText().toLower().toStdString();
    string texteSoupconPlagiat = TextEditSoupcon->toPlainText().toLower().toStdString();
    vector< vector<string> > listeTexteOriginal;
    vector< vector<string> > listeTexteSoupconPlagiat;    

    //Methode pour retirer les mot de liaison : ICI
    listeTexteOriginal= decomposerTexte(texteOriginal);
    listeTexteSoupconPlagiat = decomposerTexte(texteSoupconPlagiat);
    result = texteSoupconPlagiat.c_str();

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
                for(size_t l=0; l<listeTexteSoupconPlagiat[j].size(); l++)
                {
                    nbMot=listeTexteSoupconPlagiat[j].size();
                    if(listeTexteOriginal[i][k] == listeTexteSoupconPlagiat[j][l])
                    {
                        nbPlagiat++;
                        nbPlagiatTotal++;
                    }
                }
                QString match = QString::fromStdString(listeTexteOriginal[i][k]);
                cout << match.toStdString() << endl;
                result = result.replace(match,"<r> "+QString::fromStdString(listeTexteOriginal[i][k])+"</r>");
            }
        }
    }
    cout << " Rendu après traitement : " << result.toStdString() << endl;
    scorePlagiat = (float(nbPlagiatTotal)/nbMot)*100;
    return scorePlagiat;
}

float moteurSemantique::testSynonyme(QTextEdit *&TextEditOriginal,QTextEdit *&TextEditSoupcon)
{
    float scorePlagiat=0.0;
    int nbMot=0;
    string texteOriginal = TextEditOriginal->toPlainText().toLower().toStdString();
    string texteSoupconPlagiat = result.toStdString();
    vector< vector<string> > listeTexteOriginal;
    vector< vector<string> > listeTexteSoupconPlagiat;

    //Methode pour retirer les mot de liaison : ICI
    listeTexteOriginal= decomposerTexte(texteOriginal);
    listeTexteSoupconPlagiat = decomposerTexte(texteSoupconPlagiat);

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
                for(size_t l=0; l<listeTexteSoupconPlagiat[j].size(); l++)
                {
                    nbMot=listeTexteSoupconPlagiat[j].size();
                    if(con->isSynonyme(listeTexteSoupconPlagiat[j][l],listeTexteOriginal[i][k]))
                    {
                        QString match = QString::fromStdString(listeTexteSoupconPlagiat[j][l]);
                        result = result.replace(match,"<bl> "+QString::fromStdString(listeTexteSoupconPlagiat[j][l])+"</bl>");
                        nbPlagiat++;
                        nbPlagiatTotal++;
                    }
                }
            }
        }
    }
    scorePlagiat = (float(nbPlagiatTotal)/nbMot)*100;
    cout << TextEditSoupcon->toPlainText().toLower().toStdString() << endl;
    return scorePlagiat;
}

float moteurSemantique::testVerbe(QTextEdit *&TextEditOriginal,QTextEdit *&TextEditSoupcon)
{
    return 60.0f;
}

void moteurSemantique::colorPlagiat(QTextEdit *&Text)
{
    result = result.replace("<bl> ","<font color='blue'>");
    result = result.replace("<r> ","<font color='red'>");
    result = result.replace("</r> ","</font> ");
    result = result.replace("</bl> ","</font> ");
    cout << result.toStdString() << endl;
    Text->clear();
    Text->setTextColor(QColor("black"));
    Text->insertHtml(result);

}
