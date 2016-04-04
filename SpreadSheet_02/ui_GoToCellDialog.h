/********************************************************************************
** Form generated from reading UI file 'GoToCellDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOTOCELLDIALOG_H
#define UI_GOTOCELLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CGoToCell
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *m_pCellLocationLabel;
    QLineEdit *m_pCellLocation;
    QDialogButtonBox *m_pBtnBox;

    void setupUi(QWidget *CGoToCell)
    {
        if (CGoToCell->objectName().isEmpty())
            CGoToCell->setObjectName(QStringLiteral("CGoToCell"));
        CGoToCell->resize(329, 148);
        verticalLayout = new QVBoxLayout(CGoToCell);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        m_pCellLocationLabel = new QLabel(CGoToCell);
        m_pCellLocationLabel->setObjectName(QStringLiteral("m_pCellLocationLabel"));

        horizontalLayout_2->addWidget(m_pCellLocationLabel);

        m_pCellLocation = new QLineEdit(CGoToCell);
        m_pCellLocation->setObjectName(QStringLiteral("m_pCellLocation"));

        horizontalLayout_2->addWidget(m_pCellLocation);


        verticalLayout->addLayout(horizontalLayout_2);

        m_pBtnBox = new QDialogButtonBox(CGoToCell);
        m_pBtnBox->setObjectName(QStringLiteral("m_pBtnBox"));
        m_pBtnBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(m_pBtnBox);

#ifndef QT_NO_SHORTCUT
        m_pCellLocationLabel->setBuddy(m_pCellLocation);
#endif // QT_NO_SHORTCUT

        retranslateUi(CGoToCell);

        QMetaObject::connectSlotsByName(CGoToCell);
    } // setupUi

    void retranslateUi(QWidget *CGoToCell)
    {
        CGoToCell->setWindowTitle(QApplication::translate("CGoToCell", "Go To Cell", 0));
        m_pCellLocationLabel->setText(QApplication::translate("CGoToCell", "&Cell Location", 0));
    } // retranslateUi

};

namespace Ui {
    class CGoToCell: public Ui_CGoToCell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOTOCELLDIALOG_H
