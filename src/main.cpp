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
    QStringList fileTypes;
    fileTypes <<  "application/x-shellscript" << "application/x-desktop" << "application/x-perl" << "application/x-php" << "application/x-ruby" << "application/xml" << "model/vrml" << "image/svg+xml" << "application/json";
    if (arguments.count() > 1)
    {
        for (int i = 1; i < arguments.count(); i++)
        {
            QString file = (arguments.at(i));
            QMimeDatabase db;
            QMimeType fileType = db.mimeTypeForFile(file);
            qDebug() << fileType.name();
            if (fileType.name().contains("text") || fileTypes.contains(fileType.name()))
            {
                w.openFile(file);
            }
//            else
//            {
//                QMessageBox::warning(this, "warning", "unknown file type");
//            }
        }
    }
    else
    {
        w.on_actionNew_triggered();
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
    QApplication app(argc, argv);
    MainWindow w;
    w.setTheme();
    QStringList fileTypes;

    fileTypes <<  "application/x-shellscript" << "application/x-desktop" << "application/x-perl" << "application/x-php" << "application/x-ruby" << "application/xml" << "model/vrml" << "image/svg+xml" << "application/json";
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            QString file = QString::fromUtf8(argv[i]);
            QMimeDatabase db;
            QMimeType fileType = db.mimeTypeForFile(file);
            qDebug() << fileType.name();
            if (fileType.name().contains("text") || fileTypes.contains(fileType.name()))
            {
                w.openFile(file);
            }
            else
            {
                QMessageBox::warning(&w, "warning", "unknown file type");
            }
        }
    }
    else
    {
        w.on_actionNew_triggered();
    }
//    Application app(argc, argv, true);

//    if (app.isSecondary())
//    {
//        app.sendMessage(app.arguments().join("#").toUtf8());
//        return 0;
//    }
    w.show();
    return app.exec();
}
