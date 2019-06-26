#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{

    //close all not working properly
    //save all feature to add
    ui->setupUi(this);

    ui->splitter_2->setStretchFactor(1,1);
    ui->splitter->setStretchFactor(1,1);

    ui->treeView->hide();       //fileExplorer
    ui->listWidget->hide();     //openedFiles
    ui->label->hide();          //fileExplorer Title
    ui->label_2->hide();        //openedFiles Title
    ui->widget->hide();         //find dialog

    defaultLocation();      //sets fileExplorer default location

    linenum = new QLabel();
    ui->statusBar->addWidget(linenum);

    newTab("untitled");
    setEOL();
    //((codeEditor*)ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapWord);

    connect(((codeEditor*)ui->tabWidget->currentWidget()),&QsciScintilla::cursorPositionChanged,
            this,&MainWindow::statusbar);

    connect(((codeEditor*)ui->tabWidget->currentWidget()),&QsciScintilla::cursorPositionChanged,
            this,&MainWindow::lineNumwidthIncrement);

    connect(((codeEditor*)ui->tabWidget->currentWidget()),&QsciScintilla::textChanged,
            this,&MainWindow::saveChanges);


    find = new findDialog();
    ui->widget->setLayout(find->layout());

    connect(find,SIGNAL(closeFindDialog()),this,SLOT(closeFindDialog()));

    connect(find,SIGNAL(findButton_clicked(QString)),this,SLOT(findButton_clicked(QString)));

    connect(find,SIGNAL(findPrev_clicked(QString)),this,SLOT(findPrev_clicked(QString)));

    connect(find,SIGNAL(replace_clicked(QString)),this,SLOT(replace_clicked(QString)));

    connect(find,SIGNAL(replaceAll_clicked(QString, QString)),this,SLOT(replaceAll_clicked(QString, QString)));
}


MainWindow::~MainWindow()
{
    delete ui;
}


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


void MainWindow::statusbar(int line, int index)
{

    linenum->setText("Col: " + QString::number(index) + ", Line: " + QString::number(line));
}


void MainWindow::setEOL()
{
    if ((QSysInfo::productType() == "windows") | (QSysInfo::productType() == "winrt")) {
        ui->actionWindows->setChecked(true);
        on_actionWindows_triggered();

    }
    else if (QSysInfo::productType() == "osx") {
        ui->actionMac->setChecked(true);
        on_actionMac_triggered();
    }
    else {
        ui->actionUnix->setChecked(true);
        on_actionUnix_triggered();
    }
}


int MainWindow::newTab(QString tabname)
{
    codeEditor *texteditor = new codeEditor;
    int tabindex = ui->tabWidget->addTab(texteditor,tabname);
    ui->tabWidget->setCurrentIndex(tabindex);
    ui->listWidget->addItem(tabname);
    return tabindex;
}


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
}


void MainWindow::openFile(QString filepath)
{
    codeEditor *texteditor = new codeEditor();
    QString line;
    if (filepath.isNull()) {
        filepath = QFileDialog::getOpenFileName(this,tr("Open file"),QDir::homePath());
    }
    for (int i = 0; i < ui->tabWidget->count(); i++) {
        if(ui->tabWidget->tabWhatsThis(i) == filepath) {
            ui->tabWidget->setCurrentIndex(i);
            return;
        }
    }
    QFile file(filepath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }
    QTextStream in(&file);
    while (!in.atEnd()) {
        line = in.readAll();
    }
    texteditor->setText(line);
    QString filename = filepath.section("/",-1,-1);
    int tabindex = ui->tabWidget->addTab(texteditor,filename);
    ui->tabWidget->setCurrentIndex(tabindex);
    ui->tabWidget->setTabWhatsThis(tabindex,filepath);
    addtoOpenedFiles(filename);
}


void MainWindow::addtoOpenedFiles(QString filename)
{
    ui->listWidget->addItem(filename);
}


