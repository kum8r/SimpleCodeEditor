#ifndef MINIMAP_H
#define MINIMAP_H

#include <QWidget>
#include "Qsci/qscilexer.h"
#include "Qsci/qsciscintilla.h"

namespace Ui {
class minimap;
}

class MinimapText : public QsciScintilla
{
public:

    explicit MinimapText(QWidget *parent = nullptr)
    {
        setMarginWidth(0, "");
        setMargins(0);
        setReadOnly(true);
        setWrapMode(QsciScintilla::WrapNone);
        setStyleSheet("margin-top:30px\n");
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    }
    void focusInEvent (QFocusEvent *e)
    {
        this->focusWidget()->clearFocus();
    }
};

class minimap : public QWidget
{
    Q_OBJECT

public:
    explicit minimap(QWidget *parent = nullptr);
    ~minimap();

    QsciScintilla *getText() const;


private:
    Ui::minimap *ui;
    QsciScintilla *text;
};

#endif // MINIMAP_H
