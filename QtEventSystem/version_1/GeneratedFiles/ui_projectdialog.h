/********************************************************************************
** Form generated from reading UI file 'projectdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTDIALOG_H
#define UI_PROJECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include "projectlistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_CProjectDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *m_pALabel;
    QLabel *m_pBLabel;
    CProjectListWidget *m_pAListItem;
    QSpacerItem *spacerItem;
    CProjectListWidget *m_pBListItem;
    QToolButton *m_pLeftBtn;
    QToolButton *m_pRightBtn;
    QSpacerItem *spacerItem1;

    void setupUi(QDialog *CProjectDialog)
    {
        if (CProjectDialog->objectName().isEmpty())
            CProjectDialog->setObjectName(QStringLiteral("CProjectDialog"));
        CProjectDialog->resize(429, 359);
        gridLayout = new QGridLayout(CProjectDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        m_pALabel = new QLabel(CProjectDialog);
        m_pALabel->setObjectName(QStringLiteral("m_pALabel"));
        m_pALabel->setAlignment(Qt::AlignHCenter);

        gridLayout->addWidget(m_pALabel, 0, 0, 1, 1);

        m_pBLabel = new QLabel(CProjectDialog);
        m_pBLabel->setObjectName(QStringLiteral("m_pBLabel"));
        m_pBLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(m_pBLabel, 0, 2, 1, 1);

        m_pAListItem = new CProjectListWidget(CProjectDialog);
        m_pAListItem->setObjectName(QStringLiteral("m_pAListItem"));

        gridLayout->addWidget(m_pAListItem, 1, 0, 4, 1);

        spacerItem = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem, 1, 1, 1, 1);

        m_pBListItem = new CProjectListWidget(CProjectDialog);
        m_pBListItem->setObjectName(QStringLiteral("m_pBListItem"));

        gridLayout->addWidget(m_pBListItem, 1, 2, 4, 1);

        m_pLeftBtn = new QToolButton(CProjectDialog);
        m_pLeftBtn->setObjectName(QStringLiteral("m_pLeftBtn"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/leftarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pLeftBtn->setIcon(icon);
        m_pLeftBtn->setIconSize(QSize(22, 22));

        gridLayout->addWidget(m_pLeftBtn, 2, 1, 1, 1);

        m_pRightBtn = new QToolButton(CProjectDialog);
        m_pRightBtn->setObjectName(QStringLiteral("m_pRightBtn"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/rightarrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        m_pRightBtn->setIcon(icon1);
        m_pRightBtn->setIconSize(QSize(22, 22));

        gridLayout->addWidget(m_pRightBtn, 3, 1, 1, 1);

        spacerItem1 = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(spacerItem1, 4, 1, 1, 1);


        retranslateUi(CProjectDialog);

        QMetaObject::connectSlotsByName(CProjectDialog);
    } // setupUi

    void retranslateUi(QDialog *CProjectDialog)
    {
        CProjectDialog->setWindowTitle(QApplication::translate("CProjectDialog", "Choose Project", 0));
        m_pALabel->setText(QApplication::translate("CProjectDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Project A</span></p></body></html>", 0));
        m_pBLabel->setText(QApplication::translate("CProjectDialog", "<html><head><meta name=\"qrichtext\" content=\"1\" /></head><body style=\" white-space: pre-wrap; font-family:Sans Serif; font-weight:400; font-style:normal; text-decoration:none;\"><p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Project B</span></p></body></html>", 0));
        m_pLeftBtn->setText(QApplication::translate("CProjectDialog", "...", 0));
        m_pRightBtn->setText(QApplication::translate("CProjectDialog", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class CProjectDialog: public Ui_CProjectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTDIALOG_H
