#include "termwidget.h"

#include <QFontDatabase>
#include <QProcessEnvironment>

TermWidget::TermWidget(int startnow, QWidget * parent)
  : QTermWidget(startnow, parent)
{
    QFont fixedFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    fixedFont.setPointSize(12);
    this->setTerminalFont(fixedFont);
    setenv("TERM", "xterm-256color", 1);
    setColorScheme("WhiteOnBlack");
    QStringList env;
    env << "TERM=xterm";
    setEnvironment(env);
}
