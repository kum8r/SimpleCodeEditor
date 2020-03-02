#include "mainwindow.h"
#include <QApplication>
#include "singleapplication.h"
#include <QMimeDatabase>

class Application : public SingleApplication
{
public:
    explicit Application(int &argc, char *argv[], bool allowSecondary = false, Options options = Mode::User, int timeout = 1000);
    ~Application();
    void run();
    void addarguments(QStringList arguments);

public slots:
    void onArgumentRecieved(quint32 instanceId, QByteArray message);

private:
    MainWindow w;
};

Application::Application(int &argc, char *argv[], bool allowSecondary, SingleApplication::Options options, int timeout):
    SingleApplication(argc, argv, allowSecondary, options, timeout)
{
    connect(this, &Application::receivedMessage, this, &Application::onArgumentRecieved);
}

Application::~Application()
{
}

void Application::run()
{
    w.show();
}

void Application::addarguments(QStringList arguments)
{
    if (arguments.count() > 1)
    {
         for (int i = 1; i < arguments.count(); i++)
         {
             QString file = (arguments.at(i));
             QMimeDatabase db;
             QMimeType fileType = db.mimeTypeForFile(file);
             qDebug() << fileType.name();
             w.openFile(file);
//             if (fileType.name().contains("video"))
//             {
////                w.addToPlaylist(file);
//             }
         }
    }
}

void Application::onArgumentRecieved(quint32 instanceId, QByteArray message)
{
    QStringList arguments;
    QList<QByteArray> messages = message.split('#');

    foreach (QByteArray mes, messages)
    {
        arguments.append(QString::fromLocal8Bit(mes));
    }
    addarguments(arguments);
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QFile f(":/style/editor_style.qss");
//    if (!f.exists())
//    {
//        printf("Unable to set stylesheet, file not found\n");
//    }
//    else
//    {
//        f.open(QFile::ReadOnly | QFile::Text);
//        QTextStream ts(&f);
//        qApp->setStyleSheet(ts.readAll());
//    }

//    MainWindow w;
//   if (argc > 1)
//   {
//        for (int i = 1; i < argc; i++)
//        {
//            QFile file(QString::fromStdString(argv[1]));
//            if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
//            {
//                printf("could not open file");
//            }
//            else
//            {
//                w.openFile(QString::fromStdString(argv[i]));
//            }
//        }
//   }
//   else
//   {
//        w.newTab("untitled");
//   }
//    w.show();

    Application app(argc, argv, true);

    if (app.isSecondary())
    {
        app.sendMessage(app.arguments().join("#").toUtf8());
        return 0;
    }
    app.addarguments(app.arguments());
    app.run();
    return a.exec();
}
