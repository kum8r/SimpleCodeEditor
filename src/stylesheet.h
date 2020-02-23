#ifndef STYLESHEET_H
#define STYLESHEET_H

#include <Qsci/qsciscintilla.h>
#include <QObject>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <Qsci/qscilexer.h>
#include <Qsci/qscilexercpp.h>

class stylesheet
{
public:
    stylesheet();
    QsciLexer* setStyleSheet(QsciLexer *lexer, QString themeFileName, QsciScintilla *codeeditor);

};

#endif // STYLESHEET_H
