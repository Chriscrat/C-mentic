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

/*QVector<string> Connexion::getGroupList()
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
            //const QString id = rec.value("id_groupe").toString();
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
    //cout << maRequete.toStdString() << endl;
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
}*/

// ----------------------------------------------

// Renvoi les synonymes d'un mot
// Si retourne 0 réponses, il n'y a pas de synonymes
QVector<string> Connexion::getSynonymes(string mot)
{
    string maRequete = "SELECT mot FROM mot, synonymeDe WHERE mot.id_mot = synonymeDe.id_mot ";
    maRequete += "AND synonymeDe.id_synonyme = (SELECT id_mot FROM mot WHERE mot = '";
    maRequete += mot;
    maRequete += "') UNION SELECT mot FROM mot, synonymeDe WHERE mot.id_mot = synonymeDe.id_synonyme ";
    maRequete += "AND synonymeDe.id_mot = (SELECT id_mot FROM mot WHERE mot = '";
    maRequete += mot;
    maRequete += "')";

    QSqlQuery query;
    QVector<string> synonymes;
    if(!query.exec(QString::fromStdString(maRequete)))
    {
       // Generation d'une erreur
       QSqlError err = query.lastError();
       QMessageBox::critical(0, "Erreur methode 'getSynonymes()' : ", err.text());
    }
    else
    {
       while(query.next())
       {
            QSqlRecord rec = query.record();
            const QString nom = rec.value("mot").toString();
            synonymes.append(nom.toStdString());
       }
    }
    return synonymes;
}

// Renvoi la liste des terminaison possibles
// Si aucunes terminaisons ne corresponds, essayer le mot entier en tant que verbe irrégulier
QVector<string> Connexion::getTerminaisonsPossibles()
{
    string maRequete = "SELECT terminaison.n1singulier, terminaison.n2singulier, terminaison.n3singulier, terminaison.n1pluriel, terminaison.n2pluriel, terminaison.n3pluriel ";
    maRequete += "FROM groupetemps, terminaison ";
    maRequete += "WHERE groupetemps.id_terminaison = terminaison.id_terminaison";

    QSqlQuery query;
    QVector<string> terminaisons;
    if(!query.exec(QString::fromStdString(maRequete)))
    {
       // Generation d'une erreur
       QSqlError err = query.lastError();
       QMessageBox::critical(0, "Erreur methode 'getSynonymes()' : ", err.text());
    }
    else
    {
       while(query.next())
       {
            QSqlRecord rec = query.record();
            const QString n1s = rec.value("n1singulier").toString();
            const QString n2s = rec.value("n2singulier").toString();
            const QString n3s = rec.value("n3singulier").toString();
            const QString n1p = rec.value("n1pluriel").toString();
            const QString n2p = rec.value("n2pluriel").toString();
            const QString n3p = rec.value("n3pluriel").toString();
            terminaisons.append(n1s.toStdString());
            terminaisons.append(n2s.toStdString());
            terminaisons.append(n3s.toStdString());
            terminaisons.append(n1p.toStdString());
            terminaisons.append(n2p.toStdString());
            terminaisons.append(n3p.toStdString());
       }
    }
    return terminaisons;
}

