#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->splitter_4->setStretchFactor(1,1);
    ui->splitter->setStretchFactor(1,1);
    ui->splitter_2->setStretchFactor(0, 1);

    ui->treeView->hide();       //fileExplorer
    ui->listWidget->hide();     //openedFiles
    ui->label->hide();          //fileExplorer Title
    ui->label_2->hide();        //openedFiles Title
    ui->findWidget->hide();         //find dialog
    ui->terminalWidget->hide();
    ui->widget->hide();

    defaultLocation();      //sets fileExplorer default location

    //status bar line number widget
    statSpitter = new QSplitter(this);
    lineNumLabel = new QLabel(this);
    fileTypeLabel = new QLabel(this);
    ui->statusBar->addWidget(lineNumLabel);
    ui->statusBar->addWidget(statSpitter);
    ui->statusBar->addWidget(fileTypeLabel);

    //minimap
    Mmap = new minimap ();
    ui->minimap->setLayout(Mmap->layout());

    mySettings = new QSettings ("kumar","SimpleCodeEditor",this);
    themeFiles = new QMap<QString, QString> ();
    themeFiles->insert("Light", ":/style/src/icons/default_classic.xml");
    themeFiles->insert("Dark", ":/style/src/icons/creator-dark.xml");

    menuActionGroup();
    loadWindowsGeomentry();
    loadSettings();
    createRecentAction();
    connect(ui->menuRecent_files, &QMenu::aboutToShow, this, &MainWindow::updateRecentActionList);
    connect(this, &MainWindow::focusOutEvent, this, &MainWindow::lostFocus);

    //find dialog
    find = new findDialog();
    ui->findWidget->setLayout(find->layout());
    connect(find,SIGNAL(closeFindDialog()),this,SLOT(closeFindDialog()));
    connect(find,SIGNAL(findButton_clicked(QString)),this,SLOT(findButton_clicked(QString)));
    connect(find,SIGNAL(findPrev_clicked(QString)),this,SLOT(findPrev_clicked(QString)));
    connect(find,SIGNAL(replace_clicked(QString)),this,SLOT(replace_clicked(QString)));
    connect(find, SIGNAL(replaceAll_clicked(QString, QString)), this, SLOT(replaceAll_clicked(QString, QString)));
    connect(find, SIGNAL(findStringChanged()), this, SLOT(findString_Changed()));

    console = new termwidget (0, this);
    ui->gridLayout_5->addWidget(console);

    on_actionShow_Minimap_triggered();
    isAutoSave = false;
    searchTextposlist.clear();

    ui->mainToolBar->hide();
    ui->menuThemes->hide();
}

MainWindow::~MainWindow()
{
    saveWindowsGeomentry();
    saveSettings();
//    delete find;
//    delete Mmap;
//    delete filemodel;
//    delete settingsDialog;
    delete ui;
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
    QStringList recentFilePaths = mySettings->value("recentFiles").toStringList();

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

void MainWindow::saveSettings()
{
    mySettings->setValue("file explorer", ui->actionFile_Explorer->isChecked());
    mySettings->setValue("opened files", ui->actionOpened_Files->isChecked());
//    mySettings->setValue("Current Theme", curThemeFile);
}

void MainWindow::saveWindowsGeomentry()
{
    mySettings->setValue("geomentry",this->saveGeometry());
}

void MainWindow::loadWindowsGeomentry()
{
    this->restoreGeometry(mySettings->value("geomentry").toByteArray());
}

void MainWindow::loadCodeEditorSettings()
{
    codeEditor* codeeditor = static_cast<codeEditor*>(ui->tabWidget->currentWidget());
    QString fontName = mySettings->value("font", codeeditor->defaultFont).toString();
    int fontSize = mySettings->value("fontSize", 13).toInt();
    QFont font = QFont(fontName);
    font.setPointSize(fontSize);

    codeeditor->setFont(font);
    codeeditor->setTabWidth(mySettings->value("tabWidth").toInt());
    codeeditor->setAutoIndent(mySettings->value("autoIndent").toBool());

    //caret width 4 is block
    if (mySettings->value("caretWidth").toInt() == 4)
    {
        codeeditor->SendScintilla(QsciScintilla::SCI_SETCARETSTYLE,2);
    }
    else
    {
      codeeditor->setCaretWidth(mySettings->value("caretWidth").toInt());
    }

    //match brackets
    if (mySettings->value("matchBracket").toBool())
    {
        codeeditor->setBraceMatching(QsciScintilla::SloppyBraceMatch);
    }
    else
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setBraceMatching(QsciScintilla::NoBraceMatch);
    }

    //show linenumbers
    if (mySettings->value("lineNumbers").toBool())
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"0000");
    }
    else
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"");
    }

    //wrap words
    if (mySettings->value("wordWrap").toBool())
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapWord);
    }
    else
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapNone);
    }

    //autocomplete
    if (mySettings->value("autocomplete").toBool())
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setAutoCompletionSource(QsciScintilla::AcsAll);
    }
    else
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setAutoCompletionSource(QsciScintilla::AcsNone);
    }
}

