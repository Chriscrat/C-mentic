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
    QVector<string> getGroupList();

private:
    QSqlDatabase db;
};

#endif // CONNEXION_H
