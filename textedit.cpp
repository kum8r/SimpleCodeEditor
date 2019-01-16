#include "textedit.h"
#include "ui_textedit.h"
#include <string>

TextEdit::TextEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextEdit)
{
    ui->setupUi(this);

    //removing spaces from gridlayout
    ui->gridLayout->setSpacing(0);
    ui->gridLayout->setMargin(0);
    ui->gridLayout->setContentsMargins(0,0,0,0);

    //check if text is changed or not
    changed = false;

    //list of syntaxes
     lexers.insert('None', "None");
     lexers.insert('Bash', "QsciLexerBash");
     lexers.insert("Batch","QsciLexerBatch");
     lexers.insert("CMake", "QsciLexerCMake");
     lexers.insert("CoffeeScript", "QsciLexerCoffeeScript");
     lexers.insert("C++", "QsciLexerCPP");
     lexers.insert("C#","QsciLexerCSharp");
     lexers.insert("CSS","QsciLexerCSS");
     lexers.insert("Fortran","QsciLexerFortran");
     lexers.insert("HTML","QsciLexerHTML");
     lexers.insert("Java","QsciLexerJava");
     lexers.insert("JavaScript","QsciLexerJavaScript");
     lexers.insert("JSON","QsciLexerJSON");
     lexers.insert("Lua","QsciLexerLua");
     lexers.insert("Makefile","QsciLexerMakefile");
     lexers.insert("Markdown","QsciLexerMarkdown");
     lexers.insert("Matlab","QsciLexerMatlab");
     lexers.insert("Pascal","QsciLexerPascal");
     lexers.insert("Perl","QsciLexerPerl");
     lexers.insert("Python","QsciLexerPython");
     lexers.insert("Ruby","QsciLexerRuby");
     lexers.insert("SQL","QsciLexerSQL");
     lexers.insert("TeX","QsciLexerTeX");
     lexers.insert("YAML","QsciLexerYAML");
     lexers.insert("XML","QsciLexerXML");
}

TextEdit::~TextEdit() {
    delete ui;
}

bool TextEdit::getfile(QString filepath) {
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

bool TextEdit::openfile() {
    filepath = QFileDialog::getOpenFileName(this,tr("Open File"),QDir::homePath());
    return getfile(filepath);
}

void TextEdit::setFileName(QString filepath) {
    QFileInfo fileinfo(filepath);
    filename = fileinfo.fileName();
}

QString TextEdit::fileName() {
    return filename;
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
        if (saveFileas()) {
            return true;
        }
        else {
            return false;
        }
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


bool TextEdit::close() {
    QFileInfo fileinfo(filepath);
    if (fileinfo.exists()) {
        filename = fileinfo.fileName();
        QFile file(filepath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                line = in.readAll();
            }
            if (line == ui->textEdit->text()) {
                    return true;
            }
            else {
                QMessageBox::StandardButton ask = QMessageBox::question(this,tr("Save"),tr("Do You want to Save file")+
                                                                        filename,QMessageBox::Yes | QMessageBox::No |
                                                                        QMessageBox::Cancel,QMessageBox::Cancel);
                if (ask == QMessageBox::Yes) {
                    saveFile();
                    return true;
                }
                else if (ask == QMessageBox::No) {
                    return true;
                }
                else if (ask == QMessageBox::Cancel) {
                    return false;
                }
            }
        }
    }
    else {
        if (!(ui->textEdit->text()=="")) {
            QMessageBox::StandardButton ask = QMessageBox::question(this,tr("Save"),tr("Do You want to Save file"),
                                                                    QMessageBox::Yes | QMessageBox::No |
                                                                   QMessageBox::Cancel, QMessageBox::Cancel);
            if (ask == QMessageBox::Yes) {
                saveFile();
                return true;
            }
            else if (ask == QMessageBox::No) {
                return true;
            }
            else if (ask == QMessageBox::Cancel) {
                return false;
            }
        }
        else {
            return true;
        }

    }
    return false;
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

void TextEdit::undo() {
    ui->textEdit->undo();
}

void TextEdit::redo() {
    ui->textEdit->redo();
}

void TextEdit::findText(QString str) {
    ui->textEdit->findFirst(str,false,false,false,true);
}

void TextEdit::replaceText(QString str) {
    QString replacetext = str;
    ui->textEdit->replace(replacetext);
}

void TextEdit::replaceAll(QString str){
    ui->textEdit->replaceSelectedText(str);
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
                ui->textEdit->SendScintilla(QsciScintillaBase::SCI_INDICATORFILLRANGE,cur,
                    str.length());
            }
        }
    }
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

void TextEdit::selectAll() {
    ui->textEdit->selectAll();
}

void TextEdit::deselect() {
    int pos = ui->textEdit->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
    ui->textEdit->SendScintilla(QsciScintilla::SCI_SETEMPTYSELECTION,pos);
}

void TextEdit::changesyntax(QString str) {
    QVariant key = lexers.key(str);
    QsciLexerBash *l = new QsciLexerBash ();
    ui->textEdit->setLexer(l);
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

int TextEdit::getLinecount() {
    int pos = ui->textEdit->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
    int linecount  = ui->textEdit->SendScintilla(QsciScintilla::SCI_LINEFROMPOSITION,pos);
    return linecount;
}

int TextEdit::getColpos() {
    int pos = ui->textEdit->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
    int colpos = ui->textEdit->SendScintilla(QsciScintilla::SCI_GETCOLUMN,pos);
    return colpos;
}

void TextEdit::fontSize() {

}

bool TextEdit::returnchanged() {
    return changed;
}

void TextEdit::setChanged(bool changed) {
    this->changed  = changed;
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

void TextEdit::findNext() {
    ui->textEdit->findNext();
}

void TextEdit::on_textEdit_cursorPositionChanged(int line, int index) {
    if (line  > 999) {
        ui->textEdit->setMarginType(1,QsciScintilla::NumberMargin);
        ui->textEdit->setMarginWidth(1,"00000");
    }

}

void TextEdit::on_textEdit_textChanged() {
    changed = true;
}
