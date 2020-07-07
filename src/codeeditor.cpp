#include "codeeditor.h"
#include "stylesheet.h"

#include <QFontDatabase>
#include <QScrollBar>
#include <Qsci/qscilexercpp.h>

CodeEditor::CodeEditor(QWidget * parent)
  : QsciScintilla(parent)
{
    fileName = "";
    textChanges = false;
    setMarginType(0, NumberMargin); //number margin
    //    setIndentationsUseTabs(true);
    //    setTabWidth(4);
    //    this->setAcceptDrops(true);
    //    this->verticalScrollBar()->hide();

    QFont fixedFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    fixedFont.setPointSize(12);
    this->setFont(fixedFont);

    //    setIndentationGuides(false);
    //    setAutoIndent(true);
    //    setBraceMatching(SloppyBraceMatch);
    mySettings = new QSettings("kumar", "SimpleCodeEditor", this);

    //    connect(this, SIGNAL(textChanged()), this, SLOT(setTextChanges()));

    //    setFoldMarginColors(QColor("grey"), QColor("#404244"));
}

CodeEditor::~CodeEditor()
{
}

bool CodeEditor::getTextChanges() const
{
    return textChanges;
}

void CodeEditor::initMiniMap()
{
    setMarginWidth(0, 0);
    setMargins(0);
    setReadOnly(0);
    setWrapMode(QsciScintilla::WrapNone);
    QFont fixedFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    fixedFont.setPointSize(1);
    setFont(fixedFont);
}

void CodeEditor::setTextChanges(bool value)
{
    textChanges = value;
}

QString CodeEditor::getFileName() const
{
    return fileName;
}

void CodeEditor::setFileName(const QString & value)
{
    fileName = value;
}

void CodeEditor::setColorScheme(QString t_colorschemeFile)
{
    StyleSheet * stylesheet = new StyleSheet();
    stylesheet->setFont(this->font());
    QsciLexer * lexer = this->lexer();
    stylesheet->setStyleSheet(lexer, t_colorschemeFile, this);
    setLexer(lexer);
}

void CodeEditor::setColorScheme(QString t_colorschemeFile, QsciLexer * lexer)
{
    StyleSheet * stylesheet = new StyleSheet();
    QFont font = this->font();
    font.setPointSize(1);
    stylesheet->setFont(font);
    QString text = this->text();
    clear();
    stylesheet->setStyleSheet(lexer, t_colorschemeFile, this);
    setLexer(lexer);
    setText(text);
}

void CodeEditor::autoComplete()
{
    this->setAutoCompletionSource(this->AcsAll);
    setAutoCompletionThreshold(2);
    setAutoCompletionCaseSensitivity(false);
}

void CodeEditor::dragEnterEvent(QDragEnterEvent * event)
{
    if (event->mimeData()->hasFormat("text/plain"))
        event->acceptProposedAction();
}

void CodeEditor::dropEvent(QDropEvent * event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty())
        return;

    QString fileName = urls.first().toLocalFile();
    if (fileName.isEmpty())
        return;

    emit dropFiles(fileName);
}

QString CodeEditor::getFileType() const
{
    return m_fileType;
}

void CodeEditor::setFileType(const QString & fileType)
{
    m_fileType = fileType;
}

