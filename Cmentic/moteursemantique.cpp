#include "windowcmentic.h"
#include "moteursemantique.h"
#include "ui_windowcmentic.h"
#include "connexion.h"
#include <vector>
#include <iostream>
#include <string>
#include <QMessageBox>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/algorithm/string.hpp>
using namespace std;

    QString result="";

moteurSemantique::moteurSemantique()
{
    con = new Connexion();
}

vector<string> moteurSemantique::decomposerPhrase(string texte)
{
    vector<string> vec;
    string delimiters =".\t";
    boost::split(vec, texte, boost::is_any_of(delimiters));
    return vec;
}

vector< vector<string> > moteurSemantique::decomposerTexte(std::string texte)
{
    vector<vector<string>> result;
    vector<string> lines;
    boost::split(lines, texte, boost::is_any_of("\n"));

    for (int i = 0; i < lines.size(); ++i) {
        vector<string> mots;
        boost::split(mots, lines[i], boost::is_any_of(". \t"));
        result.insert(result.end(), mots);
    }

    return result;
}

void moteurSemantique::startMoteurSemantique(QTextEdit *&TextEditOriginal,QTextEdit *&TextEditSoupcon, QTextEdit *&texteResult, QDoubleSpinBox *&seuil, QLabel *&scoreCP, QLabel *&scoreS, QLabel *&scoreV, QLabel *&scoreT)
{
    bool estPlagie=false;
    float scoreCopyPaste, scoreTestSynonyme, scoreTestVerbe;

    scoreCopyPaste = testCopyPaste(TextEditOriginal,TextEditSoupcon);
    scoreTestSynonyme = testSynonyme(TextEditOriginal,TextEditSoupcon);
    scoreTestVerbe = testVerbe(TextEditOriginal,TextEditSoupcon);

    double seuilPlagiat = seuil->value();

    // Calcul du score
    float sum = 0;
    float count = 0;
    if (scoreCopyPaste >= 0)
    {
        sum += scoreCopyPaste;
        count++;
    }
    if (scoreTestSynonyme >= 0)
    {
        sum += scoreTestSynonyme;
        count++;
    }
    if (scoreTestVerbe >= 0)
    {
        sum += scoreTestVerbe;
        count++;
    }

    if (count == 0) count = 1;

    float scorePlagiat = sum / count;

    cout << "Recapitulatif des scores de plagiat " << endl;
    cout << " - Par copier/coller : " << scoreCopyPaste << "%" << endl;
    cout << " - Par emploi de synonyme : " << scoreTestSynonyme << "%" << endl;
    cout << " - Par changement des temps : " << scoreTestVerbe << "%" << endl;
    cout << "Ce qui équivaut à un total de " << scorePlagiat << "% de texte susceptible d'etre plagie" << endl;

    QString sCP, sS, sV, sT;
    sCP.setNum(scoreCopyPaste == -1 ? 0 : scoreCopyPaste,'f');
    sS.setNum(scoreTestSynonyme == -1 ? 0 : scoreTestSynonyme,'f');
    sV.setNum(scoreTestVerbe == -1 ? 0 : scoreTestVerbe,'f');
    sT.setNum(scorePlagiat,'f');

    scoreCP->setText(sCP+"%");
    scoreS->setText(sS+"%");
    scoreV->setText(sV+"%");
    scoreT->setText(sT+"%");
    colorPlagiat(texteResult);

    if(scorePlagiat>seuilPlagiat)
        estPlagie=true;

    QMessageBox msgBox;
    msgBox.setText("Le texte analyse est un plagiat.");
    if(!estPlagie)
    {
         msgBox.setText("Ce texte est authentique.");
    }
    msgBox.exec();
}

