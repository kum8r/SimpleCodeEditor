#include "codeeditor.h"
#include <Qsci/qscilexercpp.h>
#include <QScrollBar>

CodeEditor::CodeEditor(QWidget *parent) : QsciScintilla(parent)
{
    setWrapMode(this->WrapWord); // wrapword
    setMarginType(0,NumberMargin);  //number margin
    setMarginWidth(0,"0000");   //margin width is  space
    setIndentationsUseTabs(true);
    setTabWidth(4);
    this->setAcceptDrops(true);
    this->verticalScrollBar()->hide();

    defaultFont = "source code pro";
    QFont font(defaultFont);
    font.setFixedPitch(true);
    font.setPointSize(13);
    this->setFont(font);

    setIndentationGuides(false);
    setAutoIndent(true);
    setBraceMatching(SloppyBraceMatch);
    mySettings = new QSettings ("kumar","SimpleCodeEditor",this);

    connect(this, SIGNAL(textChanged()), this, SLOT(setTextChanges()));

    setFoldMarginColors(QColor("grey"), QColor("#404244"));
}

CodeEditor::~CodeEditor()
{

}

bool CodeEditor::getTextChanges() const
{
    return textChanges;
}

void CodeEditor::setTextChanges()
{
    textChanges = true;
}

void CodeEditor::setTextChanges(bool value)
{
    textChanges = value;
}

void CodeEditor::loadSettings()
{
    QString fontName = mySettings->value("font").toString();
    int fontSize = mySettings->value("fontSize").toInt();
    this->setFont(QFont(fontName,fontSize));
    this->setTabWidth(mySettings->value("tabSize").toInt());

    if (mySettings->value("caretWidth")==4)
    {
        SendScintilla(SCI_SETCARETSTYLE,2);
    }
    else
    {
        this->setCaretWidth(mySettings->value("caretWidth").toInt());
    }

    if (mySettings->value("autoIndent").toBool())
    {
        setAutoIndent(true);
    }
    else
    {
        setAutoIndent(false);
    }
    if (mySettings->value("matchBracket").toBool())
    {
        setBraceMatching(SloppyBraceMatch);
    }
    else
    {
       setBraceMatching(NoBraceMatch);
    }
    if (mySettings->value("lineNumber").toBool())
    {
        setMarginWidth(0, "0000");
    }
    else
    {
       setMarginWidth(0, "");
    }
    if (mySettings->value("wordWrap").toBool())
    {
        setWrapMode(WrapWord);
    }
    else
    {
       setWrapMode(WrapNone);
    }
    if (mySettings->value("autoComplete").toBool())
    {
        setAutoCompletionSource(AcsAll);
    }
    else
    {
       setAutoCompletionSource(AcsNone);
    }
}

QString CodeEditor::getFileName() const
{
    return fileName;
}

void CodeEditor::setFileName(const QString &value)
{
    fileName = value;
}

void CodeEditor::autoComplete()
{
    this->setAutoCompletionSource(this->AcsAll);
    setAutoCompletionThreshold(2);
    setAutoCompletionCaseSensitivity(false);
}


void CodeEditor::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/plain"))
        event->acceptProposedAction();
}

void CodeEditor::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty())
        return;

    QString fileName = urls.first().toLocalFile();
    if (fileName.isEmpty())
        return;

    emit dropFiles(fileName);
}
