#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->splitter_2->setStretchFactor(1,1);
    ui->splitter->setStretchFactor(1,1);

    ui->treeView->hide();       //fileExplorer
    ui->listWidget->hide();     //openedFiles
    ui->label->hide();          //fileExplorer Title
    ui->label_2->hide();        //openedFiles Title
    ui->widget->hide();         //find dialog

    defaultLocation();      //sets fileExplorer default location

    //status bar line number widget
    lineNumLabel = new QLabel(this);
    ui->statusBar->addWidget(lineNumLabel);

    statSpitter = new QSplitter(this);
    ui->statusBar->addWidget(statSpitter);

    fileTypeLabel = new QLabel(this);
    ui->statusBar->addWidget(fileTypeLabel);

    mySettings = new QSettings ("kumar","SimpleCodeEditor",this);

    menuActionGroup();
    newTab("untitled"); //creates a new tab
    setEOL();   //set the document end of line
    loadWindowsGeomentry();
    loadSettings();
    on_actionShow_Linenumbers_triggered(); // to show linenumber if it is checked

    connect(static_cast<codeEditor*>(ui->tabWidget->currentWidget()),&QsciScintilla::cursorPositionChanged,
            this,&MainWindow::statusBar);

    connect(static_cast<codeEditor*>(ui->tabWidget->currentWidget()),&QsciScintilla::cursorPositionChanged,
            this,&MainWindow::lineNumwidthIncrement);

    connect(static_cast<codeEditor*>(ui->tabWidget->currentWidget()),&QsciScintilla::textChanged,
            this,&MainWindow::saveChanges);

//    connect(this, &MainWindow::focusOutEvent, this, &MainWindow::lostFocus);


    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapWord);

    //find dialog
    find = new findDialog();
    ui->widget->setLayout(find->layout());

    connect(find,SIGNAL(closeFindDialog()),this,SLOT(closeFindDialog()));

    connect(find,SIGNAL(findButton_clicked(QString)),this,SLOT(findButton_clicked(QString)));

    connect(find,SIGNAL(findPrev_clicked(QString)),this,SLOT(findPrev_clicked(QString)));

    connect(find,SIGNAL(replace_clicked(QString)),this,SLOT(replace_clicked(QString)));

    connect(find,SIGNAL(replaceAll_clicked(QString, QString)),
            this,SLOT(replaceAll_clicked(QString, QString)));

    connect(find, SIGNAL(findStringChanged()), this, SLOT(findString_Changed()));
}

MainWindow::~MainWindow()
{
    saveWindowsGeomentry();
    delete ui;
//    delete find;
//    delete filemodel;
//    delete settingsDialog;
}

void MainWindow::saveWindowsGeomentry()
{
    mySettings->setValue("geomentry",this->saveGeometry());
}

void MainWindow::loadWindowsGeomentry()
{
    this->restoreGeometry(mySettings->value("geomentry").toByteArray());
}

void MainWindow::loadSettings()
{
    QString fontName = mySettings->value("font").toString();
    int fontSize = mySettings->value("fontSize").toInt();
    QFont font = QFont(fontName,fontSize);
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setFont(font);
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setTabWidth(mySettings->value("tabWidth").toInt());
    if (mySettings->value("caretWidth").toInt() == 4)
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_SETCARETSTYLE,2);
    }
    else
    {
      static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setCaretWidth(mySettings->value("caretWidth").toInt());
    }
    if (mySettings->value("autoIndent").toBool())
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setAutoIndent(true);
    }
    else
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setAutoIndent(false);
    }
    if (mySettings->value("matchBracket").toInt() == 4)
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setBraceMatching(QsciScintilla::SloppyBraceMatch);
    }
    else
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setBraceMatching(QsciScintilla::NoBraceMatch);
    }
    if (mySettings->value("lineNumbers").toBool())
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"0000");
    }
    else
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"");
    }
    if (mySettings->value("wordWrap").toBool()) {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapWord);
    }
    else {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapNone);
    }
    if (mySettings->value("autocomplete").toBool())
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setAutoCompletionSource(QsciScintilla::AcsAll);
    }
    else
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setAutoCompletionSource(QsciScintilla::AcsNone);
    }
}

