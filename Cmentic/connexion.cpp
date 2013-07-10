#include "connexion.h"
#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>

Connexion::Connexion()
{

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("cmentic");
    db.open();
    QSqlQuery query;
    query.prepare("SELECT * FROM verbe");
    query.exec();
    QMessageBox msgBox;
    if(query.exec())
        msgBox.setText("Requête ok");

    else if(!query.exec())
        msgBox.setText("Echec");

    msgBox.exec();

}
