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
    //DECOMPOSITION DES PHRASES EN VECTOR 2 DIMENSIONS
    //1ERE DIMENSION : LIGNES
    //2EME DIMENSION : MOT
    //con->isIrregularVerb("paraissez");
    //con->getFirstGroupVerbs("utilisons");
   // cout<<"Sortie vaut:"<<testVerbeOneWord("ajouter")<<endl;

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
            //cout<<"Sortie1:"<<phrasesOriginales[i]<<endl;
            //cout<<"Sortie2"<<phrasesSoupcon[j]<<endl;

            phrasesOriginales[i] = boost::trim_left_copy(phrasesOriginales[i]);
            phrasesOriginales[i] = boost::trim_right_copy(phrasesOriginales[i]);
            phrasesSoupcon[j] = boost::trim_left_copy(phrasesSoupcon[j]);
            phrasesSoupcon[j] = boost::trim_right_copy(phrasesSoupcon[j]);

            if(phrasesOriginales[i]!="" && phrasesSoupcon[j]!="")
            {
                if(phrasesOriginales[i] == phrasesSoupcon[j])
                {
                    cout<<"phrase copiee!"<<endl;
                    nbPlagiat++;
                }
            }
        }
    }
    cout<<"nb phrases du texte:"<<(phrasesSoupcon.size()-1)<<endl;
    cout<<"nb plagiats releves:"<<nbPlagiat<<endl;

    scorePlagiat = (float(nbPlagiat)/(phrasesSoupcon.size()-1)*100);

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
    if(nbPlagiatTotal==0)
    {
        scorePlagiat = 0;
    }
    else
    {
        scorePlagiat = (float(nbPlagiatTotal)/nbMot)*100;
    }

    cout << TextEditSoupcon->toPlainText().toLower().toStdString() << endl;
    return scorePlagiat;
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
    QVector<string> bdd;
    vector< vector<string> > texteSortie;
    vector<string> ligneSortie;
    bdd.append("au");
    bdd.append("de");
    bdd.append("la");

    for(int i=0; i<texte.size();i++)
    {
        for(int j=0; j<texte[i].size();j++)
        {
            for(int k=0; k<bdd.size();k++)
            {
                if(bdd[k].compare(texte[i][j])==0)
                {
                    cout<<texte[i][j]<<endl;
                    cout<<bdd[k]<<endl;
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
                cout<<"res:"<<texte[l][m]<<endl;
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
    string retourMotOrig;
    string retourMotSoupcon;
    string retourCompteurVerbes;

    string texteOriginal = TextEditOriginal->toPlainText().toLower().toStdString();
    string texteSoupconPlagiat = TextEditSoupcon->toPlainText().toLower().toStdString();

    vector< vector<string> > listeTexteOriginal;
    vector< vector<string> > listeTexteSoupconPlagiat;

    int nbMot=0;
    int nbVerbesTexteAnalyse=0;
    int nbVerbesPlagies=0;
    float scorePlagiat=0.0;

    listeTexteOriginal= decomposerTexte(texteOriginal);
    listeTexteOriginal = deleteLinkWords(listeTexteOriginal);

    listeTexteSoupconPlagiat = decomposerTexte(texteSoupconPlagiat);
    listeTexteSoupconPlagiat = deleteLinkWords(listeTexteSoupconPlagiat);

    //Compter le nombre de verbes du texte plagié
    for(size_t h=0; h<listeTexteSoupconPlagiat.size(); h++)
    {
        for(size_t g=0; g<listeTexteSoupconPlagiat[h].size();g++)
        {
            retourCompteurVerbes = testVerbeOneWord(listeTexteSoupconPlagiat[h][g]);
            if(!retourCompteurVerbes.empty())
            {
                nbVerbesTexteAnalyse++;
            }
        }
    }


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

                    retourMotOrig = testVerbeOneWord(listeTexteOriginal[i][k]);
                    retourMotSoupcon = testVerbeOneWord(listeTexteSoupconPlagiat[j][l]);

                    if(!(retourMotOrig.empty()&& retourMotSoupcon.empty()))
                    {
                        if(retourMotOrig == retourMotSoupcon)
                        {
                            cout<<"verbe soupcon plagié"<<endl;
                            cout<<"verbe soupcon:"<<retourMotSoupcon<<endl;
                            cout<<"verbe orig:"<<retourMotOrig<<endl;
                            nbVerbesPlagies++;
                        }
                    }
                    retourMotOrig="";
                    retourMotSoupcon="";
                }
            }
        }
        cout<<"Nombre de verbes du texte:"<<nbVerbesTexteAnalyse<<endl;
        cout<<"Nombre de verbes plagies:"<<nbVerbesPlagies<<endl;
        //cout<<"Pourcentage de verbes plagiés:"<<((nbVerbesPlagies/nbVerbesTexteAnalyse)*100)<<"%"<<endl;
        if(nbVerbesPlagies==0 && nbVerbesTexteAnalyse == 0)
        {
            scorePlagiat = 0;
        }
        else
        {
            scorePlagiat = (float(nbVerbesPlagies)/nbVerbesTexteAnalyse)*100;
        }
    }
    return scorePlagiat;
}

string moteurSemantique::testVerbeOneWord(string mot)
{
    string retour="";

    retour = con->wordOrVerb(mot);
    cout<<"Retour1:"<<retour<<endl;
    if(retour.empty())
    {
        retour = con->isIrregularVerb(mot);
        cout<<"Retour2:"<<retour<<endl;

        if(retour.empty())
        {
            retour= con->getFirstGroupVerbs(mot);
            cout<<"Retour3:"<<retour<<endl;
        }
    }
    else
    {
        retour = "";
    }
    return retour;
}







