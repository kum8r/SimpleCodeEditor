#include "termwidget.h"
#include <QProcessEnvironment>
#include <QDebug>
termwidget::termwidget(int startnow, QWidget *parent) : QTermWidget(startnow, parent)
{
    QFont font;
    font.setFamily("Monospace");
    font.setPointSize(12);
    this->setTerminalFont(font);
    setenv("TERM", "xterm-256color", 1);
    setColorScheme("WhiteOnBlack");
    QStringList env;
    env << "TERM=xterm";
    setEnvironment(env);
}
