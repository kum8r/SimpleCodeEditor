#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //removing the space between layouts in mainwindow
    ui->verticalLayout->setSpacing(0);
    ui->verticalLayout->setMargin(0);
    ui->verticalLayout->setContentsMargins(0,0,0,0);
    ui->gridLayout->setSpacing(0);
    ui->gridLayout->setMargin(0);
    ui->gridLayout->setContentsMargins(0,0,0,0);
    ui->gridLayout_2->setSpacing(0);
    ui->gridLayout_2->setMargin(0);
    ui->gridLayout_2->setContentsMargins(0,0,0,0);
    ui->splitter->setStretchFactor(1,1);
    ui->splitter->setHandleWidth(0);

    //removing the space between layout in find widget
    ui->horizontalLayout->setSpacing(0);
    ui->horizontalLayout->setMargin(0);
    ui->horizontalLayout->setContentsMargins(0,0,0,0);
    ui->horizontalLayout_2->setSpacing(0);
    ui->horizontalLayout_2->setMargin(0);
    ui->horizontalLayout_2->setContentsMargins(0,0,0,0);
    ui->verticalLayout_2->setSpacing(0);
    ui->verticalLayout_2->setMargin(0);
    ui->verticalLayout_2->setContentsMargins(0,0,0,0);

    //find widget
    ui->widget_2->hide();
    ui->widget_4->hide();

    // line ending
    lineending = new QActionGroup (this);
    lineending->addAction(ui->actionWindows);
    lineending->addAction(ui->actionUnix);
    lineending->addAction(ui->actionMac);

    //statusBar
    label = new QLabel();
    ui->statusBar->addWidget(label);
    on_actionNew_triggered();


    //timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(statusbar()));
    timer->start(1000);

    statusbar();
}

MainWindow::~MainWindow() {
    delete ui;
}

int MainWindow::newtab(QString tabname) {
    TextEdit *editor = new TextEdit;
    tabs.append(editor);
    int tabindex = ui->tabWidget->addTab(editor,tabname);
    ui->tabWidget->setCurrentIndex(tabindex);
    return tabindex;
}