//default location of the file explorer
void MainWindow::defaultLocation()
{
    filemodel = new QFileSystemModel();
    filemodel->setRootPath(QDir::homePath());
    ui->treeView->setModel(filemodel);
    ui->treeView->setRootIndex(filemodel->index(QDir::homePath()));

    //it hides the other columns in treeview
    ui->treeView->setColumnHidden(1, 1);
    ui->treeView->setColumnHidden(2, 1);
    ui->treeView->setColumnHidden(3, 1);
}

void MainWindow::statusBar(int line, int index)
{
    lineNumLabel->setText("Col: " + QString::number(index) + ", Line: " + QString::number(line));
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
    codeEditor *texteditor = new codeEditor;
    int tabindex = ui->tabWidget->addTab(texteditor,tabname);
    ui->tabWidget->setCurrentIndex(tabindex);
    ui->listWidget->addItem(tabname);
    return tabindex;
}

//opens directory in file explorer
void MainWindow::openDirectory()
{
    QString filedir = QFileDialog::getExistingDirectory(this,"Open Directory",QDir::homePath());
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
    codeEditor *texteditor = new codeEditor();
    QString line;
    if (filepath.isNull()) {
        filepath = QFileDialog::getOpenFileName(this,tr("Open file"),QDir::homePath());
    }
    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        if(ui->tabWidget->tabWhatsThis(i) == filepath)
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
    if (ui->tabWidget->tabText(ui->tabWidget->currentIndex()).contains("- *"))
    {
        QString tabtext = ui->tabWidget->tabText(ui->tabWidget->currentIndex()).remove("- *");
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),tabtext);
    }
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
    painter.drawText(100, 100, 500, 500, Qt::AlignLeft|Qt::AlignTop, text);
    painter.end();
}

void MainWindow::closeFile()
{
    closeFile(ui->tabWidget->currentIndex());
}

void MainWindow::closeFile(int index)
{
    if(static_cast<codeEditor*>(ui->tabWidget->currentWidget())->getTextChanges()) {
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
    if(ui->tabWidget->count() == 0)
    {
        newTab("untitled");
    }
}

// it collects the text is changed or not
void MainWindow::saveChanges()
{
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setTextChanges(true);
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
}

void MainWindow::setFiletype(QString file)
{
    QFileInfo fileinfo(file);
    QString extension = fileinfo.suffix();
    extension = extension.toLower();
    if (extension == "txt") {
        on_actionNormal_triggered();
        //setLexers(nullptr);
        fileTypeLabel->setText("Normal");
    }
    else if (extension == "sh") {
      on_actionBash_triggered();
        //  setLexers(lexer);
        fileTypeLabel->setText("Bash File");
    }
    else if (extension == "bat") {
        on_actionBatch_File_triggered();
        //  setLexers(lexer);
        fileTypeLabel->setText("Batch File");
    }
    else if ((extension == "c") or (extension == "cpp") or (extension == "h") or (extension == "cxx")
             or (extension == "hpp") or (extension == "hxx" )) {
        on_actionCpp_triggered();
        //  setLexers(lexer);
        fileTypeLabel->setText("C++");
    }
    else if (extension == "cs" ) {
        on_actionCSharp_triggered();
        fileTypeLabel->setText("CSharp");
    }
    else if (extension == "css") {
        on_actionCSS_triggered();
        fileTypeLabel->setText("CSS");
    }
    else if (extension == "d") {
        on_actionD_triggered();
        fileTypeLabel->setText("D");
    }
    else if (extension == "f") {
        on_actionFortan_triggered();
        fileTypeLabel->setText("Fortan");
    }
    else if (extension == "html") {
        on_actionHTML_triggered();
        fileTypeLabel->setText("HTML");
    }
    else if (extension == "java") {
        on_actionJava_triggered();
        fileTypeLabel->setText("Java");
    }
    else if (extension == "js") {
        on_actionJavaScript_triggered();
        fileTypeLabel->setText("Javascript");
    }
    else if (extension == "json") {
        on_actionJSON_triggered();
        fileTypeLabel->setText("JSON");
    }
    else if (extension == "lua") {
        on_actionLua_triggered();
        fileTypeLabel->setText("Lua");
    }
    else if (extension == "md") {
        on_actionMarkDown_triggered();
        fileTypeLabel->setText("Markdown");
    }
    else if (extension == "mlx") {
        on_actionMatLab_triggered();
        fileTypeLabel->setText("Matlab");
    }
    else if (extension == "pas") {
        on_actionPascal_triggered();
        fileTypeLabel->setText("Pascal");
    }
    else if (extension == "pl") {
        on_actionPerl_triggered();
        fileTypeLabel->setText("Perl");
    }
    else if (extension == "py") {
        on_actionPython_triggered();
        fileTypeLabel->setText("Python");
    }
    else if (extension == "rb") {
        on_actionRuby_triggered();
        fileTypeLabel->setText("Ruby");
    }
    else if (extension == "sql" or extension == "sqlite") {
        on_actionSQL_triggered();
        fileTypeLabel->setText("SQL");
    }
    else if (extension == "yaml") {
        on_actionYAML_triggered();
        fileTypeLabel->setText("YAML");
    }
    else if (extension == "xml") {
        on_actionXML_triggered();
        fileTypeLabel->setText("XML");
    }
    else {
        on_actionNormal_triggered();
        fileTypeLabel->setText("Normal");
    }    
}

void MainWindow::setLexers(QsciLexer *lexer)
{
    QFont font = ui->tabWidget->currentWidget()->font();
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(lexer);
    lexer->setFont(font);
}

void MainWindow::changeFilename()
{
    QString tabName = ui->tabWidget->tabText(ui->tabWidget->currentIndex());
    if (!tabName.contains("- *"))
    {
        tabName = ui->tabWidget->tabText(ui->tabWidget->currentIndex()) + "- *";
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),tabName);
    }
}

