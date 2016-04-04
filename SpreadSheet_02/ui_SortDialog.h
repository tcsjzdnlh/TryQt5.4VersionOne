/********************************************************************************
** Form generated from reading UI file 'SortDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SORTDIALOG_H
#define UI_SORTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CSortDialog
{
public:
    QGridLayout *gridLayout_4;
    QGroupBox *m_pPkGB;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *m_pPColumnCB;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QComboBox *m_pPOrderCB;
    QVBoxLayout *verticalLayout;
    QPushButton *m_pOkBtn;
    QPushButton *m_pCancelBtn;
    QSpacerItem *verticalSpacer;
    QPushButton *m_pMoreBtn;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *m_pSkGB;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QComboBox *m_pSColumnCB;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QComboBox *m_pSOrderCB;
    QGroupBox *m_pTkGB;
    QGridLayout *gridLayout_3;
    QLabel *label_5;
    QComboBox *m_pTColumnCB;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_6;
    QComboBox *m_pTOrderCB;

    void setupUi(QDialog *CSortDialog)
    {
        if (CSortDialog->objectName().isEmpty())
            CSortDialog->setObjectName(QStringLiteral("CSortDialog"));
        CSortDialog->resize(321, 276);
        gridLayout_4 = new QGridLayout(CSortDialog);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        m_pPkGB = new QGroupBox(CSortDialog);
        m_pPkGB->setObjectName(QStringLiteral("m_pPkGB"));
        gridLayout = new QGridLayout(m_pPkGB);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(m_pPkGB);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        m_pPColumnCB = new QComboBox(m_pPkGB);
        m_pPColumnCB->setObjectName(QStringLiteral("m_pPColumnCB"));

        gridLayout->addWidget(m_pPColumnCB, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(74, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        label_2 = new QLabel(m_pPkGB);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        m_pPOrderCB = new QComboBox(m_pPkGB);
        m_pPOrderCB->setObjectName(QStringLiteral("m_pPOrderCB"));

        gridLayout->addWidget(m_pPOrderCB, 1, 1, 1, 2);


        gridLayout_4->addWidget(m_pPkGB, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_pOkBtn = new QPushButton(CSortDialog);
        m_pOkBtn->setObjectName(QStringLiteral("m_pOkBtn"));
        m_pOkBtn->setDefault(true);

        verticalLayout->addWidget(m_pOkBtn);

        m_pCancelBtn = new QPushButton(CSortDialog);
        m_pCancelBtn->setObjectName(QStringLiteral("m_pCancelBtn"));

        verticalLayout->addWidget(m_pCancelBtn);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        m_pMoreBtn = new QPushButton(CSortDialog);
        m_pMoreBtn->setObjectName(QStringLiteral("m_pMoreBtn"));
        m_pMoreBtn->setCheckable(true);

        verticalLayout->addWidget(m_pMoreBtn);


        gridLayout_4->addLayout(verticalLayout, 0, 1, 2, 1);

        verticalSpacer_2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 1, 0, 1, 1);

        m_pSkGB = new QGroupBox(CSortDialog);
        m_pSkGB->setObjectName(QStringLiteral("m_pSkGB"));
        gridLayout_2 = new QGridLayout(m_pSkGB);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_3 = new QLabel(m_pSkGB);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        m_pSColumnCB = new QComboBox(m_pSkGB);
        m_pSColumnCB->setObjectName(QStringLiteral("m_pSColumnCB"));

        gridLayout_2->addWidget(m_pSColumnCB, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label_4 = new QLabel(m_pSkGB);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        m_pSOrderCB = new QComboBox(m_pSkGB);
        m_pSOrderCB->setObjectName(QStringLiteral("m_pSOrderCB"));

        gridLayout_2->addWidget(m_pSOrderCB, 1, 1, 1, 2);


        gridLayout_4->addWidget(m_pSkGB, 2, 0, 1, 1);

        m_pTkGB = new QGroupBox(CSortDialog);
        m_pTkGB->setObjectName(QStringLiteral("m_pTkGB"));
        gridLayout_3 = new QGridLayout(m_pTkGB);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_5 = new QLabel(m_pTkGB);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        m_pTColumnCB = new QComboBox(m_pTkGB);
        m_pTColumnCB->setObjectName(QStringLiteral("m_pTColumnCB"));

        gridLayout_3->addWidget(m_pTColumnCB, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        label_6 = new QLabel(m_pTkGB);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        m_pTOrderCB = new QComboBox(m_pTkGB);
        m_pTOrderCB->setObjectName(QStringLiteral("m_pTOrderCB"));

        gridLayout_3->addWidget(m_pTOrderCB, 1, 1, 1, 2);


        gridLayout_4->addWidget(m_pTkGB, 3, 0, 1, 1);

        QWidget::setTabOrder(m_pPColumnCB, m_pPOrderCB);
        QWidget::setTabOrder(m_pPOrderCB, m_pSColumnCB);
        QWidget::setTabOrder(m_pSColumnCB, m_pSOrderCB);
        QWidget::setTabOrder(m_pSOrderCB, m_pTColumnCB);
        QWidget::setTabOrder(m_pTColumnCB, m_pTOrderCB);
        QWidget::setTabOrder(m_pTOrderCB, m_pOkBtn);
        QWidget::setTabOrder(m_pOkBtn, m_pCancelBtn);
        QWidget::setTabOrder(m_pCancelBtn, m_pMoreBtn);

        retranslateUi(CSortDialog);
        QObject::connect(m_pOkBtn, SIGNAL(clicked()), CSortDialog, SLOT(accept()));
        QObject::connect(m_pCancelBtn, SIGNAL(clicked()), CSortDialog, SLOT(reject()));
        QObject::connect(m_pMoreBtn, SIGNAL(toggled(bool)), m_pSkGB, SLOT(setVisible(bool)));
        QObject::connect(m_pMoreBtn, SIGNAL(toggled(bool)), m_pTkGB, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(CSortDialog);
    } // setupUi

    void retranslateUi(QDialog *CSortDialog)
    {
        CSortDialog->setWindowTitle(QApplication::translate("CSortDialog", "Dialog", 0));
        m_pPkGB->setTitle(QApplication::translate("CSortDialog", "&Primary Key", 0));
        label->setText(QApplication::translate("CSortDialog", "Column:", 0));
        m_pPColumnCB->clear();
        m_pPColumnCB->insertItems(0, QStringList()
         << QApplication::translate("CSortDialog", "None", 0)
        );
        label_2->setText(QApplication::translate("CSortDialog", "Order:", 0));
        m_pPOrderCB->clear();
        m_pPOrderCB->insertItems(0, QStringList()
         << QApplication::translate("CSortDialog", "Ascending", 0)
         << QApplication::translate("CSortDialog", "Descending", 0)
        );
        m_pOkBtn->setText(QApplication::translate("CSortDialog", "Ok", 0));
        m_pCancelBtn->setText(QApplication::translate("CSortDialog", "Cancel", 0));
        m_pMoreBtn->setText(QApplication::translate("CSortDialog", "&More", 0));
        m_pSkGB->setTitle(QApplication::translate("CSortDialog", "&Secondary Key", 0));
        label_3->setText(QApplication::translate("CSortDialog", "Column:", 0));
        m_pSColumnCB->clear();
        m_pSColumnCB->insertItems(0, QStringList()
         << QApplication::translate("CSortDialog", "None", 0)
        );
        label_4->setText(QApplication::translate("CSortDialog", "Order:", 0));
        m_pSOrderCB->clear();
        m_pSOrderCB->insertItems(0, QStringList()
         << QApplication::translate("CSortDialog", "Ascending", 0)
         << QApplication::translate("CSortDialog", "Descending", 0)
        );
        m_pTkGB->setTitle(QApplication::translate("CSortDialog", "&Tertiary Key", 0));
        label_5->setText(QApplication::translate("CSortDialog", "Column:", 0));
        m_pTColumnCB->clear();
        m_pTColumnCB->insertItems(0, QStringList()
         << QApplication::translate("CSortDialog", "None", 0)
        );
        label_6->setText(QApplication::translate("CSortDialog", "Order:", 0));
        m_pTOrderCB->clear();
        m_pTOrderCB->insertItems(0, QStringList()
         << QApplication::translate("CSortDialog", "Ascending", 0)
         << QApplication::translate("CSortDialog", "Descending", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class CSortDialog: public Ui_CSortDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SORTDIALOG_H