void MainWindow::setEOL() {
    if (QSysInfo::productType() == "windows" | QSysInfo::productType() == "winrt") {
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

QString MainWindow::settabname() {

}

void MainWindow::statusbar() {
    int colpos = tabs[ui->tabWidget->currentIndex()]->getColpos();
    int linecount = tabs[ui->tabWidget->currentIndex()]->getLinecount();
    label->setText("Col: " + QString::number(colpos) + " Line: " + QString::number(linecount));
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
    newtab(filename);
    setEOL();
}

void MainWindow::on_actionOpen_triggered() {
    int tabindex = newtab("");
    if (tabs[tabindex]->openfile()) {
        filepath = tabs[tabindex]->filePath();
        for (int i = 0; i < filelist.length(); i++) {
            if (filelist[i] == filepath) {
                ui->tabWidget->setCurrentIndex(i);
                ui->tabWidget->removeTab(tabindex);
                return;
            }
        }
        filename = tabs[tabindex]->fileName();
        ui->tabWidget->setTabText(tabindex,filename);
    }
    filelist.append(filepath);
    setEOL();
}

void MainWindow::on_actionSave_triggered() {
    //if two file name are same it will be confused
    int currentindex = ui->tabWidget->currentIndex();
    if (tabs[currentindex]->saveFile()) {
        filename = tabs[currentindex]->filename;
        ui->tabWidget->setTabText(currentindex,filename);
    }
    else {
        ui->tabWidget->removeTab(currentindex);
    }
}

void MainWindow::on_actionSave_As_triggered() {
    int currentindex = ui->tabWidget->currentIndex();
    if (tabs[currentindex]->saveFileas()) {
        QString filename = tabs[currentindex]->filename;
        ui->tabWidget->setTabText(currentindex,filename);
    }
    else {
        ui->tabWidget->removeTab(currentindex);
    }
}

void MainWindow::on_actionClose_triggered() {
    if (tabs[ui->tabWidget->currentIndex()]->close()) {
        ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
    }
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

void MainWindow::on_actionReload_triggered() {
    tabs[ui->tabWidget->currentIndex()]->reload();
}

void MainWindow::on_actionUndo_triggered() {
    tabs[ui->tabWidget->currentIndex()]->undo();
}

void MainWindow::on_actionRedo_triggered() {
    tabs[ui->tabWidget->currentIndex()]->redo();
}

void MainWindow::on_actionNew_Window_triggered() {
    newwindow = new MainWindow ();
    newwindow->show();
}

void MainWindow::on_actionClose_Window_triggered() {
    this->close();
}

void MainWindow::on_actionClose_All_Files_triggered() {
    //close files are not working properly
    //except one tab is not closing
    int tabcount = ui->tabWidget->count();
 //   QMessageBox::about(this,QString::number(tabcount),QString::number(ui->tabWidget->currentIndex()));

   int i = 0;
    while (i < tabcount) {
        ui->tabWidget->setCurrentIndex(i);
        QMessageBox::about(this,QString::number(i),ui->tabWidget->tabText(i));
//        if (tabs[i]->closeAllFiles()) {
//            ui->tabWidget->removeTab(i);

//        }
        i =i +1;
    }

}

void MainWindow::on_actionFind_triggered() {
    ui->widget_2->show();
}

void MainWindow::on_pushButton_clicked() {
    QString searchtext = ui->lineEdit_2->text();
    tabs[ui->tabWidget->currentIndex()]->findText(searchtext);
}

void MainWindow::on_actionReplace_triggered() {
    ui->widget_4->show();
    QString replacetext = ui->lineEdit_3->text();
    tabs[ui->tabWidget->currentIndex()]->replaceText(replacetext);
}

void MainWindow::on_actionSidebar_triggered() {
    if (ui->actionSidebar->isChecked()) {
        ui->widget->show();
    }
    else {
        ui->widget->hide();
    }
}

void MainWindow::on_actionStatusbar_triggered() {
    if (ui->actionStatusbar->isChecked()) {
        ui->statusBar->show();
    }
    else {
        ui->statusBar->hide();
    }
}

void MainWindow::on_actionToolbar_triggered() {
    if (ui->actionToolbar->isChecked()) {
        ui->mainToolBar->show();
    }
    else {
        ui->mainToolBar->hide();
    }
}


void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this,tr("About SimpleCodeEditor"),tr("SimpleCodeEditor \n @kumar"));
}

void MainWindow::on_actionAbout_QT_triggered() {
    QMessageBox::aboutQt(this,tr("About QT"));
}

void MainWindow::on_actionFind_Next_triggered() {
    tabs[ui->tabWidget->currentIndex()]->findNext();
}

void MainWindow::on_actionReplace_All_triggered() {
    tabs[ui->tabWidget->currentIndex()]->replaceAll(ui->lineEdit_3->text());
}

void MainWindow::on_pushButton_3_clicked() {
    QString replacetext = ui->lineEdit_3->text();
    tabs[ui->tabWidget->currentIndex()]->replaceText(replacetext);
}

void MainWindow::on_pushButton_4_clicked() {
    tabs[ui->tabWidget->currentIndex()]->replaceAll(ui->lineEdit_3->text());
}

void MainWindow::on_pushButton_2_clicked() {
    tabs[ui->tabWidget->currentIndex()]->findAll(ui->lineEdit_2->text());
}

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

void MainWindow::on_actionFind_All_triggered() {
    tabs[ui->tabWidget->currentIndex()]->findAll(ui->lineEdit_2->text());
}

void MainWindow::on_actionSelect_All_triggered() {
    tabs[ui->tabWidget->currentIndex()]->selectAll();
}

void MainWindow::on_actionDeselect_triggered() {
    tabs[ui->tabWidget->currentIndex()]->deselect();
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
    tabs[ui->tabWidget->currentIndex()]->changetoCpp();
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

void MainWindow::on_actionQuit_triggered() {
    qApp->exit();
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

void MainWindow::on_listView_doubleClicked(const QModelIndex &index) {
    int tabindex = newtab("");
    QString filepath = filemodel->filePath(index);
    if (tabs[tabindex]->getfile(filepath)) {
        QString filename = tabs[tabindex]->filename;
        ui->tabWidget->setTabText(ui->tabWidget->currentIndex(),filename);
    }
    setEOL();
}

void MainWindow::on_actionShow_Linenumbers_triggered() {
    if (ui->actionShow_Linenumbers->isChecked()) {
        tabs[ui->tabWidget->currentIndex()]->showLinenumbers();
    }
    else {
        tabs[ui->tabWidget->currentIndex()]->hideLinenumbers();
    }
}

void MainWindow::on_tabWidget_tabCloseRequested(int index) {
    if (tabs[index]->close() == true) {
        ui->tabWidget->removeTab(index);
    }
}

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
