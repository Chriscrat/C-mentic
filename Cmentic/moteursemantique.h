#ifndef MOTEURSEMANTIQUE_H
#define MOTEURSEMANTIQUE_H
#include <vector>
#include <iostream>
#include "windowcmentic.h"

using namespace std;
class moteurSemantique
{
public:
    moteurSemantique();
    vector< vector<string> > decomposerTexte(std::string texte);
    void startMoteurSemantique();
};

#endif // MOTEURSEMANTIQUE_H