void MainWindow::saveFile(QString filepath)
{
    QFileInfo fileinfo(filepath);
    if (fileinfo.exists()) {
        QFile file(filepath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << ((codeEditor*)ui->tabWidget->currentWidget())->text();
        }
    }
}


void MainWindow::saveFileAs()
{
    QString filepath = QFileDialog::getSaveFileName(this,tr("Save File"),QDir::homePath());
    QFile file(filepath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << ((codeEditor*)ui->tabWidget->currentWidget())->text();
    }
    QString filename = filepath.section("/",-1,-1);
    int tabindex = ui->tabWidget->currentIndex();
    ui->tabWidget->setCurrentIndex(tabindex);
    ui->tabWidget->setTabWhatsThis(tabindex,filepath);
    ui->tabWidget->setTabText(tabindex,filename);
    ui->listWidget->takeItem(tabindex);
    ui->listWidget->insertItem(tabindex,filename);

}


void MainWindow::closeFile()
{
    closeFile(ui->tabWidget->currentIndex());
}


void MainWindow::closeFile(int index)
{
    if(((codeEditor*)ui->tabWidget->widget(index))->getTextChanges()) {
            QMessageBox::StandardButton ask = QMessageBox::question(this,tr(""),tr("Save changes before close"),
                                                                 QMessageBox::Yes|QMessageBox::No|QMessageBox::Cancel,
                                                                 QMessageBox::Cancel);

            if (ask == QMessageBox::Yes) {
                if (ui->tabWidget->tabWhatsThis(index) == "") {
                    saveFileAs();
                    delete ui->tabWidget->widget(index);
                    ui->listWidget->takeItem(index);
                }
                else {
                    QString filepath = ui->tabWidget->tabWhatsThis(index);
                    saveFile(filepath);
                    delete ui->tabWidget->widget(index);
                    ui->listWidget->takeItem(index);
                }
            }

            else if (ask == QMessageBox::No) {
                delete ui->tabWidget->widget(index);
                ui->listWidget->takeItem(index);
            }

            else if (ask == QMessageBox::Cancel) {
                //do nothing
            }
    }
    else {
        delete ui->tabWidget->widget(index);
        ui->listWidget->takeItem(index);
    }
    if(ui->tabWidget->count() == 0) {
        newTab("untitled");
    }
}


void MainWindow::saveChanges()
{
    ((codeEditor*)ui->tabWidget->currentWidget())->setTextChanges(true);
}


void MainWindow::lineNumwidthIncrement(int line, int index)
{
    if (line > 10) {
        ((codeEditor*)ui->tabWidget->currentWidget())->setMarginWidth(0,"000");
    }
    else if (line > 100) {
        ((codeEditor*)ui->tabWidget->currentWidget())->setMarginWidth(0,"0000");
    }
    else if (line > 1000) {
        ((codeEditor*)ui->tabWidget->currentWidget())->setMarginWidth(0,"00000");
    }
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
    openDirectory();
}


void MainWindow::on_actionSave_triggered()
{
    if (ui->tabWidget->tabWhatsThis(ui->tabWidget->currentIndex()) == "") {
    saveFileAs();
    }
    else {
        QString filepath = ui->tabWidget->tabWhatsThis(ui->tabWidget->currentIndex());
        saveFile(filepath);
    }
}


