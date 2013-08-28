#include "windowcmentic.h"
#include "moteursemantique.h"
#include "ui_windowcmentic.h"
#include "connexion.h"
#include <stdexcept>
#include <vector>
#include <iostream>
#include <string>
#include <QMessageBox>
#include <boost/algorithm/string/predicate.hpp>
using namespace std;


moteurSemantique::moteurSemantique()
{
    con = new Connexion();
}

void moteurSemantique::startMoteurSemantique(QTextEdit *&TexteOriginal,QTextEdit *&TexteSoupcon)
{
    bool estPlagie=false;
    float scoreCopyPaste, scoreTestSynonyme, scoreTestVerbe;
    scoreCopyPaste = testCopyPaste(TexteOriginal,TexteSoupcon);
    scoreTestSynonyme = testSynonyme(TexteOriginal,TexteSoupcon);
    scoreTestVerbe = testVerbe(TexteOriginal,TexteSoupcon);


    float scorePlagiat = (scoreCopyPaste + scoreTestSynonyme + scoreTestVerbe) / 3;

    cout << "Recapitulatif des scores de plagiat " << endl;
    cout << " - Par copier/coller : " << scoreCopyPaste << "%" << endl;
    cout << " - Par emploi de synonyme : " << scoreTestSynonyme << "%" << endl;
    cout << " - Par changement des temps : " << scoreTestVerbe << "%" << endl;
    cout << "Ce qui équivaut à un total de " << scorePlagiat << "% de texte susceptible d'etre plagie" << endl;


    if(scorePlagiat>60)
        estPlagie=true;

    QMessageBox msgBox;
    msgBox.setText("Le texte analyse s'avere être un plagiat");
    if(!estPlagie)
    {
         msgBox.setText("Ce texte est authentique");
    }
    //msgBox.exec();
}

vector< vector<string> > moteurSemantique::decomposerTexte(std::string texte)
{
    //DECOMPOSITION DES PHRASES EN VECTOR 2 DIMENSIONS
    //1ERE DIMENSION : LIGNES
    //2EME DIMENSION : MOT

    string delimiter1 = ".";
    string delimiter2 = ".";
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
        catch( std::out_of_range& exception )
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

float moteurSemantique::testCopyPaste(QTextEdit *&TexteOriginal,QTextEdit *&TexteSoupcon)
{
    float scorePlagiat=0.0;
    int nbMot=0;
    string expression;
    size_t position=0;
    string texteOriginal = TexteOriginal->toPlainText().toLower().toStdString();;
    string texteSoupconPlagiat = TexteSoupcon->toPlainText().toLower().toStdString();
    string BeginHtmlColor ="<font color=\"red\">";
    string EndHtmlColor ="</font>";
    vector< vector<string> > listeTexteOriginal;
    vector< vector<string> > listeTexteSoupconPlagiat;    
    QString result = texteSoupconPlagiat.c_str();
    //Methode pour retirer les mot de liaison : ICI
    cout << "Mots originaux : " << texteOriginal << " et mots douteux " << texteSoupconPlagiat << endl;
    listeTexteOriginal= decomposerTexte(texteOriginal);
    listeTexteSoupconPlagiat = decomposerTexte(texteSoupconPlagiat);

    int nbPlagiatTotal = 0;
    cout<<"Nombre de lignes texte original:"<<listeTexteOriginal.size()<<endl;
    cout<<"Nombre de lignes texte original:"<<listeTexteSoupconPlagiat.size()<<endl;
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
                        cout<<"phrase "<<i+1<<" original : " << listeTexteOriginal[i][k]<<endl;
                        cout<<"phrase "<<j+1<<" plagiat : " << listeTexteSoupconPlagiat[j][l]<<endl;


                        /*
                        position = texteSoupconPlagiat.find(listeTexteSoupconPlagiat[j][l],position);
                        int wordSize = listeTexteSoupconPlagiat[j][l].size();
                        cout << "Position trouvee : " << position << endl;
                        cout << "Taille trouvee : " << wordSize << endl;
                        texteSoupconPlagiat.insert(position, BeginHtmlColor);
                        position = texteSoupconPlagiat.find(listeTexteSoupconPlagiat[j][l]);
                        texteSoupconPlagiat.insert((position+wordSize), EndHtmlColor);
                        cout << texteSoupconPlagiat << endl;
                        position++;
                        */

                        nbPlagiat++;
                        nbPlagiatTotal++;

                    }
                }
                QString match = QString::fromStdString(listeTexteOriginal[i][k]);
                result = result.replace(match,"<font color='red'>"+QString::fromStdString(listeTexteOriginal[i][k])+"</font>");
                cout << "affichage du test : " << result.toStdString() << endl;
                /*result = result.replace(regReplace,"<font color='red'>\\1</font>");
                cout << "test de remplacement de : "+ exp.toStdString() + " par <font color='red'>\\1</font> \n" + result.toStdString() << endl;*/

            }
        }
    }
    cout<<"Au total:"<<nbPlagiatTotal<<" plagiats ont ete releves."<<endl;
    //scorePlagiat = (float(nbPlagiatTotal)/nbMot)*100;
    scorePlagiat = (float(nbPlagiatTotal)/listeTexteOriginal.size())*100;
    cout<<"Score en % de mot plagie : "<<scorePlagiat<<"%"<<endl;

    TexteSoupcon->clear();
    TexteSoupcon->setTextColor(QColor("black"));
    TexteSoupcon->insertHtml(result);
    return scorePlagiat;
}

