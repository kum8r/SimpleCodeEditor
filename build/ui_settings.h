/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QCheckBox *checkBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QFontComboBox *fontComboBox;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QWidget *tab_2;
    QWidget *tab_3;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(430, 393);
        gridLayout = new QGridLayout(Settings);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(Settings);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        checkBox = new QCheckBox(tab);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(130, 200, 87, 20));
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 282, 27));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        fontComboBox = new QFontComboBox(widget);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        horizontalLayout->addWidget(fontComboBox);

        widget1 = new QWidget(tab);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(40, 120, 209, 29));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBox = new QSpinBox(widget1);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(72);

        horizontalLayout_2->addWidget(spinBox);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Settings);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Dialog", nullptr));
        checkBox->setText(QApplication::translate("Settings", "CheckBox", nullptr));
        label->setText(QApplication::translate("Settings", "Font", nullptr));
        label_2->setText(QApplication::translate("Settings", "Font SIze", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Settings", "View", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Settings", "Editor", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Settings", "Window", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