void MainWindow::loadSettings()
{
    ui->actionFile_Explorer->setChecked(mySettings->value("file explorer").toBool());
    ui->actionOpened_Files->setChecked(mySettings->value("opened files").toBool());
    on_actionOpened_Files_triggered();
    on_actionFile_Explorer_triggered();
    curThemeFile = themeFiles->value(mySettings->value("theme", "Light").toString());
}

//default location of the file explorer
void MainWindow::defaultLocation()
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

void MainWindow::statusBar(int line, int index)
{
    lineNumLabel->setText("Col: " + QString::number(index + 1) + ", Line: " + QString::number(line + 1));
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

int MainWindow::newTab(QString tabname)
{
    codeEditor *texteditor = new codeEditor(this);
    int tabindex = ui->tabWidget->addTab(texteditor,tabname);
    ui->tabWidget->setCurrentIndex(tabindex);
    ui->listWidget->addItem(tabname);
    ui->tabWidget->currentWidget()->setFocus();
    qDebug() << curThemeFile;
    loadCodeEditorSettings();
    setStyleSheet(texteditor->lexer(), curThemeFile);
    return tabindex;
}

//opens directory in file explorer
void MainWindow::openDirectory(QString filedir)
{
    filemodel = new QFileSystemModel();
    filemodel->setRootPath(filedir);
    ui->treeView->setModel(filemodel);
    ui->treeView->setRootIndex(filemodel->index(filedir));

    //it hides the other columns in treeview
    ui->treeView->setColumnHidden(1, 1);
    ui->treeView->setColumnHidden(2, 1);
    ui->treeView->setColumnHidden(3, 1);

    ui->label->show();
    ui->treeView->show();
    ui->actionFile_Explorer->setChecked(true);
}

void MainWindow::openFile(QString filepath)
{
    codeEditor *texteditor = new codeEditor(this);
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
    static_cast<codeEditor*>(ui->tabWidget->widget(tabindex))->setFileName(filename);
    static_cast<codeEditor*>(ui->tabWidget->widget(tabindex))->setTextChanges(false);
    updateRecentFileList(filepath);
    setStyleSheet(texteditor->lexer(), curThemeFile);
    loadCodeEditorSettings();
    changeTabName();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
//    switch (event->key())
//    {
//        case (Qt::Key_Backslash):
//        qDebug() << "bs";
//        if (event->modifiers() & Qt::ControlModifier)
//        {
//            comment *c = new comment (static_cast<codeEditor*>(ui->tabWidget->currentWidget()));
//            c->toggleComment();
//        }
//        break;
//    }
}

void MainWindow::addtoOpenedFiles(QString filename)
{
    ui->listWidget->addItem(filename);
}

void MainWindow::saveFile(QString filepath)
{
    QFileInfo fileinfo(filepath);
    if (fileinfo.exists())
    {
        QFile file(filepath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << static_cast<codeEditor*>(ui->tabWidget->currentWidget())->text();
        }
    }
    changeTabName();
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
        out << static_cast<codeEditor*>(ui->tabWidget->currentWidget())->text();
    }
    QString filename = filepath.section("/",-1,-1);
    int tabindex = ui->tabWidget->currentIndex();
    ui->tabWidget->setCurrentIndex(tabindex);
    ui->tabWidget->setTabWhatsThis(tabindex,filepath);
    ui->tabWidget->setTabText(tabindex,filename);
    ui->listWidget->takeItem(tabindex);
    ui->listWidget->insertItem(tabindex,filename);
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setFileName(filename);
}

void MainWindow::print(QPrinter *printer)
{
    QString text = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->text(); // your text is here
    QPainter painter;
    painter.begin(printer);
    QPrintPreviewDialog preview(printer, this);
    QRect rect = printer->pageRect();
    painter.drawText(rect, Qt::AlignLeft | Qt::AlignTop, text);
    painter.end();
}

void MainWindow::closeFile()
{
    closeFile(ui->tabWidget->currentIndex());
}

