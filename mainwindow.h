#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "textedit.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QActionGroup>
#include <QTextStream>
#include <QSysInfo>
#include <QFontDialog>
#include <QFileSystemModel>
#include <QLabel>
#include "Qsci/qsciscintilla.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QList <TextEdit *> tabs;
    QStringList filelist;
    QString filepath;
    QString filename;
    QString line;
    MainWindow *newwindow;
    QActionGroup *lineending;
    QFileSystemModel *filemodel;
    QLabel *label;
    QTimer *timer;

//functions
    int newtab(QString tabname);
    void setEOL();
    QString settabname();


private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionClose_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionReload_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionNew_Window_triggered();

    void on_actionClose_Window_triggered();

    void on_actionClose_All_Files_triggered();

    void on_actionFind_triggered();

    void on_pushButton_clicked();

    void on_actionReplace_triggered();

    void on_actionSidebar_triggered();

    void on_actionStatusbar_triggered();

    void on_actionToolbar_triggered();

    void on_actionAbout_triggered();

    void on_actionAbout_QT_triggered();

    void on_actionFind_Next_triggered();

    void on_actionReplace_All_triggered();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_actionShow_Tabs_triggered();

    void on_actionWindows_triggered();

    void on_actionUnix_triggered();

    void on_actionMac_triggered();

    void on_actionFind_All_triggered();

    void on_actionSelect_All_triggered();

    void on_actionDeselect_triggered();

    void on_actionOpen_Directory_triggered();

    void on_actionC_2_triggered();

    void on_actionBash_triggered();

    void on_actionBatch_File_triggered();

    void on_actionCoffeeScript_triggered();

    void on_actionC_triggered();

    void on_actionJava_triggered();

    void on_actionCSS_triggered();

    void on_actionHTML_triggered();

    void on_actionJavaScript_triggered();

    void on_actionJSON_triggered();

    void on_actionMakeFile_triggered();

    void on_actionMatLab_triggered();

    void on_actionQuit_triggered();

    void on_actionPascal_triggered();

    void on_actionPython_triggered();

    void on_actionCMake_triggered();

    void on_actionFortan_triggered();

    void on_actionXML_triggered();

    void on_actionLua_triggered();

    void on_actionMarkDown_triggered();

    void on_actionPerl_triggered();

    void on_actionRuby_triggered();

    void on_actionSQL_triggered();

    void on_actionTeX_triggered();

    void on_actionC_3_triggered();

    void on_actionChange_Font_triggered();

    void on_listView_doubleClicked(const QModelIndex &index);

    void on_actionShow_Linenumbers_triggered();

    void on_tabWidget_tabCloseRequested(int index);

    void on_lineEdit_returnPressed();

    void on_actionWordWrap_triggered();

    void statusbar();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
