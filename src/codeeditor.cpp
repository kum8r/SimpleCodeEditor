#include "codeeditor.h"

codeEditor::codeEditor()
{
    setWrapMode(this->WrapWord); // wrapword
    setMarginType(0,NumberMargin);  //number margin
    setMarginWidth(0,"0000");   //margin width is  space
    setIndentationsUseTabs(true);
    setTabWidth(4);

    QFont font("source code pro");
    font.setStyleHint(QFont::Monospace);
    this->setFont(font);

    setIndentationGuides(false);
    setAutoIndent(true);
//    setCaretForegroundColor(QColor("#ffff7f"));
    setColor("#00000");
    setBraceMatching(SloppyBraceMatch);
    mySettings = new QSettings ("kumar","SimpleCodeEditor",this);
//    autoComplete();
//    loadSettings();
}

bool codeEditor::getTextChanges() const
{
    return textChanges;
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

void codeEditor::autoCompleteForCpp(QsciLexer *lexer)
{
    QsciAPIs *API = new QsciAPIs (lexer);
    QVector<QString> autoCompleteWords = {
                                          "asm", "auto", "bool", "break", "case",
                                          "catch", "char", "class", "const", "const_cast",
                                          "continue", "default", "delete", "do", "double",
                                          "dynamic_cast", "else", "enum", "explicit",
                                          "export", "extern", "false", "float", "for",
                                          "friend", "goto", "if", "inline", "int",
                                          "long", "mutable", "namespace", "new", "operator",
                                          "private", "protected", "public", "register", "reinterpret_cast",
                                          "return", "short", "signed", "sizeof", "static",
                                          "static_cast", "struct", "switch", "namespace", "throw",
                                          "true", "try", "typedef", "typeid", "typename",
                                          "union", "unsigned", "using", "virtual", "void",
                                          "volatile", "wchar_t", "while", "template"
                                          };
    for (int i = 0;i < autoCompleteWords.size();i++) {
        API->add(autoCompleteWords.at(i));
    }
    API->prepare();
}




