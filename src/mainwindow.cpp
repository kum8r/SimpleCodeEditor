#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileSystemWatcher>
#include <QFontDatabase>
#include <QMimeDatabase>

MainWindow::MainWindow(QWidget * parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->menuSyntax->hide();
    ui->actionOpened_Files->setVisible(false);
    ui->openedFiles->hide();
    ui->actionShow_Minimap->setVisible(false);
    ui->minimap->hide();

    ui->splitter_4->setStretchFactor(1, 1); //file explorer and editor splitter
    //    ui->splitter->setStretchFactor(1, 1); //fileexplorer and opened files splitter
    ui->splitter_2->setStretchFactor(0, 1); //terminal and editor splitter
    ui->terminalWidget->hide();
    ui->findWidget->hide();

    m_settings = new QSettings("kumar", "SimpleCodeEditor", this);
    colorScheme = new QMap<QString, QString>();
    is_autosave = false;
    m_searchTextPosList.clear();

    colorScheme->insert("Default", ":/style/src/icons/default_classic.xml");
    colorScheme->insert("Default Dark", ":/style/src/icons/creator-dark.xml");

    menuActionGroup();
    loadWindowsGeomentry();
    createStatusBarWidgets();
    setupTerminalWidgets();
    setupMiniMapWidget();
    setupFindWidgets();
    createRecentAction();
    loadSettings();
    setDefaultLocationForFileExplorer(); //sets fileExplorer default location

    loadColorScheme();
    connect(ui->menuRecent_files, &QMenu::aboutToShow, this, &MainWindow::updateRecentActionList);
    //        connect(this, &MainWindow::focusOutEvent, this, &MainWindow::lostFocus);

    QsciLexer * lexer = new QsciLexerBash();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerBatch();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerCMake();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerCoffeeScript();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerCPP();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerCSharp();
    qDebug() << "csharp" << lexer->lexer();
    lexer = new QsciLexerCSS();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerD();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerDiff();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerFortran();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerFortran77();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerHTML();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerJavaScript();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerJSON();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerLua();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerMakefile();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerJava();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerMarkdown();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerMatlab();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerPascal();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerPerl();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerProperties();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerPython();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerRuby();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerSQL();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerTeX();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerYAML();
    qDebug() << lexer->lexer();
    lexer = new QsciLexerXML();
    qDebug() << lexer->lexer();
}

MainWindow::~MainWindow()
{
    saveWindowsGeomentry();
    saveSettings();
    delete m_findWidget;
    //    delete m_miniMap;
    delete m_filemodel;
    if (m_settingDialog != nullptr)
        delete m_settingDialog;
    delete m_terminal;
    delete m_statusBarSplitter;
    delete m_lineNumLabel;
    delete m_fileTypeLabel;
    delete ui;
}

void MainWindow::setTheme()
{
    //    QString theme = m_settings->value("theme", "Light").toString();
    //    if (theme == "Light")
    //    {
    //        theme = ":/style/light_theme.qss";
    //    }
    //    else
    //    {
    //        theme = ":/style/dark_theme.qss";
    //    }
    //    QFile f(theme);
    //    if (!f.exists())
    //    {
    //        printf("Unable to set stylesheet, file not found\n");
    //    }
    //    else
    //    {
    //        f.open(QFile::ReadOnly | QFile::Text);
    //        QTextStream ts(&f);
    //        //        qApp->setStyleSheet(ts.readAll());
    //    }
}

int MainWindow::newTab(QString tabname)
{
    CodeEditor * texteditor = new CodeEditor(this);
    int tabindex = ui->tabWidget->addTab(texteditor, tabname);
    ui->tabWidget->setCurrentIndex(tabindex);
    on_actionShow_Linenumbers_triggered();
    ui->tabWidget->currentWidget()->setFocus();
    return tabindex;
}

void MainWindow::openFile(QString filepath, int tabindex)
{
    if (filepath.isNull())
    {
        filepath = QFileDialog::getOpenFileName(this, tr("Open file"), QDir::homePath());
    }

    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        CodeEditor * editor = static_cast<CodeEditor *>(ui->tabWidget->widget(i));
        if (editor->getFileName() == filepath)
        {
            ui->tabWidget->setCurrentIndex(i);
            return;
        }
    }

    CodeEditor * texteditor = static_cast<CodeEditor *>(ui->tabWidget->widget(tabindex));
    QString line;

    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        line = in.readAll();
    }

    texteditor->setText(line);
    texteditor->setFileName(filepath);

    QString filename = filepath.section("/", -1, -1);
    ui->tabWidget->setTabText(tabindex, filename);
    setFiletype(filename);

    updateRecentFileList(filepath);
    revertBackTabName();
    loadCodeEditorSettings();
    setpreferencefornewtab(tabindex);
}

void MainWindow::createStatusBarWidgets()
{
    m_statusBarSplitter = new QSplitter(this);
    m_lineNumLabel = new QLabel(this);
    m_fileTypeLabel = new QLabel(this);
    ui->statusBar->addWidget(m_lineNumLabel);
    ui->statusBar->addWidget(m_statusBarSplitter);
    ui->statusBar->addWidget(m_fileTypeLabel);
}

void MainWindow::setupMiniMapWidget()
{
    //    m_miniMap = new CodeEditor(this);
    //    ui->gridLayout_6->addWidget(m_miniMap);
    //    m_miniMap->initMiniMap();
}

void MainWindow::setupTerminalWidgets()
{
    m_terminal = new TermWidget(0, this);
    ui->gridLayout_5->addWidget(m_terminal);
}