void MainWindow::autoComplete()
{

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
    openDirectory();
}

void MainWindow::on_actionSave_triggered()
{
    if (ui->tabWidget->tabWhatsThis(ui->tabWidget->currentIndex()) == "") {
    saveFileAs(ui->tabWidget->tabText(ui->tabWidget->currentIndex()));
    }
    else {
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
    for (int i =0;i < ui->tabWidget->count();i++) {
        if (ui->tabWidget->tabWhatsThis(i) == "") {
            saveFileAs(ui->tabWidget->tabText(i));
        }
        else {
            QString filepath = ui->tabWidget->tabWhatsThis(i);
        }
    }
    ui->tabWidget->setCurrentIndex(curIndex);
}

void MainWindow::on_actionPrint_triggered()
{
    QString text = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->text(); // your text is here
    QPrinter printer;

    QPrintDialog *dialog = new QPrintDialog(&printer);
    dialog->setWindowTitle("Print Document");

    if (dialog->exec() != QDialog::Accepted)
        return;

    QPainter painter;
    painter.begin(&printer);

    painter.drawText(100, 100, 500, 500, Qt::AlignLeft|Qt::AlignTop, text);

    painter.end();
}

void MainWindow::on_actionPrint_Preview_triggered()
{
    QPrinter printer(QPrinter::HighResolution);
    QPrintPreviewDialog preview(&printer, this);
    connect(&preview, SIGNAL(paintRequested(QPrinter *)),
            this, SLOT(print(QPrinter *)));
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
    for (int i=0;i<ui->tabWidget->count();i++)
    {
        closeFile(0);
    }
}

void MainWindow::on_actionNew_Window_triggered()
{
    MainWindow *newwindow = new MainWindow();
    newwindow->show();
}

void MainWindow::on_actionClose_Window_triggered()
{
    this->close();
}

void MainWindow::on_actionExit_triggered()
{
    qApp->exit();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << ui->tabWidget->count();
    for (int i = 0; i < ui->tabWidget->count(); ++i)
    {
        qDebug() << static_cast<codeEditor*>(ui->tabWidget->widget(i))->getTextChanges();
        if (static_cast<codeEditor*>(ui->tabWidget->widget(i))->getTextChanges())
        {
            if (ui->tabWidget->tabWhatsThis(i) != "")
            {
                saveFile(ui->tabWidget->tabWhatsThis(i));
                qDebug() << "closing";
            }
        }
    }
    qDebug() << "closign";
    QMainWindow::closeEvent(event);
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
//    int curLine = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_LINEFROMPOSITION,curPos);
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
    ui->widget->show();
    find->hidereplaceWidget();
}

void MainWindow::on_actionFind_Prev_triggered()
{
    findPrev_clicked(find->getFindString());
}

void MainWindow::on_actionReplace_triggered()
{
    ui->widget->show();
    find->showreplaceWidget();
}

void MainWindow::on_actionReplace_All_triggered()
{
    replaceAll_clicked(find->getFindString(),find->getReplaceString());
}

void MainWindow::findButton_clicked(QString searchtext)
{
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->focusWidget();
    int curPos = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_SETCURRENTPOS,curPos);
    bool search = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->findFirst(searchtext,0,0,0,0,1);
    if (!search)
    {
        QMessageBox::warning(this, "Find", "search has ended", QMessageBox::Ok);
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setCursorPosition(0, 0);
        search = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->findFirst(searchtext,0,0,0,0,1);
    }
    highlighsearchtext(searchtext);
}

