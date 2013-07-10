#ifndef MOTEURSEMANTIQUE_H
#define MOTEURSEMANTIQUE_H
#include <vector>
#include <iostream>

using namespace std;

class MoteurSemantique
{
public:
    MoteurSemantique();
    vector< vector<string> > decomposerTexte(string texte);

};

#endif // MOTEURSEMANTIQUE_H