void CodeEditor::toggleCommentLines()
{
    /*bash
        { "CSS", new QsciLexerCSS() }, - no
        { "Diff", new QsciLexerDiff() },
        { "HTML", new QsciLexerHTML() },
        { "JSON", new QsciLexerJSON() },
        { "Lua", new QsciLexerLua() },
        { "Makefile", new QsciLexerMakefile() },
        { "Markdown", new QsciLexerMarkdown() },
        { "Matlab", new QsciLexerMatlab() },
        { "Pascal", new QsciLexerPascal() },
        { "TeX", new QsciLexerTeX() },
        { "YAML", new QsciLexerYAML() },
        { "XML", new QsciLexerXML() }
xml*/
    QString m_fileType = this->lexer()->lexer();
    QString comment;

    if (m_fileType == "C++" || m_fileType == "PHP" || m_fileType == "C#" || m_fileType == "Java" || m_fileType == "Javascript"
        || m_fileType == "D")
        comment = "//";
    else if (m_fileType == "Bash" || m_fileType == "Python" || m_fileType == "CMake" || m_fileType == "Makefile" || m_fileType == "Perl" || m_fileType == "Properties"
             || m_fileType == "CoffeeScript" || m_fileType == "Ruby")
        comment = "#";
    else if (m_fileType == "Batch")
        comment = "::";
    else if (m_fileType == "Fortran" || m_fileType == "Fortan77")
        comment = "!";
    else if (m_fileType == "Matlab")
        comment = "%";
    else if (m_fileType == "SQL")
        comment = "--";

    if (comment.isEmpty())
        return;

    if (this->hasSelectedText())
    {
        int line1, col1, line2, col2, curLine, curCol;
        this->getSelection(&line1, &col1, &line2, &col2);
        this->getCursorPosition(&curLine, &curCol);

        QString str1 = this->text(line1);
        QString ln = str1.simplified();
        bool toComment = true;

        if (ln.startsWith(comment))
        {
            toComment = false;
        }

        if (col2 == 0)
            --line2;

        for (int line = line1; line <= line2; ++line)
        {
            str1 = this->text(line);
            if (toComment)
            {
                if (!str1.simplified().startsWith(comment))
                    commentLine(line, str1, comment);
            }
            else
            {
                if (str1.simplified().startsWith(comment))
                    uncommentLine(line, str1, comment);
            }
        }

        if (curCol > 0)
            this->setCursorPosition(curLine, curCol + comment.length() * (toComment ? 1 : -1));
        else
            this->setCursorPosition(curLine, curCol);
    }
    else
    {
        int line1, col1;
        this->getCursorPosition(&line1, &col1);
        QString str1 = this->text(line1);

        QString ln = str1.simplified();
        if (ln.startsWith(comment))
        {
            uncommentLine(line1, str1, comment);
            this->setCursorPosition(line1, col1 - comment.length());
        }
        else
        {
            commentLine(line1, str1, comment);
            this->setCursorPosition(line1, col1 + comment.length());
        }
    }
}

void CodeEditor::toggleCommentBlock()
{
    QString commBeg, commEnd;
    QString s = this->lexer()->lexer();
    if (s == "C++" || s == "Java" || s == "CSharp" || s == "PHP" || s == "CSS" || s == "Javascript" || s == "SQL")
    {
        commBeg = "/*";
        commEnd = "*/";
    }
    else if (s == "HTML" || s == "XML")
    {
        commBeg = "<!--";
        commEnd = "-->";
    }
    else if (s == "Python")
    {
        commBeg = "'''";
        commEnd = "'''";
    }

    if (commBeg.isEmpty() || commEnd.isEmpty())
        return;

    if (this->hasSelectedText())
    {
        int line1, col1, line2, col2, curLine, curCol;
        this->getSelection(&line1, &col1, &line2, &col2);
        this->getCursorPosition(&curLine, &curCol);

        QString str1 = this->selectedText();
        bool toComment = true;
        if (str1.startsWith(commBeg) && str1.endsWith(commEnd))
            toComment = false;

        QString str2;
        if (toComment)
            str2 = commBeg + str1 + commEnd;
        else
        {
            str2 = str1;
            str2.chop(commEnd.length());
            str2.remove(0, commBeg.length());
        }
        replaceSelectedText(str2);
        if (line1 == line2)
        {
            if (curCol == col1)
                this->setCursorPosition(curLine, curCol);
            else
                this->setCursorPosition(curLine, curCol + (commBeg.length() + commEnd.length()) * (toComment ? 1 : -1));
        }
        else
        {
            if (curLine == line2 && curCol == col2)
                this->setCursorPosition(curLine, curCol + commEnd.length() * (toComment ? 1 : -1));
            else
                this->setCursorPosition(curLine, curCol);
        }
    }
}

void CodeEditor::commentLine(int line, const QString & str1, const QString & comment)
{
    QString str2 = comment + str1;
    this->setSelection(line, 0, line + 1, 0);
    replaceSelectedText(str2);
}

void CodeEditor::uncommentLine(int line, const QString & str1, const QString & comment)
{
    int pos = str1.indexOf(comment);
    QString str2 = str1;
    str2.replace(pos, comment.length(), "");
    this->setSelection(line, 0, line + 1, 0);
    replaceSelectedText(str2);
}
