#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->splitter_4->setStretchFactor(1,1);  //file explorer and editor splitter
    ui->splitter->setStretchFactor(1,1);    //fileexplorer and opened files splitter
    ui->splitter_2->setStretchFactor(0, 1); //terminal and editor splitter

    createStatusBarWidgets();

    ui->treeView->hide();       //fileExplorer
    ui->listWidget->hide();     //openedFiles
    ui->label->hide();          //fileExplorer Title
    ui->label_2->hide();        //openedFiles Title
    ui->findWidget->hide();         //find dialog
    ui->terminalWidget->hide();
    ui->widget->hide();

//    minimap
    minimap = new MiniMap ();
    ui->minimap->setLayout(minimap->layout());

//    termwidget
    console = new TermWidget (0, this);
    ui->gridLayout_5->addWidget(console);

    setupFindWidgets();

    my_settings = new QSettings ("kumar","SimpleCodeEditor",this);
    colorScheme = new QMap<QString, QString> ();
    colorScheme->insert("Default", ":/style/src/icons/default_classic.xml");
    colorScheme->insert("Default Dark", ":/style/src/icons/creator-dark.xml");

    menuActionGroup();
    loadWindowsGeomentry();
    loadSettings();
    setDefaultLocationForFileExplorer();      //sets fileExplorer default location
    createRecentAction();
    on_actionShow_Minimap_triggered();

    is_autosave = false;
    searchtext_position_list.clear();

    connect(ui->menuRecent_files, &QMenu::aboutToShow, this, &MainWindow::updateRecentActionList);
//    connect(this, &MainWindow::focusOutEvent, this, &MainWindow::lostFocus);
}

MainWindow::~MainWindow()
{
    saveWindowsGeomentry();
    saveSettings();
    delete find;
    delete minimap;
    delete filemodel;
    if (settings_dialog)
        delete settings_dialog;
    delete console;
    delete ui;
}

void MainWindow::setTheme()
{
    QString theme = my_settings->value("theme", "Light").toString();
    if (theme == "Light")
    {
        theme = ":/style/light_theme.qss";
    }
    else
    {
        theme = ":/style/dark_theme.qss";
    }
    QFile f(theme);
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }
}

int MainWindow::newTab(QString tabname)
{
    CodeEditor *texteditor = new CodeEditor(this);
    int tabindex = ui->tabWidget->addTab(texteditor,tabname);
    ui->tabWidget->setCurrentIndex(tabindex);
    ui->listWidget->addItem(tabname);
    ui->tabWidget->currentWidget()->setFocus();
    loadCodeEditorSettings();
    on_actionShow_Linenumbers_triggered(); // to show linenumber if it is checked
    setColorScheme(texteditor->lexer(), current_theme_file);
    return tabindex;
}

void MainWindow::createStatusBarWidgets()
{
//  line number and file type widget for statusbar
    statusbar_splitter = new QSplitter(this);
    linenumber_label = new QLabel(this);
    filetype_label = new QLabel(this);
    ui->statusBar->addWidget(linenumber_label);
    ui->statusBar->addWidget(statusbar_splitter);
    ui->statusBar->addWidget(filetype_label);
}

void MainWindow::setupFindWidgets()
{
    find = new FindDialog();
    ui->findWidget->setLayout(find->layout());

    connect(find, SIGNAL(closeFindDialog()),this,SLOT(closeFindDialog()));
    connect(find, SIGNAL(findButton_clicked(QString)),this,SLOT(findButton_clicked(QString)));
    connect(find, SIGNAL(findPrev_clicked(QString)),this,SLOT(findPrev_clicked(QString)));
    connect(find, SIGNAL(replace_clicked(QString)),this,SLOT(replace_clicked(QString)));
    connect(find, SIGNAL(replaceAll_clicked(QString, QString)), this, SLOT(replaceAll_clicked(QString, QString)));
    connect(find, SIGNAL(findStringChanged()), this, SLOT(clearSearchHighlight()));
}

void MainWindow::createRecentAction()
{
    QAction* recentFileAction = 0;
    for(auto i = 0; i < maxRecentFiles; ++i)
    {
        recentFileAction = new QAction(this);
        recentFileAction->setVisible(false);
        connect(recentFileAction, &QAction::triggered, this, &MainWindow::openRecent);
        recentFileActionList.append(recentFileAction);
        ui->menuRecent_files->addAction(recentFileAction);
    }
    recentFileAction = new QAction (this);
    recentFileAction->setText("Clear List");
    connect(recentFileAction, &QAction::triggered, this, &MainWindow::clearRecent);
    ui->menuRecent_files->addAction(recentFileAction);
}