void MainWindow::setupFindWidgets()
{
    m_findWidget = new FindDialog();
    ui->findWidget->setLayout(m_findWidget->layout());

    connect(m_findWidget, SIGNAL(closeFindDialog()), this, SLOT(closeFindDialog()));
    connect(m_findWidget, SIGNAL(findButton_clicked(QString)), this, SLOT(findButton_clicked(QString)));
    connect(m_findWidget, SIGNAL(findPrev_clicked(QString)), this, SLOT(findPrev_clicked(QString)));
    connect(m_findWidget, SIGNAL(replace_clicked(QString)), this, SLOT(replace_clicked(QString)));
    connect(m_findWidget, SIGNAL(replaceAll_clicked(QString, QString)), this, SLOT(replaceAll_clicked(QString, QString)));
    connect(m_findWidget, SIGNAL(findStringChanged()), this, SLOT(clearSearchHighlight()));
}

void MainWindow::createRecentAction()
{
    QAction * recentFileAction = 0;
    for (auto i = 0; i < maxRecentFiles; ++i)
    {
        recentFileAction = new QAction(this);
        recentFileAction->setVisible(false);
        connect(recentFileAction, &QAction::triggered, this, &MainWindow::openRecent);
        m_recentFileActionList.append(recentFileAction);
        ui->menuRecent_files->addAction(recentFileAction);
    }
    recentFileAction = new QAction(this);
    recentFileAction->setText("Clear List");
    connect(recentFileAction, &QAction::triggered, this, &MainWindow::clearRecent);
    ui->menuRecent_files->addAction(recentFileAction);
}

void MainWindow::updateRecentActionList()
{
    QStringList recentFilePaths = m_settings->value("recentfiles").toStringList();

    int itEnd = 0u;
    if (recentFilePaths.size() <= maxRecentFiles)
        itEnd = recentFilePaths.size();
    else
        itEnd = maxRecentFiles;

    for (int i = 0u; i < itEnd; ++i)
    {
        QString strippedName = QFileInfo(recentFilePaths.at(i)).fileName();
        m_recentFileActionList.at(i)->setText(strippedName);
        m_recentFileActionList.at(i)->setData(recentFilePaths.at(i));
        m_recentFileActionList.at(i)->setVisible(true);
    }

    for (int i = itEnd; i < maxRecentFiles; ++i)
        m_recentFileActionList.at(i)->setVisible(false);
}

void MainWindow::updateRecentFileList(QString recentFilePath)
{
    QStringList recentFilePaths = m_settings->value("recentfiles").toStringList();
    recentFilePaths.removeAll(recentFilePath);
    recentFilePaths.prepend(recentFilePath);
    while (recentFilePaths.size() > maxRecentFiles)
        recentFilePaths.removeLast();
    m_settings->setValue("recentfiles", recentFilePaths);

    updateRecentActionList();
}

void MainWindow::menuActionGroup()
{
    QActionGroup * EOLGroup = new QActionGroup(this);
    ui->actionWindows->setActionGroup(EOLGroup);
    ui->actionMac->setActionGroup(EOLGroup);
    ui->actionUnix->setActionGroup(EOLGroup);

    QActionGroup * lexerGroup = new QActionGroup(this);
    ui->actionBash->setActionGroup(lexerGroup);
    ui->actionBatch_File->setActionGroup(lexerGroup);
    ui->actionC->setActionGroup(lexerGroup);
    ui->actionCpp->setActionGroup(lexerGroup);
    ui->actionCSharp->setActionGroup(lexerGroup);
    ui->actionCSS->setActionGroup(lexerGroup);
    ui->actionCoffeeScript->setActionGroup(lexerGroup);
    ui->actionCMake->setActionGroup(lexerGroup);
    ui->actionD->setActionGroup(lexerGroup);
    ui->actionDiff->setActionGroup(lexerGroup);
    ui->actionFortan->setActionGroup(lexerGroup);
    ui->actionFortan77->setActionGroup(lexerGroup);
    ui->actionHTML->setActionGroup(lexerGroup);
    ui->actionJSON->setActionGroup(lexerGroup);
    ui->actionJava->setActionGroup(lexerGroup);
    ui->actionJavaScript->setActionGroup(lexerGroup);
    ui->actionLua->setActionGroup(lexerGroup);
    ui->actionMatLab->setActionGroup(lexerGroup);
    ui->actionMakeFile->setActionGroup(lexerGroup);
    ui->actionMarkDown->setActionGroup(lexerGroup);
    ui->actionNormal->setActionGroup(lexerGroup);
    ui->actionPerl->setActionGroup(lexerGroup);
    ui->actionPascal->setActionGroup(lexerGroup);
    ui->actionPython->setActionGroup(lexerGroup);
    ui->actionProperties->setActionGroup(lexerGroup);
    ui->actionRuby->setActionGroup(lexerGroup);
    ui->actionSQL->setActionGroup(lexerGroup);
    ui->actionTeX->setActionGroup(lexerGroup);
    ui->actionYAML->setActionGroup(lexerGroup);
    ui->actionXML->setActionGroup(lexerGroup);
}

void MainWindow::saveWindowsGeomentry()
{
    m_settings->setValue("geomentry", this->saveGeometry());
}

void MainWindow::saveSettings()
{
}

void MainWindow::loadWindowsGeomentry()
{
    this->restoreGeometry(m_settings->value("geomentry").toByteArray());
}

void MainWindow::loadSettings()
{
    ui->actionFile_Explorer->setChecked(m_settings->value("fileexplorer", true).toBool());
    ui->actionShow_Minimap->setChecked(m_settings->value("minimap", true).toBool());
    ui->actionToolBar->setChecked(m_settings->value("toolbar", false).toBool());
    on_actionFile_Explorer_triggered();
    on_actionShow_Minimap_triggered();
    on_actionToolBar_triggered();

    //    ui->actionOpened_Files->setChecked(my_settings->value("opened files", true).toBool());
    //    on_actionOpened_Files_triggered();
}

