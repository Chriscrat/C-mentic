#include "connexion.h"
#include <QVector>
#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <iostream>
#include <QtCore>
#include <QtSql>
using namespace std;


Connexion::Connexion()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("cmentic.db");
    db.open();

    if (db.isOpen())
    {
       cout << "Connexion ok" << endl;
       /*QVector<string> groupList = this->getGroupList();
       for(int i=0;i<groupList.size();i++)
       {
           cout << "Groupe a l'indice numero " << i << " : " << groupList[i] << "" << endl;
       }*/
    }
    else
    {
        cout << "Erreur connexion" << endl;
    }
}

void Connexion::disconnect()
{
    db.close();
}

QVector<string> Connexion::getGroupList()
{
    QString maRequete = "SELECT * FROM groupe";
    QSqlQuery query;
    QVector<string> groupList;
    if(!query.exec(maRequete))
    {
       // Generation d'une erreur
       QSqlError err = query.lastError();
       QMessageBox::critical(0, "Erreur : ", err.text());
    }
    else
    {
       while(query.next())
       {
            QSqlRecord rec = query.record();
            const QString id = rec.value("id_groupe").toString();
            const QString nom = rec.value("nom_groupe").toString();
            //qWarning() << id << nom;
            groupList.append(nom.toStdString());
       }
    }
    return groupList;
}
