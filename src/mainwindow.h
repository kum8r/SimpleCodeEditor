#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "finddialog.h"
#include "codeeditor.h"
#include "settings.h"

#include <QMainWindow>
#include <QList>
#include <QFileDialog>
#include <QDir>
#include <QFileSystemModel>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QDebug>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QPrintPreviewDialog>
#include <Qsci/qsciprinter.h>
#include <QTextDocument>
#include <QSettings>
#include <QSplitter>
#include <QSpacerItem>
#include <QInputDialog>
#include <QMimeData>

//lexer

#include "lexers/lexers.h"

#include "Qsci/qscilexer.h"
#include "Qsci/qscilexerbash.h"
#include "Qsci/qscilexerbatch.h"
#include "Qsci/qscilexercmake.h"
#include "Qsci/qscilexercoffeescript.h"
#include "Qsci/qscilexercsharp.h"
#include "Qsci/qscilexerd.h"
#include "Qsci/qscilexerdiff.h"
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
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void saveSettings();
    void saveWindowsGeomentry();
    void loadSettings();
    void loadWindowsGeomentry();

    void defaultLocation();
    void statusBar(int, int);
    void setEOL();
    int newTab(QString tabname);
    void openDirectory();
    void openFile(QString filepath = nullptr);
    void addtoOpenedFiles(QString);
    void saveFile(QString);
    void saveFileAs(QString fileName);
    void closeFile();
    void closeFile(int index);
    void lineNumwidthIncrement(int ,int);
    void setFiletype(QString);



    void syntaxHighlighting(QsciLexer* lexers);

    void setMainWindowStyle(QString,QString);
    void setTabWidgetStyle(QString, QString);
    void updateHighlighterTheme();
    void setOverViewStyle(QString, QString);
    void setLineNumStyle(QString, QString);

    void menuActionGroup();
    void changeFilename();

    void autoComplete();
    void highlighsearchtext(QString searchtext);

    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);

private slots:


    void print(QPrinter *printer);
    void lostFocus(QEvent *event);

    void on_actionNew_triggered();
    void on_actionOpen_triggered();
    void on_actionOpenDirectory_triggered();
    void on_actionSave_triggered();
    void on_actionSave_AS_triggered();
    void on_actionSave_All_triggered();
    void on_actionPrint_triggered();
    void on_actionPrint_Preview_triggered();
    void on_actionClose_triggered();
    void on_tabWidget_tabCloseRequested(int index);
    void on_actionClose_All_Files_triggered();
    void on_actionNew_Window_triggered();
    void on_actionClose_Window_triggered();
    void on_actionExit_triggered();

    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionCut_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionSelect_All_triggered();
    void on_actionDeselect_triggered();

    void on_actionFind_triggered();
    void on_actionFind_Prev_triggered();
    void on_actionReplace_triggered();
    void on_actionReplace_All_triggered();
    void findButton_clicked(QString searchtext);
    void findPrev_clicked(QString searchtext);
    void replace_clicked(QString);
    void replaceAll_clicked(QString, QString);
    void closeFindDialog();

    void on_actionOpened_Files_triggered();
    void on_actionFile_Explorer_triggered();
    void on_actionMac_triggered();
    void on_actionUnix_triggered();
    void on_actionWindows_triggered();
    void on_actionShow_Linenumbers_triggered();
    void on_actionStatusBar_triggered();
    void on_actionToolBar_triggered();

    //syntax highlightning - lexers
    void on_actionNormal_triggered();
    void on_actionBash_triggered();
    void on_actionBatch_File_triggered();
    void on_actionC_triggered();
    void on_actionCSharp_triggered();
    void on_actionCpp_triggered();
    void on_actionCSS_triggered();
    void on_actionCMake_triggered();
    void on_actionCoffeeScript_triggered();
    void on_actionD_triggered();
    void on_actionDiff_triggered();
    void on_actionFortan_triggered();
    void on_actionFortan77_triggered();
    void on_actionHTML_triggered();
    void on_actionJava_triggered();
    void on_actionJavaScript_triggered();
    void on_actionJSON_triggered();
    void on_actionLua_triggered();
    void on_actionMarkDown_triggered();
    void on_actionMakeFile_triggered();
    void on_actionMatLab_triggered();
    void on_actionPascal_triggered();
    void on_actionPython_triggered();
    void on_actionPerl_triggered();
    void on_actionProperties_triggered();
    void on_actionRuby_triggered();
    void on_actionSQL_triggered();
    void on_actionTeX_triggered();
    void on_actionXML_triggered();
    void on_actionYAML_triggered();

    void on_actionAbout_triggered();
    void on_actionAbout_QT_triggered();

    void on_treeView_doubleClicked(const QModelIndex &index);
    void on_tabWidget_currentChanged(int index);
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void setLexer(QString lexername);

    void on_actionWordWrap_triggered();
    void on_actionAdd_Indent_triggered();
    void on_actionSettings_triggered();
    void on_actionDuplicate_Line_triggered();
    void findString_Changed();
    void on_actionUPPER_CASE_triggered();
    void on_actionlower_case_triggered();
    void on_actionGo_to_Line_triggered();
    void on_actionDecrease_Indent_triggered();

private:
    Ui::MainWindow *ui;
    findDialog *find;
    Settings *settingsDialog;
    QFileSystemModel *filemodel;
    QStringList filelist;
    QLabel *lineNumLabel, *fileTypeLabel;
    QSplitter *statSpitter;
    QSpacerItem *spacer;
    QString theme;
    QColor lineColor;
    QSettings *mySettings;
    QList<int> searchTextposlist;
    QString searchString;

    void setStyleSheet(QsciLexer *lexer, QMap <QString, QString> themes);
    void setStyleSheet(QsciLexer *lexer);

protected:
    void closeEvent(QCloseEvent *event);

};

#endif // MAINWINDOW_H
