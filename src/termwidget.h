#ifndef TERMWIDGET_H
#define TERMWIDGET_H

#include <qtermwidget5/qtermwidget.h>

class termwidget : public QTermWidget
{

public:
    termwidget(int startnow, QWidget *parent = nullptr);

};

#endif // TERMWIDGET_H
