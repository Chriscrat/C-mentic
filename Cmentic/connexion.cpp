#include "connexion.h"
#include <stdio.h>
#include <stdlib.h>
#include <winsock.h>
#include <unistd.h>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QtSql>

Connexion::Connexion()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("cmentic");
    db.setUserName("root");
    db.setPassword("");
    if ( !db.open() )
    {
        qDebug("Connexion impossible : " ) ;
    }
    else
    {

    }
}


