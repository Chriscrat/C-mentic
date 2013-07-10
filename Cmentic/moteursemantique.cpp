#include "moteursemantique.h"
#include "windowcmentic.h"
#include <stdexcept>
#include <vector>
#include <iostream>
using namespace std;

moteurSemantique::moteurSemantique()
{

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
    //DECOMPOSITION DES PHRASES EN LISTE
    return listePhrases;
}

void moteurSemantique::startMoteurSemantique()
{
        //ALGO SERA DEROULE ICI
        moteurSemantique ms;

        //deleteDoublonsWord(phraseTest);

        string texteOriginal = "verbes troisieme groupe verbes irreguliers.";
        string texteSoupconPlagiat = "en font aussi partie verbes irreguliers. Conjuguer des verbes c'est cool.";
        vector< vector<string> > listeTexteOriginal;
        vector< vector<string> > listeTexteSoupconPlagiat;

        //Methode pour retirer les mot de liaison : ICI

        //ms.decomposerTexte("blabla");
        //
        listeTexteOriginal=ms.decomposerTexte(texteOriginal);
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


