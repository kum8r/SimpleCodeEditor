#ifndef MINIMAP_H
#define MINIMAP_H

#include <QWidget>
#include "Qsci/qscilexer.h"
#include "Qsci/qsciscintilla.h"

namespace Ui {
class minimap;
}

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
