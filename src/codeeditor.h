#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include "Qsci/qsciscintilla.h"

class codeEditor : public QsciScintilla
{
public:

    codeEditor();

    bool getTextChanges() const;
    void setTextChanges(bool value);

    QFont getFont() const;
    void setFont(const QFont &value);

private:

    bool textChanges = false;
    QFont font;
};

#endif // CODEEDITOR_H