void MainWindow::loadCodeEditorSettings()
{
    CodeEditor * codeeditor = static_cast<CodeEditor *>(ui->tabWidget->currentWidget());

    QFont fixedFont = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    QString fontName = m_settings->value("editorfont", fixedFont.family()).toString();
    int fontSize = m_settings->value("editorfontsize", 13).toInt();
    QFont font(fontName);
    font.setPointSize(fontSize);

    codeeditor->setFont(font);
    codeeditor->setTabWidth(m_settings->value("tabwidth").toInt());
    codeeditor->setAutoIndent(m_settings->value("autoindent").toBool());

    //caret width
    codeeditor->SendScintilla(QsciScintilla::SCI_SETCARETSTYLE, m_settings->value("caretstyle", 1).toInt());

    //match brackets
    if (m_settings->value("matchbracket").toBool())
    {
        codeeditor->setBraceMatching(QsciScintilla::SloppyBraceMatch);
    }
    else
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setBraceMatching(QsciScintilla::NoBraceMatch);
    }

    //show linenumbers
    if (m_settings->value("linenumbers").toBool())
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setMarginWidth(0, "0000");
    }
    else
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setMarginWidth(0, "");
    }

    //wrap words
    if (m_settings->value("wordwrap").toBool())
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapWord);
    }
    else
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapNone);
    }

    //autocomplete
    if (m_settings->value("autocomplete").toBool())
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setAutoCompletionSource(QsciScintilla::AcsAll);
    }
    else
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setAutoCompletionSource(QsciScintilla::AcsNone);
    }

    //    setTheme();
    setColorScheme();
}

void MainWindow::openDirectory(QString fileDir)
{
    m_filemodel = new QFileSystemModel();
    m_filemodel->setRootPath(fileDir);
    ui->treeView->setModel(m_filemodel);
    ui->treeView->setRootIndex(m_filemodel->index(fileDir));

    //it hides the other columns in treeview
    ui->treeView->setColumnHidden(1, 1);
    ui->treeView->setColumnHidden(2, 1);
    ui->treeView->setColumnHidden(3, 1);

    ui->fileExplorer->show();
    ui->actionFile_Explorer->setChecked(true);
}

void MainWindow::saveFile(QString filePath)
{
    QFileInfo fileinfo(filePath);
    if (fileinfo.exists())
    {
        QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->text();
        }
    }
    revertBackTabName();
}

void MainWindow::saveFileAs(QString fileName)
{
    QString saveFileName = "Save File - " + fileName;
    QString filepath = QFileDialog::getSaveFileName(this, saveFileName, QDir::homePath());
    if (filepath.isEmpty())
        return;

    QFile file(filepath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->text();
    }
    int tabindex = ui->tabWidget->currentIndex();
    ui->tabWidget->setCurrentIndex(tabindex);

    QString filename = filepath.section("/", -1, -1);
    ui->tabWidget->setTabText(tabindex, filename);

    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setFileName(filepath);
    revertBackTabName();
}

bool MainWindow::closeFile(int index)
{
    ui->findWidget->hide();
    ui->tabWidget->setCurrentIndex(index);

    if (static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->getTextChanges())
    {
        QMessageBox::StandardButton ask = QMessageBox::question(this, tr("Save changes before close"), tr("Do you want to save ") + ui->tabWidget->tabText(ui->tabWidget->currentIndex()),
                                                                QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Cancel);

        CodeEditor * editor = static_cast<CodeEditor *>(ui->tabWidget->widget(index));
        if (ask == QMessageBox::Yes)
        {
            if (editor->getFileName() == "")
            {
                saveFileAs(ui->tabWidget->tabText(ui->tabWidget->currentIndex()));
                delete ui->tabWidget->widget(index);
                ui->tabWidget->removeTab(index);
            }
            else
            {
                QString filepath = editor->getFileName();
                saveFile(filepath);
                delete ui->tabWidget->widget(index);
                ui->tabWidget->removeTab(index);
            }
            return true;
        }

        else if (ask == QMessageBox::No)
        {
            delete ui->tabWidget->widget(index);
            ui->tabWidget->removeTab(index);
            return true;
        }

        else if (ask == QMessageBox::Cancel)
        {
            return false;
        }
    }
    else
    {
        delete ui->tabWidget->widget(index);
        ui->tabWidget->removeTab(index);
        return true;
    }
    return true;
}

void MainWindow::setLineNumberAndColInStatusBar(int line, int index)
{
    m_lineNumLabel->setText("Col: " + QString::number(index + 1) + ", Line: " + QString::number(line + 1));

    if (line > 100)
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setMarginWidth(0, "00000");
    }
    else if (line > 1000)
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setMarginWidth(0, "000000");
    }
    else if (line > 10000)
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setMarginWidth(0, "0000000");
    }
}

void MainWindow::setDefaultLocationForFileExplorer()
{
    m_filemodel = new QFileSystemModel();
    m_filemodel->setRootPath(QDir::homePath());
    ui->treeView->setModel(m_filemodel);
    ui->treeView->setRootIndex(m_filemodel->index(QDir::homePath()));

    //hides header
    ui->treeView->setHeaderHidden(true);

    //it hides the other columns in treeview
    ui->treeView->setColumnHidden(1, 1);
    ui->treeView->setColumnHidden(2, 1);
    ui->treeView->setColumnHidden(3, 1);
}

