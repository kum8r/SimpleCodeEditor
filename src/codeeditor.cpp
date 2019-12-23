#include "codeeditor.h"
#include <Qsci/qscilexercpp.h>

codeEditor::codeEditor(QWidget *parent) : QsciScintilla(parent)
{
    setWrapMode(this->WrapWord); // wrapword
    setMarginType(0,NumberMargin);  //number margin
    setMarginWidth(0,"0000");   //margin width is  space
    setIndentationsUseTabs(true);
    setTabWidth(4);
    this->setAcceptDrops(true);
    QFont font("source code pro");
    font.setStyleHint(QFont::Monospace);
    this->setFont(font);
    setIndentationGuides(false);
    setAutoIndent(true);
    setBraceMatching(SloppyBraceMatch);
    mySettings = new QSettings ("kumar","SimpleCodeEditor",this);
    connect(this, SIGNAL(textChanged()), this, SLOT(setTextChanges()));
}

codeEditor::~codeEditor()
{

}

bool codeEditor::getTextChanges() const
{
    return textChanges;
}

void codeEditor::setTextChanges()
{
    textChanges = true;
}

void codeEditor::setTextChanges(bool value)
{
    textChanges = value;
}

void codeEditor::loadSettings()
{
    QString fontName = mySettings->value("font").toString();
    int fontSize = mySettings->value("fontSize").toInt();
    this->setFont(QFont(fontName,fontSize));
    this->setTabWidth(mySettings->value("tabSize").toInt());
    if (mySettings->value("caretWidth")==4) {
        SendScintilla(SCI_SETCARETSTYLE,2);
    }
    else {
        this->setCaretWidth(mySettings->value("caretWidth").toInt());
    }
    if (mySettings->value("autoIndent").toBool()) {
        setAutoIndent(true);
    }
    else {
        setAutoIndent(false);
    }
    if (mySettings->value("matchBracket").toBool()) {
        setBraceMatching(SloppyBraceMatch);
    }
    else {
       setBraceMatching(NoBraceMatch);
    }
    if (mySettings->value("lineNumber").toBool()) {
        setMarginWidth(0, "0000");
    }
    else {
       setMarginWidth(0, "");
    }
    if (mySettings->value("wordWrap").toBool()) {
        setWrapMode(WrapWord);
    }
    else {
       setWrapMode(WrapNone);
    }
    if (mySettings->value("autoComplete").toBool()) {
        setAutoCompletionSource(AcsAll);
    }
    else {
       setAutoCompletionSource(AcsNone);
    }
}

QString codeEditor::getFileName() const
{
    return fileName;
}

void codeEditor::setFileName(const QString &value)
{
    fileName = value;
}

void codeEditor::autoComplete()
{
    this->setAutoCompletionSource(this->AcsAll);
    setAutoCompletionThreshold(2);
    setAutoCompletionCaseSensitivity(false);
}

void codeEditor::setWhiteTheme()
{
    this->setPaper(QColor(255, 255, 255));
    this->setMarginsBackgroundColor(QColor(243, 245, 247));
    this->setMarginsForegroundColor(QColor(0, 0, 0));
    this->setCaretForegroundColor(QColor(0, 0, 0));
    this->setCaretLineBackgroundColor(QColor(0, 0, 0));
    this->setColor(QColor(0,0,0));
    if (this->lexer() != 0)
    {
        QsciLexer *lexer = this->lexer();
        lexer->setDefaultPaper(QColor(255, 255, 255));
    }
}

void codeEditor::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("text/plain"))
        event->acceptProposedAction();
}

void codeEditor::dropEvent(QDropEvent *event)
{
//    if (event->mimeData()->hasFormat("text/plain"))
    {
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty())
        return;

    QString fileName = urls.first().toLocalFile();
    if (fileName.isEmpty())
        return;

    emit dropFiles(fileName);
    }
}
