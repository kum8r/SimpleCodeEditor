/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_AS;
    QAction *actionExit;
    QAction *actionOpenDirectory;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionSelect_All;
    QAction *actionAbout;
    QAction *actionAbout_QT;
    QAction *actionClose;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionDeselect;
    QAction *actionFile_Explorer;
    QAction *actionOpened_Files;
    QAction *actionNew_Window;
    QAction *actionClose_Window;
    QAction *actionUnix;
    QAction *actionWindows;
    QAction *actionMac;
    QAction *actionClose_All_Files;
    QAction *actionFind;
    QAction *actionFind_Prev;
    QAction *actionReplace;
    QAction *actionReplace_All;
    QAction *actionToolBar;
    QAction *actionJSON;
    QAction *actionBatch_File;
    QAction *actionCoffeeScript;
    QAction *actionCSharp;
    QAction *actionJava;
    QAction *actionCSS;
    QAction *actionJavaScript;
    QAction *actionMakeFile;
    QAction *actionMatLab;
    QAction *actionPascal;
    QAction *actionPython;
    QAction *actionBash;
    QAction *actionCMake;
    QAction *actionCpp;
    QAction *actionFortan;
    QAction *actionXML;
    QAction *actionLua;
    QAction *actionMarkDown;
    QAction *actionPerl;
    QAction *actionRuby;
    QAction *actionSQL;
    QAction *actionTeX;
    QAction *actionC;
    QAction *actionYAML;
    QAction *actionNormal;
    QAction *actionDiff;
    QAction *actionFortan77;
    QAction *actionD;
    QAction *actionProperties;
    QAction *actionShow_Linenumbers;
    QAction *actionHTML;
    QAction *actionStatusBar;
    QAction *actionWordWrap;
    QAction *actionSettings;
    QAction *actionPrint;
    QAction *actionPrint_Preview;
    QAction *actionAdd_Indent;
    QAction *actionDecrease_Indent;
    QAction *actionPrefrences;
    QAction *actionSave_All;
    QAction *actionDuplicate_Line;
    QAction *actionUPPER_CASE;
    QAction *actionlower_case;
    QAction *actionGo_to_Line;
    QAction *actionShow_Minimap;
    QAction *actionDark;
    QAction *actionLight;
    QAction *actionclear;
    QAction *actionComment;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *openedFiles;
    QLabel *label_2;
    QListWidget *listWidget;
    QWidget *layoutWidget1;
    QVBoxLayout *fileExplorer;
    QLabel *label;
    QTreeView *treeView;
    QSplitter *splitter_3;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *widget_2;
    QWidget *widget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuRecent_files;
    QMenu *menuEdit;
    QMenu *menuIndent;
    QMenu *menuLine;
    QMenu *menuConvert_to;
    QMenu *menuHelp;
    QMenu *menuView;
    QMenu *menuShow_Panels;
    QMenu *menuLine_Ending;
    QMenu *menuSyntax;
    QMenu *menuFind;
    QMenu *menuPrefrences;
    QMenu *menuThemes;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(720, 544);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/SimpleCodeEditor.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("border:0;"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon1;
        QString iconThemeName = QString::fromUtf8("document-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionNew->setIcon(icon1);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionOpen->setIcon(icon2);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionSave->setIcon(icon3);
        actionSave_AS = new QAction(MainWindow);
        actionSave_AS->setObjectName(QString::fromUtf8("actionSave_AS"));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("document-save-as");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionSave_AS->setIcon(icon4);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon5;
        iconThemeName = QString::fromUtf8("window-close");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionExit->setIcon(icon5);
        actionOpenDirectory = new QAction(MainWindow);
        actionOpenDirectory->setObjectName(QString::fromUtf8("actionOpenDirectory"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon6;
        iconThemeName = QString::fromUtf8("edit-cut");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionCut->setIcon(icon6);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon7;
        iconThemeName = QString::fromUtf8("edit-copy");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon7 = QIcon::fromTheme(iconThemeName);
        } else {
            icon7.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionCopy->setIcon(icon7);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon8;
        iconThemeName = QString::fromUtf8("edit-paste");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon8 = QIcon::fromTheme(iconThemeName);
        } else {
            icon8.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionPaste->setIcon(icon8);
        actionSelect_All = new QAction(MainWindow);
        actionSelect_All->setObjectName(QString::fromUtf8("actionSelect_All"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_QT = new QAction(MainWindow);
        actionAbout_QT->setObjectName(QString::fromUtf8("actionAbout_QT"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon9;
        iconThemeName = QString::fromUtf8("document-close");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon9 = QIcon::fromTheme(iconThemeName);
        } else {
            icon9.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionClose->setIcon(icon9);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon10;
        iconThemeName = QString::fromUtf8("edit-undo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon10 = QIcon::fromTheme(iconThemeName);
        } else {
            icon10.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionUndo->setIcon(icon10);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon11;
        iconThemeName = QString::fromUtf8("edit-redo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon11 = QIcon::fromTheme(iconThemeName);
        } else {
            icon11.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionRedo->setIcon(icon11);
        actionDeselect = new QAction(MainWindow);
        actionDeselect->setObjectName(QString::fromUtf8("actionDeselect"));
        actionFile_Explorer = new QAction(MainWindow);
        actionFile_Explorer->setObjectName(QString::fromUtf8("actionFile_Explorer"));
        actionFile_Explorer->setCheckable(true);
        actionOpened_Files = new QAction(MainWindow);
        actionOpened_Files->setObjectName(QString::fromUtf8("actionOpened_Files"));
        actionOpened_Files->setCheckable(true);
        actionNew_Window = new QAction(MainWindow);
        actionNew_Window->setObjectName(QString::fromUtf8("actionNew_Window"));
        QIcon icon12;
        iconThemeName = QString::fromUtf8("window-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon12 = QIcon::fromTheme(iconThemeName);
        } else {
            icon12.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionNew_Window->setIcon(icon12);
        actionClose_Window = new QAction(MainWindow);
        actionClose_Window->setObjectName(QString::fromUtf8("actionClose_Window"));
        actionClose_Window->setIcon(icon5);
        actionUnix = new QAction(MainWindow);
        actionUnix->setObjectName(QString::fromUtf8("actionUnix"));
        actionUnix->setCheckable(true);
        actionWindows = new QAction(MainWindow);
        actionWindows->setObjectName(QString::fromUtf8("actionWindows"));
        actionWindows->setCheckable(true);
        actionMac = new QAction(MainWindow);
        actionMac->setObjectName(QString::fromUtf8("actionMac"));
        actionMac->setCheckable(true);
        actionClose_All_Files = new QAction(MainWindow);
        actionClose_All_Files->setObjectName(QString::fromUtf8("actionClose_All_Files"));
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        actionFind_Prev = new QAction(MainWindow);
        actionFind_Prev->setObjectName(QString::fromUtf8("actionFind_Prev"));
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName(QString::fromUtf8("actionReplace"));
        actionReplace_All = new QAction(MainWindow);
        actionReplace_All->setObjectName(QString::fromUtf8("actionReplace_All"));
        actionToolBar = new QAction(MainWindow);
        actionToolBar->setObjectName(QString::fromUtf8("actionToolBar"));
        actionToolBar->setCheckable(true);
        actionToolBar->setChecked(false);
        actionJSON = new QAction(MainWindow);
        actionJSON->setObjectName(QString::fromUtf8("actionJSON"));
        actionJSON->setCheckable(true);
        actionBatch_File = new QAction(MainWindow);
        actionBatch_File->setObjectName(QString::fromUtf8("actionBatch_File"));
        actionBatch_File->setCheckable(true);
        actionCoffeeScript = new QAction(MainWindow);
        actionCoffeeScript->setObjectName(QString::fromUtf8("actionCoffeeScript"));
        actionCoffeeScript->setCheckable(true);
        actionCSharp = new QAction(MainWindow);
        actionCSharp->setObjectName(QString::fromUtf8("actionCSharp"));
        actionCSharp->setCheckable(true);
        actionJava = new QAction(MainWindow);
        actionJava->setObjectName(QString::fromUtf8("actionJava"));
        actionJava->setCheckable(true);
        actionCSS = new QAction(MainWindow);
        actionCSS->setObjectName(QString::fromUtf8("actionCSS"));
        actionCSS->setCheckable(true);
        actionJavaScript = new QAction(MainWindow);
        actionJavaScript->setObjectName(QString::fromUtf8("actionJavaScript"));
        actionJavaScript->setCheckable(true);
        actionMakeFile = new QAction(MainWindow);
        actionMakeFile->setObjectName(QString::fromUtf8("actionMakeFile"));
        actionMakeFile->setCheckable(true);
        actionMatLab = new QAction(MainWindow);
        actionMatLab->setObjectName(QString::fromUtf8("actionMatLab"));
        actionMatLab->setCheckable(true);
        actionPascal = new QAction(MainWindow);
        actionPascal->setObjectName(QString::fromUtf8("actionPascal"));
        actionPascal->setCheckable(true);
        actionPython = new QAction(MainWindow);
        actionPython->setObjectName(QString::fromUtf8("actionPython"));
        actionPython->setCheckable(true);
        actionBash = new QAction(MainWindow);
        actionBash->setObjectName(QString::fromUtf8("actionBash"));
        actionBash->setCheckable(true);
        actionCMake = new QAction(MainWindow);
        actionCMake->setObjectName(QString::fromUtf8("actionCMake"));
        actionCMake->setCheckable(true);
        actionCpp = new QAction(MainWindow);
        actionCpp->setObjectName(QString::fromUtf8("actionCpp"));
        actionCpp->setCheckable(true);
        actionFortan = new QAction(MainWindow);
        actionFortan->setObjectName(QString::fromUtf8("actionFortan"));
        actionFortan->setCheckable(true);
        actionXML = new QAction(MainWindow);
        actionXML->setObjectName(QString::fromUtf8("actionXML"));
        actionXML->setCheckable(true);
        actionLua = new QAction(MainWindow);
        actionLua->setObjectName(QString::fromUtf8("actionLua"));
        actionLua->setCheckable(true);
        actionMarkDown = new QAction(MainWindow);
        actionMarkDown->setObjectName(QString::fromUtf8("actionMarkDown"));
        actionMarkDown->setCheckable(true);
        actionPerl = new QAction(MainWindow);
        actionPerl->setObjectName(QString::fromUtf8("actionPerl"));
        actionPerl->setCheckable(true);
        actionRuby = new QAction(MainWindow);
        actionRuby->setObjectName(QString::fromUtf8("actionRuby"));
        actionRuby->setCheckable(true);
        actionSQL = new QAction(MainWindow);
        actionSQL->setObjectName(QString::fromUtf8("actionSQL"));
        actionSQL->setCheckable(true);
        actionTeX = new QAction(MainWindow);
        actionTeX->setObjectName(QString::fromUtf8("actionTeX"));
        actionTeX->setCheckable(true);
        actionC = new QAction(MainWindow);
        actionC->setObjectName(QString::fromUtf8("actionC"));
        actionC->setCheckable(true);
        actionYAML = new QAction(MainWindow);
        actionYAML->setObjectName(QString::fromUtf8("actionYAML"));
        actionYAML->setCheckable(true);
        actionNormal = new QAction(MainWindow);
        actionNormal->setObjectName(QString::fromUtf8("actionNormal"));
        actionNormal->setCheckable(true);
        actionDiff = new QAction(MainWindow);
        actionDiff->setObjectName(QString::fromUtf8("actionDiff"));
        actionDiff->setCheckable(true);
        actionFortan77 = new QAction(MainWindow);
        actionFortan77->setObjectName(QString::fromUtf8("actionFortan77"));
        actionFortan77->setCheckable(true);
        actionD = new QAction(MainWindow);
        actionD->setObjectName(QString::fromUtf8("actionD"));
        actionD->setCheckable(true);
        actionProperties = new QAction(MainWindow);
        actionProperties->setObjectName(QString::fromUtf8("actionProperties"));
        actionProperties->setCheckable(true);
        actionShow_Linenumbers = new QAction(MainWindow);
        actionShow_Linenumbers->setObjectName(QString::fromUtf8("actionShow_Linenumbers"));
        actionShow_Linenumbers->setCheckable(true);
        actionShow_Linenumbers->setChecked(true);
        actionHTML = new QAction(MainWindow);
        actionHTML->setObjectName(QString::fromUtf8("actionHTML"));
        actionHTML->setCheckable(true);
        actionStatusBar = new QAction(MainWindow);
        actionStatusBar->setObjectName(QString::fromUtf8("actionStatusBar"));
        actionStatusBar->setCheckable(true);
        actionStatusBar->setChecked(true);
        actionWordWrap = new QAction(MainWindow);
        actionWordWrap->setObjectName(QString::fromUtf8("actionWordWrap"));
        actionWordWrap->setCheckable(true);
        actionWordWrap->setChecked(true);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionPrint = new QAction(MainWindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        actionPrint_Preview = new QAction(MainWindow);
        actionPrint_Preview->setObjectName(QString::fromUtf8("actionPrint_Preview"));
        actionAdd_Indent = new QAction(MainWindow);
        actionAdd_Indent->setObjectName(QString::fromUtf8("actionAdd_Indent"));
        actionDecrease_Indent = new QAction(MainWindow);
        actionDecrease_Indent->setObjectName(QString::fromUtf8("actionDecrease_Indent"));
        actionPrefrences = new QAction(MainWindow);
        actionPrefrences->setObjectName(QString::fromUtf8("actionPrefrences"));
        actionSave_All = new QAction(MainWindow);
        actionSave_All->setObjectName(QString::fromUtf8("actionSave_All"));
        actionDuplicate_Line = new QAction(MainWindow);
        actionDuplicate_Line->setObjectName(QString::fromUtf8("actionDuplicate_Line"));
        actionUPPER_CASE = new QAction(MainWindow);
        actionUPPER_CASE->setObjectName(QString::fromUtf8("actionUPPER_CASE"));
        actionlower_case = new QAction(MainWindow);
        actionlower_case->setObjectName(QString::fromUtf8("actionlower_case"));
        actionGo_to_Line = new QAction(MainWindow);
        actionGo_to_Line->setObjectName(QString::fromUtf8("actionGo_to_Line"));
        actionShow_Minimap = new QAction(MainWindow);
        actionShow_Minimap->setObjectName(QString::fromUtf8("actionShow_Minimap"));
        actionDark = new QAction(MainWindow);
        actionDark->setObjectName(QString::fromUtf8("actionDark"));
        actionLight = new QAction(MainWindow);
        actionLight->setObjectName(QString::fromUtf8("actionLight"));
        actionclear = new QAction(MainWindow);
        actionclear->setObjectName(QString::fromUtf8("actionclear"));
        actionComment = new QAction(MainWindow);
        actionComment->setObjectName(QString::fromUtf8("actionComment"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setStyleSheet(QString::fromUtf8(""));
        splitter->setOrientation(Qt::Vertical);
        splitter->setHandleWidth(0);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        openedFiles = new QVBoxLayout(layoutWidget);
        openedFiles->setSpacing(6);
        openedFiles->setContentsMargins(11, 11, 11, 11);
        openedFiles->setObjectName(QString::fromUtf8("openedFiles"));
        openedFiles->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setStyleSheet(QString::fromUtf8(" text-transform: uppercase;\n"
""));

        openedFiles->addWidget(label_2);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy2);
        listWidget->setStyleSheet(QString::fromUtf8(""));
        listWidget->setMovement(QListView::Free);
        listWidget->setResizeMode(QListView::Adjust);

        openedFiles->addWidget(listWidget);

        splitter->addWidget(layoutWidget);
        layoutWidget1 = new QWidget(splitter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        fileExplorer = new QVBoxLayout(layoutWidget1);
        fileExplorer->setSpacing(0);
        fileExplorer->setContentsMargins(11, 11, 11, 11);
        fileExplorer->setObjectName(QString::fromUtf8("fileExplorer"));
        fileExplorer->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setStyleSheet(QString::fromUtf8("text-transform: uppercase;\n"
"padding-top:5px;\n"
""));

        fileExplorer->addWidget(label);

        treeView = new QTreeView(layoutWidget1);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        sizePolicy2.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy2);
        treeView->setStyleSheet(QString::fromUtf8(""));
        treeView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeView->setHeaderHidden(true);

        fileExplorer->addWidget(treeView);

        splitter->addWidget(layoutWidget1);
        splitter_2->addWidget(splitter);
        splitter_3 = new QSplitter(splitter_2);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        widget_3 = new QWidget(splitter_3);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(widget_3);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setUsesScrollButtons(true);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);

        horizontalLayout->addWidget(tabWidget);

        widget_2 = new QWidget(widget_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy2.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy2);
        widget_2->setMaximumSize(QSize(110, 16777215));

        horizontalLayout->addWidget(widget_2);

        splitter_3->addWidget(widget_3);
        widget = new QWidget(splitter_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        splitter_3->addWidget(widget);
        splitter_2->addWidget(splitter_3);

        gridLayout->addWidget(splitter_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 720, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuRecent_files = new QMenu(menuFile);
        menuRecent_files->setObjectName(QString::fromUtf8("menuRecent_files"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuIndent = new QMenu(menuEdit);
        menuIndent->setObjectName(QString::fromUtf8("menuIndent"));
        menuLine = new QMenu(menuEdit);
        menuLine->setObjectName(QString::fromUtf8("menuLine"));
        menuConvert_to = new QMenu(menuEdit);
        menuConvert_to->setObjectName(QString::fromUtf8("menuConvert_to"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuShow_Panels = new QMenu(menuView);
        menuShow_Panels->setObjectName(QString::fromUtf8("menuShow_Panels"));
        menuLine_Ending = new QMenu(menuView);
        menuLine_Ending->setObjectName(QString::fromUtf8("menuLine_Ending"));
        menuSyntax = new QMenu(menuView);
        menuSyntax->setObjectName(QString::fromUtf8("menuSyntax"));
        menuFind = new QMenu(menuBar);
        menuFind->setObjectName(QString::fromUtf8("menuFind"));
        menuPrefrences = new QMenu(menuBar);
        menuPrefrences->setObjectName(QString::fromUtf8("menuPrefrences"));
        menuPrefrences->setEnabled(true);
        menuThemes = new QMenu(menuPrefrences);
        menuThemes->setObjectName(QString::fromUtf8("menuThemes"));
        menuThemes->setEnabled(true);
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setEnabled(true);
        mainToolBar->setStyleSheet(QString::fromUtf8(""));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuFind->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuPrefrences->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionOpenDirectory);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_AS);
        menuFile->addAction(actionSave_All);
        menuFile->addAction(actionPrint);
        menuFile->addAction(actionPrint_Preview);
        menuFile->addAction(menuRecent_files->menuAction());
        menuFile->addAction(actionNew_Window);
        menuFile->addAction(actionClose_Window);
        menuFile->addAction(actionSettings);
        menuFile->addAction(actionClose);
        menuFile->addAction(actionClose_All_Files);
        menuFile->addAction(actionExit);
        menuRecent_files->addAction(actionclear);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSelect_All);
        menuEdit->addAction(actionDeselect);
        menuEdit->addAction(menuIndent->menuAction());
        menuEdit->addAction(menuLine->menuAction());
        menuEdit->addAction(menuConvert_to->menuAction());
        menuEdit->addAction(actionGo_to_Line);
        menuIndent->addAction(actionAdd_Indent);
        menuIndent->addAction(actionDecrease_Indent);
        menuLine->addAction(actionDuplicate_Line);
        menuLine->addAction(actionComment);
        menuConvert_to->addAction(actionUPPER_CASE);
        menuConvert_to->addAction(actionlower_case);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_QT);
        menuView->addAction(menuShow_Panels->menuAction());
        menuView->addAction(menuLine_Ending->menuAction());
        menuView->addAction(menuSyntax->menuAction());
        menuView->addAction(actionWordWrap);
        menuView->addAction(actionShow_Linenumbers);
        menuView->addAction(actionToolBar);
        menuView->addAction(actionShow_Minimap);
        menuShow_Panels->addAction(actionFile_Explorer);
        menuShow_Panels->addAction(actionOpened_Files);
        menuLine_Ending->addAction(actionWindows);
        menuLine_Ending->addAction(actionMac);
        menuLine_Ending->addAction(actionUnix);
        menuSyntax->addAction(actionNormal);
        menuSyntax->addAction(actionBash);
        menuSyntax->addAction(actionBatch_File);
        menuSyntax->addAction(actionC);
        menuSyntax->addAction(actionCpp);
        menuSyntax->addAction(actionCSharp);
        menuSyntax->addAction(actionCMake);
        menuSyntax->addAction(actionCoffeeScript);
        menuSyntax->addAction(actionCSS);
        menuSyntax->addAction(actionD);
        menuSyntax->addAction(actionDiff);
        menuSyntax->addAction(actionHTML);
        menuSyntax->addAction(actionFortan);
        menuSyntax->addAction(actionFortan77);
        menuSyntax->addAction(actionJava);
        menuSyntax->addAction(actionJavaScript);
        menuSyntax->addAction(actionJSON);
        menuSyntax->addAction(actionLua);
        menuSyntax->addAction(actionMakeFile);
        menuSyntax->addAction(actionMarkDown);
        menuSyntax->addAction(actionMatLab);
        menuSyntax->addAction(actionPascal);
        menuSyntax->addAction(actionProperties);
        menuSyntax->addAction(actionPerl);
        menuSyntax->addAction(actionPython);
        menuSyntax->addAction(actionRuby);
        menuSyntax->addAction(actionYAML);
        menuSyntax->addAction(actionTeX);
        menuSyntax->addAction(actionSQL);
        menuSyntax->addAction(actionXML);
        menuFind->addAction(actionFind);
        menuFind->addAction(actionFind_Prev);
        menuFind->addAction(actionReplace);
        menuFind->addAction(actionReplace_All);
        menuPrefrences->addAction(menuThemes->menuAction());
        menuThemes->addAction(actionDark);
        menuThemes->addAction(actionLight);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionSave_AS);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCut);
        mainToolBar->addAction(actionCopy);
        mainToolBar->addAction(actionPaste);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionUndo);
        mainToolBar->addAction(actionRedo);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SimpleCodeEditor", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_AS->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_AS->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpenDirectory->setText(QCoreApplication::translate("MainWindow", "Open Directory", nullptr));
        actionCut->setText(QCoreApplication::translate("MainWindow", "Cut", nullptr));
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSelect_All->setText(QCoreApplication::translate("MainWindow", "Select All", nullptr));
#if QT_CONFIG(shortcut)
        actionSelect_All->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionAbout_QT->setText(QCoreApplication::translate("MainWindow", "About QT", nullptr));
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
#if QT_CONFIG(shortcut)
        actionClose->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
#if QT_CONFIG(shortcut)
        actionUndo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Z", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
#if QT_CONFIG(shortcut)
        actionRedo->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDeselect->setText(QCoreApplication::translate("MainWindow", "Deselect", nullptr));
#if QT_CONFIG(shortcut)
        actionDeselect->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFile_Explorer->setText(QCoreApplication::translate("MainWindow", "File Explorer", nullptr));
        actionOpened_Files->setText(QCoreApplication::translate("MainWindow", "Opened Files", nullptr));
        actionNew_Window->setText(QCoreApplication::translate("MainWindow", "New Window", nullptr));
#if QT_CONFIG(shortcut)
        actionNew_Window->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClose_Window->setText(QCoreApplication::translate("MainWindow", "Close Window", nullptr));
#if QT_CONFIG(shortcut)
        actionClose_Window->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionUnix->setText(QCoreApplication::translate("MainWindow", "Unix", nullptr));
        actionWindows->setText(QCoreApplication::translate("MainWindow", "Windows", nullptr));
        actionMac->setText(QCoreApplication::translate("MainWindow", "Mac", nullptr));
        actionClose_All_Files->setText(QCoreApplication::translate("MainWindow", "Close All Files", nullptr));
        actionFind->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
#if QT_CONFIG(shortcut)
        actionFind->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFind_Prev->setText(QCoreApplication::translate("MainWindow", "Find Prev", nullptr));
        actionReplace->setText(QCoreApplication::translate("MainWindow", "Replace", nullptr));
        actionReplace_All->setText(QCoreApplication::translate("MainWindow", "Replace All", nullptr));
        actionToolBar->setText(QCoreApplication::translate("MainWindow", "ToolBar", nullptr));
        actionJSON->setText(QCoreApplication::translate("MainWindow", "JSO&N", nullptr));
        actionBatch_File->setText(QCoreApplication::translate("MainWindow", "Batch F&ile", nullptr));
        actionCoffeeScript->setText(QCoreApplication::translate("MainWindow", "C&offeeScript", nullptr));
        actionCSharp->setText(QCoreApplication::translate("MainWindow", "C#", nullptr));
        actionJava->setText(QCoreApplication::translate("MainWindow", "&Java", nullptr));
        actionCSS->setText(QCoreApplication::translate("MainWindow", "CSS", nullptr));
        actionJavaScript->setText(QCoreApplication::translate("MainWindow", "Ja&vaScript", nullptr));
        actionMakeFile->setText(QCoreApplication::translate("MainWindow", "Ma&keFile", nullptr));
        actionMatLab->setText(QCoreApplication::translate("MainWindow", "MatLab", nullptr));
        actionPascal->setText(QCoreApplication::translate("MainWindow", "&Pascal", nullptr));
        actionPython->setText(QCoreApplication::translate("MainWindow", "P&ython", nullptr));
        actionBash->setText(QCoreApplication::translate("MainWindow", "&Bash", nullptr));
        actionCMake->setText(QCoreApplication::translate("MainWindow", "CMake", nullptr));
        actionCpp->setText(QCoreApplication::translate("MainWindow", "C++", nullptr));
        actionFortan->setText(QCoreApplication::translate("MainWindow", "&Fortan", nullptr));
        actionXML->setText(QCoreApplication::translate("MainWindow", "&XML", nullptr));
        actionLua->setText(QCoreApplication::translate("MainWindow", "&Lua", nullptr));
        actionMarkDown->setText(QCoreApplication::translate("MainWindow", "&MarkDown", nullptr));
        actionPerl->setText(QCoreApplication::translate("MainWindow", "P&erl", nullptr));
        actionRuby->setText(QCoreApplication::translate("MainWindow", "&Ruby", nullptr));
        actionSQL->setText(QCoreApplication::translate("MainWindow", "&SQL", nullptr));
        actionTeX->setText(QCoreApplication::translate("MainWindow", "&TeX", nullptr));
        actionC->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        actionYAML->setText(QCoreApplication::translate("MainWindow", "YAML", nullptr));
        actionNormal->setText(QCoreApplication::translate("MainWindow", "Normal", nullptr));
        actionDiff->setText(QCoreApplication::translate("MainWindow", "Diff", nullptr));
        actionFortan77->setText(QCoreApplication::translate("MainWindow", "Fortan&77", nullptr));
        actionD->setText(QCoreApplication::translate("MainWindow", "&D", nullptr));
        actionProperties->setText(QCoreApplication::translate("MainWindow", "Properties", nullptr));
        actionShow_Linenumbers->setText(QCoreApplication::translate("MainWindow", "Show Linenumbers", nullptr));
        actionHTML->setText(QCoreApplication::translate("MainWindow", "HTML", nullptr));
        actionStatusBar->setText(QCoreApplication::translate("MainWindow", "StatusBar", nullptr));
        actionWordWrap->setText(QCoreApplication::translate("MainWindow", "WordWrap", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainWindow", "Settings", nullptr));
        actionPrint->setText(QCoreApplication::translate("MainWindow", "Print", nullptr));
        actionPrint_Preview->setText(QCoreApplication::translate("MainWindow", "Print Preview", nullptr));
        actionAdd_Indent->setText(QCoreApplication::translate("MainWindow", "Add Indent", nullptr));
        actionDecrease_Indent->setText(QCoreApplication::translate("MainWindow", "Decrease Indent", nullptr));
        actionPrefrences->setText(QCoreApplication::translate("MainWindow", "Prefrences", nullptr));
        actionSave_All->setText(QCoreApplication::translate("MainWindow", "Save All", nullptr));
        actionDuplicate_Line->setText(QCoreApplication::translate("MainWindow", "Duplicate Line", nullptr));
        actionUPPER_CASE->setText(QCoreApplication::translate("MainWindow", "UPPER CASE", nullptr));
        actionlower_case->setText(QCoreApplication::translate("MainWindow", "lower case", nullptr));
        actionGo_to_Line->setText(QCoreApplication::translate("MainWindow", "Go to Line", nullptr));
        actionShow_Minimap->setText(QCoreApplication::translate("MainWindow", "Show Minimap", nullptr));
        actionDark->setText(QCoreApplication::translate("MainWindow", "Dark", nullptr));
        actionLight->setText(QCoreApplication::translate("MainWindow", "Light", nullptr));
        actionclear->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        actionComment->setText(QCoreApplication::translate("MainWindow", "Toogle Comment", nullptr));
#if QT_CONFIG(tooltip)
        actionComment->setToolTip(QCoreApplication::translate("MainWindow", "Toogle Comment", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionComment->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+/", nullptr));
#endif // QT_CONFIG(shortcut)
        label_2->setText(QCoreApplication::translate("MainWindow", "Opened Files", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "FileExplorer", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuRecent_files->setTitle(QCoreApplication::translate("MainWindow", "Recent files", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuIndent->setTitle(QCoreApplication::translate("MainWindow", "Indent", nullptr));
        menuLine->setTitle(QCoreApplication::translate("MainWindow", "Line", nullptr));
        menuConvert_to->setTitle(QCoreApplication::translate("MainWindow", "Convert to", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuShow_Panels->setTitle(QCoreApplication::translate("MainWindow", "Show Panels", nullptr));
        menuLine_Ending->setTitle(QCoreApplication::translate("MainWindow", "Line Ending", nullptr));
        menuSyntax->setTitle(QCoreApplication::translate("MainWindow", "Syntax", nullptr));
        menuFind->setTitle(QCoreApplication::translate("MainWindow", "Find", nullptr));
        menuPrefrences->setTitle(QCoreApplication::translate("MainWindow", "Prefrences", nullptr));
        menuThemes->setTitle(QCoreApplication::translate("MainWindow", "Themes", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
