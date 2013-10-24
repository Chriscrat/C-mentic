#ifndef MOTEURSEMANTIQUE_H
#define MOTEURSEMANTIQUE_H
#include <vector>
#include <iostream>
#include "windowcmentic.h"
#include "connexion.h"
#include <QTextEdit>
#include <QLabel>
#include <QSpinBox>
using namespace std;
class moteurSemantique
{
    public:
        Connexion *con;
        moteurSemantique();
        vector< vector<string> > decomposerTexte(std::string texte);
        vector<string> decomposerPhrase(std::string texte);
        void startMoteurSemantique(QTextEdit *&texteOriginal, QTextEdit *&texteDouteux, QTextEdit *&texteResult, QDoubleSpinBox *&texteSeuil, QLabel *&scoreCP, QLabel *&scoreS,QLabel *&scoreV, QLabel *&scoreT);
        float testCopyPaste(QTextEdit *&texteOriginal, QTextEdit *&texteDouteux);
        float testSynonyme(QTextEdit *&texteOriginal, QTextEdit *&texteDouteux);
        bool isSynonyme(string s1, string s2);
        float testVerbe(QTextEdit *&texteOriginal, QTextEdit *&texteDouteux);
        void colorPlagiat(QTextEdit *&Text);
        vector< vector<string> > deleteLinkWords(vector< vector<string> > texte);
        string getBaseVerbe(string mot);
        string getTerminaisonVerbe(string mot);
        bool getVerbeIrregulier(string mot);
        int getNbMotsTexte(vector< vector<string> > texte);
};

#endif // MOTEURSEMANTIQUE_H
