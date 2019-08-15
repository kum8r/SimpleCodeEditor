#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include "Qsci/qsciscintilla.h"

class codeEditor : public QsciScintilla
{
public:

    codeEditor();

    bool getTextChanges() const;
    void setTextChanges(bool value);

    void showLinenum(bool);


    QString getFileName() const;
    void setFileName(const QString &value);

private:

    bool textChanges = false;
    QFont font;
    QString fileName = "";
};

#endif // CODEEDITOR_H
