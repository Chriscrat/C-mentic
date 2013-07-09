// Tuto.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

//Méthodes vont ici


vector< vector<string> >& decomposeTexte(string texte){
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

void deleteLinkWordsFromListPhrase(vector< vector<string> >texte)
{
	//SUPPRESSION DES MOTS DE LIAISON DANS PHRASE
	//Existant : listePhrases qui contient toutes les phrases du texte
	//Entree : listePhrases
	//Sortie : listePhrases sans mots de liaison

	//Boucle 1ere dimension (phrase)
		//Boucle 2nd dimension (mot)
			//requete BDD : SELECT mot FROM MotLiaison
			//recuperation du resultat requete
			//Boucle sur resultats requete
				//Si motRequete = mot
				//Supprimer index vector
				vector<string> vec;
				string resultSQL = "la";

				vec.push_back("la");
				vec.push_back("mer");
				vec.push_back("est");
				vec.push_back("la");
				vec.push_back("meilleure");

				//vec.erase(vec.begin() + 1);

				for (size_t i=0; i<vec.size(); i++)
				{
					if(resultSQL==vec[i])
					{
						vec.erase(vec.begin()+i);
					}
				}
	//SUPPRESSION DES MOTS DE LIAISON DANS PHRASE
}


void displayVectorDimension()
{
	//AFFICHAGE VECTOR DEUX DIMENSIONS
	/*for(size_t i=0; i<listePhrases.size(); i++)
	{
		for(size_t j=0; j<listePhrases[i].size(); j++)
		{
			cout<<listePhrases[i][j];
		}
		cout<<endl;
	}*/
	//AFFICHAGE VECTOR DEUX DIMENSIONS
}

void terminaisonSQL()
{
	//PARTIE TERMINAISON + BASE MOT SQL
	string Str("appelerai");
	//Taille de la terminaison, peut être récupérée depuis le retour en SQL
	int n = 4;

	cout <<"Terminaison:"<< Str.substr( Str.size() - n , n)<<endl;
	cout <<"Base du mot:"<< Str.substr(0, Str.size()-n)<<endl;
	//FIN TERMINAISON SQL
}

/*void deleteDoublonsWord(string phrase)
{
	vector<string> newPhrase;
	vector<string> newPhrase2;
	string mot;
	int pos1 = 0;
	int pos2 = 0;

	while ((pos2 = phrase.find(" ")) != -1)
	{
		mot = phrase.substr(pos1, pos2);
		newPhrase.push_back(mot);
		phrase.erase(0, pos2 + 1);
	}
	newPhrase.push_back(phrase);
	newPhrase2 = newPhrase;

	for(size_t i= 0; i<newPhrase.size(); i++)
	{
		for(size_t j=1; newPhrase2.size(); j++)
		{
			//cout<<newPhrase[i]<<endl;
			//cout<<newPhrase[j]<<endl;
			if(newPhrase[i]==newPhrase2[j])
			{
				newPhrase.erase(newPhrase.begin()+i);
			}
		}
	}
	cout<<"yolo"<<endl;
}*/

//vector<vector<string>> decomposeTexte(string texte);
//void deleteDoublonsWord(string phrase);

int main()
{
	string phraseTest = "les verbes irreguliers sont irreguliers";
	//deleteDoublonsWord(phraseTest);

	string texteOriginal = "va manger des nouilles.";
	string texteSoupconPlagiat = "on en fout partout. va manger des nouilles.";
	vector< vector<string> > listeTexteOriginal;
	vector< vector<string> > listeTexteSoupconPlagiat;

	//Methode pour retirer les mot de liaison : ICI

	listeTexteOriginal = decomposeTexte(texteOriginal);
	listeTexteSoupconPlagiat = decomposeTexte(texteSoupconPlagiat);

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

    return 0;
}




