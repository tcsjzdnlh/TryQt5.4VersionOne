/********************************************************************************
** Form generated from reading UI file 'testwidgets.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWIDGETS_H
#define UI_TESTWIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CTestWidgetsClass
{
public:

    void setupUi(QWidget *CTestWidgetsClass)
    {
        if (CTestWidgetsClass->objectName().isEmpty())
            CTestWidgetsClass->setObjectName(QStringLiteral("CTestWidgetsClass"));
        CTestWidgetsClass->resize(600, 400);

        retranslateUi(CTestWidgetsClass);

        QMetaObject::connectSlotsByName(CTestWidgetsClass);
    } // setupUi

    void retranslateUi(QWidget *CTestWidgetsClass)
    {
        CTestWidgetsClass->setWindowTitle(QApplication::translate("CTestWidgetsClass", "CTestWidgets", 0));
    } // retranslateUi

};

namespace Ui {
    class CTestWidgetsClass: public Ui_CTestWidgetsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWIDGETS_H
