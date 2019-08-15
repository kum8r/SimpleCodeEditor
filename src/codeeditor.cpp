#include "codeeditor.h"
#include <QDebug>
codeEditor::codeEditor()
{
    setWrapMode(this->WrapWord);
    setMarginType(0,NumberMargin);
    setMarginWidth(0,"00");
    this->setFont(QFont("consolas"));
}


bool codeEditor::getTextChanges() const
{
    return textChanges;
}


void codeEditor::setTextChanges(bool value)
{
    textChanges = value;
}




void codeEditor::showLinenum(bool)
{
    this->marginWidth(0);
}



QString codeEditor::getFileName() const
{
    return fileName;
}

void codeEditor::setFileName(const QString &value)
{
    fileName = value;
}