void MainWindow::setEOL()
{
    if ((QSysInfo::productType() == "windows") | (QSysInfo::productType() == "winrt"))
    {
        ui->actionWindows->setChecked(true);
        on_actionWindows_triggered();
    }
    else if (QSysInfo::productType() == "osx")
    {
        ui->actionMac->setChecked(true);
        on_actionMac_triggered();
    }
    else
    {
        ui->actionUnix->setChecked(true);
        on_actionUnix_triggered();
    }
}

void MainWindow::addtoOpenedFiles(QString fileName)
{
    ui->listWidget->addItem(fileName);
}

void MainWindow::setFiletype(QString fileName)
{
    QFileInfo fileinfo(fileName);
    QString extension = fileinfo.suffix();

    if (extension.isEmpty())
    {
        QMimeDatabase db;
        QMimeType mime = db.mimeTypeForFile(fileinfo);
        qDebug() << mime.suffixes();
        extension = mime.preferredSuffix();
    }

    if (extension == "txt")
    {
        ui->actionNormal->setChecked(true);
        on_actionNormal_triggered();
    }
    else if (extension == "sh")
    {
        ui->actionBash->setChecked(true);
        on_actionBash_triggered();
    }
    else if (extension == "bat")
    {
        ui->actionBatch_File->setChecked(true);
        on_actionBatch_File_triggered();
    }
    else if ((extension == "c") or (extension == "cpp") or (extension == "h") or (extension == "cxx")
             or (extension == "hpp") or (extension == "hxx"))
    {
        ui->actionC->setChecked(true);
        on_actionCpp_triggered();
    }
    else if (extension == "cs")
    {
        ui->actionCSharp->setChecked(true);
        on_actionCSharp_triggered();
    }
    else if (extension == "css")
    {
        ui->actionCSS->setChecked(true);
        on_actionCSS_triggered();
    }
    else if (extension == "d")
    {
        ui->actionD->setChecked(true);
        on_actionD_triggered();
    }
    else if (extension == "f")
    {
        on_actionFortan_triggered();
    }
    else if (extension == "html")
    {
        ui->actionHTML->setChecked(true);
        on_actionHTML_triggered();
    }
    else if (extension == "java")
    {
        ui->actionJava->setChecked(true);
        on_actionJava_triggered();
    }
    else if (extension == "js")
    {
        ui->actionJavaScript->setChecked(true);
        on_actionJavaScript_triggered();
        //        m_fileTypeLabel->setText("Javascript");
    }
    else if (extension == "json")
    {
        ui->actionJSON->setChecked(true);
        on_actionJSON_triggered();
    }
    else if (extension == "lua")
    {
        on_actionLua_triggered();
    }
    else if (extension == "md")
    {
        ui->actionMarkDown->setChecked(true);
        on_actionMarkDown_triggered();
    }
    else if (extension == "mlx")
    {
        ui->actionMatLab->setChecked(true);
        on_actionMatLab_triggered();
        //        m_fileTypeLabel->setText("Matlab");
    }
    else if (extension == "pas")
    {
        on_actionPascal_triggered();
        //        m_fileTypeLabel->setText("Pascal");
    }
    else if (extension == "pl")
    {
        ui->actionPerl->setChecked(true);
        on_actionPerl_triggered();
        //        m_fileTypeLabel->setText("Perl");
    }
    else if (extension == "py")
    {
        ui->actionPython->setChecked(true);
        on_actionPython_triggered();
        //        m_fileTypeLabel->setText("Python");
    }
    else if (extension == "rb")
    {
        ui->actionRuby->setChecked(true);
        on_actionRuby_triggered();
    }
    else if (extension == "sql" or extension == "sqlite")
    {
        ui->actionSQL->setChecked(true);
        on_actionSQL_triggered();
    }
    else if (extension == "yaml")
    {
        ui->actionYAML->setChecked(true);
        on_actionYAML_triggered();
    }
    else if (extension == "xml")
    {
        ui->actionXML->setChecked(true);
        on_actionXML_triggered();
        //        m_fileTypeLabel->setText("XML");
    }
    else
    {
        ui->actionNormal->setChecked(true);
        on_actionNormal_triggered();
        //        m_fileTypeLabel->setText("Normal");
    }
}

void MainWindow::changeTabNameIfFileChanges()
{
    QString tabName;
    if (!ui->tabWidget->tabText(ui->tabWidget->currentIndex()).contains("- *"))
    {
        tabName = ui->tabWidget->tabText(ui->tabWidget->currentIndex()) + "- *";
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), tabName);
    }
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setTextChanges(true);
}

void MainWindow::highlighsearchtext(QString searchText)
{
    search_string = searchText;
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_INDICSETSTYLE, 0, 7);
    m_searchTextPosList.clear();
    QString document = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->text();
    int end = document.lastIndexOf(searchText);

    if (!searchText.isEmpty())
    {
        int curpos = -1;
        if (end != -1)
        {
            while (curpos != end)
            {
                curpos = document.indexOf(searchText, curpos + 1);
                static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_INDICATORFILLRANGE, curpos, searchText.length());
                m_searchTextPosList.append(curpos);
            }
        }
    }
}

void MainWindow::setColorScheme(QString colorSchemeFile)
{
    if (colorSchemeFile.isNull())
    {
        colorSchemeFile = colorScheme->value(m_settings->value("colorscheme", "Default").toString());
    }
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setColorScheme(colorSchemeFile);
}

void MainWindow::revertBackTabName()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setTextChanges(false);
    if (ui->tabWidget->tabText(ui->tabWidget->currentIndex()).contains("- *"))
    {
        QString filepath = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->getFileName();
        QString tabtext = filepath.section("/", -1, -1);
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), tabtext);
    }
}