void MainWindow::closeFile(int index)
{
    if(static_cast<codeEditor*>(ui->tabWidget->currentWidget())->getTextChanges())
    {
            QMessageBox::StandardButton ask = QMessageBox::question(this,tr(""),tr("Save changes before close"),
                                                      QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel,
                                                      QMessageBox::Cancel);

            if (ask == QMessageBox::Yes)
            {
                if (ui->tabWidget->tabWhatsThis(index) == "")
                {
                    saveFileAs(ui->tabWidget->tabText(ui->tabWidget->currentIndex()));
                    delete ui->tabWidget->widget(index);
                    ui->listWidget->takeItem(index);
                }
                else
                {
                    QString filepath = ui->tabWidget->tabWhatsThis(index);
                    saveFile(filepath);
                    delete ui->tabWidget->widget(index);
                    ui->listWidget->takeItem(index);
                }
            }

            else if (ask == QMessageBox::No)
            {
                delete ui->tabWidget->widget(index);
                ui->listWidget->takeItem(index);
            }

            else if (ask == QMessageBox::Cancel)
            {
                //do nothing
            }
    }
    else
    {
        delete ui->tabWidget->widget(index);
        ui->listWidget->takeItem(index);
    }
    ui->findWidget->hide();
    if(ui->tabWidget->count() == 0)
    {
        newTab("untitled");
    }
}

void MainWindow::lineNumwidthIncrement(int line, int index)
{
    if (line > 100)
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"00000");
    }
    else if (line > 1000)
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"000000");
    }
    else if (line > 10000)
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"0000000");
    }

    Mmap->setFocusPolicy(Qt::NoFocus);
    if (Mmap->hasFocus())
        Mmap->clearFocus();
}

void MainWindow::setFiletype(QString file)
{
    QFileInfo fileinfo(file);
    QString extension = fileinfo.suffix();
    extension = extension.toLower();
    if (extension == "txt")
    {
        ui->actionNormal->setChecked(true);
        on_actionNormal_triggered();
        fileTypeLabel->setText("Normal");
    }
    else if (extension == "sh")
    {
        ui->actionBash->setChecked(true);
        on_actionBash_triggered();
        fileTypeLabel->setText("Bash File");
    }
    else if (extension == "bat")
    {
        ui->actionBatch_File->setChecked(true);
        on_actionBatch_File_triggered();
        fileTypeLabel->setText("Batch File");
    }
    else if ((extension == "c") or (extension == "cpp") or (extension == "h") or (extension == "cxx")
             or (extension == "hpp") or (extension == "hxx" ))
    {
        ui->actionC->setChecked(true);
        on_actionCpp_triggered();
        fileTypeLabel->setText("C++");
    }
    else if (extension == "cs" )
    {
        ui->actionCSharp->setChecked(true);
        on_actionCSharp_triggered();
        fileTypeLabel->setText("CSharp");
    }
    else if (extension == "css")
    {
        ui->actionCSS->setChecked(true);
        on_actionCSS_triggered();
        fileTypeLabel->setText("CSS");
    }
    else if (extension == "d")
    {
        ui->actionD->setChecked(true);
        on_actionD_triggered();
        fileTypeLabel->setText("D");
    }
    else if (extension == "f")
    {
        on_actionFortan_triggered();
        fileTypeLabel->setText("Fortan");
    }
    else if (extension == "html")
    {
        ui->actionHTML->setChecked(true);
        on_actionHTML_triggered();
        fileTypeLabel->setText("HTML");
    }
    else if (extension == "java")
    {
        ui->actionJava->setChecked(true);
        on_actionJava_triggered();
        fileTypeLabel->setText("Java");
    }
    else if (extension == "js")
    {
        ui->actionJavaScript->setChecked(true);
        on_actionJavaScript_triggered();
        fileTypeLabel->setText("Javascript");
    }
    else if (extension == "json")
    {
        ui->actionJSON->setChecked(true);
        on_actionJSON_triggered();
        fileTypeLabel->setText("JSON");
    }
    else if (extension == "lua")
    {
        on_actionLua_triggered();
        fileTypeLabel->setText("Lua");
    }
    else if (extension == "md")
    {
        ui->actionMarkDown->setChecked(true);
        on_actionMarkDown_triggered();
        fileTypeLabel->setText("Markdown");
    }
    else if (extension == "mlx")
    {
        ui->actionMatLab->setChecked(true);
        on_actionMatLab_triggered();
        fileTypeLabel->setText("Matlab");
    }
    else if (extension == "pas")
    {
        on_actionPascal_triggered();
        fileTypeLabel->setText("Pascal");
    }
    else if (extension == "pl")
    {
        ui->actionPerl->setChecked(true);
        on_actionPerl_triggered();
        fileTypeLabel->setText("Perl");
    }
    else if (extension == "py")
    {
        ui->actionPython->setChecked(true);
        on_actionPython_triggered();
        fileTypeLabel->setText("Python");
    }
    else if (extension == "rb")
    {
        ui->actionRuby->setChecked(true);
        on_actionRuby_triggered();
        fileTypeLabel->setText("Ruby");
    }
    else if (extension == "sql" or extension == "sqlite")
    {
        ui->actionSQL->setChecked(true);
        on_actionSQL_triggered();
        fileTypeLabel->setText("SQL");
    }
    else if (extension == "yaml")
    {
        ui->actionYAML->setChecked(true);
        on_actionYAML_triggered();
        fileTypeLabel->setText("YAML");
    }
    else if (extension == "xml")
    {
        ui->actionXML->setChecked(true);
        on_actionXML_triggered();
        fileTypeLabel->setText("XML");
    }
    else
    {
        ui->actionNormal->setChecked(true);
        on_actionNormal_triggered();
        fileTypeLabel->setText("Normal");
    }    
}

