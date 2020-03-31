#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include "Qsci/qsciscintilla.h"
#include "Qsci/qsciapis.h"
#include "Qsci/qscilexer.h"
#include <QSettings>
#include <QDebug>
#include <QMimeData>
#include <QObject>
#include <QDragEnterEvent>

class CodeEditor : public QsciScintilla
{
    Q_OBJECT

public:
    explicit CodeEditor(QWidget *parent = nullptr);
    ~CodeEditor();

    QString defaultFont;

    void loadSettings();
    void autoComplete();
    void autoCompleteForCpp(QsciLexer *lexer);
    void setCodeFolding();
    bool getTextChanges() const;
    void setTextChanges(bool value);
    QString getFileName() const;
    void setFileName(const QString &value);
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);

signals:
    void dropFiles(QString file);

private slots:
    void setTextChanges();

private:

    bool textChanges = false;
    QString fileName = "";
    QSettings *mySettings;
};

#endif // CODEEDITOR_H
