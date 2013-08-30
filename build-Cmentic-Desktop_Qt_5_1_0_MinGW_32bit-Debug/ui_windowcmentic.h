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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowCmentic
{
public:
    QLabel *label;
    QTextEdit *texteSoupconne;
    QLabel *label_2;
    QTextEdit *texteOriginal;
    QPushButton *btnStart;
    QPushButton *btnQuit;
    QTextEdit *texteResult;
    QGroupBox *groupBox;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *scoreCP;
    QLabel *scoreS;
    QLabel *scoreV;
    QFrame *line_2;
    QLabel *label_7;
    QLabel *scoreT;
    QLabel *label_6;
    QFrame *line;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox;

    void setupUi(QWidget *WindowCmentic)
    {
        if (WindowCmentic->objectName().isEmpty())
            WindowCmentic->setObjectName(QStringLiteral("WindowCmentic"));
        WindowCmentic->resize(480, 470);
        label = new QLabel(WindowCmentic);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(9, 9, 131, 16));
        texteSoupconne = new QTextEdit(WindowCmentic);
        texteSoupconne->setObjectName(QStringLiteral("texteSoupconne"));
        texteSoupconne->setGeometry(QRect(10, 30, 211, 171));
        label_2 = new QLabel(WindowCmentic);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(9, 209, 127, 16));
        texteOriginal = new QTextEdit(WindowCmentic);
        texteOriginal->setObjectName(QStringLiteral("texteOriginal"));
        texteOriginal->setGeometry(QRect(10, 228, 211, 175));
        btnStart = new QPushButton(WindowCmentic);
        btnStart->setObjectName(QStringLiteral("btnStart"));
        btnStart->setGeometry(QRect(9, 409, 75, 23));
        btnQuit = new QPushButton(WindowCmentic);
        btnQuit->setObjectName(QStringLiteral("btnQuit"));
        btnQuit->setGeometry(QRect(9, 438, 75, 23));
        texteResult = new QTextEdit(WindowCmentic);
        texteResult->setObjectName(QStringLiteral("texteResult"));
        texteResult->setGeometry(QRect(260, 30, 211, 171));
        texteResult->setReadOnly(true);
        groupBox = new QGroupBox(WindowCmentic);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(260, 270, 201, 131));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 20, 101, 16));
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 40, 71, 16));
        label_4->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 60, 81, 16));
        label_5->setStyleSheet(QStringLiteral("color: rgb(0, 170, 0);"));
        scoreCP = new QLabel(groupBox);
        scoreCP->setObjectName(QStringLiteral("scoreCP"));
        scoreCP->setGeometry(QRect(110, 20, 21, 16));
        scoreS = new QLabel(groupBox);
        scoreS->setObjectName(QStringLiteral("scoreS"));
        scoreS->setGeometry(QRect(110, 40, 21, 16));
        scoreV = new QLabel(groupBox);
        scoreV->setObjectName(QStringLiteral("scoreV"));
        scoreV->setGeometry(QRect(110, 60, 21, 16));
        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(0, 80, 201, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 100, 81, 16));
        scoreT = new QLabel(groupBox);
        scoreT->setObjectName(QStringLiteral("scoreT"));
        scoreT->setGeometry(QRect(110, 100, 21, 16));
        label_6 = new QLabel(WindowCmentic);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(260, 10, 46, 13));
        line = new QFrame(WindowCmentic);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(230, 10, 20, 451));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label_8 = new QLabel(WindowCmentic);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(270, 230, 71, 16));
        doubleSpinBox = new QDoubleSpinBox(WindowCmentic);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setGeometry(QRect(350, 230, 62, 22));
        doubleSpinBox->setValue(60);

        retranslateUi(WindowCmentic);

        QMetaObject::connectSlotsByName(WindowCmentic);
    } // setupUi

    void retranslateUi(QWidget *WindowCmentic)
    {
        WindowCmentic->setWindowTitle(QApplication::translate("WindowCmentic", "WindowCmentic", 0));
        label->setText(QApplication::translate("WindowCmentic", "Copier le texte \303\240 analyser :", 0));
        texteSoupconne->setHtml(QApplication::translate("WindowCmentic", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p></body></html>", 0));
        label_2->setText(QApplication::translate("WindowCmentic", "Copier le mod\303\250le \303\240 tester :", 0));
        btnStart->setText(QApplication::translate("WindowCmentic", "Analyser", 0));
        btnQuit->setText(QApplication::translate("WindowCmentic", "Quitter", 0));
        texteResult->setHtml(QApplication::translate("WindowCmentic", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"><br /></p></body></html>", 0));
        groupBox->setTitle(QApplication::translate("WindowCmentic", "Scores plagiat", 0));
        label_3->setText(QApplication::translate("WindowCmentic", "Copier / Coller :", 0));
        label_4->setText(QApplication::translate("WindowCmentic", "Synonyme :", 0));
        label_5->setText(QApplication::translate("WindowCmentic", "Verbes / Temps :", 0));
        scoreCP->setText(QApplication::translate("WindowCmentic", "0%", 0));
        scoreS->setText(QApplication::translate("WindowCmentic", "0%", 0));
        scoreV->setText(QApplication::translate("WindowCmentic", "0%", 0));
        label_7->setText(QApplication::translate("WindowCmentic", "Score total :", 0));
        scoreT->setText(QApplication::translate("WindowCmentic", "0%", 0));
        label_6->setText(QApplication::translate("WindowCmentic", "R\303\251sultat :", 0));
        label_8->setText(QApplication::translate("WindowCmentic", "Seuil plagiat :", 0));
    } // retranslateUi

};

namespace Ui {
    class WindowCmentic: public Ui_WindowCmentic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWCMENTIC_H
