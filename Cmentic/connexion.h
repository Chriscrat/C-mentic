#ifndef CONNEXION_H
#define CONNEXION_H
#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>

class Connexion
{
public:
    Connexion();

private:
    QSqlDatabase db;
};

#endif // CONNEXION_H