void MainWindow::updateRecentActionList()
{
    QStringList recentFilePaths = my_settings->value("recentFiles").toStringList();

    auto itEnd = 0u;
    if(recentFilePaths.size() <= maxRecentFiles)
        itEnd = recentFilePaths.size();
    else
        itEnd = maxRecentFiles;

    for (auto i = 0u; i < itEnd; ++i)
    {
        QString strippedName = QFileInfo(recentFilePaths.at(i)).fileName();
        recentFileActionList.at(i)->setText(strippedName);
        recentFileActionList.at(i)->setData(recentFilePaths.at(i));
        recentFileActionList.at(i)->setVisible(true);
    }

    for (auto i = itEnd; i < maxRecentFiles; ++i)
        recentFileActionList.at(i)->setVisible(false);
}

void MainWindow::updateRecentFileList(QString recentFilePath)
{
    QStringList recentFilePaths = my_settings->value("recentFiles").toStringList();
    recentFilePaths.removeAll(recentFilePath);
    recentFilePaths.prepend(recentFilePath);
    while (recentFilePaths.size() > maxRecentFiles)
        recentFilePaths.removeLast();
    my_settings->setValue("recentFiles", recentFilePaths);

    updateRecentActionList();
}

void MainWindow::menuActionGroup()
{
    QActionGroup* EOLGroup = new QActionGroup(this);
    ui->actionWindows->setActionGroup(EOLGroup);
    ui->actionMac->setActionGroup(EOLGroup);
    ui->actionUnix->setActionGroup(EOLGroup);

    QActionGroup *lexerGroup = new QActionGroup(this);
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
    my_settings->setValue("geomentry",this->saveGeometry());
}

void MainWindow::saveSettings()
{

}

void MainWindow::loadWindowsGeomentry()
{
    this->restoreGeometry(my_settings->value("geomentry").toByteArray());
}

void MainWindow::loadSettings()
{
    ui->actionFile_Explorer->setChecked(my_settings->value("file explorer", true).toBool());
    ui->actionOpened_Files->setChecked(my_settings->value("opened files", true).toBool());
    ui->actionShow_Minimap->setChecked(my_settings->value("minimap", true).toBool());
    ui->actionToolBar->setChecked(my_settings->value("toolbar", false).toBool());
    on_actionOpened_Files_triggered();
    on_actionFile_Explorer_triggered();
    on_actionShow_Minimap_triggered();
    on_actionToolBar_triggered();
}

void MainWindow::loadCodeEditorSettings()
{
    CodeEditor* codeeditor = static_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    QString fontName = my_settings->value("editorfont", codeeditor->defaultFont).toString();
    int fontSize = my_settings->value("editorfontsize", 13).toInt();
    QFont font = QFont(fontName);
    font.setPointSize(fontSize);

    codeeditor->setFont(font);
    codeeditor->setTabWidth(my_settings->value("tabwidth").toInt());
    codeeditor->setAutoIndent(my_settings->value("autoindent").toBool());

    //caret width 4 is block
    if (my_settings->value("caretwidth").toInt() == 4)
    {
        codeeditor->SendScintilla(QsciScintilla::SCI_SETCARETSTYLE,2);
    }
    else
    {
      codeeditor->setCaretWidth(my_settings->value("caretwidth").toInt());
    }

    //match brackets
    if (my_settings->value("matchbracket").toBool())
    {
        codeeditor->setBraceMatching(QsciScintilla::SloppyBraceMatch);
    }
    else
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setBraceMatching(QsciScintilla::NoBraceMatch);
    }

    //show linenumbers
    if (my_settings->value("linenumbers").toBool())
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"0000");
    }
    else
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"");
    }

    //wrap words
    if (my_settings->value("wordwrap").toBool())
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapWord);
    }
    else
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapNone);
    }

    //autocomplete
    if (my_settings->value("autocomplete").toBool())
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setAutoCompletionSource(QsciScintilla::AcsAll);
    }
    else
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setAutoCompletionSource(QsciScintilla::AcsNone);
    }
    setTheme();
    changeColorScheme();
}

void MainWindow::openDirectory(QString fileDir)
{
    filemodel = new QFileSystemModel();
    filemodel->setRootPath(fileDir);
    ui->treeView->setModel(filemodel);
    ui->treeView->setRootIndex(filemodel->index(fileDir));

    //it hides the other columns in treeview
    ui->treeView->setColumnHidden(1, 1);
    ui->treeView->setColumnHidden(2, 1);
    ui->treeView->setColumnHidden(3, 1);

//    ui->label->show();
    ui->treeView->show();
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
            out << static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->text();
        }
    }
    revertBackTabName();
}

void MainWindow::saveFileAs(QString fileName)
{
    QString saveFileName = "Save File - " + fileName;
    QString filepath = QFileDialog::getSaveFileName(this,saveFileName,QDir::homePath());
    if (filepath.isEmpty()) return;
    QFile file(filepath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->text();
    }
    QString filename = filepath.section("/",-1,-1);
    int tabindex = ui->tabWidget->currentIndex();
    ui->tabWidget->setCurrentIndex(tabindex);
    ui->tabWidget->setTabWhatsThis(tabindex,filepath);
    ui->tabWidget->setTabText(tabindex,filename);
    ui->listWidget->takeItem(tabindex);
    ui->listWidget->insertItem(tabindex,filename);
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setFileName(filename);
}