void MainWindow::loadMiniMap(int index)
{
    //    if (ui->actionShow_Minimap->isChecked())
    //    {
    //        QsciDocument document = static_cast<CodeEditor *>(ui->tabWidget->widget(index))->document();
    //        m_miniMap->setDocument(document);
    //    }
}

void MainWindow::setpreferencefornewtab(int index)
{
    connect(static_cast<CodeEditor *>(ui->tabWidget->widget(index)), &QsciScintilla::cursorPositionChanged, this, &MainWindow::statusBar);
    connect(static_cast<CodeEditor *>(ui->tabWidget->widget(index)), &QsciScintilla::textChanged, this, &MainWindow::changeTabNameIfFileChanges);
    connect(static_cast<CodeEditor *>(ui->tabWidget->widget(index)), &QsciScintilla::cursorPositionChanged, this, &MainWindow::setLineNumberAndColInStatusBar);
    connect(static_cast<CodeEditor *>(ui->tabWidget->widget(index)), SIGNAL(dropFiles(QString)), this, SLOT(openFile(QString)));
    connect(static_cast<CodeEditor *>(ui->tabWidget->widget(index))->verticalScrollBar(), &QScrollBar::valueChanged, this, &MainWindow::scrollMiniMap);
}

void MainWindow::closeEvent(QCloseEvent * event)
{
    int tabcount = ui->tabWidget->count();
    for (int i = tabcount - 1; i >= 0; i--)
    {
        if (!closeFile(i))
        {
            break;
        }
    }
    if (ui->tabWidget->count() == 0)
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    event->accept();
}

void MainWindow::dragEnterEvent(QDragEnterEvent * event)
{
    event->accept();
}

void MainWindow::dragMoveEvent(QDragMoveEvent * event)
{
    event->accept();
}

void MainWindow::dropEvent(QDropEvent * event)
{
    if (event->mimeData()->hasFormat("text/uri-list"))
    {
        QList<QUrl> urls = event->mimeData()->urls();
        if (urls.isEmpty())
            return;

        QString fileName = urls.first().toLocalFile();
        if (fileName.isEmpty())
            return;

        openFile(fileName);
    }
}

void MainWindow::focusOutEvent(QFocusEvent * event)
{
    Q_UNUSED(event);
}

void MainWindow::openFile(QString filepath)
{
    openFile(filepath, newTab(""));
}

void MainWindow::on_actionNew_triggered()
{
    int tabindex = newTab("untitled");
    loadCodeEditorSettings();
    setpreferencefornewtab(tabindex);
}

void MainWindow::on_actionOpen_triggered()
{
    openFile();
}

void MainWindow::on_actionOpenDirectory_triggered()
{
    QString filedir = QFileDialog::getExistingDirectory(this, "Open Directory", QDir::homePath());
    openDirectory(filedir);
}

void MainWindow::on_actionSave_triggered()
{
    CodeEditor * editor = static_cast<CodeEditor *>(ui->tabWidget->currentWidget());
    if (editor->getFileName() == "")
    {
        saveFileAs(ui->tabWidget->tabText(ui->tabWidget->currentIndex()));
    }
    else
    {
        QString filepath = editor->getFileName();
        saveFile(filepath);
    }
}

void MainWindow::on_actionSave_AS_triggered()
{
    saveFileAs(ui->tabWidget->tabText(ui->tabWidget->currentIndex()));
}

void MainWindow::on_actionSave_All_triggered()
{
    int curIndex = ui->tabWidget->currentIndex(), tabcount = ui->tabWidget->count();
    for (int i = 0; i < tabcount; i++)
    {
        CodeEditor * editor = static_cast<CodeEditor *>(ui->tabWidget->widget(i));
        bool textchanged = editor->getTextChanges();
        if (textchanged)
        {
            if (editor->getFileName() == "")
            {
                saveFileAs(ui->tabWidget->tabText(i));
            }
            else
            {
                QString filepath = editor->getFileName();
                saveFile(filepath);
            }
        }
    }
    ui->tabWidget->setCurrentIndex(curIndex);
}

void MainWindow::on_actionPrint_triggered()
{
    QsciPrinter printer;
    QsciScintilla * codeeditor = static_cast<CodeEditor *>(ui->tabWidget->currentWidget());
    QPrintDialog * dialog = new QPrintDialog(&printer);
    dialog->setWindowTitle("Print Document");
    if (dialog->exec() != QDialog::Accepted)
        return;

    printer.printRange(codeeditor);
}

void MainWindow::on_actionPrint_Preview_triggered()
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer, this);

    connect(&preview, SIGNAL(paintRequested(QPrinter *)), this, SLOT(print(QPrinter *)));
    preview.exec();
}

void MainWindow::print(QPrinter * printer)
{
    QString text = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->text(); // your text is here
    QPainter painter;
    painter.begin(printer);
    QPrintPreviewDialog preview(printer, this);
    CodeEditor * editor = static_cast<CodeEditor *>(ui->tabWidget->currentWidget());
    QFontMetrics fm(editor->font());

    QRect rect = fm.boundingRect(fm.boundingRect(text), Qt::AlignLeft | Qt::AlignTop, text);
    qDebug() << rect;
    painter.drawText(rect, Qt::AlignLeft | Qt::AlignTop, text);
    painter.end();
}

void MainWindow::openRecent()
{
    QAction * action = qobject_cast<QAction *>(sender());
    if (action)
        openFile(action->data().toString());
}

void MainWindow::clearRecent()
{
    m_settings->remove("recentfiles");
}

void MainWindow::on_actionNew_Window_triggered()
{
    MainWindow * newwindow = new MainWindow();
    newwindow->show();
    newwindow->on_actionNew_triggered();
}