float moteurSemantique::testCopyPaste(QTextEdit *&TextEditOriginal,QTextEdit *&TextEditSoupcon)
{
    vector<string> phrasesOriginales;
    vector<string> phrasesSoupcon;

    float scorePlagiat=0.0;
    int nbMots = 0;
    int nbPlagiat = 0;

    string texteOriginal = TextEditOriginal->toPlainText().toLower().toStdString();
    string texteSoupconPlagiat = TextEditSoupcon->toPlainText().toLower().toStdString();

    phrasesOriginales = decomposerPhrase(texteOriginal);
    phrasesSoupcon = decomposerPhrase(texteSoupconPlagiat);

    for(int i=0; i<phrasesOriginales.size(); i++)
    {
        for(int j=0; j<phrasesSoupcon.size(); j++)
        {
            phrasesOriginales[i] = boost::trim_left_copy(phrasesOriginales[i]);
            phrasesOriginales[i] = boost::trim_right_copy(phrasesOriginales[i]);
            phrasesSoupcon[j] = boost::trim_left_copy(phrasesSoupcon[j]);
            phrasesSoupcon[j] = boost::trim_right_copy(phrasesSoupcon[j]);

            if(phrasesOriginales[i]!="" && phrasesSoupcon[j]!="")
            {
                if(phrasesOriginales[i] == phrasesSoupcon[j])
                {
                    nbPlagiat++;
                }
            }
        }
    }

    scorePlagiat = nbPlagiat == 0 ? -1 : (float(nbPlagiat)/(phrasesSoupcon.size())*100);

    return scorePlagiat;
}

float moteurSemantique::testSynonyme(QTextEdit *&TextEditOriginal,QTextEdit *&TextEditSoupcon)
{
    float scorePlagiat=0.0;
    int nbMot=0;
    string texteOriginal = TextEditOriginal->toPlainText().toLower().toStdString();
    string texteSoupconPlagiat = TextEditSoupcon->toPlainText().toLower().toStdString();
    //string texteSoupconPlagiat = result.toStdString();
    vector< vector<string> > listeTexteOriginal;
    vector< vector<string> > listeTexteSoupconPlagiat;

    //Methode pour retirer les mot de liaison : ICI
    listeTexteOriginal= decomposerTexte(texteOriginal);
    listeTexteOriginal = deleteLinkWords(listeTexteOriginal);

    listeTexteSoupconPlagiat = decomposerTexte(texteSoupconPlagiat);
    listeTexteSoupconPlagiat = deleteLinkWords(listeTexteSoupconPlagiat);

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
                    if(isSynonyme(listeTexteSoupconPlagiat[j][l],listeTexteOriginal[i][k]))
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
    if(nbPlagiatTotal==0)
    {
        scorePlagiat = -1;
    }
    else
    {
        scorePlagiat = (float(nbPlagiatTotal)/nbMot)*100;
    }

    return scorePlagiat;
}

