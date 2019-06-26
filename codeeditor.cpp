#include "codeeditor.h"

codeEditor::codeEditor()
{
    setWrapMode(this->WrapWord);
    setMarginType(0,NumberMargin);
    setMarginWidth(0,"00");
}


bool codeEditor::getTextChanges() const
{
    return textChanges;
}


void codeEditor::setTextChanges(bool value)
{
    textChanges = value;
}

QFont codeEditor::getFont() const
{
    return font;
}

void codeEditor::setFont(const QFont &value)
{
    font = value;
}
