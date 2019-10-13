#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include "Qsci/qsciscintilla.h"
#include "Qsci/qsciapis.h"
#include <QSettings>
#include <QDebug>

class codeEditor : public QsciScintilla
{
public:

    codeEditor();

    bool getTextChanges() const;
    void setTextChanges(bool value);

    void loadSettings();

    QString getFileName() const;
    void setFileName(const QString &value);

    void autoComplete();
    void autoCompleteForCpp(QsciLexer *lexer);

private:

    bool textChanges = false;
    QString fileName = "";
    QSettings *mySettings;
};

#endif // CODEEDITOR_H
