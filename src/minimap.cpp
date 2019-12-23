#include "minimap.h"
#include "ui_minimap.h"

minimap::minimap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::minimap)
{
    ui->setupUi(this);
    text = ui->textEdit;
    ui->textEdit->setMarginWidth(0,0);
    ui->textEdit->setMargins(0);
    ui->textEdit->setReadOnly(0);
    ui->textEdit->setWrapMode(QsciScintilla::WrapNone);

    QFont font("monospace",1);
    if (text->lexer() == nullptr)
    {
        text->setColor(QColor("black"));
        text->setPaper(QColor("#cbcdce"));
        text->setFont(font);
    }
    else
    {
        QsciLexer *lexer = text->lexer();
        lexer->setDefaultColor(QColor("black"));
        lexer->setDefaultPaper(QColor("#cbcdce"));
        lexer->setDefaultFont(font);
    }
}

minimap::~minimap()
{
    delete ui;
}

QsciScintilla *minimap::getText() const
{
    return text;
}