void MainWindow::findPrev_clicked(QString searchtext)
{
    bool search;
    (static_cast<codeEditor*>(ui->tabWidget->currentWidget())->findFirst(searchtext,0,0,0,0,0));
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
    if(!replacetext.isEmpty()) {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_INDICSETSTYLE,0,7);
        int end = document.lastIndexOf(replacetext);
        int cur = -1;
        if (end != -1) {
            while (cur != end) {
                cur = document.indexOf(replacetext,cur+1);
            }
        }
    }
}

void MainWindow::closeFindDialog()
{
    ui->widget->hide();
    findString_Changed();
}
//--------

void MainWindow::on_actionOpened_Files_triggered()
{
    if(ui->actionOpened_Files->isChecked()) {
        ui->listWidget->show();
        ui->label_2->show();
    }
    else {
        ui->listWidget->hide();
        ui->label_2->hide();
    }
}

void MainWindow::on_actionFile_Explorer_triggered()
{
    if(ui->actionFile_Explorer->isChecked()) {
        ui->treeView->show();
        ui->label->show();
    }
    else {
        ui->treeView->hide();
        ui->label->hide();
    }
}

//End of line functions
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

//----------

void MainWindow::on_actionShow_Linenumbers_triggered()
{
    if (ui->actionShow_Linenumbers->isChecked()) {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"0000");
    }
    else {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setMarginWidth(0,"");
    }
}

void MainWindow::on_actionStatusBar_triggered()
{
    if (ui->actionStatusBar->isChecked()) {
        ui->statusBar->show();
    }
    else {
        ui->statusBar->hide();
    }
}

void MainWindow::on_actionToolBar_triggered()
{
    if (ui->actionToolBar->isChecked()) {
        ui->mainToolBar->show();
    }
    else {
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
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(lexer);
}

void MainWindow::on_actionBatch_File_triggered()
{
    fileTypeLabel->setText("Batch");
//    QsciLexerBatch *lexer = new QsciLexerBatch (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(lexer);
    this->setLexer("Bash");
}

void MainWindow::on_actionC_triggered()
{
    fileTypeLabel->setText("C");
    setLexer("C++");
//    QsciLexerCPP *lexer = new QsciLexerCPP (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(lexer);
}

void MainWindow::on_actionCSharp_triggered()
{
    fileTypeLabel->setText("CSharp");
    setLexer("C#");
//    QsciLexerCSharp *lexer = new QsciLexerCSharp (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(lexer);
}

void MainWindow::on_actionCpp_triggered()
{
    fileTypeLabel->setText("Cpp");
    setLexer("C++");
    //QsciLexerCPP *lexer =  new QsciLexerCPP(this);
  //  static_cast<codeEditor*>(ui->tabWidget->currentWidget())->autoCompleteForCpp(lexer);
    //static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(lexer);
}

void MainWindow::on_actionCSS_triggered()
{
    fileTypeLabel->setText("CSS");
    setLexer("CSS");
    /*QsciLexerBash *lexer = new QsciLexerBash (this);
    lexer->setFont(QFont(mySettings->value("font").toString()));
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerCSS(this));*/
}

void MainWindow::on_actionCMake_triggered()
{
    fileTypeLabel->setText("CMake");
    setLexer("CMake");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerCMake(this));
}