void MainWindow::on_actionClose_Window_triggered()
{
    int tabcount = ui->tabWidget->count();
    for (int i = 0; i < tabcount; i++)
    {
        if (!closeFile(i))
        {
            break;
        }
    }
    if (ui->tabWidget->count() == 0)
    {
        this->close();
    }
}

void MainWindow::on_actionClose_triggered()
{
    closeFile(ui->tabWidget->currentIndex());
    if (ui->tabWidget->count() == 0)
    {
        on_actionNew_triggered();
    }
}

void MainWindow::on_actionClose_All_Files_triggered()
{
    int tabcount = ui->tabWidget->count();
    for (int i = tabcount - 1; i >= 0; i--)
    {
        if (!closeFile(i))
        {
            break;
        }
    }
    if (ui->tabWidget->count() == 0)
    {
        on_actionNew_triggered();
    }
}

void MainWindow::on_actionExit_triggered()
{
    int tabcount = ui->tabWidget->count();
    for (int i = tabcount - 1; i >= 0; i--)
    {
        if (!closeFile(i))
        {
            break;
        }
    }
    if (ui->tabWidget->count() == 0)
    {
        qApp->exit();
    }
}

void MainWindow::on_actionUndo_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->redo();
}

void MainWindow::on_actionCut_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->paste();
}

void MainWindow::on_actionSelect_All_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->selectAll();
}

void MainWindow::on_actionDeselect_triggered()
{
    int curPos = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_SETCURRENTPOS);
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->selectAll(false);
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_SETCURRENTPOS, curPos);
}

void MainWindow::on_actionAdd_Indent_triggered()
{
    int pos = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
    int line = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_LINEFROMPOSITION, pos);
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->indent(line);
}

void MainWindow::on_actionDecrease_Indent_triggered()
{
    int pos = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
    int line = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_LINEFROMPOSITION, pos);
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->unindent(line);
}

void MainWindow::on_actionDuplicate_Line_triggered()
{

    CodeEditor * editor = static_cast<CodeEditor *>(ui->tabWidget->currentWidget());

    if (editor->hasSelectedText())
    {
        int lineFrom, indexFrom, lineTo, indexTo;
        editor->getSelection(&lineFrom, &indexFrom, &lineTo, &indexTo);
        editor->SendScintilla(QsciScintilla::SCI_SELECTIONDUPLICATE);
    }
    else
    {
        editor->SendScintilla(QsciScintilla::SCI_LINEDUPLICATE);
    }
    //    int pos = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
    //    int linepos = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_LINEFROMPOSITION, pos);
    //    QString text = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->text(linepos);
    //    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->insertAt(text, linepos, 0);
}

void MainWindow::on_actionComment_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->toggleCommentLines();
}

void MainWindow::on_actionComment_Block_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->toggleCommentBlock();
}

void MainWindow::on_actionUPPER_CASE_triggered()
{
    QString selectedText = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->selectedText();
    if (!selectedText.isEmpty())
    {
        QString uppercase_string = selectedText.toUpper();
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->replaceSelectedText(uppercase_string);
    }
}

void MainWindow::on_actionlower_case_triggered()
{
    QString selectedText = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->selectedText();
    if (!selectedText.isEmpty())
    {
        QString lowercase_string = selectedText.toLower();
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->replaceSelectedText(lowercase_string);
    }
}

void MainWindow::on_actionFind_triggered()
{
    ui->findWidget->show();
    m_findWidget->hidereplaceWidget();
}

void MainWindow::on_actionFind_Prev_triggered()
{
    findPrev_clicked(m_findWidget->getFindString());
}

void MainWindow::on_actionReplace_triggered()
{
    ui->findWidget->show();
    m_findWidget->showreplaceWidget();
}

void MainWindow::on_actionReplace_All_triggered()
{
    replaceAll_clicked(m_findWidget->getFindString(), m_findWidget->getReplaceString());
}

void MainWindow::on_actionGo_to_Line_triggered()
{
    int totalline = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->lines();
    int line = QInputDialog::getInt(this, "Go to Line", "enter the line", 1, 1, totalline);
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setCursorPosition(line - 1, 0);
}

void MainWindow::findButton_clicked(QString searchtext)
{
    bool search = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->findFirst(searchtext, m_findWidget->getRegexp(), m_findWidget->getCasesensitive(), m_findWidget->getWholeword(), 0);
    if (!search)
    {
        QMessageBox::warning(this, "Find", "search has ended", QMessageBox::Ok);
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setCursorPosition(0, 0);
        search = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->findFirst(searchtext, m_findWidget->getRegexp(), m_findWidget->getCasesensitive(), m_findWidget->getWholeword(), 0);
    }
    highlighsearchtext(searchtext);
}

void MainWindow::findPrev_clicked(QString searchtext)
{
    bool search;
    (static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->findFirst(searchtext, m_findWidget->getRegexp(), m_findWidget->getCasesensitive(), m_findWidget->getWholeword(), 0, 0));
    {
        search = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->findNext();
    }
    if (!search)
    {
        QMessageBox::warning(this, "find", "search has ended", QMessageBox::Ok);
    }
    highlighsearchtext(searchtext);
}

void MainWindow::replace_clicked(QString replacetext)
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->replaceSelectedText(replacetext);
}

void MainWindow::replaceAll_clicked(QString searchtext, QString replacetext)
{
    QString document = static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->text();
    document.replace(searchtext, replacetext);
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setText(document);
}

void MainWindow::closeFindDialog()
{
    ui->findWidget->hide();
    clearSearchHighlight();
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->cancelFind();
}