void MainWindow::setFileTypeInStatusBar(QString strFileName)
{
    QFileInfo fileinfo(strFileName);
    QString extension = fileinfo.suffix();
    extension = extension.toLower();
    if (extension == "txt")
    {
        ui->actionNormal->setChecked(true);
        fileTypeLabel->setText("Normal");
    }
    else if (extension == "sh")
    {
        ui->actionBash->setChecked(true);
        fileTypeLabel->setText("Bash File");
    }
    else if (extension == "bat")
    {
        ui->actionBatch_File->setChecked(true);
        fileTypeLabel->setText("Batch File");
    }
    else if ((extension == "c") or (extension == "cpp") or (extension == "h") or (extension == "cxx")
             or (extension == "hpp") or (extension == "hxx" ))
    {
        ui->actionC->setChecked(true);
        fileTypeLabel->setText("C++");
    }
    else if (extension == "cs" )
    {
        ui->actionCSharp->setChecked(true);
        fileTypeLabel->setText("CSharp");
    }
    else if (extension == "css")
    {
        ui->actionCSS->setChecked(true);
        fileTypeLabel->setText("CSS");
    }
    else if (extension == "d")
    {
        ui->actionD->setChecked(true);
        fileTypeLabel->setText("D");
    }
    else if (extension == "f")
    {
        fileTypeLabel->setText("Fortan");
    }
    else if (extension == "html")
    {
        ui->actionHTML->setChecked(true);
        fileTypeLabel->setText("HTML");
    }
    else if (extension == "java")
    {
        ui->actionJava->setChecked(true);
        fileTypeLabel->setText("Java");
    }
    else if (extension == "js")
    {
        ui->actionJavaScript->setChecked(true);
        fileTypeLabel->setText("Javascript");
    }
    else if (extension == "json")
    {
        ui->actionJSON->setChecked(true);
        fileTypeLabel->setText("JSON");
    }
    else if (extension == "lua")
    {
        fileTypeLabel->setText("Lua");
    }
    else if (extension == "md")
    {
        ui->actionMarkDown->setChecked(true);
        fileTypeLabel->setText("Markdown");
    }
    else if (extension == "mlx")
    {
        ui->actionMatLab->setChecked(true);
        fileTypeLabel->setText("Matlab");
    }
    else if (extension == "pas")
    {
        fileTypeLabel->setText("Pascal");
    }
    else if (extension == "pl")
    {
        ui->actionPerl->setChecked(true);
        fileTypeLabel->setText("Perl");
    }
    else if (extension == "py")
    {
        ui->actionPython->setChecked(true);
        fileTypeLabel->setText("Python");
    }
    else if (extension == "rb")
    {
        ui->actionRuby->setChecked(true);
        on_actionRuby_triggered();
        fileTypeLabel->setText("Ruby");
    }
    else if (extension == "sql" or extension == "sqlite")
    {
        ui->actionSQL->setChecked(true);
        fileTypeLabel->setText("SQL");
    }
    else if (extension == "yaml")
    {
        ui->actionYAML->setChecked(true);
        fileTypeLabel->setText("YAML");
    }
    else if (extension == "xml")
    {
        ui->actionXML->setChecked(true);
        fileTypeLabel->setText("XML");
    }
    else
    {
        ui->actionNormal->setChecked(true);
        fileTypeLabel->setText("Normal");
    }
}

void MainWindow::changeTabName()
{
    if (ui->tabWidget->tabText(ui->tabWidget->currentIndex()).contains("- *"))
    {
        QString tabtext = ui->tabWidget->tabText(ui->tabWidget->currentIndex()).remove("- *");
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),tabtext);
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setTextChanges(false);
    }
}

void MainWindow::changeTabNameIfFileChanges()
{
    QString tabName = ui->tabWidget->tabText(ui->tabWidget->currentIndex());
    if (!tabName.contains("- *"))
    {
        tabName = ui->tabWidget->tabText(ui->tabWidget->currentIndex()) + "- *";
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),tabName);
    }
}

void MainWindow::on_actionNew_triggered()
{
    newTab("untitled");
    on_actionShow_Linenumbers_triggered(); // to show linenumber if it is checked
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
        bool textchanged = static_cast<codeEditor*>(ui->tabWidget->widget(i))->getTextChanges();
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
    QsciScintilla *codeeditor = static_cast<codeEditor*>(ui->tabWidget->currentWidget());
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

void MainWindow::on_actionClose_triggered()
{
    closeFile(ui->tabWidget->currentIndex());
}

void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    closeFile(index);
}

