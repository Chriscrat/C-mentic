#-------------------------------------------------
#
# Project created by QtCreator 2013-07-04T20:44:33
#
#-------------------------------------------------

QT += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
LIBS += D:\dev\mysql-connector-c++-noinstall-1.1.3-winx64\lib\mysqlcppconn.lib
TARGET = Cmentic
TEMPLATE = app


SOURCES += main.cpp\
        windowcmentic.cpp \
    connexion.cpp

HEADERS  += windowcmentic.h \
    connexion.h

FORMS    += windowcmentic.ui
