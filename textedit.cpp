#include "textedit.h"
#include "ui_textedit.h"
#include <string>

TextEdit::TextEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextEdit)
{
    ui->setupUi(this);

    //check if text is changed or not
    changed = false;
}

TextEdit::~TextEdit() {
    delete ui;
}

void TextEdit::setFileName(QString filepath) {
    QFileInfo fileinfo(filepath);
    filename = fileinfo.fileName();
}

QString TextEdit::fileName() {
    return filename;
}

bool TextEdit::returnchanged() {
    return changed;
}

void TextEdit::setChanged(bool changed) {
    this->changed  = changed;
}

void TextEdit::converttouppercase() {
    ui->textEdit->replaceSelectedText(ui->textEdit->selectedText().toUpper());
}

void TextEdit::converttolowercase() {
    ui->textEdit->replaceSelectedText(ui->textEdit->selectedText().toLower());
}

void TextEdit::converttotitlecase() {
    QString str = ui->textEdit->selectedText();
    for (int i = 0; i < str.length(); i++) {
        if (str[i].isSpace()) {
            str[i + 1] = str[i+1].toUpper();
        }
        else {
            str[i] = str[i].toLower();
        }
    }
    ui->textEdit->replaceSelectedText(str);
}

void TextEdit::on_textEdit_textChanged() {
    changed = true;
}

QString TextEdit::dirName() {
    QFileInfo fileinfo(filepath);
    QDir dir = fileinfo.dir();
    dirname = dir.dirName();
    return dirname;
}

QString TextEdit::filePath() {
    return filepath;
}

//set the text from file to textedit
bool TextEdit::getfile(QString filepath) {
    this->filepath = filepath;
    QFile file(filepath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            line = in.readAll();
        }
        ui->textEdit->setText(line);
    }
    else {
        return false;
    }
    setFileName(filepath);
    return true;
}

bool TextEdit::openfile(QString filepath) {

}

bool TextEdit::saveFile() {
    QFileInfo fileinfo(filepath);
    if (fileinfo.exists()) {
        QFile file(filepath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << ui->textEdit->text();
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return  saveFileas();
    }
}

bool TextEdit::saveFileas() {
    filepath = QFileDialog::getSaveFileName(this,tr("Save File"),QDir::homePath());
    QFile file(filepath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << ui->textEdit->text();
        setFileName(filepath);
        return true;
    }
    else {
        return false;
    }
}

void TextEdit::reload() {
    QFileInfo fileinfo (filepath);
    if (fileinfo.exists()) {
        QFile file(filepath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                line = in.readAll();
            }
            ui->textEdit->setText(line);
        }
    }
}

void TextEdit::cut() {
    ui->textEdit->cut();
}

void TextEdit::copy() {
    ui->textEdit->copy();
}

void TextEdit::paste() {
    ui->textEdit->paste();
}

void TextEdit::undo() {
    ui->textEdit->undo();
}

void TextEdit::redo() {
    ui->textEdit->redo();
}

void TextEdit::selectAll() {
    ui->textEdit->selectAll();
}

void TextEdit::deselect() {
    int pos = ui->textEdit->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
    ui->textEdit->SendScintilla(QsciScintilla::SCI_SETEMPTYSELECTION,pos);
}

void TextEdit::findText(QString str) {
    ui->textEdit->findFirst(str,false,false,false,true);
}

void TextEdit::findNext() {
    ui->textEdit->findNext();
}

void TextEdit::findPrev(QString str) {
    ui->textEdit->findFirst(str,false,false,false,true,false);
}

void TextEdit::findAll(QString str) {
    if (!str.isEmpty()) {
        ui->textEdit->SendScintilla(QsciScintillaBase::SCI_INDICSETSTYLE, 0, 7);
        QString docText = ui->textEdit->text();
        int end = docText.lastIndexOf(str);
        int cur = -1;

        if(end != -1)
        {
            while(cur != end)
            {
                cur = docText.indexOf(str,cur+1);
                ui->textEdit->SendScintilla(QsciScintillaBase::SCI_INDICATORFILLRANGE,cur,str.length());
            }
        }
    }
}

void TextEdit::replaceText(QString str) {
    QString replacetext = str;
    ui->textEdit->replace(replacetext);
}

void TextEdit::replaceAll(QString str){
    ui->textEdit->replaceSelectedText(str);
}

void TextEdit::windowsEOL() {
    ui->textEdit->setEolMode(QsciScintilla::EolWindows);
}