float moteurSemantique::testSynonyme(QTextEdit *&TexteOriginal,QTextEdit *&TexteSoupcon)
{
    /*float scorePlagiat=0.0;
    int nbMot=0;
    int position=0;
    string texteOriginal = TexteOriginal->toPlainText().toLower().toStdString();;
    string texteSoupconPlagiat = TexteSoupcon->toPlainText().toLower().toStdString();
    string BeginHtmlColor ="<font color=\"red\">";
    string EndHtmlColor ="</font>";
    vector< vector<string> > listeTexteOriginal;
    vector< vector<string> > listeTexteSoupconPlagiat;

    //Methode pour retirer les mot de liaison : ICI
    cout << "Mots originaux : " << texteOriginal << " et mots douteux " << texteSoupconPlagiat << endl;
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
                    if(listeTexteOriginal[i][k] == listeTexteSoupconPlagiat[j][l])
                    {

                        cout<<"phrase "<<i+1<<" original : "<<listeTexteOriginal[i][k]<<endl;
                        cout<<"phrase "<<j+1<<" plagiat : "<<listeTexteSoupconPlagiat[j][l]<<endl;
                        position = texteSoupconPlagiat.find(listeTexteSoupconPlagiat[j][l],position);
                        int wordSize = listeTexteSoupconPlagiat[j][l].size();
                        cout << "Position trouvee : " << position << endl;
                        cout << "Taille trouvee : " << wordSize << endl;
                        texteSoupconPlagiat.insert(position, BeginHtmlColor);
                        position = texteSoupconPlagiat.find(listeTexteSoupconPlagiat[j][l]);
                        texteSoupconPlagiat.insert((position+wordSize), EndHtmlColor);
                        cout << texteSoupconPlagiat << endl;
                        nbPlagiat++;
                        nbPlagiatTotal++;
                        position++;
                    }
                }
            }
        }
    }
    cout<<"Au total:"<<nbPlagiatTotal<<" plagiats ont ete releves."<<endl;
    scorePlagiat = (float(nbPlagiatTotal)/nbMot)*100;
    cout<<"Score en % de mot plagie : "<<scorePlagiat<<"%"<<endl;

    QString result = texteSoupconPlagiat.c_str();
    TexteSoupcon->clear();
    TexteSoupcon->insertHtml(result);
    return scorePlagiat;*/

    return 60.0f;
}

float moteurSemantique::testVerbe(QTextEdit *&TexteOriginal,QTextEdit *&TexteSoupcon)
{
    /*Connexion con;
    QVector<string> groupList = con.getGroupList();
    cout<<"Parcours de la liste groupList:"<<endl;
    for(size_t i=0; i<groupList.size();i++)
    {
        cout<<groupList[i]<<endl;
    }*/

    //test

    return 60.0f;
}

string moteurSemantique::getBaseVerbe(string mot)
{
    //Partie SQL a réaliser par Florian
    //instance Connexion
    //SQL : select base from verbe;

    //Placer le retour SQL dans basesVerbes
    //QVector<string> basesVerbes = retour SQL;

    QVector<string> basesVerbes;
    basesVerbes.append("interess");
    basesVerbes.append("programm");
    basesVerbes.append("utilis");

    bool trouve = false;
    string baseVerbe;

    for(int i=0; i<basesVerbes.size();i++)
    {
        if(boost::algorithm::contains(mot, basesVerbes[i]))
        {
            trouve = true;
            baseVerbe = basesVerbes[i];
        }
    }
       return baseVerbe;
}

string moteurSemantique::getTerminaisonVerbe(string mot)
{
    string baseVerbe = getBaseVerbe(mot);
    string terminaison = mot.substr(baseVerbe.length(),(mot.length()-baseVerbe.length()));
    return terminaison;
}
