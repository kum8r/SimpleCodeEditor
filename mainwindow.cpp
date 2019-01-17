#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //set splitter stretch
    ui->splitter->setStretchFactor(1,1);

    //find widget
    ui->widget_2->hide();
    ui->widget_4->hide();

    // line ending
    lineending = new QActionGroup (this);
    lineending->addAction(ui->actionWindows);
    lineending->addAction(ui->actionUnix);
    lineending->addAction(ui->actionMac);

    //statusbar
    label = new QLabel();
    ui->statusBar->addWidget(label);

    on_actionNew_triggered();

}

MainWindow::~MainWindow() {
    delete ui;
}

int MainWindow::newTab(QString tabname) {
    TextEdit *editor = new TextEdit;
    tabs.append(editor);
    int tabindex = ui->tabWidget->addTab(editor,tabname);
    ui->tabWidget->setCurrentIndex(tabindex);
    return tabindex;
}

void MainWindow::setEOL() {
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

void MainWindow::disableMenu() {
    ui->actionSave->setDisabled(true);
    ui->actionSave_As->setDisabled(true);
    ui->actionClose->setDisabled(true);
    ui->actionClose_All_Files->setDisabled(true);
    ui->actionReload->setDisabled(true);
    ui->actionUndo->setDisabled(true);
    ui->actionRedo->setDisabled(true);
    ui->actionCut->setDisabled(true);
    ui->actionCopy->setDisabled(true);
    ui->actionPaste->setDisabled(true);
    ui->actionSelect_All->setDisabled(true);
    ui->actionDeselect->setDisabled(true);
    ui->actionFind->setDisabled(true);
    ui->actionFind_All->setDisabled(true);
    ui->actionFind_Next->setDisabled(true);
    ui->actionReplace->setDisabled(true);
    ui->actionReplace_All->setDisabled(true);
    ui->actionShow_Linenumbers->setDisabled(true);
    ui->actionShow_Tabs->setDisabled(true);
    ui->menuSyntax->setDisabled(true);
    ui->menuLine_Ending->setDisabled(true);
    ui->actionChange_Font->setDisabled(true);
    ui->actionWordWrap->setDisabled(true);
}

void MainWindow::enableMenu() {
    ui->actionSave->setEnabled(true);
    ui->actionSave_As->setEnabled(true);
    ui->actionClose->setEnabled(true);
    ui->actionClose_All_Files->setEnabled(true);
    ui->actionReload->setEnabled(true);
    ui->actionUndo->setEnabled(true);
    ui->actionRedo->setEnabled(true);
    ui->actionCut->setEnabled(true);
    ui->actionCopy->setEnabled(true);
    ui->actionPaste->setEnabled(true);
    ui->actionSelect_All->setEnabled(true);
    ui->actionDeselect->setEnabled(true);
    ui->actionFind->setEnabled(true);
    ui->actionFind_All->setEnabled(true);
    ui->actionFind_Next->setEnabled(true);
    ui->actionReplace->setEnabled(true);
    ui->actionReplace_All->setEnabled(true);
    ui->actionShow_Linenumbers->setEnabled(true);
    ui->actionShow_Tabs->setEnabled(true);
    ui->menuSyntax->setEnabled(true);
    ui->menuLine_Ending->setEnabled(true);
    ui->actionChange_Font->setEnabled(true);
    ui->actionWordWrap->setEnabled(true);
}

void MainWindow::filetype(QString filepath) {
    QFileInfo fileinfo(filepath);
    QString extension = fileinfo.completeSuffix();
    if ((extension == "cpp") | (extension == "c") | (extension == "h") | (extension == "cc") | (extension == "cxx")
             | (extension == "hpp") | (extension == "hxx")) {
        on_actionC_2_triggered();
    }
    else if ((extension == "cs")) {
        on_actionC_triggered();
    }
    else if ((extension == "cmake")) {
        on_actionCMake_triggered();
    }
    else if ((extension == "litcoffee")) {
        on_actionCoffeeScript_triggered();
    }
    else if ((extension == "css")) {
        on_actionCSS_triggered();
    }
    else if ((extension == "d")) {
        on_actionD_triggered();
    }
    else if ((extension == "diff") | (extension == "patch")) {
        on_actionDiff_triggered();
    }
    else if ((extension == "f") | (extension == "for") | (extension == "f90")| (extension == "f95") | (extension == "f2k")) {
        on_actionFortan_triggered();
    }
    else if ((extension == "f77")) {
        on_actionFortan77_triggered();
    }
    else if ((extension == "htm") | (extension == "html") | (extension == "shtml") | (extension == "xhtml")| (extension == "hta")) {
        on_actionHTML_triggered();
    }
    else if ((extension == "java")) {
        on_actionJava_triggered();
    }
    else if ((extension == "js")) {
        on_actionJavaScript_triggered();
    }
    else if ((extension == "lua")) {
        on_actionLua_triggered();
    }
    else if ((extension == "mak")) {
        on_actionMakeFile_triggered();
    }
    else if ((extension == "m")) {
        on_actionMatLab_triggered();
    }
    else if ((extension == "pas") | (extension == "inc")) {
        on_actionPascal_triggered();
    }
    else if ((extension == "pl") | (extension == "pm") | (extension == "plx")) {
        on_actionPerl_triggered();
    }
    else if ((extension == "ps")) {
        on_actionPascal_triggered();
    }
    else if ((extension == "properties")) {
       on_actionProperties_triggered();
    }
    else if ((extension == "py") | (extension == "pyw")) {
        on_actionPython_triggered();
    }
    else if ((extension == "rb") | (extension == "rbw")) {
        on_actionRuby_triggered();
    }
    else if ((extension == "sql")) {
        on_actionSQL_triggered();
    }
    else if ((extension == "tex")) {
        on_actionTeX_triggered();
    }
    else if ((extension == "xml") | (extension == "xsml") | (extension == "xsl") | (extension == "kml") | (extension == "wsdl") | (extension == "xlf") | (extension == "xliff")) {
        on_actionXML_triggered();
    }
    else if (extension == "yml") {
        on_actionYAML_triggered();
    }
    else {
        on_actionNormal_triggered();
    }
}

void MainWindow::statusbar(int line,int index) {
    label->setText("Col: " + QString::number(line) + " Line: " + QString::number(index));
}

void MainWindow::on_actionNew_triggered() {
    QString filename = "untitled";
    int j = 1;
    for (int i = 0; i < filelist.length(); i++) {
        if (filelist[i] == filename) {
            filename = "untitled " + QString::number(j);
            j++;
            i = 0;
        }
    }
    filelist.append(filename);
    newTab(filename);
    setEOL();
}

void MainWindow::on_actionOpen_triggered() {
    int tabindex = newTab("");
    if (tabs[tabindex]->openfile()) {
        filepath = tabs[tabindex]->filePath();
        for (int i = 0; i < filelist.length(); i++) {
            if (filelist[i] == filepath) {
                ui->tabWidget->setCurrentIndex(i);
                ui->tabWidget->removeTab(tabindex);
                tabs.removeAt(tabindex);
                setEOL();
                return;
            }
        }
        filename = tabs[tabindex]->fileName();
        for (int i = 0; i < ui->tabWidget->count(); i++) {
            QString tabname = ui->tabWidget->tabText(i);
             for (int i = 0; i < tabname.length(); i++) {
                 if (tabname[i] == '&') {
                     tabname.remove(i,1);
                 }
             }

                 if (filename == tabname) {
                    QFileInfo fileinfo(filepath);
                    QDir dir = fileinfo.dir();
                    filename = dir.dirName() + "/" + filename;
                    ui->tabWidget->setTabText(tabindex,filename);
                    QStringList result = filelist.filter(tabname);
                    QFileInfo fileinfo1(result[0]);
                    QDir dir1 = fileinfo1.dir();
                    tabname = dir1.dirName() + "/" + tabname;
                    ui->tabWidget->setTabText(i,tabname);
                    filelist.append(filepath);
                    setEOL();
                    filetype(filepath);
                    return;
                 }

    }
    filename = tabs[tabindex]->fileName();
    ui->tabWidget->setTabText(tabindex,filename);
    filelist.append(filepath);
    filetype(filepath);
    setEOL();
    }
    else {
        QMessageBox::about(this,tr("Error"),tr("Not Opened"));
        ui->tabWidget->removeTab(tabindex);
        tabs.removeAt(tabindex);
    }
}


void MainWindow::on_actionOpen_Directory_triggered() {
    QString filedir = QFileDialog::getExistingDirectory(this,tr("Open Directory"),QDir::homePath());
    if (!filedir.isEmpty()) {
        filemodel = new QFileSystemModel();
        filemodel->setRootPath(filedir);
        ui->listView->setModel(filemodel);
        ui->listView->setRootIndex(filemodel->index(filedir));
    }
}

// opening file from filebrowser sidebar by double clicking
void MainWindow::on_listView_doubleClicked(const QModelIndex &index) {
    int tabindex = newTab("");
    QString filepath = filemodel->filePath(index);
    for (int i = 0; i < filelist.length(); i++) {
        if (filelist[i] == filepath) {
            ui->tabWidget->setCurrentIndex(i);
            ui->tabWidget->removeTab(tabindex);
            tabs.removeAt(tabindex);
            setEOL();
            return;
        }
    }
    if (tabs[tabindex]->getfile(filepath)) {
        QString filename = tabs[tabindex]->fileName();
        for (int i = 0; i < ui->tabWidget->count(); i++) {
            QString tabname = ui->tabWidget->tabText(i);
             for (int i = 0; i < tabname.length(); i++) {
                 if (tabname[i] == '&') {
                     tabname.remove(i,1);
                 }
             }
                 if (filename == tabname) {
                    QFileInfo fileinfo(filepath);
                    QDir dir = fileinfo.dir();
                    filename = dir.dirName() + "/" + filename;
                    ui->tabWidget->setTabText(tabindex,filename);
                    QStringList result = filelist.filter(tabname);
                    QFileInfo fileinfo1(result[0]);
                    QDir dir1 = fileinfo1.dir();
                    tabname = dir1.dirName() + "/" + tabname;
                    ui->tabWidget->setTabText(i,tabname);
                    filelist.append(filepath);
                    filetype(filepath);
                    setEOL();
                    return;
                 }
    }
    filename = tabs[tabindex]->fileName();
    ui->tabWidget->setTabText(tabindex,filename);
    filelist.append(filepath);
    filetype(filepath);
    setEOL();
    }
    else {
        QMessageBox::about(this,tr("Error"),tr("Not Opened"));
        ui->tabWidget->removeTab(tabindex);
        tabs.removeAt(tabindex);
    }
}

void MainWindow::on_actionSave_triggered() {
    int currentindex = ui->tabWidget->currentIndex();
    if (tabs[currentindex]->saveFile()) {
        filename = tabs[currentindex]->filename;
        ui->tabWidget->setTabText(currentindex,filename);
        filepath = tabs[currentindex]->filePath();
        filetype(filepath);
    }
    else {
        tabs.removeAt(currentindex);
        ui->tabWidget->removeTab(currentindex);
    }
}

void MainWindow::on_actionSave_As_triggered() {
    int currentindex = ui->tabWidget->currentIndex();
    if (tabs[currentindex]->saveFileas()) {
        QString filename = tabs[currentindex]->filename;
        ui->tabWidget->setTabText(currentindex,filename);QString
        filepath = tabs[currentindex]->filePath();
        filetype(filepath);
    }
    else {
        tabs.removeAt(currentindex);
        ui->tabWidget->removeTab(currentindex);
    }
}

void MainWindow::on_actionReload_triggered() {
    if (tabs[ui->tabWidget->currentIndex()]->returnchanged()) {
     QMessageBox::StandardButton ask = QMessageBox::question(this,tr("reload"),tr("The Document is modified. do you"
                                                                                  "want to save"),
                                                             QMessageBox::Yes | QMessageBox::No ,
                                                             QMessageBox::No);
     if (ask == QMessageBox::Yes) {
         tabs[ui->tabWidget->currentIndex()]->reload();
     }
    }
    else {
        tabs[ui->tabWidget->currentIndex()]->reload();
    }
}

void MainWindow::on_tabWidget_tabCloseRequested(int index) {
    if (tabs[index]->returnchanged()) {
        QMessageBox::StandardButton ask = QMessageBox::question(this,tr("Save before close "),
                                                                tr("Do you want to save "),
                                                                QMessageBox::Yes | QMessageBox::No ,
                                                                QMessageBox::No);
        if (ask == QMessageBox::Yes) {
            tabs[index]->saveFile();
            QString tabname = ui->tabWidget->tabText(index);
             for (int i = 0; i < tabname.length(); i++) {
                 if (tabname[i] == '&') {
                     tabname.remove(i,1);
                 }
             }
            QStringList result = filelist.filter(tabname);
            filelist.removeOne(result[0]);
            ui->tabWidget->removeTab(index);
            tabs.removeAt(index);
        }
        else if (ask == QMessageBox::No) {
            QString tabname = ui->tabWidget->tabText(index);
             for (int i = 0; i < tabname.length(); i++) {
                 if (tabname[i] == '&') {
                     tabname.remove(i,1);
                 }
             }
            QStringList result = filelist.filter(tabname);
            filelist.removeOne(result[0]);
            ui->tabWidget->removeTab(index);
            tabs.removeAt(index);
        }
    }
    else {
        QString tabname = ui->tabWidget->tabText(index);
         for (int i = 0; i < tabname.length(); i++) {
             if (tabname[i] == '&') {
                 tabname.remove(i,1);
             }
         }
        QStringList result = filelist.filter(tabname);
        filelist.removeOne(result[0]);
        ui->tabWidget->removeTab(index);
        tabs.removeAt(index);
    }
}

void MainWindow::on_actionClose_triggered() {
    if (tabs[ui->tabWidget->currentIndex()]->returnchanged()) {
        QMessageBox::StandardButton ask = QMessageBox::question(this,tr("Save before close "),
                                                                tr("Do you want to save "),
                                                                QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel ,
                                                                QMessageBox::Cancel);
        if (ask == QMessageBox::Yes) {
            tabs[ui->tabWidget->currentIndex()]->saveFile();
            QString tabname = ui->tabWidget->tabText(ui->tabWidget->currentIndex());
             for (int i = 0; i < tabname.length(); i++) {
                 if (tabname[i] == '&') {
                     tabname.remove(i,1);
                 }
             }
            QStringList result = filelist.filter(tabname);
            filelist.removeOne(result[0]);
            ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
            tabs.removeAt(ui->tabWidget->currentIndex());
        }
        else if (ask == QMessageBox::No) {
            QString tabname = ui->tabWidget->tabText(ui->tabWidget->currentIndex());
             for (int i = 0; i < tabname.length(); i++) {
                 if (tabname[i] == '&') {
                     tabname.remove(i,1);
                 }
             }
            QStringList result = filelist.filter(tabname);
            filelist.removeOne(result[0]);
            ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
            tabs.removeAt(ui->tabWidget->currentIndex());
        }
    }
}

void MainWindow::on_actionClose_All_Files_triggered() {
    for (int i = 0;i <= ui->tabWidget->count(); i++) {
        i =0;
        ui->tabWidget->setCurrentIndex(i);
        if (tabs[i]->returnchanged()) {
            QMessageBox::StandardButton ask = QMessageBox::question(this,tr("Save before exit ")+ ui->tabWidget->tabText(i),
                                                                    tr("Do you want to save ")+ ui->tabWidget->tabText(i),
                                                                    QMessageBox::Yes | QMessageBox::No , QMessageBox::Yes);
            if (ask == QMessageBox::Yes) {
                tabs[i]->saveFile();
                ui->tabWidget->removeTab(i);
                tabs.removeAt(i);
            }
            else if (ask == QMessageBox::No) {
                ui->tabWidget->removeTab(i);
                tabs.removeAt(i);
            }
        }
        else {
            ui->tabWidget->removeTab(i);
            tabs.removeAt(i);
        }
    }
}

void MainWindow::on_actionNew_Window_triggered() {
    newwindow = new MainWindow ();
    newwindow->show();
}

void MainWindow::on_actionClose_Window_triggered() {
    on_actionClose_All_Files_triggered();
    this->close();
}

void MainWindow::on_actionQuit_triggered() {
    on_actionClose_All_Files_triggered();
    qApp->exit();
}

void MainWindow::on_actionCut_triggered() {
    tabs[ui->tabWidget->currentIndex()]->cut();
}

void MainWindow::on_actionCopy_triggered() {
    tabs[ui->tabWidget->currentIndex()]->copy();
}

void MainWindow::on_actionPaste_triggered() {
    tabs[ui->tabWidget->currentIndex()]->paste();
}

void MainWindow::on_actionUndo_triggered() {
    tabs[ui->tabWidget->currentIndex()]->undo();
}

void MainWindow::on_actionRedo_triggered() {
    tabs[ui->tabWidget->currentIndex()]->redo();
}

void MainWindow::on_actionSelect_All_triggered() {
    tabs[ui->tabWidget->currentIndex()]->selectAll();
}

void MainWindow::on_actionDeselect_triggered() {
    tabs[ui->tabWidget->currentIndex()]->deselect();
}

void MainWindow::on_actionFind_triggered() {
    ui->widget_2->show();
    ui->widget_3->show();
}

//find text by clicking find button
void MainWindow::on_pushButton_clicked() {
    QString searchtext = ui->lineEdit_2->text();
    tabs[ui->tabWidget->currentIndex()]->findText(searchtext);
}

//find next
void MainWindow::on_actionFind_Next_triggered() {
    tabs[ui->tabWidget->currentIndex()]->findNext();
}

//find all
void MainWindow::on_actionFind_All_triggered() {
    tabs[ui->tabWidget->currentIndex()]->findAll(ui->lineEdit_2->text());
}

//find all by clicking button
void MainWindow::on_pushButton_2_clicked() {
    tabs[ui->tabWidget->currentIndex()]->findAll(ui->lineEdit_2->text());
}

//find prev by click button
void MainWindow::on_pushButton_5_clicked() {
    tabs[ui->tabWidget->currentIndex()]->findPrev(ui->lineEdit_2->text());
}

//close the find and replace widget
void MainWindow::on_toolButton_clicked() {
    ui->widget_3->hide();
    ui->widget_4->hide();
    ui->widget_2->hide();
}

void MainWindow::on_actionReplace_triggered() {
    ui->widget_2->show();
    ui->widget_3->show();
    ui->widget_4->show();
    QString replacetext = ui->lineEdit_3->text();
    tabs[ui->tabWidget->currentIndex()]->replaceText(replacetext);
}

//replace text by clicking replace button
void MainWindow::on_pushButton_3_clicked() {
    QString replacetext = ui->lineEdit_3->text();
    tabs[ui->tabWidget->currentIndex()]->replaceText(replacetext);
}

//replace all the selected text
void MainWindow::on_actionReplace_All_triggered() {
    tabs[ui->tabWidget->currentIndex()]->replaceAll(ui->lineEdit_3->text());
}

//replace all by clicking button
void MainWindow::on_pushButton_4_clicked() {
    tabs[ui->tabWidget->currentIndex()]->replaceAll(ui->lineEdit_3->text());
}

//hide the replace window
void MainWindow::on_toolButton_2_clicked() {
    ui->widget_4->hide();
}

//show or hide the filebrowser
void MainWindow::on_actionSidebar_triggered() {
    if (ui->actionSidebar->isChecked()) {
        ui->widget->show();
    }
    else {
        ui->widget->hide();
    }
}

//show or hide the statusbar
void MainWindow::on_actionStatusbar_triggered() {
    if (ui->actionStatusbar->isChecked()) {
        ui->statusBar->show();
    }
    else {
        ui->statusBar->hide();
    }
}

//show or hide the toolbar
void MainWindow::on_actionToolbar_triggered() {
    if (ui->actionToolbar->isChecked()) {
        ui->mainToolBar->show();
    }
    else {
        ui->mainToolBar->hide();
    }
}

//show or hide the tabbar
void MainWindow::on_actionShow_Tabs_triggered() {
    if (ui->actionShow_Tabs->isChecked()) {
        QTabBar *tabBar = ui->tabWidget->findChild<QTabBar *>();
        tabBar->show();
    }
    else {
        QTabBar *tabBar = ui->tabWidget->findChild<QTabBar *>();
        tabBar->hide();
    }
}

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this,tr("About SimpleCodeEditor"),tr("SimpleCodeEditor \n @kumar"));
}

