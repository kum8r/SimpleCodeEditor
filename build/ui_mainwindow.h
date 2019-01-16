/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionQuit;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionClose;
    QAction *actionReload;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionNew_Window;
    QAction *actionClose_Window;
    QAction *actionClose_All_Files;
    QAction *actionFind;
    QAction *actionFind_Next;
    QAction *actionReplace;
    QAction *actionReplace_All;
    QAction *actionSidebar;
    QAction *actionStatusbar;
    QAction *actionToolbar;
    QAction *actionAbout;
    QAction *actionAbout_QT;
    QAction *actionShow_Tabs;
    QAction *actionWindows;
    QAction *actionUnix;
    QAction *actionMac;
    QAction *actionFind_All;
    QAction *actionSelect_All;
    QAction *actionDeselect;
    QAction *actionOpen_Directory;
    QAction *actionBatch_File;
    QAction *actionCoffeeScript;
    QAction *actionC;
    QAction *actionJava;
    QAction *actionCSS;
    QAction *actionHTML;
    QAction *actionJavaScript;
    QAction *actionJSON;
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
    QAction *actionChange_Font;
    QAction *actionShow_Linenumbers;
    QAction *actionWordWrap;
    QAction *actionSettings;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QListView *listView;
    QTabWidget *tabWidget;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuFind;
    QMenu *menuView;
    QMenu *menuLine_Ending;
    QMenu *menuSyntax;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(807, 590);
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
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("document-save-as");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionSave_As->setIcon(icon3);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("window-close");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionQuit->setIcon(icon4);
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
        actionCut->setVisible(true);
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
        actionReload = new QAction(MainWindow);
        actionReload->setObjectName(QString::fromUtf8("actionReload"));
        QIcon icon9;
        iconThemeName = QString::fromUtf8("reload");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon9 = QIcon::fromTheme(iconThemeName);
        } else {
            icon9.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionReload->setIcon(icon9);
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
        actionClose_Window->setIcon(icon4);
        actionClose_All_Files = new QAction(MainWindow);
        actionClose_All_Files->setObjectName(QString::fromUtf8("actionClose_All_Files"));
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        actionFind_Next = new QAction(MainWindow);
        actionFind_Next->setObjectName(QString::fromUtf8("actionFind_Next"));
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName(QString::fromUtf8("actionReplace"));
        actionReplace_All = new QAction(MainWindow);
        actionReplace_All->setObjectName(QString::fromUtf8("actionReplace_All"));
        actionSidebar = new QAction(MainWindow);
        actionSidebar->setObjectName(QString::fromUtf8("actionSidebar"));
        actionSidebar->setCheckable(true);
        actionSidebar->setChecked(true);
        actionStatusbar = new QAction(MainWindow);
        actionStatusbar->setObjectName(QString::fromUtf8("actionStatusbar"));
        actionStatusbar->setCheckable(true);
        actionStatusbar->setChecked(true);
        actionToolbar = new QAction(MainWindow);
        actionToolbar->setObjectName(QString::fromUtf8("actionToolbar"));
        actionToolbar->setCheckable(true);
        actionToolbar->setChecked(true);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_QT = new QAction(MainWindow);
        actionAbout_QT->setObjectName(QString::fromUtf8("actionAbout_QT"));
        actionShow_Tabs = new QAction(MainWindow);
        actionShow_Tabs->setObjectName(QString::fromUtf8("actionShow_Tabs"));
        actionShow_Tabs->setCheckable(true);
        actionShow_Tabs->setChecked(true);
        actionWindows = new QAction(MainWindow);
        actionWindows->setObjectName(QString::fromUtf8("actionWindows"));
        actionWindows->setCheckable(true);
        actionUnix = new QAction(MainWindow);
        actionUnix->setObjectName(QString::fromUtf8("actionUnix"));
        actionUnix->setCheckable(true);
        actionMac = new QAction(MainWindow);
        actionMac->setObjectName(QString::fromUtf8("actionMac"));
        actionMac->setCheckable(true);
        actionFind_All = new QAction(MainWindow);
        actionFind_All->setObjectName(QString::fromUtf8("actionFind_All"));
        actionSelect_All = new QAction(MainWindow);
        actionSelect_All->setObjectName(QString::fromUtf8("actionSelect_All"));
        actionDeselect = new QAction(MainWindow);
        actionDeselect->setObjectName(QString::fromUtf8("actionDeselect"));
        actionOpen_Directory = new QAction(MainWindow);
        actionOpen_Directory->setObjectName(QString::fromUtf8("actionOpen_Directory"));
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
        actionHTML = new QAction(MainWindow);
        actionHTML->setObjectName(QString::fromUtf8("actionHTML"));
        actionJavaScript = new QAction(MainWindow);
        actionJavaScript->setObjectName(QString::fromUtf8("actionJavaScript"));
        actionJSON = new QAction(MainWindow);
        actionJSON->setObjectName(QString::fromUtf8("actionJSON"));
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
        actionChange_Font = new QAction(MainWindow);
        actionChange_Font->setObjectName(QString::fromUtf8("actionChange_Font"));
        actionShow_Linenumbers = new QAction(MainWindow);
        actionShow_Linenumbers->setObjectName(QString::fromUtf8("actionShow_Linenumbers"));
        actionShow_Linenumbers->setCheckable(true);
        actionShow_Linenumbers->setChecked(true);
        actionWordWrap = new QAction(MainWindow);
        actionWordWrap->setObjectName(QString::fromUtf8("actionWordWrap"));
        actionWordWrap->setCheckable(true);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setMidLineWidth(0);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(0);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        listView = new QListView(widget);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        splitter->addWidget(widget);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setAcceptDrops(true);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        splitter->addWidget(tabWidget);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton = new QToolButton(widget_3);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setIcon(icon4);

        horizontalLayout->addWidget(toolButton);

        lineEdit_2 = new QLineEdit(widget_3);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        toolButton_2 = new QToolButton(widget_4);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setIcon(icon4);

        horizontalLayout_2->addWidget(toolButton_2);

        lineEdit_3 = new QLineEdit(widget_4);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_2->addWidget(lineEdit_3);

        pushButton_3 = new QPushButton(widget_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget_4);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);


        verticalLayout_2->addWidget(widget_4);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 807, 24));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuFind = new QMenu(menuBar);
        menuFind->setObjectName(QString::fromUtf8("menuFind"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuLine_Ending = new QMenu(menuView);
        menuLine_Ending->setObjectName(QString::fromUtf8("menuLine_Ending"));
        menuSyntax = new QMenu(menuView);
        menuSyntax->setObjectName(QString::fromUtf8("menuSyntax"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
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
        menuFile->addAction(actionOpen_Directory);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionReload);
        menuFile->addAction(actionNew_Window);
        menuFile->addAction(actionClose_Window);
        menuFile->addAction(actionClose);
        menuFile->addAction(actionClose_All_Files);
        menuFile->addAction(actionQuit);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionSelect_All);
        menuEdit->addAction(actionDeselect);
        menuEdit->addAction(actionSettings);
        menuFind->addAction(actionFind);
        menuFind->addAction(actionFind_Next);
        menuFind->addAction(actionFind_All);
        menuFind->addAction(actionReplace);
        menuFind->addAction(actionReplace_All);
        menuView->addAction(actionSidebar);
        menuView->addAction(actionStatusbar);
        menuView->addAction(actionToolbar);
        menuView->addAction(actionShow_Tabs);
        menuView->addAction(actionShow_Linenumbers);
        menuView->addAction(actionWordWrap);
        menuView->addAction(menuSyntax->menuAction());
        menuView->addAction(menuLine_Ending->menuAction());
        menuView->addAction(actionChange_Font);
        menuLine_Ending->addAction(actionWindows);
        menuLine_Ending->addAction(actionUnix);
        menuLine_Ending->addAction(actionMac);
        menuSyntax->addAction(actionBash);
        menuSyntax->addAction(actionBatch_File);
        menuSyntax->addAction(actionCMake);
        menuSyntax->addAction(actionCoffeeScript);
        menuSyntax->addAction(actionC_3);
        menuSyntax->addAction(actionC_2);
        menuSyntax->addAction(actionC);
        menuSyntax->addAction(actionCSS);
        menuSyntax->addAction(actionFortan);
        menuSyntax->addAction(actionHTML);
        menuSyntax->addAction(actionJava);
        menuSyntax->addAction(actionJavaScript);
        menuSyntax->addAction(actionJSON);
        menuSyntax->addAction(actionLua);
        menuSyntax->addAction(actionMarkDown);
        menuSyntax->addAction(actionMakeFile);
        menuSyntax->addAction(actionMatLab);
        menuSyntax->addAction(actionPascal);
        menuSyntax->addAction(actionPerl);
        menuSyntax->addAction(actionPython);
        menuSyntax->addAction(actionRuby);
        menuSyntax->addAction(actionSQL);
        menuSyntax->addAction(actionTeX);
        menuSyntax->addAction(actionXML);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionAbout_QT);
        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionSave_As);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionCut);
        mainToolBar->addAction(actionCopy);
        mainToolBar->addAction(actionPaste);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionUndo);
        mainToolBar->addAction(actionRedo);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SimpleCodeEditor", nullptr));
        actionNew->setText(QApplication::translate("MainWindow", "&New", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "create a new document", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "&Open", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open a document", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "&Save", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "Save a document", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_As->setText(QApplication::translate("MainWindow", "Sa&ve As", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave_As->setToolTip(QApplication::translate("MainWindow", "Save as ", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSave_As->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionQuit->setToolTip(QApplication::translate("MainWindow", "Quit", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionCut->setText(QApplication::translate("MainWindow", "&Cut", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("MainWindow", "C&opy", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "&Paste", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionClose->setText(QApplication::translate("MainWindow", "C&lose", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClose->setToolTip(QApplication::translate("MainWindow", "Close document", nullptr));
#endif // QT_NO_TOOLTIP
        actionReload->setText(QApplication::translate("MainWindow", "&Reload", nullptr));
        actionUndo->setText(QApplication::translate("MainWindow", "&Undo", nullptr));
        actionRedo->setText(QApplication::translate("MainWindow", "&Redo", nullptr));
        actionNew_Window->setText(QApplication::translate("MainWindow", "New &Window", nullptr));
        actionClose_Window->setText(QApplication::translate("MainWindow", "&Close Window", nullptr));
        actionClose_All_Files->setText(QApplication::translate("MainWindow", "Close All &Files", nullptr));
        actionFind->setText(QApplication::translate("MainWindow", "&Find", nullptr));
        actionFind_Next->setText(QApplication::translate("MainWindow", "Find &Next", nullptr));
        actionReplace->setText(QApplication::translate("MainWindow", "&Replace", nullptr));
        actionReplace_All->setText(QApplication::translate("MainWindow", "R&eplace All", nullptr));
        actionSidebar->setText(QApplication::translate("MainWindow", "&Show Sidebar", nullptr));
        actionStatusbar->setText(QApplication::translate("MainWindow", "S&how Statusbar", nullptr));
        actionToolbar->setText(QApplication::translate("MainWindow", "Sh&ow Toolbar", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "&About ", nullptr));
        actionAbout_QT->setText(QApplication::translate("MainWindow", "About &Qt", nullptr));
        actionShow_Tabs->setText(QApplication::translate("MainWindow", "Sho&w Tabs", nullptr));
        actionWindows->setText(QApplication::translate("MainWindow", "&Windows", nullptr));
        actionUnix->setText(QApplication::translate("MainWindow", "&Unix", nullptr));
        actionMac->setText(QApplication::translate("MainWindow", "&Mac", nullptr));
        actionFind_All->setText(QApplication::translate("MainWindow", "F&ind All", nullptr));
        actionSelect_All->setText(QApplication::translate("MainWindow", "&Select All", nullptr));
        actionDeselect->setText(QApplication::translate("MainWindow", "&Deselect", nullptr));
        actionOpen_Directory->setText(QApplication::translate("MainWindow", "Open &Directory", nullptr));
        actionBatch_File->setText(QApplication::translate("MainWindow", "Batch F&ile", nullptr));
        actionCoffeeScript->setText(QApplication::translate("MainWindow", "C&offeeScript", nullptr));
        actionC->setText(QApplication::translate("MainWindow", "C#", nullptr));
        actionJava->setText(QApplication::translate("MainWindow", "&Java", nullptr));
        actionCSS->setText(QApplication::translate("MainWindow", "CSS", nullptr));
        actionHTML->setText(QApplication::translate("MainWindow", "&HTML", nullptr));
        actionJavaScript->setText(QApplication::translate("MainWindow", "Ja&vaScript", nullptr));
        actionJSON->setText(QApplication::translate("MainWindow", "JSO&N", nullptr));
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
        actionChange_Font->setText(QApplication::translate("MainWindow", "&Change Font", nullptr));
        actionShow_Linenumbers->setText(QApplication::translate("MainWindow", "Show L&inenumbers", nullptr));
        actionWordWrap->setText(QApplication::translate("MainWindow", "Wo&rdWrap", nullptr));
        actionSettings->setText(QApplication::translate("MainWindow", "S&ettings", nullptr));
        toolButton->setText(QApplication::translate("MainWindow", "...", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Find", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Find All", nullptr));
        toolButton_2->setText(QApplication::translate("MainWindow", "...", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Replace", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Replace All", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", nullptr));
        menuFind->setTitle(QApplication::translate("MainWindow", "F&ind", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "&View", nullptr));
        menuLine_Ending->setTitle(QApplication::translate("MainWindow", "&Line Ending", nullptr));
        menuSyntax->setTitle(QApplication::translate("MainWindow", "S&yntax", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "&Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
