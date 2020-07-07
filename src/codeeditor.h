#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include "Qsci/qsciapis.h"
#include "Qsci/qscilexer.h"
#include "Qsci/qsciscintilla.h"
#include <QDebug>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QObject>
#include <QSettings>

class CodeEditor : public QsciScintilla
{
    Q_OBJECT

public:
    explicit CodeEditor(QWidget * parent = nullptr);
    ~CodeEditor();

    void autoComplete();
    void autoCompleteForCpp(QsciLexer * lexer);
    void setCodeFolding();

    bool getTextChanges() const;
    void setTextChanges(bool value);

    QString getFileName() const;
    void setFileName(const QString & value);

    void setColorScheme(QString t_colorschemeFile);
    void setColorScheme(QString t_colorschemeFile, QsciLexer * lexer);

    void initMiniMap();

    void toggleCommentLines();
    void toggleCommentBlock();

    QString getFileType() const;
    void setFileType(const QString & fileType);

protected:
    void dragEnterEvent(QDragEnterEvent * event);
    void dropEvent(QDropEvent * event);

signals:
    void dropFiles(QString file);

private:
    bool textChanges;
    QString fileName, m_fileType;
    QSettings * mySettings;

    void commentLine(int line, const QString & str1, const QString & comment);
    void uncommentLine(int line, const QString & str1, const QString & comment);
};

#endif // CODEEDITOR_H