void MainWindow::closeFile()
{
    closeFile(ui->tabWidget->currentIndex());
}

bool MainWindow::closeFile(int index)
{
    ui->findWidget->hide();
    ui->tabWidget->setCurrentIndex(index);
    if(static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->getTextChanges())
    {
            QMessageBox::StandardButton ask = QMessageBox::question(this,tr(""),tr("Save changes before close"),
                                                      QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel,
                                                      QMessageBox::Cancel);

            if (ask == QMessageBox::Yes)
            {
                if (ui->tabWidget->tabWhatsThis(index) == "")
                {
                    saveFileAs(ui->tabWidget->tabText(ui->tabWidget->currentIndex()));
//                    delete ui->tabWidget->widget(index);
                    ui->listWidget->takeItem(index);
                    ui->tabWidget->removeTab(index);
                }
                else
                {
                    QString filepath = ui->tabWidget->tabWhatsThis(index);
                    saveFile(filepath);
//                    delete ui->tabWidget->widget(index);
                    ui->listWidget->takeItem(index);
                    ui->tabWidget->removeTab(index);
                }
                return true;
            }

            else if (ask == QMessageBox::No)
            {
//                delete ui->tabWidget->widget(index);
                ui->listWidget->takeItem(index);
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
//        delete ui->tabWidget->widget(index);
        ui->listWidget->takeItem(index);
        ui->tabWidget->removeTab(index);
        return true;
    }
    return true;
}

void MainWindow::setLineNumberAndColInStatusBar(int line, int index)
{
    linenumber_label->setText("Col: " + QString::number(index + 1) + ", Line: " + QString::number(line + 1));

    if (line > 100)
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"00000");
    }
    else if (line > 1000)
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"000000");
    }
    else if (line > 10000)
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"0000000");
    }

    minimap->setFocusPolicy(Qt::NoFocus);
    if (minimap->hasFocus())
        minimap->clearFocus();
}

void MainWindow::setDefaultLocationForFileExplorer()
{
    filemodel = new QFileSystemModel();
    filemodel->setRootPath(QDir::homePath());
    ui->treeView->setModel(filemodel);
    ui->treeView->setRootIndex(filemodel->index(QDir::homePath()));

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
    extension = extension.toLower();
    if (extension == "txt")
    {
        ui->actionNormal->setChecked(true);
        on_actionNormal_triggered();
        filetype_label->setText("Normal");
    }
    else if (extension == "sh")
    {
        ui->actionBash->setChecked(true);
        on_actionBash_triggered();
        filetype_label->setText("Bash File");
    }
    else if (extension == "bat")
    {
        ui->actionBatch_File->setChecked(true);
        on_actionBatch_File_triggered();
        filetype_label->setText("Batch File");
    }
    else if ((extension == "c") or (extension == "cpp") or (extension == "h") or (extension == "cxx")
             or (extension == "hpp") or (extension == "hxx" ))
    {
        ui->actionC->setChecked(true);
        on_actionCpp_triggered();
        filetype_label->setText("C++");
    }
    else if (extension == "cs" )
    {
        ui->actionCSharp->setChecked(true);
        on_actionCSharp_triggered();
        filetype_label->setText("CSharp");
    }
    else if (extension == "css")
    {
        ui->actionCSS->setChecked(true);
        on_actionCSS_triggered();
        filetype_label->setText("CSS");
    }
    else if (extension == "d")
    {
        ui->actionD->setChecked(true);
        on_actionD_triggered();
        filetype_label->setText("D");
    }
    else if (extension == "f")
    {
        on_actionFortan_triggered();
        filetype_label->setText("Fortan");
    }
    else if (extension == "html")
    {
        ui->actionHTML->setChecked(true);
        on_actionHTML_triggered();
        filetype_label->setText("HTML");
    }
    else if (extension == "java")
    {
        ui->actionJava->setChecked(true);
        on_actionJava_triggered();
        filetype_label->setText("Java");
    }
    else if (extension == "js")
    {
        ui->actionJavaScript->setChecked(true);
        on_actionJavaScript_triggered();
        filetype_label->setText("Javascript");
    }
    else if (extension == "json")
    {
        ui->actionJSON->setChecked(true);
        on_actionJSON_triggered();
        filetype_label->setText("JSON");
    }
    else if (extension == "lua")
    {
        on_actionLua_triggered();
        filetype_label->setText("Lua");
    }
    else if (extension == "md")
    {
        ui->actionMarkDown->setChecked(true);
        on_actionMarkDown_triggered();
        filetype_label->setText("Markdown");
    }
    else if (extension == "mlx")
    {
        ui->actionMatLab->setChecked(true);
        on_actionMatLab_triggered();
        filetype_label->setText("Matlab");
    }
    else if (extension == "pas")
    {
        on_actionPascal_triggered();
        filetype_label->setText("Pascal");
    }
    else if (extension == "pl")
    {
        ui->actionPerl->setChecked(true);
        on_actionPerl_triggered();
        filetype_label->setText("Perl");
    }
    else if (extension == "py")
    {
        ui->actionPython->setChecked(true);
        on_actionPython_triggered();
        filetype_label->setText("Python");
    }
    else if (extension == "rb")
    {
        ui->actionRuby->setChecked(true);
        on_actionRuby_triggered();
        filetype_label->setText("Ruby");
    }
    else if (extension == "sql" or extension == "sqlite")
    {
        ui->actionSQL->setChecked(true);
        on_actionSQL_triggered();
        filetype_label->setText("SQL");
    }
    else if (extension == "yaml")
    {
        ui->actionYAML->setChecked(true);
        on_actionYAML_triggered();
        filetype_label->setText("YAML");
    }
    else if (extension == "xml")
    {
        ui->actionXML->setChecked(true);
        on_actionXML_triggered();
        filetype_label->setText("XML");
    }
    else
    {
        ui->actionNormal->setChecked(true);
        on_actionNormal_triggered();
        filetype_label->setText("Normal");
    }
}

