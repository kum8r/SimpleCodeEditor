/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
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
    QAction *actionFind_Next;
    QAction *actionFind_Prev;
    QAction *actionReplace;
    QAction *actionReplace_All;
    QAction *actionToolBar;
    QAction *actionJSON;
    QAction *actionBatch_File;
    QAction *actionCoffeeScript;
    QAction *actionC;
    QAction *actionJava;
    QAction *actionCSS;
    QAction *actionJavaScript;
    QAction *actionMakeFile;
    QAction *actionMatLab;
    QAction *actionPascal;
    QAction *actionPython;
    QAction *actionBash;
    QAction *actionCMake;
    QAction *actionC_2;
    QAction *actionFortan;
    QAction *actionXML;
    QAction *actionLua;
    QAction *actionMarkDown;
    QAction *actionPerl;
    QAction *actionRuby;
    QAction *actionSQL;
    QAction *actionTeX;
    QAction *actionC_3;
    QAction *actionYAML;
    QAction *actionNormal;
    QAction *actionDiff;
    QAction *actionFortan77;
    QAction *actionD;
    QAction *actionProperties;
    QAction *actionShow_Linenumbers_2;
    QAction *actionHTML;
    QAction *actionStatusBar_2;
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
    QTabWidget *tabWidget;
    QWidget *widget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuHelp;
    QMenu *menuView;
    QMenu *menuShow_Panels;
    QMenu *menuLine_Ending;
    QMenu *menuSyntax;
    QMenu *menuFind;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(720, 488);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("document-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon1;
        iconThemeName = QString::fromUtf8("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionSave->setIcon(icon2);
        actionSave_AS = new QAction(MainWindow);
        actionSave_AS->setObjectName(QString::fromUtf8("actionSave_AS"));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("document-save-as");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionSave_AS->setIcon(icon3);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("window-close");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionExit->setIcon(icon4);
        actionOpenDirectory = new QAction(MainWindow);
        actionOpenDirectory->setObjectName(QString::fromUtf8("actionOpenDirectory"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon5;
        iconThemeName = QString::fromUtf8("edit-cut");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionCut->setIcon(icon5);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon6;
        iconThemeName = QString::fromUtf8("edit-copy");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionCopy->setIcon(icon6);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon7;
        iconThemeName = QString::fromUtf8("edit-paste");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon7 = QIcon::fromTheme(iconThemeName);
        } else {
            icon7.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionPaste->setIcon(icon7);
        actionSelect_All = new QAction(MainWindow);
        actionSelect_All->setObjectName(QString::fromUtf8("actionSelect_All"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_QT = new QAction(MainWindow);
        actionAbout_QT->setObjectName(QString::fromUtf8("actionAbout_QT"));
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        QIcon icon8;
        iconThemeName = QString::fromUtf8("document-close");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon8 = QIcon::fromTheme(iconThemeName);
        } else {
            icon8.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionClose->setIcon(icon8);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon9;
        iconThemeName = QString::fromUtf8("edit-undo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon9 = QIcon::fromTheme(iconThemeName);
        } else {
            icon9.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionUndo->setIcon(icon9);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon10;
        iconThemeName = QString::fromUtf8("edit-redo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon10 = QIcon::fromTheme(iconThemeName);
        } else {
            icon10.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionRedo->setIcon(icon10);
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
        QIcon icon11;
        iconThemeName = QString::fromUtf8("window-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon11 = QIcon::fromTheme(iconThemeName);
        } else {
            icon11.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionNew_Window->setIcon(icon11);
        actionClose_Window = new QAction(MainWindow);
        actionClose_Window->setObjectName(QString::fromUtf8("actionClose_Window"));
        actionClose_Window->setIcon(icon4);
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
        actionFind_Next = new QAction(MainWindow);
        actionFind_Next->setObjectName(QString::fromUtf8("actionFind_Next"));
        actionFind_Prev = new QAction(MainWindow);
        actionFind_Prev->setObjectName(QString::fromUtf8("actionFind_Prev"));
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName(QString::fromUtf8("actionReplace"));
        actionReplace_All = new QAction(MainWindow);
        actionReplace_All->setObjectName(QString::fromUtf8("actionReplace_All"));
        actionToolBar = new QAction(MainWindow);
        actionToolBar->setObjectName(QString::fromUtf8("actionToolBar"));
        actionToolBar->setCheckable(true);
        actionToolBar->setChecked(true);
        actionJSON = new QAction(MainWindow);
        actionJSON->setObjectName(QString::fromUtf8("actionJSON"));
        actionBatch_File = new QAction(MainWindow);
        actionBatch_File->setObjectName(QString::fromUtf8("actionBatch_File"));
        actionCoffeeScript = new QAction(MainWindow);
        actionCoffeeScript->setObjectName(QString::fromUtf8("actionCoffeeScript"));
        actionC = new QAction(MainWindow);
        actionC->setObjectName(QString::fromUtf8("actionC"));
        actionJava = new QAction(MainWindow);
        actionJava->setObjectName(QString::fromUtf8("actionJava"));
        actionCSS = new QAction(MainWindow);
        actionCSS->setObjectName(QString::fromUtf8("actionCSS"));
        actionJavaScript = new QAction(MainWindow);
        actionJavaScript->setObjectName(QString::fromUtf8("actionJavaScript"));
        actionMakeFile = new QAction(MainWindow);
        actionMakeFile->setObjectName(QString::fromUtf8("actionMakeFile"));
        actionMatLab = new QAction(MainWindow);
        actionMatLab->setObjectName(QString::fromUtf8("actionMatLab"));
        actionPascal = new QAction(MainWindow);
        actionPascal->setObjectName(QString::fromUtf8("actionPascal"));
        actionPython = new QAction(MainWindow);
        actionPython->setObjectName(QString::fromUtf8("actionPython"));
        actionBash = new QAction(MainWindow);
        actionBash->setObjectName(QString::fromUtf8("actionBash"));
        actionCMake = new QAction(MainWindow);
        actionCMake->setObjectName(QString::fromUtf8("actionCMake"));
        actionC_2 = new QAction(MainWindow);
        actionC_2->setObjectName(QString::fromUtf8("actionC_2"));
        actionFortan = new QAction(MainWindow);
        actionFortan->setObjectName(QString::fromUtf8("actionFortan"));
        actionXML = new QAction(MainWindow);
        actionXML->setObjectName(QString::fromUtf8("actionXML"));
        actionLua = new QAction(MainWindow);
        actionLua->setObjectName(QString::fromUtf8("actionLua"));
        actionMarkDown = new QAction(MainWindow);
        actionMarkDown->setObjectName(QString::fromUtf8("actionMarkDown"));
        actionPerl = new QAction(MainWindow);
        actionPerl->setObjectName(QString::fromUtf8("actionPerl"));
        actionRuby = new QAction(MainWindow);
        actionRuby->setObjectName(QString::fromUtf8("actionRuby"));
        actionSQL = new QAction(MainWindow);
        actionSQL->setObjectName(QString::fromUtf8("actionSQL"));
        actionTeX = new QAction(MainWindow);
        actionTeX->setObjectName(QString::fromUtf8("actionTeX"));
        actionC_3 = new QAction(MainWindow);
        actionC_3->setObjectName(QString::fromUtf8("actionC_3"));
        actionYAML = new QAction(MainWindow);
        actionYAML->setObjectName(QString::fromUtf8("actionYAML"));
        actionNormal = new QAction(MainWindow);
        actionNormal->setObjectName(QString::fromUtf8("actionNormal"));
        actionDiff = new QAction(MainWindow);
        actionDiff->setObjectName(QString::fromUtf8("actionDiff"));
        actionFortan77 = new QAction(MainWindow);
        actionFortan77->setObjectName(QString::fromUtf8("actionFortan77"));
        actionD = new QAction(MainWindow);
        actionD->setObjectName(QString::fromUtf8("actionD"));
        actionProperties = new QAction(MainWindow);
        actionProperties->setObjectName(QString::fromUtf8("actionProperties"));
        actionShow_Linenumbers_2 = new QAction(MainWindow);
        actionShow_Linenumbers_2->setObjectName(QString::fromUtf8("actionShow_Linenumbers_2"));
        actionShow_Linenumbers_2->setCheckable(true);
        actionShow_Linenumbers_2->setChecked(true);
        actionHTML = new QAction(MainWindow);
        actionHTML->setObjectName(QString::fromUtf8("actionHTML"));
        actionStatusBar_2 = new QAction(MainWindow);
        actionStatusBar_2->setObjectName(QString::fromUtf8("actionStatusBar_2"));
        actionStatusBar_2->setCheckable(true);
        actionStatusBar_2->setChecked(true);
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
        splitter_2->setHandleWidth(0);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
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

        openedFiles->addWidget(label_2);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

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

        fileExplorer->addWidget(label);

        treeView = new QTreeView(layoutWidget1);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        fileExplorer->addWidget(treeView);

        splitter->addWidget(layoutWidget1);
        splitter_2->addWidget(splitter);
        splitter_3 = new QSplitter(splitter_2);
        splitter_3->setObjectName(QString::fromUtf8("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        tabWidget = new QTabWidget(splitter_3);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        splitter_3->addWidget(tabWidget);
        widget = new QWidget(splitter_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        splitter_3->addWidget(widget);
        splitter_2->addWidget(splitter_3);

        gridLayout->addWidget(splitter_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 720, 17));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
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
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuFind->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionOpenDirectory);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_AS);
        menuFile->addAction(actionNew_Window);
        menuFile->addAction(actionClose_Window);
        menuFile->addAction(actionClose);
        menuFile->addAction(actionClose_All_Files);
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionSelect_All);
        menuEdit->addAction(actionDeselect);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_QT);
        menuView->addAction(menuShow_Panels->menuAction());
        menuView->addAction(menuLine_Ending->menuAction());
        menuView->addAction(menuSyntax->menuAction());
        menuView->addAction(actionShow_Linenumbers_2);
        menuView->addAction(actionToolBar);
        menuShow_Panels->addAction(actionFile_Explorer);
        menuShow_Panels->addAction(actionOpened_Files);
        menuLine_Ending->addAction(actionWindows);
        menuLine_Ending->addAction(actionMac);
        menuLine_Ending->addAction(actionUnix);
        menuSyntax->addAction(actionNormal);
        menuSyntax->addAction(actionBash);
        menuSyntax->addAction(actionBatch_File);
        menuSyntax->addAction(actionC_3);
        menuSyntax->addAction(actionC_2);
        menuSyntax->addAction(actionC);
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
        menuFind->addAction(actionFind_Next);
        menuFind->addAction(actionFind_Prev);
        menuFind->addAction(actionReplace);
        menuFind->addAction(actionReplace_All);
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SimpleCodeEditor", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionSave_AS->setText(QApplication::translate("MainWindow", "Save As", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionOpenDirectory->setText(QApplication::translate("MainWindow", "Open Directory", nullptr));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", nullptr));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", nullptr));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", nullptr));
        actionSelect_All->setText(QApplication::translate("MainWindow", "Select All", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
        actionAbout_QT->setText(QApplication::translate("MainWindow", "About QT", nullptr));
        actionClose->setText(QApplication::translate("MainWindow", "Close", nullptr));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", nullptr));
        actionDeselect->setText(QApplication::translate("MainWindow", "Deselect", nullptr));
        actionFile_Explorer->setText(QApplication::translate("MainWindow", "File Explorer", nullptr));
        actionOpened_Files->setText(QApplication::translate("MainWindow", "Opened Files", nullptr));
        actionNew_Window->setText(QApplication::translate("MainWindow", "New Window", nullptr));
        actionClose_Window->setText(QApplication::translate("MainWindow", "Close Window", nullptr));
        actionUnix->setText(QApplication::translate("MainWindow", "Unix", nullptr));
        actionWindows->setText(QApplication::translate("MainWindow", "Windows", nullptr));
        actionMac->setText(QApplication::translate("MainWindow", "Mac", nullptr));
        actionClose_All_Files->setText(QApplication::translate("MainWindow", "Close All Files", nullptr));
        actionFind->setText(QApplication::translate("MainWindow", "Find", nullptr));
        actionFind_Next->setText(QApplication::translate("MainWindow", "Find Next", nullptr));
        actionFind_Prev->setText(QApplication::translate("MainWindow", "Find Prev", nullptr));
        actionReplace->setText(QApplication::translate("MainWindow", "Replace", nullptr));
        actionReplace_All->setText(QApplication::translate("MainWindow", "Replace All", nullptr));
        actionToolBar->setText(QApplication::translate("MainWindow", "ToolBar", nullptr));
        actionJSON->setText(QApplication::translate("MainWindow", "JSO&N", nullptr));
        actionBatch_File->setText(QApplication::translate("MainWindow", "Batch F&ile", nullptr));
        actionCoffeeScript->setText(QApplication::translate("MainWindow", "C&offeeScript", nullptr));
        actionC->setText(QApplication::translate("MainWindow", "C#", nullptr));
        actionJava->setText(QApplication::translate("MainWindow", "&Java", nullptr));
        actionCSS->setText(QApplication::translate("MainWindow", "CSS", nullptr));
        actionJavaScript->setText(QApplication::translate("MainWindow", "Ja&vaScript", nullptr));
        actionMakeFile->setText(QApplication::translate("MainWindow", "Ma&keFile", nullptr));
        actionMatLab->setText(QApplication::translate("MainWindow", "MatLab", nullptr));
        actionPascal->setText(QApplication::translate("MainWindow", "&Pascal", nullptr));
        actionPython->setText(QApplication::translate("MainWindow", "P&ython", nullptr));
        actionBash->setText(QApplication::translate("MainWindow", "&Bash", nullptr));
        actionCMake->setText(QApplication::translate("MainWindow", "&CMake", nullptr));
        actionC_2->setText(QApplication::translate("MainWindow", "C++", nullptr));
        actionFortan->setText(QApplication::translate("MainWindow", "&Fortan", nullptr));
        actionXML->setText(QApplication::translate("MainWindow", "&XML", nullptr));
        actionLua->setText(QApplication::translate("MainWindow", "&Lua", nullptr));
        actionMarkDown->setText(QApplication::translate("MainWindow", "&MarkDown", nullptr));
        actionPerl->setText(QApplication::translate("MainWindow", "P&erl", nullptr));
        actionRuby->setText(QApplication::translate("MainWindow", "&Ruby", nullptr));
        actionSQL->setText(QApplication::translate("MainWindow", "&SQL", nullptr));
        actionTeX->setText(QApplication::translate("MainWindow", "&TeX", nullptr));
        actionC_3->setText(QApplication::translate("MainWindow", "C", nullptr));
        actionYAML->setText(QApplication::translate("MainWindow", "YAML", nullptr));
        actionNormal->setText(QApplication::translate("MainWindow", "Normal", nullptr));
        actionDiff->setText(QApplication::translate("MainWindow", "Diff", nullptr));
        actionFortan77->setText(QApplication::translate("MainWindow", "Fortan&77", nullptr));
        actionD->setText(QApplication::translate("MainWindow", "&D", nullptr));
        actionProperties->setText(QApplication::translate("MainWindow", "Properties", nullptr));
        actionShow_Linenumbers_2->setText(QApplication::translate("MainWindow", "Show Linenumbers", nullptr));
        actionHTML->setText(QApplication::translate("MainWindow", "HTML", nullptr));
        actionStatusBar_2->setText(QApplication::translate("MainWindow", "StatusBar", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Opened Files", nullptr));
        label->setText(QApplication::translate("MainWindow", "FileExplorer", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menuShow_Panels->setTitle(QApplication::translate("MainWindow", "Show Panels", nullptr));
        menuLine_Ending->setTitle(QApplication::translate("MainWindow", "Line Ending", nullptr));
        menuSyntax->setTitle(QApplication::translate("MainWindow", "Syntax", nullptr));
        menuFind->setTitle(QApplication::translate("MainWindow", "Find", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