void TextEdit::unixEOL() {
        ui->textEdit->setEolMode(QsciScintilla::EolUnix);
}

void TextEdit::osxEOL() {
    ui->textEdit->setEolMode(QsciScintilla::EolMac);
}

void TextEdit::changeFont(QFont font) {
    ui->textEdit->setFont(font);
    QsciLexer *lexer = ui->textEdit->lexer();
    if (lexer != 0) {
        lexer->setFont(font);
    }
}

QFont TextEdit::getFont() {
    QFont font = ui->textEdit->font();
    return  font;
}

void TextEdit::showLinenumbers() {
    ui->textEdit->setMarginType(1,QsciScintilla::NumberMargin);
    ui->textEdit->setMarginWidth(1,"0000");
}

void TextEdit::hideLinenumbers() {
    ui->textEdit->setMarginWidth(0,"");
}

void TextEdit::wordwrap() {
    ui->textEdit->setWrapMode(QsciScintilla::WrapCharacter);
}

void TextEdit::wordwrapNone() {
    ui->textEdit->setWrapMode(QsciScintilla::WrapNone);
}


void TextEdit::fontSize() {

}

void TextEdit::changetoNormal() {
    ui->textEdit->setLexer(0);
    changeFont(getFont());
}

void TextEdit::changetoBash() {
    QsciLexerBash *lexer = new QsciLexerBash ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoBatch() {
    QsciLexerBatch *lexer = new QsciLexerBatch ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoCpp() {
    QsciLexerCPP *lexer = new QsciLexerCPP ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
    QsciAPIs *api = new QsciAPIs(lexer);
    api->add("int");
    api->prepare();
    ui->textEdit->setAutoCompletionSource(QsciScintilla::AcsAll);
}

void TextEdit::changetoCMake() {
    QsciLexerCMake *lexer = new QsciLexerCMake ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoCScript() {
    QsciLexerCoffeeScript *lexer = new QsciLexerCoffeeScript ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoCSharp() {
    QsciLexerCSharp *lexer = new QsciLexerCSharp ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoD() {
    QsciLexerD *lexer = new QsciLexerD();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoFortan77() {
    QsciLexerFortran77 *lexer = new QsciLexerFortran77();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoYAML() {
    QsciLexerYAML *lexer = new QsciLexerYAML();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoProp() {
    QsciLexerProperties *lexer = new QsciLexerProperties();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoDiff() {
    QsciLexerDiff *lexer = new QsciLexerDiff();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoJava() {
    QsciLexerJava *lexer = new QsciLexerJava ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoCSS() {
    QsciLexerCSS *lexer = new QsciLexerCSS ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoJavascipt() {
    QsciLexerJavaScript *lexer = new QsciLexerJavaScript ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoFortan() {
    QsciLexerFortran *lexer = new QsciLexerFortran ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoJSON() {
    QsciLexerJSON *lexer = new QsciLexerJSON ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoHTML() {
    QsciLexerHTML *lexer = new QsciLexerHTML ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoLua() {
    QsciLexerLua *lexer = new QsciLexerLua ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoMakefile() {
    QsciLexerMakefile *lexer = new QsciLexerMakefile ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoMatlab() {
    QsciLexerMatlab *lexer = new QsciLexerMatlab ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoPascal() {
    QsciLexerPascal *lexer = new QsciLexerPascal ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoPython() {
    QsciLexerPython *lexer = new QsciLexerPython ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoPerl() {
    QsciLexerPerl *lexer = new QsciLexerPerl ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoXML() {
    QsciLexerXML *lexer = new QsciLexerXML ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoMarkdown() {
    QsciLexerMarkdown *lexer = new QsciLexerMarkdown ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoSQL() {
    QsciLexerSQL *lexer = new QsciLexerSQL ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoRuby() {
    QsciLexerRuby *lexer = new QsciLexerRuby ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::changetoTex() {
    QsciLexerTeX *lexer = new QsciLexerTeX ();
    ui->textEdit->setLexer(lexer);
    changeFont(getFont());
}

void TextEdit::on_textEdit_cursorPositionChanged(int line, int index) {
    texteditcursorchanged(line,index);
    if (line  > 999) {
        ui->textEdit->setMarginType(1,QsciScintilla::NumberMargin);
        ui->textEdit->setMarginWidth(1,"00000");
    }

}

void TextEdit::texteditcursorchanged(int l,int i) {
    emit cursorchanged(l,i);
}