void MainWindow::changeTabNameIfFileChanges()
{
    if (ui->tabWidget->tabText(ui->tabWidget->currentIndex()).contains("- *"))
    {
        QString tabtext = ui->tabWidget->tabText(ui->tabWidget->currentIndex()).remove("- *");
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),tabtext);
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setTextChanges(false);
    }
}

void MainWindow::highlighsearchtext(QString searchText)
{
    search_string = searchText;
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_INDICSETSTYLE,0,7);
    searchtext_position_list.clear();
    QString document = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->text();
    int end = document.lastIndexOf(searchText);

    if (!searchText.isEmpty())
    {
        int curpos = -1;
        if (end != -1)
        {
            while (curpos != end)
            {
                curpos = document.indexOf(searchText, curpos + 1);
                static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_INDICATORFILLRANGE, curpos, searchText.length());
                searchtext_position_list.append(curpos);
            }
        }
    }
}

void MainWindow::setColorScheme(QsciLexer *lexer, QString themeFile)
{
    current_theme_file = themeFile;
    QString setsearchresultcolor;
    StyleSheet *styleSheet = new StyleSheet ();
    QString text = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->text();
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->clear();
    styleSheet->setStyleSheet(lexer, themeFile, static_cast<CodeEditor*>(ui->tabWidget->currentWidget()));
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setText(text);
    loadMiniMap(ui->tabWidget->currentIndex());
}

void MainWindow::revertBackTabName()
{
    if (ui->tabWidget->tabText(ui->tabWidget->currentIndex()).contains("- *"))
    {
        QString tabtext = ui->tabWidget->tabText(ui->tabWidget->currentIndex()).remove("- *");
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),tabtext);
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setTextChanges(false);
    }
}

void MainWindow::changeColorScheme()
{
    QString colorscheme = my_settings->value("colorscheme", "Default").toString();
    QsciLexer *lexer = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->lexer();
    setColorScheme(lexer, colorScheme->value(colorscheme));
}