void MainWindow::on_actionClose_All_Files_triggered()
{
    int tabcount = ui->tabWidget->count();
    for (int i = 0;i < tabcount; i++)
    {
        closeFile(i);
    }
}

void MainWindow::on_actionNew_Window_triggered()
{
    MainWindow *newwindow = new MainWindow();
    newwindow->show();
    newwindow->on_actionNew_triggered();
}

void MainWindow::on_actionClose_Window_triggered()
{
    this->close();
}

void MainWindow::on_actionExit_triggered()
{
    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        if (static_cast<codeEditor*>(ui->tabWidget->widget(i))->getTextChanges())
        {
            QMessageBox::StandardButton ask = QMessageBox::question(this,tr("Save changes before close"),tr("Save changes before close ") + ui->tabWidget->tabText(i), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::Cancel);
            if (ask == QMessageBox::No)
            {
                continue;
            }
            else if (ask == QMessageBox::Cancel)
            {
                break;
            }
            else if (ask == QMessageBox::Yes)
            {
                if (ui->tabWidget->tabWhatsThis(i) != "")
                {
                    saveFile(ui->tabWidget->tabWhatsThis(i));
                }
            }
        }
    }
    qApp->exit();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    on_actionExit_triggered();
}

void MainWindow::on_actionUndo_triggered()
{
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->redo();
}

void MainWindow::on_actionCut_triggered()
{
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->paste();
}

void MainWindow::on_actionSelect_All_triggered()
{
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->selectAll();
}

void MainWindow::on_actionDeselect_triggered()
{
    int curPos = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_SETCURRENTPOS);
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->selectAll(false);
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_SETCURRENTPOS,curPos);
}

//Find and Replace function
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

void MainWindow::findButton_clicked(QString searchtext)
{
//    int curPos = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_SETCURRENTPOS,curPos);
    bool search = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->findFirst(searchtext,find->getRegexp(),find->getCasesensitive(),find->getWholeword(),0);
    if (!search)
    {
        QMessageBox::warning(this, "Find", "search has ended", QMessageBox::Ok);
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setCursorPosition(0, 0);
        search = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->findFirst(searchtext,find->getRegexp(),find->getCasesensitive(),find->getWholeword(),0);
    }
    highlighsearchtext(searchtext);
}

void MainWindow::findPrev_clicked(QString searchtext)
{
    bool search;
    (static_cast<codeEditor*>(ui->tabWidget->currentWidget())->findFirst(searchtext,find->getRegexp(),find->getCasesensitive(),find->getWholeword(),0, 0));
    {
        search = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->findNext();
    }
    if (!search)
    {
        QMessageBox::warning(this, "find", "search has ended", QMessageBox::Ok);
    }
    highlighsearchtext(searchtext);
}

void MainWindow::replace_clicked(QString replacetext)
{
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->replaceSelectedText(replacetext);
}

void MainWindow::replaceAll_clicked(QString searchtext, QString replacetext)
{
    QString document = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->text();
    document.replace(searchtext,replacetext);
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setText(document);
//    if(!replacetext.isEmpty())
//    {
//        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_INDICSETSTYLE,0,7);
//        int end = document.lastIndexOf(replacetext);
//        int cur = -1;
//        if (end != -1)
//        {
//            while (cur != end)
//            {
//                cur = document.indexOf(replacetext,cur+1);
//            }
//        }
//    }
}

void MainWindow::closeFindDialog()
{
    ui->findWidget->hide();
    findString_Changed();
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->cancelFind();
}

void MainWindow::on_actionOpened_Files_triggered()
{
    if(ui->actionOpened_Files->isChecked())
    {
        ui->listWidget->show();
        ui->label_2->show();
    }
    else
    {
        ui->listWidget->hide();
        ui->label_2->hide();
    }
}

void MainWindow::on_actionFile_Explorer_triggered()
{
    if(ui->actionFile_Explorer->isChecked())
    {
        ui->treeView->show();
        ui->label->show();
        ui->widget->show();
    }
    else
    {
        ui->treeView->hide();
        ui->label->hide();
        ui->widget->hide();
    }
}

void MainWindow::on_actionMac_triggered()
{
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setEolMode(QsciScintilla::EolMac);
}

void MainWindow::on_actionUnix_triggered()
{
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setEolMode(QsciScintilla::EolUnix);
}

void MainWindow::on_actionWindows_triggered()
{
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setEolMode(QsciScintilla::EolWindows);
}

void MainWindow::on_actionShow_Linenumbers_triggered()
{
    if (ui->actionShow_Linenumbers->isChecked())
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"0000");
    }
    else
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"");
    }
}