void MainWindow::on_actionCoffeeScript_triggered()
{
    fileTypeLabel->setText("CoffeeScript");
    setLexer("CoffeeScript");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerCoffeeScript(this));
}

void MainWindow::on_actionD_triggered()
{
    fileTypeLabel->setText("D");
    setLexer("D");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerD(this));
}

void MainWindow::on_actionDiff_triggered()
{
    fileTypeLabel->setText("Diff");
    setLexer("Diff");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerDiff(this));
}

void MainWindow::on_actionFortan_triggered()
{
    fileTypeLabel->setText("Fortran");
    setLexer("Fortran");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerFortran(this));
}

void MainWindow::on_actionFortan77_triggered()
{
    fileTypeLabel->setText("Fortran77");
    setLexer("Fortran77");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerFortran77(this));
}

void MainWindow::on_actionHTML_triggered()
{
    fileTypeLabel->setText("HTML");
    setLexer("HTML");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerHTML(this));
}

void MainWindow::on_actionJava_triggered()
{
    fileTypeLabel->setText("Java");
    setLexer("Java");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerJava(this));
}

void MainWindow::on_actionJavaScript_triggered()
{
    fileTypeLabel->setText("JavaScript");
    setLexer("JavaScript");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerJavaScript(this));
}

void MainWindow::on_actionJSON_triggered()
{
    fileTypeLabel->setText("JSON");
    setLexer("JSON");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerJSON(this));
}

void MainWindow::on_actionLua_triggered()
{
    fileTypeLabel->setText("Lua");
    setLexer("Lua");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerLua(this));
}

void MainWindow::on_actionMarkDown_triggered()
{
    fileTypeLabel->setText("MarkDown");
    setLexer("Markdown");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerMarkdown(this));
}

void MainWindow::on_actionMakeFile_triggered()
{
    fileTypeLabel->setText("MakeFile");
    setLexer("Makefile");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerMakefile(this));
}

void MainWindow::on_actionMatLab_triggered()
{
    fileTypeLabel->setText("MatLab");
    setLexer("Matlab");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerMatlab(this));
}

void MainWindow::on_actionPascal_triggered()
{
    fileTypeLabel->setText("Pascal");
    setLexer("Pascal");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerPascal(this));
}

void MainWindow::on_actionPython_triggered()
{
    fileTypeLabel->setText("Python");
    setLexer("Python");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerPython(this));
}

void MainWindow::on_actionPerl_triggered()
{
    fileTypeLabel->setText("Perl");
    setLexer("Perl");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerPerl(this));
}

void MainWindow::on_actionProperties_triggered()
{
    fileTypeLabel->setText("Properties");
    setLexer("Properties");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerProperties(this));
}

void MainWindow::on_actionRuby_triggered()
{
    fileTypeLabel->setText("Ruby");
    setLexer("Ruby");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerRuby(this));
}

void MainWindow::on_actionSQL_triggered()
{
    fileTypeLabel->setText("SQL");
    setLexer("SQL");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerSQL(this));
}

void MainWindow::on_actionTeX_triggered()
{
    fileTypeLabel->setText("TeX");
    setLexer("TeX");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerTeX(this));
}

void MainWindow::on_actionXML_triggered()
{
    fileTypeLabel->setText("XML");
    setLexer("XML");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerXML(this));
}

