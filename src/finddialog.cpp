#include "finddialog.h"
#include "ui_finddialog.h"

findDialog::findDialog(QWidget *parent) : QDialog(parent),
    ui(new Ui::findDialog)
{
    ui->setupUi(this);
    ui->widget->hide();
}

findDialog::~findDialog()
{
    delete ui;
}


void findDialog::on_FindBtn_clicked()
{
    emit findButton_clicked(ui->findString->text());
}


void findDialog::on_FindPrevBtn_clicked()
{
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
    emit closeFindDialog();
}


void findDialog::on_replaceCloseBtn_clicked()
{
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