void MainWindow::on_actionStatusBar_triggered()
{
    if (ui->actionStatusBar->isChecked())
    {
        ui->statusBar->show();
    }
    else
    {
        ui->statusBar->hide();
    }
}

void MainWindow::on_actionToolBar_triggered()
{
    if (ui->actionToolBar->isChecked())
    {
        ui->mainToolBar->show();
    }
    else
    {
        ui->mainToolBar->hide();
    }
}

//lexers
void MainWindow::on_actionNormal_triggered()
{
    fileTypeLabel->setText("Normal");
    setLexer("Normal");
}

void MainWindow::on_actionBash_triggered()
{
    fileTypeLabel->setText("Bash");
    setLexer("Bash");
}

void MainWindow::on_actionBatch_File_triggered()
{
    fileTypeLabel->setText("Batch");
    this->setLexer("Bash");
}

void MainWindow::on_actionC_triggered()
{
    fileTypeLabel->setText("C");
    setLexer("C++");
}

void MainWindow::on_actionCSharp_triggered()
{
    fileTypeLabel->setText("CSharp");
    setLexer("C#");
}

void MainWindow::on_actionCpp_triggered()
{
    fileTypeLabel->setText("Cpp");
    setLexer("C++");
}

void MainWindow::on_actionCSS_triggered()
{
    fileTypeLabel->setText("CSS");
    setLexer("CSS");
}

void MainWindow::on_actionCMake_triggered()
{
    fileTypeLabel->setText("CMake");
    setLexer("CMake");
}

void MainWindow::on_actionCoffeeScript_triggered()
{
    fileTypeLabel->setText("CoffeeScript");
    setLexer("CoffeeScript");
}

void MainWindow::on_actionD_triggered()
{
    fileTypeLabel->setText("D");
    setLexer("D");
}

void MainWindow::on_actionDiff_triggered()
{
    fileTypeLabel->setText("Diff");
    setLexer("Diff");
}

void MainWindow::on_actionFortan_triggered()
{
    fileTypeLabel->setText("Fortran");
    setLexer("Fortran");
}

void MainWindow::on_actionFortan77_triggered()
{
    fileTypeLabel->setText("Fortran77");
    setLexer("Fortran77");
}

void MainWindow::on_actionHTML_triggered()
{
    fileTypeLabel->setText("HTML");
    setLexer("HTML");
}

void MainWindow::on_actionJava_triggered()
{
    fileTypeLabel->setText("Java");
    setLexer("Java");
}

void MainWindow::on_actionJavaScript_triggered()
{
    fileTypeLabel->setText("JavaScript");
    setLexer("JavaScript");
}

void MainWindow::on_actionJSON_triggered()
{
    fileTypeLabel->setText("JSON");
    setLexer("JSON");
}

void MainWindow::on_actionLua_triggered()
{
    fileTypeLabel->setText("Lua");
    setLexer("Lua");
}

void MainWindow::on_actionMarkDown_triggered()
{
    fileTypeLabel->setText("MarkDown");
    setLexer("Markdown");
}

void MainWindow::on_actionMakeFile_triggered()
{
    fileTypeLabel->setText("MakeFile");
    setLexer("Makefile");
}

void MainWindow::on_actionMatLab_triggered()
{
    fileTypeLabel->setText("MatLab");
    setLexer("Matlab");
}

void MainWindow::on_actionPascal_triggered()
{
    fileTypeLabel->setText("Pascal");
    setLexer("Pascal");
}

void MainWindow::on_actionPython_triggered()
{
    fileTypeLabel->setText("Python");
    setLexer("Python");
}

void MainWindow::on_actionPerl_triggered()
{
    fileTypeLabel->setText("Perl");
    setLexer("Perl");
}

void MainWindow::on_actionProperties_triggered()
{
    fileTypeLabel->setText("Properties");
    setLexer("Properties");
}

void MainWindow::on_actionRuby_triggered()
{
    fileTypeLabel->setText("Ruby");
    setLexer("Ruby");
}

void MainWindow::on_actionSQL_triggered()
{
    fileTypeLabel->setText("SQL");
    setLexer("SQL");
}

void MainWindow::on_actionTeX_triggered()
{
    fileTypeLabel->setText("TeX");
    setLexer("TeX");
}

void MainWindow::on_actionXML_triggered()
{
    fileTypeLabel->setText("XML");
    setLexer("XML");
}