void MainWindow::loadMiniMap(int index)
{
    if (ui->actionShow_Minimap->isChecked())
    {
        setTextinMinimap();
        minimap->getText()->setLexer(0);
        minimap->getText()->setColor(static_cast<CodeEditor*>(ui->tabWidget->widget(index))->color());
        minimap->getText()->setPaper(static_cast<CodeEditor*>(ui->tabWidget->widget(index))->paper());
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    int i = 0;
    while (true)
    {
        i = ui->tabWidget->count() - 1;
        if (!closeFile(i) || i == 0)
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

void MainWindow::keyPressEvent(QKeyEvent *event)
{

}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
}

void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{
     event->accept();
}

void MainWindow::dropEvent(QDropEvent *event)
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

void MainWindow::openFile(QString filepath)
{
    CodeEditor *texteditor = new CodeEditor(this);
    QString line;

    if (filepath.isNull())
    {
        filepath = QFileDialog::getOpenFileName(this,tr("Open file"),QDir::homePath());
    }

    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        if (ui->tabWidget->tabWhatsThis(i) == filepath)
        {
            ui->tabWidget->setCurrentIndex(i);
            return;
        }
    }

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
    QString filename = filepath.section("/",-1,-1);
    int tabindex = ui->tabWidget->addTab(texteditor,filename);
    ui->tabWidget->setCurrentIndex(tabindex);
    ui->tabWidget->setTabWhatsThis(tabindex,filepath);
    addtoOpenedFiles(filename);
    setFiletype(filename);
    static_cast<CodeEditor*>(ui->tabWidget->widget(tabindex))->setFileName(filename);
    static_cast<CodeEditor*>(ui->tabWidget->widget(tabindex))->setTextChanges(false);
    updateRecentFileList(filepath);
    setColorScheme(texteditor->lexer(), current_theme_file);
    loadCodeEditorSettings();
    on_actionShow_Linenumbers_triggered();
    revertBackTabName();
}

void MainWindow::on_actionNew_triggered()
{
    newTab("untitled");
}

void MainWindow::on_actionOpen_triggered()
{
    openFile();
}

void MainWindow::on_actionOpenDirectory_triggered()
{
    QString filedir = QFileDialog::getExistingDirectory(this,"Open Directory",QDir::homePath());
    openDirectory(filedir);
}

void MainWindow::on_actionSave_triggered()
{
    if (ui->tabWidget->tabWhatsThis(ui->tabWidget->currentIndex()) == "")
    {
        saveFileAs(ui->tabWidget->tabText(ui->tabWidget->currentIndex()));
    }
    else
    {
        QString filepath = ui->tabWidget->tabWhatsThis(ui->tabWidget->currentIndex());
        saveFile(filepath);
    }
}

void MainWindow::on_actionSave_AS_triggered()
{
    saveFileAs(ui->tabWidget->tabText(ui->tabWidget->currentIndex()));
}

void MainWindow::on_actionSave_All_triggered()
{
    int curIndex = ui->tabWidget->currentIndex();
    for (int i =0;i < ui->tabWidget->count();i++)
    {
        bool textchanged = static_cast<CodeEditor*>(ui->tabWidget->widget(i))->getTextChanges();
        if (textchanged)
        {
            if (ui->tabWidget->tabWhatsThis(i) == "")
            {
                saveFileAs(ui->tabWidget->tabText(i));
            }
            else
            {
                QString filepath = ui->tabWidget->tabWhatsThis(i);
                saveFile(filepath);
            }
        }
    }
    ui->tabWidget->setCurrentIndex(curIndex);
}

void MainWindow::on_actionPrint_triggered()
{
    QsciPrinter printer;
    QsciScintilla *codeeditor = static_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    QPrintDialog *dialog = new QPrintDialog(&printer);
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

void MainWindow::print(QPrinter *printer)
{
    QString text = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->text(); // your text is here
    QPainter painter;
    painter.begin(printer);
    QPrintPreviewDialog preview(printer, this);
    QRect rect = printer->pageRect();
    painter.drawText(rect, Qt::AlignLeft | Qt::AlignTop, text);
    painter.end();
}

void MainWindow::openRecent()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
        openFile(action->data().toString());
}

void MainWindow::clearRecent()
{
    my_settings->remove("recentFiles");
}

void MainWindow::on_actionNew_Window_triggered()
{
    MainWindow *newwindow = new MainWindow();
    newwindow->show();
    newwindow->on_actionNew_triggered();
}

void MainWindow::on_actionClose_Window_triggered()
{
    int tabcount = ui->tabWidget->count();
    for (int i = 0;i <  tabcount;i++ )
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
}

void MainWindow::on_actionClose_All_Files_triggered()
{
    int i = 0;
    while (true)
    {
        i = ui->tabWidget->count() - 1;
        if (!closeFile(i) || i == 0)
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
    int i = 0;
    while (true)
    {
        i = ui->tabWidget->count() - 1;
        if (!closeFile(i) || i == 0)
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
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->redo();
}

void MainWindow::on_actionCut_triggered()
{
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->paste();
}

void MainWindow::on_actionSelect_All_triggered()
{
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->selectAll();
}

void MainWindow::on_actionDeselect_triggered()
{
    int curPos = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_SETCURRENTPOS);
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->selectAll(false);
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_SETCURRENTPOS,curPos);
}

//not working
void MainWindow::on_actionAdd_Indent_triggered()
{

    int pos =  static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(
                QsciScintilla::SCI_GETCURRENTPOS);
    int line = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(
                QsciScintilla::SCI_LINEFROMPOSITION,pos);
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->indent(line);
}

void MainWindow::on_actionDecrease_Indent_triggered()
{
    int pos =  static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(
                QsciScintilla::SCI_GETCURRENTPOS);
    int line = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(
                QsciScintilla::SCI_LINEFROMPOSITION,pos);
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->unindent(line);
}

void MainWindow::on_actionDuplicate_Line_triggered()
{
    int pos = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
    int linepos = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_LINEFROMPOSITION, pos);
    QString text = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->text(linepos);
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->insertAt(text + "\n", linepos, 0);

}

