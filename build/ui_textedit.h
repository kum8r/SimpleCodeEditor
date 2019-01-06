/********************************************************************************
** Form generated from reading UI file 'textedit.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTEDIT_H
#define UI_TEXTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include "Qsci/qsciscintilla.h"

QT_BEGIN_NAMESPACE

class Ui_TextEdit
{
public:
    QGridLayout *gridLayout;
    QsciScintilla *textEdit;

    void setupUi(QDialog *TextEdit)
    {
        if (TextEdit->objectName().isEmpty())
            TextEdit->setObjectName(QStringLiteral("TextEdit"));
        TextEdit->resize(398, 298);
        gridLayout = new QGridLayout(TextEdit);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        textEdit = new QsciScintilla(TextEdit);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        retranslateUi(TextEdit);

        QMetaObject::connectSlotsByName(TextEdit);
    } // setupUi

    void retranslateUi(QDialog *TextEdit)
    {
        TextEdit->setWindowTitle(QApplication::translate("TextEdit", "Dialog", nullptr));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        textEdit->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class TextEdit: public Ui_TextEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTEDIT_H