void MainWindow::on_actionSave_AS_triggered()
{
    saveFileAs();
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
    int tabcount  = ui->tabWidget->count();
    for (int i = 0;i < tabcount; i++) {
        closeFile(i);
        qDebug() << "closed" << i  << tabcount;
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


void MainWindow::on_actionUndo_triggered()
{
    ((codeEditor*)ui->tabWidget->currentWidget())->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ((codeEditor*)ui->tabWidget->currentWidget())->redo();
}


void MainWindow::on_actionCut_triggered()
{
    ((codeEditor*)ui->tabWidget->currentWidget())->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ((codeEditor*)ui->tabWidget->currentWidget())->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ((codeEditor*)ui->tabWidget->currentWidget())->paste();
}


void MainWindow::on_actionSelect_All_triggered()
{
    ((codeEditor*)ui->tabWidget->currentWidget())->selectAll();
}


void MainWindow::on_actionDeselect_triggered()
{
    ((codeEditor*)ui->tabWidget->currentWidget())->selectAll(false);
}


void MainWindow::on_actionFind_triggered()
{
    ui->widget->show();
}


void MainWindow::on_actionFind_Next_triggered()
{
    ((codeEditor*)ui->tabWidget->currentWidget())->findNext();
}


void MainWindow::on_actionFind_Prev_triggered()
{
    findPrev_clicked(find->getFindString());
}


void MainWindow::on_actionReplace_triggered()
{
    ui->widget->show();
}


void MainWindow::on_actionReplace_All_triggered()
{
    replaceAll_clicked(find->getFindString(),find->getReplaceString());
}


void MainWindow::findButton_clicked(QString searchtext)
{
    int curpos = ((codeEditor*)ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS);
    QString document = ((codeEditor*)ui->tabWidget->currentWidget())->text();
    int end = document.lastIndexOf(searchtext);
    if(!searchtext.isEmpty()) {
        ((codeEditor*)ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_INDICSETSTYLE,0,7);
        int cur = -1;
        if (end != -1) {
            while (cur != end) {
                cur = document.indexOf(searchtext,cur+1);
                ((codeEditor*)ui->tabWidget->currentWidget())->SendScintilla(
                            QsciScintillaBase::SCI_INDICATORFILLRANGE,cur,searchtext.length());
            }
        }
    }
    if (document.length() == ((codeEditor*)ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_GETCURRENTPOS)) {
        ((codeEditor*)ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_SETCURRENTPOS,curpos);
    }
    ((codeEditor*)ui->tabWidget->currentWidget())->findFirst(searchtext,0,0,0,0);
}


void MainWindow::findPrev_clicked(QString searchtext)
{
    if(!searchtext.isEmpty()) {
        ((codeEditor*)ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_INDICSETSTYLE,0,7);
        QString document = ((codeEditor*)ui->tabWidget->currentWidget())->text();
        int end = document.lastIndexOf(searchtext);
        int cur = -1;
        if (end != -1) {
            while (cur != end) {
                cur = document.indexOf(searchtext,cur+1);
                ((codeEditor*)ui->tabWidget->currentWidget())->SendScintilla(
                            QsciScintillaBase::SCI_INDICATORFILLRANGE,cur,searchtext.length());
            }
        }
    }
    if(((codeEditor*)ui->tabWidget->currentWidget())->findFirst(searchtext,0,0,0,0,0)) {
        ((codeEditor*)ui->tabWidget->currentWidget())->findNext();
    }
}


void MainWindow::replace_clicked(QString replacetext)
{
    ((codeEditor*)ui->tabWidget->currentWidget())->replaceSelectedText(replacetext);
}


void MainWindow::replaceAll_clicked(QString searchtext, QString replacetext)
{
    QString document = ((codeEditor*)ui->tabWidget->currentWidget())->text();
    document.replace(searchtext,replacetext);
    ((codeEditor*)ui->tabWidget->currentWidget())->setText(document);
    if(!replacetext.isEmpty()) {
        ((codeEditor*)ui->tabWidget->currentWidget())->SendScintilla(QsciScintilla::SCI_INDICSETSTYLE,0,7);
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
}


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


void MainWindow::on_actionMac_triggered()
{
    ((codeEditor*)ui->tabWidget->currentWidget())->setEolMode(QsciScintilla::EolMac);
}


void MainWindow::on_actionUnix_triggered()
{
    ((codeEditor*)ui->tabWidget->currentWidget())->setEolMode(QsciScintilla::EolUnix);
}


void MainWindow::on_actionWindows_triggered()
{
    ((codeEditor*)ui->tabWidget->currentWidget())->setEolMode(QsciScintilla::EolWindows);
}


void MainWindow::on_actionShow_Linenumbers_2_triggered()
{
    if (ui->actionShow_Linenumbers_2->isChecked()) {
        ((codeEditor*)ui->tabWidget->currentWidget())->setMarginWidth(0,"0000");
    }
    else {
        ((codeEditor*)ui->tabWidget->currentWidget())->setMarginWidth(0,"");
    }
}


void MainWindow::on_actionStatusBar_2_triggered()
{
    if (ui->actionStatusBar_2->isChecked()) {
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
    connect(((codeEditor*)ui->tabWidget->currentWidget()),&QsciScintilla::cursorPositionChanged,
            this,&MainWindow::statusbar);
    ((codeEditor*)ui->tabWidget->currentWidget())->setWrapMode(QsciScintilla::WrapNone);
}


void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    int index = ui->listWidget->row(item);
    ui->tabWidget->setCurrentIndex(index);
}


//syntax highlightning - lexers
void MainWindow::on_actionNormal_triggered()
{
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer();
}


void MainWindow::on_actionBash_triggered()
{
    QsciLexerBash *lexer = new QsciLexerBash();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionBatch_File_triggered()
{
    QsciLexerBatch *lexer = new QsciLexerBatch();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionC_triggered()
{
    QsciLexerCSharp *lexer = new QsciLexerCSharp();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionC_3_triggered()
{
    QsciLexerCPP *lexer = new QsciLexerCPP();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionC_2_triggered()
{
    QsciLexerCPP *lexer = new QsciLexerCPP();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionCSS_triggered()
{
    QsciLexerCSS *lexer = new QsciLexerCSS();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionCMake_triggered()
{
    QsciLexerCMake *lexer = new QsciLexerCMake();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionCoffeeScript_triggered()
{
    QsciLexerCoffeeScript *lexer = new QsciLexerCoffeeScript();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionD_triggered()
{
    QsciLexerD *lexer = new QsciLexerD();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionDiff_triggered()
{
    QsciLexerDiff *lexer = new QsciLexerDiff();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionFortan_triggered()
{
    QsciLexerFortran *lexer = new QsciLexerFortran();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionFortan77_triggered()
{
    QsciLexerFortran77 *lexer = new QsciLexerFortran77();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionHTML_triggered()
{
    QsciLexerHTML *lexer = new QsciLexerHTML();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionJava_triggered()
{
    QsciLexerJava *lexer = new QsciLexerJava();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionJavaScript_triggered()
{
    QsciLexerJavaScript *lexer = new QsciLexerJavaScript();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionJSON_triggered()
{
    QsciLexerJSON *lexer = new QsciLexerJSON();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionLua_triggered()
{
    QsciLexerLua *lexer = new QsciLexerLua();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionMarkDown_triggered()
{
    QsciLexerMarkdown *lexer = new QsciLexerMarkdown();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionMakeFile_triggered()
{
    QsciLexerMakefile *lexer = new QsciLexerMakefile();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionMatLab_triggered()
{
    QsciLexerMatlab *lexer = new QsciLexerMatlab();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionPascal_triggered()
{
    QsciLexerPascal *lexer = new QsciLexerPascal();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionPython_triggered()
{
    QsciLexerPython *lexer = new QsciLexerPython();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionPerl_triggered()
{
    QsciLexerPerl *lexer = new QsciLexerPerl();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionProperties_triggered()
{
    QsciLexerProperties *lexer = new QsciLexerProperties();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionRuby_triggered()
{
    QsciLexerRuby *lexer = new QsciLexerRuby();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionSQL_triggered()
{
    QsciLexerSQL *lexer = new QsciLexerSQL();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionTeX_triggered()
{
    QsciLexerTeX *lexer = new QsciLexerTeX();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionXML_triggered()
{
    QsciLexerXML *lexer = new QsciLexerXML();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


void MainWindow::on_actionYAML_triggered()
{
    QsciLexerYAML *lexer = new QsciLexerYAML();
    ((codeEditor*)ui->tabWidget->currentWidget())->setLexer(lexer);
}