void MainWindow::clearSearchHighlight()
{
    for (int i = 0; i < m_searchTextPosList.count(); i++)
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_INDICATORCLEARRANGE, m_searchTextPosList[i], search_string.length());
    }
    m_searchTextPosList.clear();
}

void MainWindow::on_actionOpened_Files_triggered()
{
    m_settings->setValue("openedfiles", ui->actionOpened_Files->isChecked());
    if (ui->actionOpened_Files->isChecked())
    {
        ui->openedFiles->show();
    }
    else
    {
        ui->openedFiles->hide();
    }
}

void MainWindow::on_actionFile_Explorer_triggered()
{
    m_settings->setValue("fileexplorer", ui->actionFile_Explorer->isChecked());
    if (ui->actionFile_Explorer->isChecked())
    {
        ui->fileExplorer->show();
        ui->splitter->show();
    }
    else
    {
        ui->fileExplorer->hide();
        ui->splitter->hide();
    }
}

void MainWindow::on_actionTerminal_triggered()
{
    ui->splitter_2->setChildrenCollapsible(true);
    QObject::connect(m_terminal, SIGNAL(finished()), this, SLOT(hideTerminalWidget()));
    ui->terminalWidget->show();
    m_terminal->startShellProgram();
    m_terminal->setFocus();
}

void MainWindow::on_actionMac_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setEolMode(QsciScintilla::EolMac);
}

void MainWindow::on_actionUnix_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setEolMode(QsciScintilla::EolUnix);
}

void MainWindow::on_actionWindows_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setEolMode(QsciScintilla::EolWindows);
}

void MainWindow::on_actionWordWrap_triggered()
{
    m_settings->setValue("wordwrap", ui->actionShow_Linenumbers->isChecked());
    if (ui->actionWordWrap->isChecked())
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapWord);
    }
    else
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapNone);
    }
}

void MainWindow::on_actionShow_Linenumbers_triggered()
{
    m_settings->setValue("linenumbers", ui->actionShow_Linenumbers->isChecked());
    if (ui->actionShow_Linenumbers->isChecked())
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setMarginWidth(0, "0000");
    }
    else
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setMarginWidth(0, "");
    }
}

void MainWindow::on_actionToolBar_triggered()
{
    m_settings->setValue("toolbar", ui->actionToolBar->isChecked());
    if (ui->actionToolBar->isChecked())
    {
        ui->mainToolBar->show();
    }
    else
    {
        ui->mainToolBar->hide();
    }
}

void MainWindow::on_actionShow_Minimap_triggered()
{
    m_settings->setValue("minimap", ui->actionShow_Minimap->isChecked());
    if (ui->actionShow_Minimap->isChecked())
    {
        //        ui->minimap->show();
    }
    else
    {
        //        ui->minimap->hide();
    }
}

void MainWindow::on_actionStatusbar_triggered()
{
    if (ui->actionStatusbar->isChecked())
    {
        ui->statusBar->show();
    }
    else
    {
        ui->statusBar->hide();
    }
}

void MainWindow::on_actionDisplay_EOL_triggered()
{
    if (ui->actionDisplay_EOL->isChecked())
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setEolVisibility(true);
    }
    else
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setEolVisibility(false);
    }
}

void MainWindow::on_actionDisplay_White_Space_triggered()
{
    if (ui->actionDisplay_White_Space->isChecked())
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setWhitespaceVisibility(QsciScintilla::WhitespaceVisibility::WsVisible);
    }
    else
    {
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setEolVisibility(QsciScintilla::WhitespaceVisibility::WsInvisible);
    }
}

void MainWindow::on_actionZoom_In_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->zoomIn();
}

void MainWindow::on_actionZoom_Out_triggered()
{
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->zoomOut();
}

void MainWindow::on_actionNormal_triggered()
{
    setLexer("Normal");
}

void MainWindow::on_actionBash_triggered()
{
    setLexer("Bash");
}

void MainWindow::on_actionBatch_File_triggered()
{
    this->setLexer("Bash");
}

void MainWindow::on_actionC_triggered()
{
    setLexer("C++");
}

void MainWindow::on_actionCSharp_triggered()
{
    setLexer("C#");
}

void MainWindow::on_actionCpp_triggered()
{
    //    m_fileTypeLabel->setText("Cpp");
    setLexer("C++");
}

void MainWindow::on_actionCSS_triggered()
{
    setLexer("CSS");
}

void MainWindow::on_actionCMake_triggered()
{
    setLexer("CMake");
}

void MainWindow::on_actionCoffeeScript_triggered()
{
    setLexer("CoffeeScript");
}

void MainWindow::on_actionD_triggered()
{
    setLexer("D");
}

void MainWindow::on_actionDiff_triggered()
{
    setLexer("Diff");
}

void MainWindow::on_actionFortan_triggered()
{
    setLexer("Fortran");
}

void MainWindow::on_actionFortan77_triggered()
{
    setLexer("Fortran77");
}

void MainWindow::on_actionHTML_triggered()
{
    setLexer("HTML");
}

void MainWindow::on_actionJava_triggered()
{
    setLexer("Java");
}

void MainWindow::on_actionJavaScript_triggered()
{
    setLexer("JavaScript");
}

void MainWindow::on_actionJSON_triggered()
{
    setLexer("JSON");
}

void MainWindow::on_actionLua_triggered()
{
    setLexer("Lua");
}

void MainWindow::on_actionMarkDown_triggered()
{
    setLexer("Markdown");
}

void MainWindow::on_actionMakeFile_triggered()
{
    setLexer("Makefile");
}

void MainWindow::on_actionMatLab_triggered()
{
    setLexer("Matlab");
}

void MainWindow::on_actionPascal_triggered()
{
    setLexer("Pascal");
}

