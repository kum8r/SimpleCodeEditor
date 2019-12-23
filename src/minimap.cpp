#include "minimap.h"
#include "ui_minimap.h"

minimap::minimap(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::minimap)
{
    ui->setupUi(this);
    MinimapText *textEdit = new MinimapText ();
    ui->gridLayout->addWidget(textEdit);
    text = textEdit;

//    text->set
    QFont font("monospace",1);
    if (textEdit->lexer() == nullptr)
    {
        textEdit->setColor(QColor("black"));
        textEdit->setPaper(QColor("#cbcdce"));
        textEdit->setFont(font);
    }
    else
    {
        QsciLexer *lexer = textEdit->lexer();
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

