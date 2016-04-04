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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *m_pOkBtn;
    QPushButton *m_pCancelBtn;

    void setupUi(QWidget *CGoToCell)
    {
        if (CGoToCell->objectName().isEmpty())
            CGoToCell->setObjectName(QStringLiteral("CGoToCell"));
        CGoToCell->resize(264, 80);
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

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_pOkBtn = new QPushButton(CGoToCell);
        m_pOkBtn->setObjectName(QStringLiteral("m_pOkBtn"));
        m_pOkBtn->setDefault(true);
        m_pOkBtn->setFlat(false);

        horizontalLayout->addWidget(m_pOkBtn);

        m_pCancelBtn = new QPushButton(CGoToCell);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));

        horizontalLayout->addWidget(m_pCancelBtn);


        verticalLayout->addLayout(horizontalLayout);

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
        m_pOkBtn->setText(QApplication::translate("CGoToCell", "Ok", 0));
        m_pCancelBtn->setText(QApplication::translate("CGoToCell", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class CGoToCell: public Ui_CGoToCell {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOTOCELLDIALOG_H
