#ifndef MOTEURSEMANTIQUE_H
#define MOTEURSEMANTIQUE_H
#include <vector>
#include <iostream>
#include "windowcmentic.h"
#include "connexion.h"
#include "QTextEdit"
using namespace std;
class moteurSemantique
{
    public:
        Connexion *con;
        moteurSemantique();
        vector< vector<string> > decomposerTexte(std::string texte);
        void startMoteurSemantique(QTextEdit *&texteOriginal, QTextEdit *&texteDouteux);
        float testCopyPaste(QTextEdit *&texteOriginal, QTextEdit *&texteDouteux);
        float testSynonyme(QTextEdit *&texteOriginal, QTextEdit *&texteDouteux);
        float testVerbe(QTextEdit *&texteOriginal, QTextEdit *&texteDouteux);

};

#endif // MOTEURSEMANTIQUE_H
