
QT += core
QT -= gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Cmentic
TEMPLATE = app

INCLUDEPATH += C:/boost_1_54_0
LIBS += -LC:/boost_1_54_0/boost

SOURCES += main.cpp\
windowcmentic.cpp \
moteursemantique.cpp

HEADERS  += windowcmentic.h \
moteursemantique.h

FORMS    += windowcmentic.ui