void MainWindow::on_actionAbout_QT_triggered() {
    QMessageBox::aboutQt(this,tr("About Qt"));
}

//setEOL - End Of line
void MainWindow::on_actionWindows_triggered() {
    if (ui->actionWindows->isChecked()) {
        tabs[ui->tabWidget->currentIndex()]->windowsEOL();
    }
}

void MainWindow::on_actionUnix_triggered() {
    if (ui->actionUnix->isChecked()) {
        tabs[ui->tabWidget->currentIndex()]->unixEOL();
    }
}

void MainWindow::on_actionMac_triggered() {
    if (ui->actionMac->isChecked()) {
        tabs[ui->tabWidget->currentIndex()]->osxEOL();
    }
}

//Set Lexer - Syntax
void MainWindow::on_actionC_2_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoCpp();
}

void MainWindow::on_actionBash_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoBash();
}

void MainWindow::on_actionBatch_File_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoBatch();
}

void MainWindow::on_actionCoffeeScript_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoCScript();
}

void MainWindow::on_actionC_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoCSharp();
}

void MainWindow::on_actionJava_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoJava();
}

void MainWindow::on_actionCSS_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoCSS();
}

void MainWindow::on_actionHTML_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoHTML();
}

void MainWindow::on_actionJavaScript_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoJavascipt();
}

