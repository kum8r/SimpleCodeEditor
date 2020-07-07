#include "minimap.h"
#include "stylesheet.h"

#include <QFontDatabase>

MiniMap::MiniMap(QWidget * parent)
  : QsciScintilla(parent)
{
    setMarginWidth(0, 0);
    setMargins(0);
    setReadOnly(0);
    setWrapMode(QsciScintilla::WrapNone);
    QFont fixedFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    fixedFont.setPointSize(1);
    setFont(fixedFont);
}

void MiniMap::setStyleSheet(QString t_filename)
{
    StyleSheet * stylesheet = new StyleSheet();
    stylesheet->setFont(this->font());
    QString text = this->text();
    QsciLexer * lexer = this->lexer();
    clear();
    stylesheet->setStyleSheet(lexer, t_filename, this);
    setLexer(lexer);
    setText(text);
}
