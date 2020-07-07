#ifndef MINIMAP_H
#define MINIMAP_H

#include "Qsci/qsciscintilla.h"

class MiniMap : public QsciScintilla
{
    Q_OBJECT
public:
    explicit MiniMap(QWidget * parent = nullptr);
    void setStyleSheet(QString t_filename);
};

#endif // MINIMAP_H
