/********************************************************************************
** Form generated from reading UI file 'finddialog.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDDIALOG_H
#define UI_FINDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

    void setupUi(QDialog *findDialog)
    {
        if (findDialog->objectName().isEmpty())
            findDialog->setObjectName(QString::fromUtf8("findDialog"));
        findDialog->resize(596, 119);
        gridLayout_2 = new QGridLayout(findDialog);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
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


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 2);

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


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_2->addWidget(widget, 2, 1, 1, 1);


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
    } // retranslateUi

};

namespace Ui {
    class findDialog: public Ui_findDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDDIALOG_H
