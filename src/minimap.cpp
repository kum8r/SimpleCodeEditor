#include "minimap.h"
#include "ui_minimap.h"

#include <QDebug>

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
        text->setColor(QColor("white"));
        text->setPaper(QColor("#393d44"));
        text->setFont(font);
    }
    else
    {
        QsciLexer *lexer = text->lexer();
        lexer->setDefaultColor(QColor("white"));
        lexer->setDefaultPaper(QColor("#393d44"));
        lexer->setDefaultFont(font);
    }

    this->setFocusPolicy(Qt::NoFocus);
}

minimap::~minimap()
{
    delete ui;
}

void minimap::focusInEvent(QFocusEvent *e)
{
        qDebug() << "clear focus";
    this->focusWidget()->clearFocus();
}

void minimap::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "clear focus";
    this->focusWidget()->clearFocus();
}

QsciScintilla *minimap::getText() const
{
    return text;
}

