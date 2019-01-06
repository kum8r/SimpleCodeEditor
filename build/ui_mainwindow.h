/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
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
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(817, 600);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        QString iconThemeName = QStringLiteral("document-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        iconThemeName = QStringLiteral("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon2;
        iconThemeName = QStringLiteral("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionSave->setIcon(icon2);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        QIcon icon3;
        iconThemeName = QStringLiteral("document-save-as");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionSave_As->setIcon(icon3);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        QIcon icon4;
        iconThemeName = QStringLiteral("window-close");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionQuit->setIcon(icon4);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon5;
        iconThemeName = QStringLiteral("edit-cut");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon5 = QIcon::fromTheme(iconThemeName);
        } else {
            icon5.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionCut->setIcon(icon5);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon6;
        iconThemeName = QStringLiteral("edit-copy");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionCopy->setIcon(icon6);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon7;
        iconThemeName = QStringLiteral("edit-paste");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon7 = QIcon::fromTheme(iconThemeName);
        } else {
            icon7.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionPaste->setIcon(icon7);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        QIcon icon8;
        iconThemeName = QStringLiteral("document-close");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon8 = QIcon::fromTheme(iconThemeName);
        } else {
            icon8.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionClose->setIcon(icon8);
        actionReload = new QAction(MainWindow);
        actionReload->setObjectName(QStringLiteral("actionReload"));
        QIcon icon9;
        iconThemeName = QStringLiteral("reload");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon9 = QIcon::fromTheme(iconThemeName);
        } else {
            icon9.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionReload->setIcon(icon9);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon10;
        iconThemeName = QStringLiteral("edit-undo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon10 = QIcon::fromTheme(iconThemeName);
        } else {
            icon10.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionUndo->setIcon(icon10);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon11;
        iconThemeName = QStringLiteral("edit-redo");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon11 = QIcon::fromTheme(iconThemeName);
        } else {
            icon11.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionRedo->setIcon(icon11);
        actionNew_Window = new QAction(MainWindow);
        actionNew_Window->setObjectName(QStringLiteral("actionNew_Window"));
        QIcon icon12;
        iconThemeName = QStringLiteral("window-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon12 = QIcon::fromTheme(iconThemeName);
        } else {
            icon12.addFile(QStringLiteral("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionNew_Window->setIcon(icon12);
        actionClose_Window = new QAction(MainWindow);
        actionClose_Window->setObjectName(QStringLiteral("actionClose_Window"));
        actionClose_Window->setIcon(icon4);
        actionClose_All_Files = new QAction(MainWindow);
        actionClose_All_Files->setObjectName(QStringLiteral("actionClose_All_Files"));
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName(QStringLiteral("actionFind"));
        actionFind_Next = new QAction(MainWindow);
        actionFind_Next->setObjectName(QStringLiteral("actionFind_Next"));
        actionReplace = new QAction(MainWindow);
        actionReplace->setObjectName(QStringLiteral("actionReplace"));
        actionReplace_All = new QAction(MainWindow);
        actionReplace_All->setObjectName(QStringLiteral("actionReplace_All"));
        actionSidebar = new QAction(MainWindow);
        actionSidebar->setObjectName(QStringLiteral("actionSidebar"));
        actionSidebar->setCheckable(true);
        actionSidebar->setChecked(true);
        actionStatusbar = new QAction(MainWindow);
        actionStatusbar->setObjectName(QStringLiteral("actionStatusbar"));
        actionStatusbar->setCheckable(true);
        actionStatusbar->setChecked(true);
        actionToolbar = new QAction(MainWindow);
        actionToolbar->setObjectName(QStringLiteral("actionToolbar"));
        actionToolbar->setCheckable(true);
        actionToolbar->setChecked(true);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionAbout_QT = new QAction(MainWindow);
        actionAbout_QT->setObjectName(QStringLiteral("actionAbout_QT"));
        actionShow_Tabs = new QAction(MainWindow);
        actionShow_Tabs->setObjectName(QStringLiteral("actionShow_Tabs"));
        actionShow_Tabs->setCheckable(true);
        actionShow_Tabs->setChecked(true);
        actionWindows = new QAction(MainWindow);
        actionWindows->setObjectName(QStringLiteral("actionWindows"));
        actionWindows->setCheckable(true);
        actionUnix = new QAction(MainWindow);
        actionUnix->setObjectName(QStringLiteral("actionUnix"));
        actionUnix->setCheckable(true);
        actionMac = new QAction(MainWindow);
        actionMac->setObjectName(QStringLiteral("actionMac"));
        actionMac->setCheckable(true);
        actionFind_All = new QAction(MainWindow);
        actionFind_All->setObjectName(QStringLiteral("actionFind_All"));
        actionSelect_All = new QAction(MainWindow);
        actionSelect_All->setObjectName(QStringLiteral("actionSelect_All"));
        actionDeselect = new QAction(MainWindow);
        actionDeselect->setObjectName(QStringLiteral("actionDeselect"));
        actionOpen_Directory = new QAction(MainWindow);
        actionOpen_Directory->setObjectName(QStringLiteral("actionOpen_Directory"));
        actionBatch_File = new QAction(MainWindow);
        actionBatch_File->setObjectName(QStringLiteral("actionBatch_File"));
        actionCoffeeScript = new QAction(MainWindow);
        actionCoffeeScript->setObjectName(QStringLiteral("actionCoffeeScript"));
        actionC = new QAction(MainWindow);
        actionC->setObjectName(QStringLiteral("actionC"));
        actionJava = new QAction(MainWindow);
        actionJava->setObjectName(QStringLiteral("actionJava"));
        actionCSS = new QAction(MainWindow);
        actionCSS->setObjectName(QStringLiteral("actionCSS"));
        actionHTML = new QAction(MainWindow);
        actionHTML->setObjectName(QStringLiteral("actionHTML"));
        actionJavaScript = new QAction(MainWindow);
        actionJavaScript->setObjectName(QStringLiteral("actionJavaScript"));
        actionJSON = new QAction(MainWindow);
        actionJSON->setObjectName(QStringLiteral("actionJSON"));
        actionMakeFile = new QAction(MainWindow);
        actionMakeFile->setObjectName(QStringLiteral("actionMakeFile"));
        actionMatLab = new QAction(MainWindow);
        actionMatLab->setObjectName(QStringLiteral("actionMatLab"));
        actionPascal = new QAction(MainWindow);
        actionPascal->setObjectName(QStringLiteral("actionPascal"));
        actionPython = new QAction(MainWindow);
        actionPython->setObjectName(QStringLiteral("actionPython"));
        actionBash = new QAction(MainWindow);
        actionBash->setObjectName(QStringLiteral("actionBash"));
        actionCMake = new QAction(MainWindow);
        actionCMake->setObjectName(QStringLiteral("actionCMake"));
        actionC_2 = new QAction(MainWindow);
        actionC_2->setObjectName(QStringLiteral("actionC_2"));
        actionFortan = new QAction(MainWindow);
        actionFortan->setObjectName(QStringLiteral("actionFortan"));
        actionXML = new QAction(MainWindow);
        actionXML->setObjectName(QStringLiteral("actionXML"));
        actionLua = new QAction(MainWindow);
        actionLua->setObjectName(QStringLiteral("actionLua"));
        actionMarkDown = new QAction(MainWindow);
        actionMarkDown->setObjectName(QStringLiteral("actionMarkDown"));
        actionPerl = new QAction(MainWindow);
        actionPerl->setObjectName(QStringLiteral("actionPerl"));
        actionRuby = new QAction(MainWindow);
        actionRuby->setObjectName(QStringLiteral("actionRuby"));
        actionSQL = new QAction(MainWindow);
        actionSQL->setObjectName(QStringLiteral("actionSQL"));
        actionTeX = new QAction(MainWindow);
        actionTeX->setObjectName(QStringLiteral("actionTeX"));
        actionC_3 = new QAction(MainWindow);
        actionC_3->setObjectName(QStringLiteral("actionC_3"));
        actionChange_Font = new QAction(MainWindow);
        actionChange_Font->setObjectName(QStringLiteral("actionChange_Font"));
        actionShow_Linenumbers = new QAction(MainWindow);
        actionShow_Linenumbers->setObjectName(QStringLiteral("actionShow_Linenumbers"));
        actionShow_Linenumbers->setCheckable(true);
        actionShow_Linenumbers->setChecked(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        listView = new QListView(widget);
        listView->setObjectName(QStringLiteral("listView"));

        verticalLayout->addWidget(listView);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        splitter->addWidget(widget);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setAcceptDrops(true);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        splitter->addWidget(tabWidget);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_2 = new QLineEdit(widget_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);

        pushButton = new QPushButton(widget_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(widget_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit_3 = new QLineEdit(widget_4);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_2->addWidget(lineEdit_3);

        pushButton_3 = new QPushButton(widget_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(widget_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);


        verticalLayout_2->addWidget(widget_4);


        gridLayout->addWidget(widget_2, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 817, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuFind = new QMenu(menuBar);
        menuFind->setObjectName(QStringLiteral("menuFind"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuLine_Ending = new QMenu(menuView);
        menuLine_Ending->setObjectName(QStringLiteral("menuLine_Ending"));
        menuSyntax = new QMenu(menuView);
        menuSyntax->setObjectName(QStringLiteral("menuSyntax"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
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
        actionNew->setText(QApplication::translate("MainWindow", "New", nullptr));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "create a new document", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "Open", nullptr));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open a document", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "Save a document", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As", nullptr));
#ifndef QT_NO_TOOLTIP
        actionSave_As->setToolTip(QApplication::translate("MainWindow", "Save as ", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionSave_As->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", nullptr));
#ifndef QT_NO_TOOLTIP
        actionQuit->setToolTip(QApplication::translate("MainWindow", "Quit", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionCut->setText(QApplication::translate("MainWindow", "Cut", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCut->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_NO_SHORTCUT
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", nullptr));
#ifndef QT_NO_SHORTCUT
        actionCopy->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPaste->setShortcut(QApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_NO_SHORTCUT
        actionClose->setText(QApplication::translate("MainWindow", "Close", nullptr));
#ifndef QT_NO_TOOLTIP
        actionClose->setToolTip(QApplication::translate("MainWindow", "Close document", nullptr));
#endif // QT_NO_TOOLTIP
        actionReload->setText(QApplication::translate("MainWindow", "Reload", nullptr));
        actionUndo->setText(QApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QApplication::translate("MainWindow", "Redo", nullptr));
        actionNew_Window->setText(QApplication::translate("MainWindow", "New Window", nullptr));
        actionClose_Window->setText(QApplication::translate("MainWindow", "Close Window", nullptr));
        actionClose_All_Files->setText(QApplication::translate("MainWindow", "Close All Files", nullptr));
        actionFind->setText(QApplication::translate("MainWindow", "Find", nullptr));
        actionFind_Next->setText(QApplication::translate("MainWindow", "Find Next", nullptr));
        actionReplace->setText(QApplication::translate("MainWindow", "Replace", nullptr));
        actionReplace_All->setText(QApplication::translate("MainWindow", "Replace All", nullptr));
        actionSidebar->setText(QApplication::translate("MainWindow", "Show Sidebar", nullptr));
        actionStatusbar->setText(QApplication::translate("MainWindow", "Show Statusbar", nullptr));
        actionToolbar->setText(QApplication::translate("MainWindow", "Show Toolbar", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About ", nullptr));
        actionAbout_QT->setText(QApplication::translate("MainWindow", "About QT", nullptr));
        actionShow_Tabs->setText(QApplication::translate("MainWindow", "Show Tabs", nullptr));
        actionWindows->setText(QApplication::translate("MainWindow", "Windows", nullptr));
        actionUnix->setText(QApplication::translate("MainWindow", "Unix", nullptr));
        actionMac->setText(QApplication::translate("MainWindow", "Mac", nullptr));
        actionFind_All->setText(QApplication::translate("MainWindow", "Find All", nullptr));
        actionSelect_All->setText(QApplication::translate("MainWindow", "Select All", nullptr));
        actionDeselect->setText(QApplication::translate("MainWindow", "Deselect", nullptr));
        actionOpen_Directory->setText(QApplication::translate("MainWindow", "Open Directory", nullptr));
        actionBatch_File->setText(QApplication::translate("MainWindow", "Batch File", nullptr));
        actionCoffeeScript->setText(QApplication::translate("MainWindow", "CoffeeScript", nullptr));
        actionC->setText(QApplication::translate("MainWindow", "C#", nullptr));
        actionJava->setText(QApplication::translate("MainWindow", "Java", nullptr));
        actionCSS->setText(QApplication::translate("MainWindow", "CSS", nullptr));
        actionHTML->setText(QApplication::translate("MainWindow", "HTML", nullptr));
        actionJavaScript->setText(QApplication::translate("MainWindow", "JavaScript", nullptr));
        actionJSON->setText(QApplication::translate("MainWindow", "JSON", nullptr));
        actionMakeFile->setText(QApplication::translate("MainWindow", "MakeFile", nullptr));
        actionMatLab->setText(QApplication::translate("MainWindow", "MatLab", nullptr));
        actionPascal->setText(QApplication::translate("MainWindow", "Pascal", nullptr));
        actionPython->setText(QApplication::translate("MainWindow", "Python", nullptr));
        actionBash->setText(QApplication::translate("MainWindow", "Bash", nullptr));
        actionCMake->setText(QApplication::translate("MainWindow", "CMake", nullptr));
        actionC_2->setText(QApplication::translate("MainWindow", "C++", nullptr));
        actionFortan->setText(QApplication::translate("MainWindow", "Fortan", nullptr));
        actionXML->setText(QApplication::translate("MainWindow", "XML", nullptr));
        actionLua->setText(QApplication::translate("MainWindow", "Lua", nullptr));
        actionMarkDown->setText(QApplication::translate("MainWindow", "MarkDown", nullptr));
        actionPerl->setText(QApplication::translate("MainWindow", "Perl", nullptr));
        actionRuby->setText(QApplication::translate("MainWindow", "Ruby", nullptr));
        actionSQL->setText(QApplication::translate("MainWindow", "SQL", nullptr));
        actionTeX->setText(QApplication::translate("MainWindow", "TeX", nullptr));
        actionC_3->setText(QApplication::translate("MainWindow", "C", nullptr));
        actionChange_Font->setText(QApplication::translate("MainWindow", "Change Font", nullptr));
        actionShow_Linenumbers->setText(QApplication::translate("MainWindow", "Show Linenumbers", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Find", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Find All", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "Replace", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "Replace All", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "&File", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "&Edit", nullptr));
        menuFind->setTitle(QApplication::translate("MainWindow", "Find", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menuLine_Ending->setTitle(QApplication::translate("MainWindow", "Line Ending", nullptr));
        menuSyntax->setTitle(QApplication::translate("MainWindow", "Syntax", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