void MainWindow::on_actionUPPER_CASE_triggered()
{
    QString selectedText = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->selectedText();
    if (!selectedText.isEmpty())
    {
        QString uppercase_string = selectedText.toUpper();
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->replaceSelectedText(uppercase_string);
    }
}

void MainWindow::on_actionlower_case_triggered()
{
    QString selectedText = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->selectedText();
    if (!selectedText.isEmpty())
    {
        QString lowercase_string = selectedText.toLower();
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->replaceSelectedText(lowercase_string);
    }
}

void MainWindow::on_actionFind_triggered()
{
    ui->findWidget->show();
    find->hidereplaceWidget();
}

void MainWindow::on_actionFind_Prev_triggered()
{
    findPrev_clicked(find->getFindString());
}

void MainWindow::on_actionReplace_triggered()
{
    ui->findWidget->show();
    find->showreplaceWidget();
}

void MainWindow::on_actionReplace_All_triggered()
{
    replaceAll_clicked(find->getFindString(),find->getReplaceString());
}

void MainWindow::on_actionGo_to_Line_triggered()
{
    int totalline = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->lines();
    int line = QInputDialog::getInt(this, "Go to Line", "enter the line", 0, 0, totalline);
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setCursorPosition(line, 0);
}

void MainWindow::findButton_clicked(QString searchtext)
{
    bool search = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->findFirst(searchtext,find->getRegexp(),find->getCasesensitive(),find->getWholeword(),0);
    if (!search)
    {
        QMessageBox::warning(this, "Find", "search has ended", QMessageBox::Ok);
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setCursorPosition(0, 0);
        search = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->findFirst(searchtext,find->getRegexp(),find->getCasesensitive(),find->getWholeword(),0);
    }
    highlighsearchtext(searchtext);
}

void MainWindow::findPrev_clicked(QString searchtext)
{
    bool search;
    (static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->findFirst(searchtext,find->getRegexp(),find->getCasesensitive(),find->getWholeword(),0, 0));
    {
        search = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->findNext();
    }
    if (!search)
    {
        QMessageBox::warning(this, "find", "search has ended", QMessageBox::Ok);
    }
    highlighsearchtext(searchtext);
}

void MainWindow::replace_clicked(QString replacetext)
{
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->replaceSelectedText(replacetext);
}

void MainWindow::replaceAll_clicked(QString searchtext, QString replacetext)
{
    QString document = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->text();
    document.replace(searchtext,replacetext);
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setText(document);
}

void MainWindow::closeFindDialog()
{
    ui->findWidget->hide();
    clearSearchHighlight();
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->cancelFind();
}

void MainWindow::clearSearchHighlight()
{
    for (int i = 0;i < searchtext_position_list.count() ; i++)
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_INDICATORCLEARRANGE, searchtext_position_list[i], search_string.length());
    }
    searchtext_position_list.clear();
}

void MainWindow::on_actionOpened_Files_triggered()
{
    my_settings->setValue("file explorer", ui->actionFile_Explorer->isChecked());
    if(ui->actionOpened_Files->isChecked())
    {
        ui->listWidget->show();
//        ui->label_2->show();
    }
    else
    {
        ui->listWidget->hide();
//        ui->label_2->hide();
    }
}

void MainWindow::on_actionFile_Explorer_triggered()
{
    my_settings->setValue("opened files", ui->actionOpened_Files->isChecked());
    if(ui->actionFile_Explorer->isChecked())
    {
        ui->treeView->show();
//        ui->label->show();
        ui->widget->show();
    }
    else
    {
        ui->treeView->hide();
//        ui->label->hide();
        ui->widget->hide();
    }
}

void MainWindow::on_actionTerminal_triggered()
{
    ui->splitter_2->setChildrenCollapsible(true);
    QObject::connect(console, SIGNAL(finished()), this, SLOT(hideTerminalWidget()));
    ui->terminalWidget->show();
    console->startShellProgram();
    console->setFocus();
}

void MainWindow::on_actionMac_triggered()
{
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setEolMode(QsciScintilla::EolMac);
}

void MainWindow::on_actionUnix_triggered()
{
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setEolMode(QsciScintilla::EolUnix);
}

void MainWindow::on_actionWindows_triggered()
{
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setEolMode(QsciScintilla::EolWindows);
}

void MainWindow::on_actionWordWrap_triggered()
{
    my_settings->setValue("wordwrap", ui->actionShow_Linenumbers->isChecked());
    if(ui->actionWordWrap->isChecked())
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapWord);
    }
    else
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapNone);
    }
}

void MainWindow::on_actionShow_Linenumbers_triggered()
{
    my_settings->setValue("linenumbers", ui->actionShow_Linenumbers->isChecked());
    if (ui->actionShow_Linenumbers->isChecked())
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"0000");
    }
    else
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"");
    }
}

