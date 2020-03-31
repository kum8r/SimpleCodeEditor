#ifndef MINIMAP_H
#define MINIMAP_H

#include <QWidget>
#include "Qsci/qscilexer.h"
#include "Qsci/qsciscintilla.h"

namespace Ui {
class minimap;
}

class MiniMap : public QWidget
{
    Q_OBJECT

public:
    explicit MiniMap(QWidget *parent = nullptr);
    ~MiniMap();
    void focusInEvent (QFocusEvent *e);
    void mousePressEvent(QMouseEvent *event);
    QsciScintilla *getText() const;
    void setcolor();

private:
    Ui::minimap *ui;
    QsciScintilla *text;
};

#endif // MINIMAP_H
