#ifndef TERMWIDGET_H
#define TERMWIDGET_H

#include <qtermwidget5/qtermwidget.h>

class TermWidget : public QTermWidget
{

public:
    TermWidget(int startnow, QWidget *parent = nullptr);

};

#endif // TERMWIDGET_H