void MainWindow::on_actionJSON_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoJSON();
}

void MainWindow::on_actionMakeFile_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoMakefile();
}

void MainWindow::on_actionMatLab_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoMatlab();
}

void MainWindow::on_actionPascal_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoPascal();
}

void MainWindow::on_actionPython_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoPython();
}

void MainWindow::on_actionCMake_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoCMake();
}

void MainWindow::on_actionFortan_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoFortan();
}

void MainWindow::on_actionXML_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoXML();
}

void MainWindow::on_actionLua_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoLua();
}

void MainWindow::on_actionMarkDown_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoMarkdown();
}

void MainWindow::on_actionPerl_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoPerl();
}

void MainWindow::on_actionRuby_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoRuby();
}

void MainWindow::on_actionSQL_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoSQL();
}

void MainWindow::on_actionTeX_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoTex();
}

void MainWindow::on_actionC_3_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoCpp();
}

void MainWindow::on_actionChange_Font_triggered() {
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);
    if (ok) {
    tabs[ui->tabWidget->currentIndex()]->changeFont(font);
    }
}

void MainWindow::on_actionShow_Linenumbers_triggered() {
    if (ui->actionShow_Linenumbers->isChecked()) {
        tabs[ui->tabWidget->currentIndex()]->showLinenumbers();
    }
    else {
        tabs[ui->tabWidget->currentIndex()]->hideLinenumbers();
    }
}

