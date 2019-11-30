/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QFormLayout *formLayout;
    QLabel *label;
    QFontComboBox *fontComboBox;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_9;
    QCheckBox *checkBox_5;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_8;
    QCheckBox *checkBox_4;
    QLabel *label_6;
    QCheckBox *checkBox_2;
    QLabel *label_7;
    QCheckBox *checkBox_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QFormLayout *formLayout_2;
    QLabel *label_10;
    QComboBox *comboBox_2;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_11;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(606, 488);
        Settings->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(Settings);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(Settings);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        fontComboBox = new QFontComboBox(tab);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, fontComboBox);

        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        comboBox = new QComboBox(tab);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox);

        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_9);

        checkBox_5 = new QCheckBox(tab);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setChecked(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, checkBox_5);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit);

        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_8);

        checkBox_4 = new QCheckBox(tab);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setChecked(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, checkBox_4);

        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_6);

        checkBox_2 = new QCheckBox(tab);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setChecked(true);

        formLayout->setWidget(7, QFormLayout::FieldRole, checkBox_2);

        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_7);

        checkBox_3 = new QCheckBox(tab);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setChecked(true);

        formLayout->setWidget(8, QFormLayout::FieldRole, checkBox_3);


        gridLayout_2->addLayout(formLayout, 0, 0, 1, 1);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_10);

        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, comboBox_2);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_4);

        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, lineEdit_2);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_11);

        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, lineEdit_3);

        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, checkBox);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_5);


        gridLayout_3->addLayout(formLayout_2, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        saveButton = new QPushButton(Settings);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout_2->addWidget(saveButton);

        cancelButton = new QPushButton(Settings);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        retranslateUi(Settings);

        tabWidget->setCurrentIndex(0);
        comboBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QCoreApplication::translate("Settings", "Settings", nullptr));
        label->setText(QCoreApplication::translate("Settings", "Font", nullptr));
        label_2->setText(QCoreApplication::translate("Settings", "Caret width", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Settings", "0", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Settings", "1", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Settings", "2", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("Settings", "3", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("Settings", "Block", nullptr));

        label_9->setText(QCoreApplication::translate("Settings", "Auto Complete", nullptr));
        checkBox_5->setText(QString());
        label_3->setText(QCoreApplication::translate("Settings", "Font Size", nullptr));
        lineEdit->setText(QCoreApplication::translate("Settings", "12", nullptr));
        label_8->setText(QCoreApplication::translate("Settings", "WordWrap", nullptr));
        checkBox_4->setText(QString());
        label_6->setText(QCoreApplication::translate("Settings", "Show Match Brackets", nullptr));
        checkBox_2->setText(QString());
        label_7->setText(QCoreApplication::translate("Settings", "Show Line Numbers", nullptr));
        checkBox_3->setText(QString());
        groupBox->setTitle(QCoreApplication::translate("Settings", "Indentation", nullptr));
        label_10->setText(QCoreApplication::translate("Settings", "Label with", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Settings", "Tabs", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Settings", "Spaces", nullptr));

        label_4->setText(QCoreApplication::translate("Settings", "Tab Size", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("Settings", "4", nullptr));
        label_11->setText(QCoreApplication::translate("Settings", "TextLabel", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("Settings", "2", nullptr));
        checkBox->setText(QString());
        label_5->setText(QCoreApplication::translate("Settings", "Auto Indent", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Settings", "General", nullptr));
        saveButton->setText(QCoreApplication::translate("Settings", "Save", nullptr));
        cancelButton->setText(QCoreApplication::translate("Settings", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
