/********************************************************************************
** Form generated from reading UI file 'windowcmentic.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWCMENTIC_H
#define UI_WINDOWCMENTIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowCmentic
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextEdit *texteSoupconne;
    QLabel *label_2;
    QTextEdit *texteOriginal;
    QPushButton *btnStart;
    QPushButton *btnQuit;

    void setupUi(QWidget *WindowCmentic)
    {
        if (WindowCmentic->objectName().isEmpty())
            WindowCmentic->setObjectName(QStringLiteral("WindowCmentic"));
        WindowCmentic->resize(400, 470);
        verticalLayout = new QVBoxLayout(WindowCmentic);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(WindowCmentic);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        texteSoupconne = new QTextEdit(WindowCmentic);
        texteSoupconne->setObjectName(QStringLiteral("texteSoupconne"));

        verticalLayout->addWidget(texteSoupconne);

        label_2 = new QLabel(WindowCmentic);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        texteOriginal = new QTextEdit(WindowCmentic);
        texteOriginal->setObjectName(QStringLiteral("texteOriginal"));

        verticalLayout->addWidget(texteOriginal);

        btnStart = new QPushButton(WindowCmentic);
        btnStart->setObjectName(QStringLiteral("btnStart"));

        verticalLayout->addWidget(btnStart);

        btnQuit = new QPushButton(WindowCmentic);
        btnQuit->setObjectName(QStringLiteral("btnQuit"));

        verticalLayout->addWidget(btnQuit);


        retranslateUi(WindowCmentic);

        QMetaObject::connectSlotsByName(WindowCmentic);
    } // setupUi

    void retranslateUi(QWidget *WindowCmentic)
    {
        WindowCmentic->setWindowTitle(QApplication::translate("WindowCmentic", "WindowCmentic", 0));
        label->setText(QApplication::translate("WindowCmentic", "Copier le texte \303\240 analyser :", 0));
        label_2->setText(QApplication::translate("WindowCmentic", "Copier le mod\303\250le \303\240 tester :", 0));
        btnStart->setText(QApplication::translate("WindowCmentic", "Analyser", 0));
        btnQuit->setText(QApplication::translate("WindowCmentic", "Quitter", 0));
    } // retranslateUi

};

namespace Ui {
    class WindowCmentic: public Ui_WindowCmentic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWCMENTIC_H