void MainWindow::on_actionYAML_triggered()
{
    fileTypeLabel->setText("YAML");
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

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (ui->tabWidget->count() <= 0)
        return;

    connect(static_cast<codeEditor*>(ui->tabWidget->widget(index)), &QsciScintilla::cursorPositionChanged, this, &MainWindow::statusBar);
    connect(static_cast<codeEditor*>(ui->tabWidget->widget(index)),&QsciScintilla::textChanged, this, &MainWindow::changeTabNameIfFileChanges);
    connect(static_cast<codeEditor*>(ui->tabWidget->widget(index)), &QsciScintilla::cursorPositionChanged, this, &MainWindow::lineNumwidthIncrement);
    connect(static_cast<codeEditor*>(ui->tabWidget->widget(index)), SIGNAL(dropFiles(QString)), this, SLOT(openFile(QString)));
    setFileTypeInStatusBar(static_cast<codeEditor*>(ui->tabWidget->widget(index))->getFileName());

    if (showMinimap)
    {
        setTextinMinimap();
    }
////    loadCodeEditorSettings();
////    setEOL();
//    on_actionShow_Linenumbers_triggered(); // to show linenumber if it is checked
//    on_actionToolBar_triggered();
//    QsciLexer *lexer = static_cast<codeEditor*>(ui->tabWidget->widget(index))->lexer();
//    setStyleSheet(lexer, curThemeFile);
//    for (int i = 0; i < ui->tabWidget->count(); ++i)
//    {
//        if (i == index) break;
//        if (static_cast<codeEditor*>(ui->tabWidget->currentWidget())->getTextChanges())
//        {
//            if (ui->tabWidget->tabWhatsThis(i) != "")
//            {
//                saveFile(ui->tabWidget->tabWhatsThis(i));
//            }
//        }
//    }

}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    int index = ui->listWidget->row(item);
    ui->tabWidget->setCurrentIndex(index);
}

void MainWindow::on_actionWordWrap_triggered()
{
    if(ui->actionWordWrap->isChecked())
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapWord);
    }
    else
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapNone);
    }
}


//not working
void MainWindow::on_actionAdd_Indent_triggered()
{

    int pos =  static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(
                QsciScintilla::SCI_GETCURRENTPOS);
    int line = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(
                QsciScintilla::SCI_LINEFROMPOSITION,pos);
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->indent(line);
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
            lexer->setDefaultFont(QFont(static_cast<codeEditor*>(ui->tabWidget->currentWidget())->defaultFont));
            lexer->setAutoIndentStyle(true);
            static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setFolding(QsciScintilla::FoldStyle::BoxedTreeFoldStyle);
//            static_cast<codeEditor*>(ui->tabWidget->currentWidget())->zoomIn(3);
        }
        else
        {
            static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setFolding(QsciScintilla::FoldStyle::NoFoldStyle);
        }
    }
    setStyleSheet(lexer, curThemeFile);
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(lexer);
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setFont(static_cast<codeEditor*>(ui->tabWidget->currentWidget())->defaultFont);
}

void MainWindow::lostFocus(QEvent *event)
{
    //save all function
    if (isAutoSave)
    {
        if (event->type() == QEvent::WindowDeactivate)
        {
            int tabcount = ui->tabWidget->count();
            for (int i = 0; i < tabcount; ++i)
            {
                if (static_cast<codeEditor*>(ui->tabWidget->currentWidget())->getTextChanges())
                {
                    if (ui->tabWidget->tabWhatsThis(i) != "")
                    {
                        saveFile(ui->tabWidget->tabWhatsThis(i));
                    }
                }
            }
        }
    }
}

void MainWindow::on_actionSettings_triggered()
{
    settingsDialog = new Settings ();
    settingsDialog->exec();
    loadCodeEditorSettings();
}


void MainWindow::on_actionDuplicate_Line_triggered()
{
    int pos = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
    int linepos = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_LINEFROMPOSITION, pos);
    QString text = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->text(linepos);
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->insertAt(text + "\n", linepos, 0);

}

void MainWindow::findString_Changed()
{
    for (int i = 0;i < searchTextposlist.count() ; i++)
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_INDICATORCLEARRANGE, searchTextposlist[i], searchString.length());
    }
    searchTextposlist.clear();
}

void MainWindow::highlighsearchtext(QString searchtext)
{
    searchString = searchtext;
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_INDICSETSTYLE,0,7);
    searchTextposlist.clear();
    QString document = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->text();
    int end = document.lastIndexOf(searchtext);

    if (!searchtext.isEmpty())
    {
        int curpos = -1;
        if (end != -1)
        {
            while (curpos != end)
            {
                curpos = document.indexOf(searchtext, curpos + 1);
                static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_INDICATORFILLRANGE, curpos, searchtext.length());
                searchTextposlist.append(curpos);
            }
        }
    }
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

void MainWindow::multiedit()
{
    QsciScintilla *textedit = static_cast<codeEditor*>(ui->tabWidget->currentWidget());
//# typing should insert in all selections at the same time

    textedit->SendScintilla(textedit->SCI_SETADDITIONALSELECTIONTYPING, 1);

//# do multiple selections
    int offset = textedit->positionFromLineIndex(0, 7);// # line-index to offset
    textedit->SendScintilla(textedit->SCI_SETSELECTION, offset, offset);
//# using the same offset twice selects no characters, hence a cursor

    offset = textedit->positionFromLineIndex(1, 5);
    textedit->SendScintilla(textedit->SCI_ADDSELECTION, offset, offset);

    offset = textedit->positionFromLineIndex(2, 5);
    textedit->SendScintilla(textedit->SCI_ADDSELECTION, offset, offset);
}