void MainWindow::on_actionToolBar_triggered()
{
    my_settings->setValue("toolbar", ui->actionToolBar->isChecked());
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
    my_settings->setValue("minimap", ui->actionShow_Minimap->isChecked());
    if (ui->actionShow_Minimap->isChecked())
    {
        ui->minimap->show();
    }
    else
    {
        ui->minimap->hide();
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
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setEolVisibility(true);
    }
    else
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setEolVisibility(false);
    }
}

void MainWindow::on_actionDisplay_White_Space_triggered()
{
    if (ui->actionDisplay_White_Space->isChecked())
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setWhitespaceVisibility(QsciScintilla::WhitespaceVisibility::WsVisible);
    }
    else
    {
        static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setEolVisibility(QsciScintilla::WhitespaceVisibility::WsInvisible);
    }
}

void MainWindow::on_actionNormal_triggered()
{
    filetype_label->setText("Normal");
    setLexer("Normal");
}

void MainWindow::on_actionBash_triggered()
{
    filetype_label->setText("Bash");
    setLexer("Bash");
}

void MainWindow::on_actionBatch_File_triggered()
{
    filetype_label->setText("Batch");
    this->setLexer("Bash");
}

void MainWindow::on_actionC_triggered()
{
    filetype_label->setText("C");
    setLexer("C++");
}

void MainWindow::on_actionCSharp_triggered()
{
    filetype_label->setText("CSharp");
    setLexer("C#");
}

void MainWindow::on_actionCpp_triggered()
{
    filetype_label->setText("Cpp");
    setLexer("C++");
}

void MainWindow::on_actionCSS_triggered()
{
    filetype_label->setText("CSS");
    setLexer("CSS");
}

void MainWindow::on_actionCMake_triggered()
{
    filetype_label->setText("CMake");
    setLexer("CMake");
}

void MainWindow::on_actionCoffeeScript_triggered()
{
    filetype_label->setText("CoffeeScript");
    setLexer("CoffeeScript");
}

void MainWindow::on_actionD_triggered()
{
    filetype_label->setText("D");
    setLexer("D");
}

void MainWindow::on_actionDiff_triggered()
{
    filetype_label->setText("Diff");
    setLexer("Diff");
}

void MainWindow::on_actionFortan_triggered()
{
    filetype_label->setText("Fortran");
    setLexer("Fortran");
}

void MainWindow::on_actionFortan77_triggered()
{
    filetype_label->setText("Fortran77");
    setLexer("Fortran77");
}

void MainWindow::on_actionHTML_triggered()
{
    filetype_label->setText("HTML");
    setLexer("HTML");
}

void MainWindow::on_actionJava_triggered()
{
    filetype_label->setText("Java");
    setLexer("Java");
}

void MainWindow::on_actionJavaScript_triggered()
{
    filetype_label->setText("JavaScript");
    setLexer("JavaScript");
}

void MainWindow::on_actionJSON_triggered()
{
    filetype_label->setText("JSON");
    setLexer("JSON");
}

void MainWindow::on_actionLua_triggered()
{
    filetype_label->setText("Lua");
    setLexer("Lua");
}

void MainWindow::on_actionMarkDown_triggered()
{
    filetype_label->setText("MarkDown");
    setLexer("Markdown");
}

void MainWindow::on_actionMakeFile_triggered()
{
    filetype_label->setText("MakeFile");
    setLexer("Makefile");
}

void MainWindow::on_actionMatLab_triggered()
{
    filetype_label->setText("MatLab");
    setLexer("Matlab");
}

void MainWindow::on_actionPascal_triggered()
{
    filetype_label->setText("Pascal");
    setLexer("Pascal");
}

void MainWindow::on_actionPython_triggered()
{
    filetype_label->setText("Python");
    setLexer("Python");
}

void MainWindow::on_actionPerl_triggered()
{
    filetype_label->setText("Perl");
    setLexer("Perl");
}

void MainWindow::on_actionProperties_triggered()
{
    filetype_label->setText("Properties");
    setLexer("Properties");
}

void MainWindow::on_actionRuby_triggered()
{
    filetype_label->setText("Ruby");
    setLexer("Ruby");
}

void MainWindow::on_actionSQL_triggered()
{
    filetype_label->setText("SQL");
    setLexer("SQL");
}

void MainWindow::on_actionTeX_triggered()
{
    filetype_label->setText("TeX");
    setLexer("TeX");
}

void MainWindow::on_actionXML_triggered()
{
    filetype_label->setText("XML");
    setLexer("XML");
}

void MainWindow::on_actionYAML_triggered()
{
    filetype_label->setText("YAML");
    setLexer("YAML");
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,tr("About code editor"),tr(" "));
}

void MainWindow::on_actionAbout_QT_triggered()
{
    QMessageBox::aboutQt(this,"About Qt");
}

void MainWindow::on_actionSettings_triggered()
{
    settings_dialog = new Settings ();
    settings_dialog->exec();
    loadCodeEditorSettings();
}

void MainWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
    QString filepath = filemodel->filePath(index);
    QFileInfo fileinfo(filepath);
    if (fileinfo.isDir())
    {
        openDirectory(filepath);
    }
    openFile(filepath);
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    int index = ui->listWidget->row(item);
    ui->tabWidget->setCurrentIndex(index);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (ui->tabWidget->count() <= 0)
        return;

    connect(static_cast<CodeEditor*>(ui->tabWidget->widget(index)), &QsciScintilla::cursorPositionChanged, this, &MainWindow::statusBar);
    connect(static_cast<CodeEditor*>(ui->tabWidget->widget(index)),&QsciScintilla::textChanged, this, &MainWindow::changeTabNameIfFileChanges);
    connect(static_cast<CodeEditor*>(ui->tabWidget->widget(index)), &QsciScintilla::cursorPositionChanged, this, &MainWindow::setLineNumberAndColInStatusBar);
    connect(static_cast<CodeEditor*>(ui->tabWidget->widget(index)), SIGNAL(dropFiles(QString)), this, SLOT(openFile(QString)));
    connect(static_cast<CodeEditor*>(ui->tabWidget->widget(index))->verticalScrollBar(), &QScrollBar::valueChanged , this, &MainWindow::scrollMiniMap);
    setFiletype(static_cast<CodeEditor*>(ui->tabWidget->widget(index))->getFileName());
    on_actionShow_Linenumbers_triggered(); // to show linenumber if it is checked
    setEOL();

    loadMiniMap(index);
    changeColorScheme();
//    loadCodeEditorSettings();
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    closeFile(index);
}

void MainWindow::setLexer(QString lexername)
{
    QMap <QString,QsciLexer*> languageToLexer = {
        {"Normal", nullptr},
        {"Bash", new QsciLexerBash()},
        {"Batch", new QsciLexerBatch()},
        {"CMake", new QsciLexerCMake()},
        {"CoffeeScript", new QsciLexerCoffeeScript()},
        {"C++", new QsciLexerCPP()},
        {"C#", new QsciLexerCSharp()},
        {"CSS", new QsciLexerCSS()},
        {"D", new QsciLexerD()},
        {"Diff", new QsciLexerDiff()},
        {"Fortran", new QsciLexerFortran()},
        {"Fortran77", new QsciLexerFortran77()},
        {"HTML", new QsciLexerHTML()},
        {"Java", new QsciLexerJava()},
        {"JavaScript", new QsciLexerJavaScript()},
        {"JSON", new QsciLexerJSON()},
        {"Lua", new QsciLexerLua()},
        {"Makefile", new QsciLexerMakefile()},
        {"Markdown", new QsciLexerMarkdown()},
        {"Matlab", new QsciLexerMatlab()},
        {"Pascal", new QsciLexerPascal()},
        {"Perl", new QsciLexerPerl()},
        {"Properties",new QsciLexerProperties()},
        {"Python", new QsciLexerPython()},
        {"Ruby", new QsciLexerRuby()},
        {"SQL", new QsciLexerSQL()},
        {"TeX", new QsciLexerTeX()},
        {"YAML", new QsciLexerYAML()},
        {"XML", new QsciLexerXML()}
    };


    QMap<QString, QsciLexer*>::iterator i = languageToLexer.find(lexername);
    QsciLexer *lexer = nullptr;
    if (i != languageToLexer.end())
    {
        lexer = i.value();
        if (lexer != nullptr)
        {
            lexer->setDefaultFont(QFont(static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->defaultFont));
            lexer->setAutoIndentStyle(true);
            static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setFolding(QsciScintilla::FoldStyle::BoxedTreeFoldStyle);
//            static_cast<codeEditor*>(ui->tabWidget->currentWidget())->zoomIn(3);
        }
        else
        {
            static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setFolding(QsciScintilla::FoldStyle::NoFoldStyle);
        }
    }
    setColorScheme(lexer, current_theme_file);
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setLexer(lexer);
    static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->setFont(static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->defaultFont);
}

void MainWindow::setTextinMinimap()
{
    //    QString text = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->text();
    //    Mmap->getText()->setText(text);
        QsciDocument text = static_cast<CodeEditor*>(ui->tabWidget->currentWidget())->document();
    //    Mmap->getText()->setLexer(nullptr);
    //    Mmap->setcolor();
    //    Mmap->getText()->setLexer(static_cast<codeEditor*>(ui->tabWidget->currentWidget())->lexer());
        minimap->getText()->setDocument(text);
}

void MainWindow::scrollMiniMap(int value)
{
    minimap->getText()->verticalScrollBar()->setValue(value * 0.25);
}

void MainWindow::hideTerminalWidget()
{
    ui->terminalWidget->hide();
}

void MainWindow::on_termClose_clicked()
{
    hideTerminalWidget();
}