void MainWindow::on_actionYAML_triggered()
{
    fileTypeLabel->setText("YAML");
    setLexer("YAML");
//    QsciLexerBash *lexer = new QsciLexerBash (this);
//    lexer->setFont(QFont(mySettings->value("font").toString()));
//    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(new QsciLexerYAML(this));
}
//--------------

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,tr("About Text editor"),tr(" "));
}

void MainWindow::on_actionAbout_QT_triggered()
{
    QMessageBox::aboutQt(this,"About Qt");
}

void MainWindow::on_treeView_doubleClicked(const QModelIndex &index)
{
    QString filepath = filemodel->filePath(index);
    openFile(filepath);
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    connect(static_cast<codeEditor*>(ui->tabWidget->widget(index)),&QsciScintilla::cursorPositionChanged,
            this,&MainWindow::statusBar);

    connect(static_cast<codeEditor*>(ui->tabWidget->widget(index)),&QsciScintilla::textChanged,
            this,&MainWindow::changeFilename);

    setFiletype(static_cast<codeEditor*>(ui->tabWidget->widget(index))->getFileName());

    for (int i = 0; i < ui->tabWidget->count(); ++i) {
        if (i == index) break;
        if (static_cast<codeEditor*>(ui->tabWidget->currentWidget())->getTextChanges()) {
            if (ui->tabWidget->tabWhatsThis(i) != "") {
                saveFile(ui->tabWidget->tabWhatsThis(i));
            }
        }
    }

}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    int index = ui->listWidget->row(item);
    ui->tabWidget->setCurrentIndex(index);
}

void MainWindow::on_actionWordWrap_triggered()
{
    if(ui->actionWordWrap->isChecked()) {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapWord);
    }
    else {
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
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_SETINDENT,4);

}


