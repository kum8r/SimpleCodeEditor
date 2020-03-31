#include "minimap.h"
#include "ui_minimap.h"

#include <QDebug>

MiniMap::MiniMap(QWidget *parent) :
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
//    {
//        text->setColor(QColor("white"));
//        text->setPaper(QColor("#393d44"));
        text->setFont(font);
//    }
    else
    {
        QsciLexer *lexer = text->lexer();
//        lexer->setDefaultColor(QColor("white"));
//        lexer->setDefaultPaper(QColor("#393d44"));
        lexer->setDefaultFont(font);
    }

    this->setFocusPolicy(Qt::NoFocus);
}

MiniMap::~MiniMap()
{
    delete ui;
}

void MiniMap::focusInEvent(QFocusEvent *e)
{
        qDebug() << "clear focus";
    this->focusWidget()->clearFocus();
}

void MiniMap::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "clear focus";
    this->focusWidget()->clearFocus();
}

QsciScintilla *MiniMap::getText() const
{
    return text;
}

void MiniMap::setcolor()
{
//    if (text->lexer() != nullptr)
//    {
//        QsciLexer *lexer = text->lexer();
//        lexer->setDefaultColor(QColor("white"));
//        lexer->setDefaultPaper(QColor("#393d44"));
//    }
////    lexer->setDefaultFont(font);
//    text->setColor(QColor("white"));
//    text->setPaper(QColor("#393d44"));
//    text->setFont(font);
}