void MainWindow::on_actionUPPER_CASE_triggered()
{
    QString selectedText = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->selectedText();
    if (!selectedText.isEmpty())
    {
        QString uppercase_string = selectedText.toUpper();
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->replaceSelectedText(uppercase_string);
    }
}

void MainWindow::on_actionlower_case_triggered()
{
    QString selectedText = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->selectedText();
    if (!selectedText.isEmpty())
    {
        QString lowercase_string = selectedText.toLower();
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->replaceSelectedText(lowercase_string);
    }
}

void MainWindow::on_actionGo_to_Line_triggered()
{
    int totalline = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->lines();
    int line = QInputDialog::getInt(this, "Go to Line", "enter the line", 0, 0, totalline);
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setCursorPosition(line, 0);

}

void MainWindow::on_actionDecrease_Indent_triggered()
{
    int pos =  static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(
                QsciScintilla::SCI_GETCURRENTPOS);
    int line = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(
                QsciScintilla::SCI_LINEFROMPOSITION,pos);
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->unindent(line);
}

void MainWindow::setTextinMinimap()
{
    QsciDocument text = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->document();
    Mmap->getText()->setDocument(text);
    Mmap->getText()->setLexer(nullptr);
}

void MainWindow::setStyleSheet(QsciLexer *lexer, QString themeFileName)
{
    curThemeFile = themeFileName;
    QString setsearchresultcolor;
    stylesheet *styleSheet = new stylesheet ();
    QString text = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->text();
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->clear();
    styleSheet->setStyleSheet(lexer, themeFileName, static_cast<codeEditor*>(ui->tabWidget->currentWidget()));
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setText(text);
}

void MainWindow::updateRecentFileList(QString recentFilePath)
{
    QStringList recentFilePaths = mySettings->value("recentFiles").toStringList();
    recentFilePaths.removeAll(recentFilePath);
    recentFilePaths.prepend(recentFilePath);
    while (recentFilePaths.size() > maxRecentFiles)
        recentFilePaths.removeLast();
    mySettings->setValue("recentFiles", recentFilePaths);

    // see note
    updateRecentActionList();
}

void MainWindow::on_actionShow_Minimap_triggered()
{
    if (ui->actionShow_Minimap->text() == "Show Minimap")
    {
        ui->actionShow_Minimap->setText("Hide Minimap");
        showMinimap = true;
        ui->minimap->show();
    }
    else
    {
        ui->actionShow_Minimap->setText("Show Minimap");
        showMinimap = false;
        ui->minimap->hide();
    }
}

void MainWindow::on_actionDark_triggered()
{
    QsciLexer *lexer = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->lexer();
    setStyleSheet(lexer, ":/style/src/icons/creator-dark.xml");
}

void MainWindow::on_actionLight_triggered()
{
    QsciLexer *lexer = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->lexer();
    setStyleSheet(lexer, ":/style/src/icons/default_classic.xml");
}

void MainWindow::on_actionComment_triggered()
{
    if (static_cast<codeEditor*>(ui->tabWidget->currentWidget())->lexer() != 0)
    {
        comment *com = new comment (static_cast<codeEditor*>(ui->tabWidget->currentWidget()));
        com->toggleComment();
    }
}

void MainWindow::openRecent()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
        openFile(action->data().toString());
}

void MainWindow::clearRecent()
{
    mySettings->remove("recentFiles");
}

void MainWindow::on_actionDisplay_EOL_triggered()
{
    if (ui->actionDisplay_EOL->isChecked())
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setEolVisibility(true);
    }
    else
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setEolVisibility(false);
    }
}

void MainWindow::on_actionDisplay_White_Space_triggered()
{
    if (ui->actionDisplay_White_Space->isChecked())
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setWhitespaceVisibility(QsciScintilla::WhitespaceVisibility::WsVisible);
    }
    else
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setEolVisibility(QsciScintilla::WhitespaceVisibility::WsInvisible);
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

void MainWindow::on_actionTerminal_triggered()
{
    ui->splitter_2->setChildrenCollapsible(true);
    QObject::connect(console, SIGNAL(finished()), this, SLOT(hideTerminalWidget()));
    ui->terminalWidget->show();
    console->startShellProgram();
    console->setFocus();
}

void MainWindow::hideTerminalWidget()
{
    ui->terminalWidget->hide();
}

void MainWindow::on_termClose_clicked()
{
    hideTerminalWidget();
}