/*
//themes
void MainWindow::on_actionSolarizedDark_triggered()
{
    theme = "solarized";
    settings.setValue("theme", "solarized");

    QString fgc = "#839496";
    QString bgc = "#fdf6e3";
    QString lc = "#eee7d5";

    setMainWindowStyle(bgc, lc);
    setTabWidgetStyle(fgc, bgc);
    setLineNumStyle(lc, fgc);
    setOverViewStyle(lc, fgc);

    updateHighlighterTheme();

    lineColor = QColor(238, 232, 213);
}

void MainWindow::setMainWindowStyle(QString backgroundColor, QString lineColor){
    QString stylesheet = "QMenu {"
                "background-color: rgb(48, 47, 54);"
                "color:white;"
                "selection-background-color: #404f4f;"
                "border: 1px solid #404f4f;"
                "border-radius: 3px 3px 3px 3px;"
             "}"
             "QMenuBar::item {"
                "background:#262626;"
             "}"
             "QMenuBar::item:selected {"
                "background: #232629;"
             "}"
             "QMessageBox {"
                "color:white;"
             "}"
             "QLineEdit {"
                "border: 1px solid #676767;"
                "border-radius: 5px 5px 5px 5px;"
             "}"
             "QScrollBar::sub-page:vertical {"
                "background: " +  backgroundColor + ";"
             "}"
             "QScrollBar::add-page:vertical {"
                "background: " +  backgroundColor + ";"
             "}"
             "QScrollBar::sub-page:horizonal {"
                "background: " +  backgroundColor +";"
             "}"
             "QScrollBar::add-page:horizontal {"
                "background: " +  backgroundColor +";"
             "}"
             "QScrollBar:vertical{"
                "background: white;"
                "width:12px;margin: 0px 0px 0px 0px;"
             "}"
             "QScrollBar::handle:vertical {"
                "background:" + lineColor  +";"
                "border: 2px solid " +  backgroundColor  +";"
                "border-radius: 5px 5px 5px 5px;"
                "min-height: 30px;"
             "}"
             "QScrollBar:horizontal{"
                "background: white;"
                "height:12px;"
                "margin: 0px 0px 0px 0px;"
             "}"
             "QScrollBar::handle:horizontal {"
                "background:" + lineColor  +";"
             "border: 2px solid " +  backgroundColor  +";"
             "border-radius: 5px 5px 5px 5px;"
             "min-height: 30px;"
             "}";

    MainWindow::setStyleSheet(stylesheet);

}

void MainWindow::setTabWidgetStyle(QString foregroundColor, QString backgroundColor){
   QString stylesheet = "QPlainTextEdit {"
                "background-color: " +  backgroundColor  +";"
                "color:" + foregroundColor  +";"
                "border: 0px;"
                "padding-left: 1px;"
                "selection-background-color: #404f4f;"
                "font-family: \"Anonymous Pro\";"
                "font-size:11pt;"
             "}"
             "QScrollBar:vertical{"
                "background: " +  backgroundColor  +";"
             "}"
             "QScrollBar:horizontal{"
                "background: " +  backgroundColor  +";"
             "}"
             "QTabBar::tab:selected{"
                "color: white;"
                "border-bottom: 3px solid #2F4F4F;"
             "}"
             "QTabBar::tab {"
                "height: 22px; width: 160px;"
                "color: #676767;"
                "font-size:9pt;"
                "margin: 0 -2px;"
                "padding: 1px 5px;"
                "background-color: #262626;"
                "border-bottom: 3px solid #212121;"
             "}";
   ui->tabWidget->setStyleSheet(stylesheet);

}

void MainWindow::setLineNumStyle(QString lineColor, QString foregroundColor){
   QString stylesheet = "background-color: " + lineColor  +";"
            "margin-top: 30px;"
            "padding-left: 5px;"
            "padding-right: 1px;"
            "color: " + foregroundColor  +";"
            "border: none;"
            "font: 11pt \"Anonymous Pro\";";
    ui->listWidget->setStyleSheet(stylesheet);
}


void MainWindow::setOverViewStyle(QString lineColor, QString foregroundColor){
    QString stylesheet = "font-family: \"Anonymous Pro\";"
            "font-size: 1pt;"
            "color:" + foregroundColor  +";"
            "margin-top: 28px;"
            "background-color:" + lineColor  +";"
            "border: 0px;";
    //codeeditor stylesheet
   // ui->fileOverview->setStyleSheet(stylesheet);
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->codeEditorTheme(lineColor,foregroundColor);

}

void MainWindow::updateHighlighterTheme(){
    int current = ui->tabWidget->currentIndex();
    int numOpenTabs = ui->tabWidget->count();
    for(int i = 0; i < numOpenTabs; i++){
        ui->tabWidget->setCurrentIndex(i);

     //   currentEditorWidget->setHighlighterTheme(theme);
    }
    ui->tabWidget->setCurrentIndex(current);
}

*/


//!important
void MainWindow::setLexer(QsciLexer *lexer)
{
    static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(lexer);
}

void MainWindow::setLexer(QString lexername)
{
    QMap <QString,QsciLexer*> languageToLexer = {
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

    QFont font = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->font();
    QMap<QString, QsciLexer*>::iterator i = languageToLexer.find(lexername);

    if (i != languageToLexer.end())
    {
        QsciLexer *lexer = i.value();
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(lexer);

        if (i.key() == "C++")
        {
            static_cast<codeEditor*>(ui->tabWidget->currentWidget())->autoCompleteForCpp(lexer);
        }
    }
    if (lexername == "Normal")
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setLexer(nullptr);
    }
    QsciLexer *curLexer = static_cast<codeEditor*>(ui->tabWidget->currentWidget())->lexer();
    if (curLexer == 0)
    {
        static_cast<codeEditor*>(ui->tabWidget->currentWidget())->setFont(font);
    }
    else
    {
        curLexer->setFont(font);
        curLexer->setAutoIndentStyle(true);
    }

}

void MainWindow::lostFocus(QEvent *event)
{
    if (event->type() == QEvent::WindowDeactivate)
    {
        for (int i = 0; i < ui->tabWidget->count(); ++i)
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

void MainWindow::on_actionSettings_triggered()
{
    settingsDialog = new Settings ();
    settingsDialog->exec();
    loadSettings();
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