//search in file browser
void MainWindow::on_lineEdit_returnPressed() {
    ui->listView->keyboardSearch(ui->lineEdit->text());
}

void MainWindow::on_actionWordWrap_triggered() {
    if (ui->actionWordWrap->isChecked()) {
        tabs[ui->tabWidget->currentIndex()]->wordwrap();
    }
    else {
        tabs[ui->tabWidget->currentIndex()]->wordwrapNone();
    }
}

//if current tab is changed
void MainWindow::on_tabWidget_currentChanged(int index) {
    if (index == -1) {
        disableMenu();
    }
    else {
       enableMenu();
       connect(tabs[index],SIGNAL(cursorchanged(int,int)),this,SLOT(statusbar(int,int)));

    }
}

//settings dialog is shown
void MainWindow::on_actionSettings_triggered() {
    Settings *settings = new Settings();
    settings->exec();
}



void MainWindow::on_actionD_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoD();
}

void MainWindow::on_actionFortan77_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoFortan77();
}

void MainWindow::on_actionDiff_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoDiff();
}

void MainWindow::on_actionProperties_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoProp();
}

void MainWindow::on_actionYAML_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoYAML();
}

void MainWindow::on_actionNormal_triggered() {
    tabs[ui->tabWidget->currentIndex()]->changetoNormal();

}
