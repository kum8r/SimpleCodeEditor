/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_findDialog
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QToolButton *findCloseBtn;
    QLineEdit *findString;
    QPushButton *FindBtn;
    QPushButton *FindPrevBtn;
    QWidget *widget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *replaceCloseBtn;
    QLineEdit *replaceText;
    QPushButton *replaceBtn;
    QPushButton *replaceAllBtn;
    QPushButton *AdvacndBtn;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *csChkBox;
    QCheckBox *woChkBox;
    QCheckBox *reChkBox;

    void setupUi(QDialog *findDialog)
    {
        if (findDialog->objectName().isEmpty())
            findDialog->setObjectName(QString::fromUtf8("findDialog"));
        findDialog->resize(596, 159);
        gridLayout_2 = new QGridLayout(findDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        findCloseBtn = new QToolButton(findDialog);
        findCloseBtn->setObjectName(QString::fromUtf8("findCloseBtn"));

        horizontalLayout->addWidget(findCloseBtn);

        findString = new QLineEdit(findDialog);
        findString->setObjectName(QString::fromUtf8("findString"));

        horizontalLayout->addWidget(findString);

        FindBtn = new QPushButton(findDialog);
        FindBtn->setObjectName(QString::fromUtf8("FindBtn"));

        horizontalLayout->addWidget(FindBtn);

        FindPrevBtn = new QPushButton(findDialog);
        FindPrevBtn->setObjectName(QString::fromUtf8("FindPrevBtn"));

        horizontalLayout->addWidget(FindPrevBtn);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        widget = new QWidget(findDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        replaceCloseBtn = new QToolButton(widget);
        replaceCloseBtn->setObjectName(QString::fromUtf8("replaceCloseBtn"));

        horizontalLayout_2->addWidget(replaceCloseBtn);

        replaceText = new QLineEdit(widget);
        replaceText->setObjectName(QString::fromUtf8("replaceText"));

        horizontalLayout_2->addWidget(replaceText);

        replaceBtn = new QPushButton(widget);
        replaceBtn->setObjectName(QString::fromUtf8("replaceBtn"));

        horizontalLayout_2->addWidget(replaceBtn);

        replaceAllBtn = new QPushButton(widget);
        replaceAllBtn->setObjectName(QString::fromUtf8("replaceAllBtn"));

        horizontalLayout_2->addWidget(replaceAllBtn);

        AdvacndBtn = new QPushButton(widget);
        AdvacndBtn->setObjectName(QString::fromUtf8("AdvacndBtn"));

        horizontalLayout_2->addWidget(AdvacndBtn);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget, 1, 0, 1, 1);

        widget_2 = new QWidget(findDialog);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_3 = new QHBoxLayout(widget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        csChkBox = new QCheckBox(widget_2);
        csChkBox->setObjectName(QString::fromUtf8("csChkBox"));

        horizontalLayout_3->addWidget(csChkBox);

        woChkBox = new QCheckBox(widget_2);
        woChkBox->setObjectName(QString::fromUtf8("woChkBox"));

        horizontalLayout_3->addWidget(woChkBox);

        reChkBox = new QCheckBox(widget_2);
        reChkBox->setObjectName(QString::fromUtf8("reChkBox"));

        horizontalLayout_3->addWidget(reChkBox);


        gridLayout_2->addWidget(widget_2, 2, 0, 1, 1);


        retranslateUi(findDialog);

        QMetaObject::connectSlotsByName(findDialog);
    } // setupUi

    void retranslateUi(QDialog *findDialog)
    {
        findDialog->setWindowTitle(QCoreApplication::translate("findDialog", "Dialog", nullptr));
        findCloseBtn->setText(QCoreApplication::translate("findDialog", "x", nullptr));
        FindBtn->setText(QCoreApplication::translate("findDialog", "Find", nullptr));
        FindPrevBtn->setText(QCoreApplication::translate("findDialog", "Find Previous", nullptr));
        replaceCloseBtn->setText(QCoreApplication::translate("findDialog", "x", nullptr));
        replaceBtn->setText(QCoreApplication::translate("findDialog", "Replace", nullptr));
        replaceAllBtn->setText(QCoreApplication::translate("findDialog", "Replace All", nullptr));
        AdvacndBtn->setText(QCoreApplication::translate("findDialog", "Advanced", nullptr));
        csChkBox->setText(QCoreApplication::translate("findDialog", "case sensitive", nullptr));
        woChkBox->setText(QCoreApplication::translate("findDialog", "whole word", nullptr));
        reChkBox->setText(QCoreApplication::translate("findDialog", "regular expression", nullptr));
    } // retranslateUi

};

namespace Ui {
    class findDialog: public Ui_findDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