// Renvoi les conjugaison pour un verbe irrégulier
// Si retourne 0 enregistrement, alors ce n'est pas un verbe
QVector<string> Connexion::getConjugaisonsIrregulier(string mot)
{
    string maRequete = "SELECT irregulier.id_temps, terminaison.n1singulier, terminaison.n2singulier, terminaison.n3singulier, terminaison.n1pluriel, terminaison.n2pluriel, terminaison.n3pluriel FROM irregulier, terminaison WHERE irregulier.id_terminaison = terminaison.id_terminaison AND irregulier.id_verbe = (SELECT DISTINCT irregulier.id_verbe FROM irregulier WHERE irregulier.id_terminaison in (SELECT id_terminaison FROM terminaison WHERE (n1singulier = '";
    maRequete += mot;
    maRequete += "' OR n2singulier = '";
    maRequete += mot;
    maRequete += "' OR n3singulier = '";
    maRequete += mot;
    maRequete += "' OR n1pluriel = '";
    maRequete += mot;
    maRequete += "' OR n2pluriel = '";
    maRequete += mot;
    maRequete += "' OR n3pluriel = '";
    maRequete += mot;
    maRequete += "')))";

    QSqlQuery query;
    QVector<string> conjugaisons;
    if(!query.exec(QString::fromStdString(maRequete)))
    {
       // Generation d'une erreur
       QSqlError err = query.lastError();
       QMessageBox::critical(0, "Erreur methode 'getSynonymes()' : ", err.text());
    }
    else
    {
       while(query.next())
       {
            QSqlRecord rec = query.record();
            const QString n1s = rec.value("n1singulier").toString();
            const QString n2s = rec.value("n2singulier").toString();
            const QString n3s = rec.value("n3singulier").toString();
            const QString n1p = rec.value("n1pluriel").toString();
            const QString n2p = rec.value("n2pluriel").toString();
            const QString n3p = rec.value("n3pluriel").toString();
            conjugaisons.append(n1s.toStdString());
            conjugaisons.append(n2s.toStdString());
            conjugaisons.append(n3s.toStdString());
            conjugaisons.append(n1p.toStdString());
            conjugaisons.append(n2p.toStdString());
            conjugaisons.append(n3p.toStdString());
       }
    }
    return conjugaisons;
}

// Renvoi les conjugaisons pour une base donnée
QVector<string> Connexion::getConjugaisons(string mot)
{
    string maRequete = "SELECT groupetemps.id_temps, terminaison.n1singulier, terminaison.n2singulier, terminaison.n3singulier, terminaison.n1pluriel, terminaison.n2pluriel, terminaison.n3pluriel ";
    maRequete += "FROM verbe, groupetemps, terminaison ";
    maRequete += "WHERE verbe.id_groupe = groupetemps.id_groupe ";
    maRequete += "AND groupetemps.id_terminaison = terminaison.id_terminaison ";
    maRequete += "AND verbe.base = '";
    maRequete += mot;
    maRequete += "'";

    QSqlQuery query;
    QVector<string> conjugaisons;
    if(!query.exec(QString::fromStdString(maRequete)))
    {
       // Generation d'une erreur
       QSqlError err = query.lastError();
       QMessageBox::critical(0, "Erreur methode 'getSynonymes()' : ", err.text());
    }
    else
    {
       while(query.next())
       {
            QSqlRecord rec = query.record();
            const QString n1s = rec.value("n1singulier").toString();
            const QString n2s = rec.value("n2singulier").toString();
            const QString n3s = rec.value("n3singulier").toString();
            const QString n1p = rec.value("n1pluriel").toString();
            const QString n2p = rec.value("n2pluriel").toString();
            const QString n3p = rec.value("n3pluriel").toString();
            conjugaisons.append(n1s.toStdString());
            conjugaisons.append(n2s.toStdString());
            conjugaisons.append(n3s.toStdString());
            conjugaisons.append(n1p.toStdString());
            conjugaisons.append(n2p.toStdString());
            conjugaisons.append(n3p.toStdString());
       }
    }
    return conjugaisons;
}

QVector<string> Connexion::getMotLiaison()
{
    string maRequete = "SELECT mot FROM motliaison";

    QSqlQuery query;
    QVector<string> mots;
    if(!query.exec(QString::fromStdString(maRequete)))
    {
       // Generation d'une erreur
       QSqlError err = query.lastError();
       QMessageBox::critical(0, "Erreur methode 'getSynonymes()' : ", err.text());
    }
    else
    {
       while(query.next())
       {
            QSqlRecord rec = query.record();
            const QString mot = rec.value("mot").toString();
            mots.append(mot.toStdString());
       }
    }
    return mots;
}