void MainWindow::on_actionPython_triggered()
{
    setLexer("Python");
}

void MainWindow::on_actionPerl_triggered()
{
    setLexer("Perl");
}

void MainWindow::on_actionProperties_triggered()
{
    setLexer("Properties");
}

void MainWindow::on_actionRuby_triggered()
{
    setLexer("Ruby");
}

void MainWindow::on_actionSQL_triggered()
{
    setLexer("SQL");
}

void MainWindow::on_actionTeX_triggered()
{
    setLexer("TeX");
}

void MainWindow::on_actionXML_triggered()
{
    setLexer("XML");
}

void MainWindow::on_actionYAML_triggered()
{
    setLexer("YAML");
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About code editor"), tr(" "));
}

void MainWindow::on_actionAbout_QT_triggered()
{
    QMessageBox::aboutQt(this, "About Qt");
}

void MainWindow::on_actionSettings_triggered()
{
    m_settingDialog = new Settings();
    m_settingDialog->exec();
    loadCodeEditorSettings();
}

void MainWindow::on_treeView_doubleClicked(const QModelIndex & index)
{
    QString filepath = m_filemodel->filePath(index);
    QFileInfo fileinfo(filepath);
    if (fileinfo.isDir())
    {
        openDirectory(filepath);
        return;
    }
    openFile(filepath);
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem * item)
{
    Q_UNUSED(item);
    //    int index = ui->listWidget->row(item);
    //    ui->tabWidget->setCurrentIndex(index);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (ui->tabWidget->count() <= 0)
        return;

    if (static_cast<CodeEditor *>(ui->tabWidget->widget(index))->lexer() != nullptr)
    {
        QString lexername = QString::fromUtf8(static_cast<CodeEditor *>(ui->tabWidget->widget(index))->lexer()->lexer());
        m_fileTypeLabel->setText(lexername.toUpper());
    }
    else
    {
        m_fileTypeLabel->setText("Normal");
    }
    loadMiniMap(index);
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    closeFile(index);
    if (ui->tabWidget->count() == 0)
    {
        on_actionNew_triggered();
    }
}

void MainWindow::setLexer(QString lexername)
{
    QMap<QString, QsciLexer *> languageToLexer = {
        { "Normal", nullptr },
        { "Bash", new QsciLexerBash() },
        { "Batch", new QsciLexerBatch() },
        { "CMake", new QsciLexerCMake() },
        { "CoffeeScript", new QsciLexerCoffeeScript() },
        { "C++", new QsciLexerCPP() },
        { "C#", new QsciLexerCSharp() },
        { "CSS", new QsciLexerCSS() },
        { "D", new QsciLexerD() },
        { "Diff", new QsciLexerDiff() },
        { "Fortran", new QsciLexerFortran() },
        { "Fortran77", new QsciLexerFortran77() },
        { "HTML", new QsciLexerHTML() },
        { "Java", new QsciLexerJava() },
        { "JavaScript", new QsciLexerJavaScript() },
        { "JSON", new QsciLexerJSON() },
        { "Lua", new QsciLexerLua() },
        { "Makefile", new QsciLexerMakefile() },
        { "Markdown", new QsciLexerMarkdown() },
        { "Matlab", new QsciLexerMatlab() },
        { "Pascal", new QsciLexerPascal() },
        { "Perl", new QsciLexerPerl() },
        { "Properties", new QsciLexerProperties() },
        { "Python", new QsciLexerPython() },
        { "Ruby", new QsciLexerRuby() },
        { "SQL", new QsciLexerSQL() },
        { "TeX", new QsciLexerTeX() },
        { "YAML", new QsciLexerYAML() },
        { "XML", new QsciLexerXML() }
    };

    m_fileTypeLabel->setText("Normal");
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setFileType(lexername);

    QMap<QString, QsciLexer *>::iterator i = languageToLexer.find(lexername);
    QsciLexer * lexer = nullptr;
    QFont font = QFont(m_settings->value("editorfont").toString());

    if (i != languageToLexer.end())
    {
        lexer = i.value();
    }

    if (lexer != nullptr)
    {
        lexer->setDefaultFont(font);
        lexer->setAutoIndentStyle(true);
        static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setFolding(QsciScintilla::FoldStyle::BoxedTreeFoldStyle);
    }

    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setLexer(lexer);
    static_cast<CodeEditor *>(ui->tabWidget->currentWidget())->setFont(font);
    setColorScheme();
}

void MainWindow::setTextinMinimap()
{
}

void MainWindow::scrollMiniMap(int value)
{
    //    m_miniMap->verticalScrollBar()->setValue(value * 0.25);
}

void MainWindow::hideTerminalWidget()
{
    ui->terminalWidget->hide();
}

void MainWindow::on_termClose_clicked()
{
    hideTerminalWidget();
}

void MainWindow::on_actionReload_File_triggered()
{
    CodeEditor * texteditor = static_cast<CodeEditor *>(ui->tabWidget->widget(ui->tabWidget->currentIndex()));
    QString filename = texteditor->getFileName();
    openFile(filename, ui->tabWidget->currentIndex());
}

void MainWindow::loadColorScheme()
{
    QFileSystemWatcher * watcher = new QFileSystemWatcher();
    watcher->addPath(QDir::homePath() + "/.config/SimpleCodeEditor/ColorScheme/");

    connect(watcher, SIGNAL(fileChanged(const QString &)), this, SLOT(addColorScheme(const QString &)));
    //    connect(watcher, &QFileSystemWatcher::fileChanged, this, &MainWindow::colorScheme);
}

void MainWindow::addColorScheme(const QString path)
{
    qDebug() << "filechanger" << path;
}