bool moteurSemantique::isSynonyme(string s1, string s2)
{
    // TODO : Système de cache pour ne pas appeler autant la BDD
    return con->getSynonymes(s1).contains(s2);
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

//JULIEN
vector< vector<string> > moteurSemantique::deleteLinkWords(vector< vector<string> > texte)
{
    QVector<string> bdd = con->getMotLiaison();
    vector< vector<string> > texteSortie;
    vector<string> ligneSortie;

    for(int i=0; i<texte.size();i++)
    {
        for(int j=0; j<texte[i].size();j++)
        {
            for(int k=0; k<bdd.size();k++)
            {
                if(bdd[k].compare(texte[i][j])==0)
                {
                    texte[i][j].erase();
                }
            }
        }
    }
    for(int l=0; l<texte.size();l++)
    {
        for(int m=0; m<texte[l].size();m++)
        {
            if(!texte[l][m].empty())
            {
                ligneSortie.push_back(texte[l][m]);
            }
        }
        texteSortie.push_back(ligneSortie);
        ligneSortie.clear();

    }
    return texteSortie;
}


//JULIEN
int moteurSemantique::getNbMotsTexte(vector< vector<string> > texte)
{
    int nbMots;
    for(int i=0; i<texte.size();i++)
    {
        for(int j=0; j<texte[i].size();j++)
        {
            nbMots++;
        }
    }
    return nbMots;

}

float moteurSemantique::testVerbe(QTextEdit *&TextEditOriginal,QTextEdit *&TextEditSoupcon)
{
    int nbVerbes = 0;
    int nbVerbesPareils = 0;

    string texteOriginal = TextEditOriginal->toPlainText().toLower().toStdString();
    string texteSoupconPlagiat = TextEditSoupcon->toPlainText().toLower().toStdString();

    vector< vector<string> > listeTexteOriginal= decomposerTexte(texteOriginal);
    listeTexteOriginal = deleteLinkWords(listeTexteOriginal);

    vector< vector<string> > listeTexteSoupconPlagiat = decomposerTexte(texteSoupconPlagiat);
    listeTexteSoupconPlagiat = deleteLinkWords(listeTexteSoupconPlagiat);

    QVector<string> terminaisons = con->getTerminaisonsPossibles();

    for (int idxLigneOriginal = 0; idxLigneOriginal < listeTexteOriginal.size(); ++idxLigneOriginal) {
        for (int idxMotOriginal = 0; idxMotOriginal < listeTexteOriginal[idxLigneOriginal].size(); ++idxMotOriginal) {
            // Pour chaque mot

            QVector<string> basesVerbePossible;

            // Si on trouve une terminaison
            for (int i = 0; i < terminaisons.size(); ++i) {
                if (boost::algorithm::ends_with(listeTexteOriginal[idxLigneOriginal][idxMotOriginal], terminaisons[i])){
                    basesVerbePossible.append(listeTexteOriginal[idxLigneOriginal][idxMotOriginal].substr(0, listeTexteOriginal[idxLigneOriginal][idxMotOriginal].size() - terminaisons[i].size()));
                }
            }

            QVector<string> conjugaisons;

            // Pour chaque base possible, vérifier si c'est bien un verbe et récupérer ses conjugaisons (on garde le premier trouvé)
            for (int i = 0; i < basesVerbePossible.size(); ++i) {
                QVector<string> possibleConjugaisons = con->getConjugaisons(basesVerbePossible[i]);
                if (possibleConjugaisons.size() > 0)
                {
                    conjugaisons = possibleConjugaisons;
                    // Pas trouvé d'autres moyens pour sortir de la boucle
                    i = basesVerbePossible.size();
                }
            }

            // Si le mot testé n'est pas un verbe "normal" on test s'il est irrégulier
            if (conjugaisons.size() == 0)
            {
                QVector<string> possibleConjugaisons = con->getConjugaisonsIrregulier(listeTexteOriginal[idxLigneOriginal][idxMotOriginal]);
                if (possibleConjugaisons.size() > 0)
                {
                    conjugaisons = possibleConjugaisons;
                }
            }

            // Si le mot est un verbe (irrégulier ou pas)
            if (conjugaisons.size() > 0)
            {
                nbVerbes++;

                for (int idxConjug = 0; idxConjug < conjugaisons.size(); ++idxConjug) {
                    for (int idxLigneSoupcon = 0; idxLigneSoupcon < listeTexteSoupconPlagiat.size(); ++idxLigneSoupcon) {
                        for (int idxMotSoupcon = 0; idxMotSoupcon < listeTexteSoupconPlagiat[idxLigneSoupcon].size(); ++idxMotSoupcon) {
                            // Si un mot dans le deuxième texte est identique, on dit qu'il est plagié
                            if (conjugaisons[idxConjug] == listeTexteSoupconPlagiat[idxLigneSoupcon][idxMotSoupcon])
                            {
                                nbVerbesPareils++;
                            }
                        }
                    }
                }
            }

        }
    }

    return nbVerbesPareils == 0 ? -1 : float(nbVerbesPareils)/nbVerbes * 100;
}
