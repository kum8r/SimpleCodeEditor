/********************************************************************************
** Form generated from reading UI file 'editor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITOR_H
#define UI_EDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include "Qsci/qsciscintilla.h"

QT_BEGIN_NAMESPACE

class Ui_editor
{
public:
    QGridLayout *gridLayout;
    QsciScintilla *textEdit;

    void setupUi(QDialog *editor)
    {
        if (editor->objectName().isEmpty())
            editor->setObjectName(QString::fromUtf8("editor"));
        editor->resize(400, 300);
        gridLayout = new QGridLayout(editor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QsciScintilla(editor);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        retranslateUi(editor);

        QMetaObject::connectSlotsByName(editor);
    } // setupUi

    void retranslateUi(QDialog *editor)
    {
        editor->setWindowTitle(QApplication::translate("editor", "Dialog", nullptr));
#ifndef QT_NO_TOOLTIP
        textEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        textEdit->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
    } // retranslateUi

};

namespace Ui {
    class editor: public Ui_editor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITOR_H
