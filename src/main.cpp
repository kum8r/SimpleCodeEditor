#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QFile f(":/style/editor_style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }
    MainWindow w;
   if (argc > 1)
   {
        for (int i = 1; i < argc; i++)
        {
            QFile file(QString::fromStdString(argv[1]));
            if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
            {
                printf("could not open file");
            }
            else
            {
                w.openFile(QString::fromStdString(argv[i]));
            }
        }
   }
   else
   {
        w.newTab("untitled");
   }
    w.show();

    return a.exec();
}
