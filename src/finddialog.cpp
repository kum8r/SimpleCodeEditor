#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget *parent) : QDialog(parent),
    ui(new Ui::findDialog)
{
    ui->setupUi(this);
    ui->widget->hide();
    ui->widget_2->hide();
    wholeword = false;
    casesensitive = false;
    regexp = false;
}

FindDialog::~FindDialog()
{
    delete ui;
}


void FindDialog::on_FindBtn_clicked()
{
    wholeword = ui->woChkBox->isChecked();
    casesensitive = ui->csChkBox->isChecked();
    regexp = ui->reChkBox->isChecked();
    emit findButton_clicked(ui->findString->text());
}


void FindDialog::on_FindPrevBtn_clicked()
{
    wholeword = ui->woChkBox->isChecked();
    casesensitive = ui->csChkBox->isChecked();
    regexp = ui->reChkBox->isChecked();
    emit findPrev_clicked(ui->findString->text());
}


void FindDialog::on_replaceBtn_clicked()
{
    emit replace_clicked(ui->replaceText->text());
}


void FindDialog::on_replaceAllBtn_clicked()
{
    emit replaceAll_clicked(ui->findString->text(),ui->replaceText->text());
}


void FindDialog::on_findCloseBtn_clicked()
{
    ui->findString->clear();
    ui->replaceText->clear();
    emit closeFindDialog();
}


void FindDialog::on_replaceCloseBtn_clicked()
{
    ui->replaceText->clear();
    ui->widget->hide();
}

void FindDialog::showreplaceWidget()
{
    ui->widget->show();
}

void FindDialog::hidereplaceWidget()
{
    ui->widget->hide();
}


void FindDialog::setReplaceString(const QString &value)
{
    replaceString = value;
}


void FindDialog::setFindString(const QString &value)
{
    findString = value;
}


QString FindDialog::getReplaceString()
{
    setReplaceString(ui->replaceText->text());
    return replaceString;
}


QString FindDialog::getFindString()
{
    setFindString(ui->findString->text());
    return findString;
}

void FindDialog::on_findString_returnPressed()
{
    wholeword = ui->woChkBox->isChecked();
    casesensitive = ui->csChkBox->isChecked();
    regexp = ui->reChkBox->isChecked();
    emit findButton_clicked(ui->findString->text());
}

void FindDialog::on_findString_textChanged(const QString &arg1)
{
    emit findStringChanged();
}

void FindDialog::on_AdvacndBtn_clicked()
{
    ui->widget_2->show();
}

bool FindDialog::getWholeword() const
{
    return wholeword;
}

bool FindDialog::getCasesensitive() const
{
    return casesensitive;
}

bool FindDialog::getRegexp() const
{
    return regexp;
}
