#ifndef STYLESHEET_H
#define STYLESHEET_H

#include <Qsci/qscilexer.h>
#include <Qsci/qscilexercpp.h>
#include <Qsci/qsciscintilla.h>

class StyleSheet
{
public:
    StyleSheet();
    void setStyleSheet(QsciLexer * lexer, QString themeFileName, QsciScintilla * codeeditor);
    void setFont(QFont font);

private:
    QFont font;
    void setStyleForCommentAttribute();
};

#endif // STYLESHEET_H
