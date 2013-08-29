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
    QVector<string> getGroupList();
    bool isSynonyme(string motDouteux, string motOrigine);
    int getIdMot(string mot);
    int getIdSynonyme(int idMot);

private:
    QSqlDatabase db;
};

#endif // CONNEXION_H
