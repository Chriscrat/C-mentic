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
       cout << "Connexion : ok" << endl;
       /*QVector<string> groupList = this->getGroupList();
       for(int i=0;i<groupList.size();i++)
       {
           cout << "Groupe a l'indice numero " << i << " : " << groupList[i] << "" << endl;
       }*/
    }
    else
    {
        cout << "Erreur de connexion" << endl;
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
       QMessageBox::critical(0, "Erreur methode 'getGroupList()' : ", err.text());
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

bool Connexion::isSynonyme(string motDouteux, string motOrigine)
{
    int idMotOri = getIdMot(motOrigine);
    int idMotDou = getIdMot(motDouteux);
    int idSynonymeDou = getIdSynonyme(idMotDou);
    int idSynonymeOri = getIdSynonyme(idMotOri);

    cout << "Mot douteux : " << motDouteux << " - ID mot : " << idMotDou << " - ID synonyme : " << idSynonymeDou << endl;
    cout << "Mot d'origine : " << motOrigine << " - ID mot : " << idMotOri << " - ID synonyme : " << idSynonymeOri << endl;

    if((idSynonymeDou==idSynonymeOri) && (idSynonymeDou>0 && idSynonymeOri>0))
        return true;
    return false;
}

int Connexion::getIdMot(string mot)
{
    QSqlQuery query;
    QString maRequete= QString::fromStdString("SELECT id_mot FROM mot WHERE mot LIKE '%"+mot+"%'");
    cout << maRequete.toStdString() << endl;
    int id=0;
    if(!query.exec(maRequete))
    {
       // Generation d'une erreur
       QSqlError err = query.lastError();
       QMessageBox::critical(0, "Erreur methode 'getIdMot()' : ", err.text());
    }
    else
    {
       while(query.next())
       {
            QSqlRecord rec = query.record();
            id = rec.value("id_mot").toInt();
            break;
       }
    }
    return id;
}

int Connexion::getIdSynonyme(int idMot)
{
    QSqlQuery* query = new QSqlQuery();
    query->prepare("SELECT id_synonyme FROM synonymeDe WHERE id_mot =?");
    query->addBindValue(idMot);
    int id=0;
    if(!query->exec())
    {
       // Generation d'une erreur
       QSqlError err = query->lastError();
       QMessageBox::critical(0, "Erreur methode 'getIdSynonyme()' : ", err.text());
    }
    else
    {
       while(query->next())
       {
            QSqlRecord rec = query->record();
            id = rec.value("id_synonyme").toInt();
       }
    }
    return id;
}
