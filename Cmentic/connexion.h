#ifndef CONNEXION_H
#define CONNEXION_H
#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>

using namespace std;

class Connexion
{
public:
    Connexion();
    void disconnect();

    QVector<string> getSynonymes(string mot);
    QVector<string> getTerminaisonsPossibles();
    QVector<string> getConjugaisonsIrregulier(string mot);
    QVector<string> getConjugaisons(string mot);
    QVector<string> getMotLiaison();


private:
    QSqlDatabase db;
};

#endif // CONNEXION_H
