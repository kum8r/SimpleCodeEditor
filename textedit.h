#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include "Qsci/qsciscintilla.h"
#include "Qsci/qsciapis.h"
#include "Qsci/qscilexer.h"
#include "Qsci/qscilexerbash.h"
#include "Qsci/qscilexercmake.h"
#include "Qsci/qscilexercoffeescript.h"
#include "Qsci/qscilexercpp.h"
#include "Qsci/qscilexercsharp.h"
#include "Qsci/qscilexerd.h"
#include "Qsci/qscilexerdiff.h"
#include "Qsci/qscilexerbatch.h"
#include "Qsci/qscilexerjava.h"
#include "Qsci/qscilexerjavascript.h"
#include "Qsci/qscilexerjson.h"
#include "Qsci/qscilexerhtml.h"
#include "Qsci/qscilexerfortran.h"
#include "Qsci/qscilexerfortran77.h"
#include "Qsci/qscilexercss.h"
#include "Qsci/qscilexerlua.h"
#include "Qsci/qscilexerlua.h"
#include "Qsci/qscilexermakefile.h"
#include "Qsci/qscilexermarkdown.h"
#include "Qsci/qscilexermatlab.h"
#include "Qsci/qscilexerproperties.h"
#include "Qsci/qscilexerpascal.h"
#include "Qsci/qscilexerperl.h"
#include "Qsci/qscilexerpython.h"
#include "Qsci/qscilexerruby.h"
#include "Qsci/qscilexersql.h"
#include "Qsci/qscilexertex.h"
#include "Qsci/qscilexerxml.h"
#include "Qsci/qscilexeryaml.h"

namespace Ui {
class TextEdit;
}

class TextEdit : public QDialog
{
    Q_OBJECT

public:
    explicit TextEdit(QWidget *parent = 0);
    ~TextEdit();


    //variables
    QString filepath;
    QString line;
    QString filename;
    QString dirname;
    QMap <QVariant, QVariant> lexers;
    bool changed;

    //functions
    bool getfile(QString filepath);
    bool openfile(QString filepath);
    void setFileName(QString filepath);
    QString fileName();
    QString dirName();
    QString filePath();
    bool saveFile();
    bool saveFileas();
    void cut();
    void copy();
    void paste();
    void reload();
    void undo();
    void redo();
    void findText(QString str);
    void findNext();
    void findPrev(QString str);
    void replaceText(QString str);
    void replaceAll(QString str);
    void findAll(QString str);
    void windowsEOL();
    void unixEOL();
    void osxEOL();
    void selectAll();
    void deselect();
    void changeFont(QFont);
    QFont getFont();
    void showLinenumbers();
    void hideLinenumbers();
    void wordwrap();
    void wordwrapNone();
    int getLinecount();
    int getColpos();
    void fontSize();
    bool returnchanged();
    void setChanged(bool changed);
    void converttouppercase();
    void converttolowercase();
    void converttotitlecase();

    //lexers
    void changetoNormal();
    void changetoBash();
    void changetoBatch();
    void changetoCpp();
    void changetoCMake();
    void changetoCScript();
    void changetoCSharp();
    void changetoD();
    void changetoFortan77();
    void changetoYAML();
    void changetoProp();
    void changetoDiff();
    void changetoJava();
    void changetoCSS();
    void changetoJavascipt();
    void changetoFortan();
    void changetoJSON();
    void changetoHTML();
    void changetoLua();
    void changetoMakefile();
    void changetoMatlab();
    void changetoPascal();
    void changetoPython();
    void changetoPerl();
    void changetoXML();
    void changetoMarkdown();
    void changetoSQL();
    void changetoRuby();
    void changetoTex();

private slots:

    void on_textEdit_cursorPositionChanged(int line, int index);

    void on_textEdit_textChanged();

    void texteditcursorchanged(int l,int i);


signals:
    void cursorchanged(int l,int i);


private:
    Ui::TextEdit *ui;
};

#endif // TEXTEDIT_H
