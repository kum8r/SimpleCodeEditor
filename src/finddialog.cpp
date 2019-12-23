#include "finddialog.h"
#include "ui_finddialog.h"

findDialog::findDialog(QWidget *parent) : QDialog(parent),
    ui(new Ui::findDialog)
{
    ui->setupUi(this);
    ui->widget->hide();
    ui->widget_2->hide();
    wholeword = false;
    casesensitive = false;
    regexp = false;
}

findDialog::~findDialog()
{
    delete ui;
}


void findDialog::on_FindBtn_clicked()
{
    wholeword = ui->woChkBox->isChecked();
    casesensitive = ui->csChkBox->isChecked();
    regexp = ui->reChkBox->isChecked();
    emit findButton_clicked(ui->findString->text());
}


void findDialog::on_FindPrevBtn_clicked()
{
    wholeword = ui->woChkBox->isChecked();
    casesensitive = ui->csChkBox->isChecked();
    regexp = ui->reChkBox->isChecked();
    emit findPrev_clicked(ui->findString->text());
}


void findDialog::on_replaceBtn_clicked()
{
    emit replace_clicked(ui->replaceText->text());
}


void findDialog::on_replaceAllBtn_clicked()
{
    emit replaceAll_clicked(ui->findString->text(),ui->replaceText->text());
}


void findDialog::on_findCloseBtn_clicked()
{
    ui->findString->clear();
    ui->replaceText->clear();
    emit closeFindDialog();
}


void findDialog::on_replaceCloseBtn_clicked()
{
    ui->replaceText->clear();
    ui->widget->hide();
}

void findDialog::showreplaceWidget()
{
    ui->widget->show();
}

void findDialog::hidereplaceWidget()
{
    ui->widget->hide();
}


void findDialog::setReplaceString(const QString &value)
{
    replaceString = value;
}


void findDialog::setFindString(const QString &value)
{
    findString = value;
}


QString findDialog::getReplaceString()
{
    setReplaceString(ui->replaceText->text());
    return replaceString;
}


QString findDialog::getFindString()
{
    setFindString(ui->findString->text());
    return findString;
}

void findDialog::on_findString_returnPressed()
{
    wholeword = ui->woChkBox->isChecked();
    casesensitive = ui->csChkBox->isChecked();
    regexp = ui->reChkBox->isChecked();
    emit findButton_clicked(ui->findString->text());
}

void findDialog::on_findString_textChanged(const QString &arg1)
{
    emit findStringChanged();
}

void findDialog::on_AdvacndBtn_clicked()
{
    ui->widget_2->show();
}

bool findDialog::getWholeword() const
{
    return wholeword;
}

bool findDialog::getCasesensitive() const
{
    return casesensitive;
}

bool findDialog::getRegexp() const
{
    return regexp;
}
