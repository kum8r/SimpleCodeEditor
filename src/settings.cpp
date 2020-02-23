#include "settings.h"
#include "ui_settings.h"

#include <QDebug>

Settings::Settings(QWidget *parent) : QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    mySettings = new QSettings ("kumar","SimpleCodeEditor",this);
    loadSettings();
}

Settings::~Settings()
{
    delete ui;
}

void Settings::loadSettings()
{
    ui->fontComboBox->setCurrentFont(QFont(mySettings->value("font").toString()));
    ui->caretWidth->setCurrentIndex(mySettings->value("caretWidth").toInt());
    ui->fontSize->setText(mySettings->value("fontSize").toString());
    ui->tabsize->setText(mySettings->value("tabSize").toString());
    if (mySettings->value("autoIndent").toBool())
    {
        ui->autoIndent->setChecked(true);
    }
    else
    {
        ui->autoIndent->setChecked(false);
    }

    if (mySettings->value("autoComplete").toBool())
    {
        ui->autoComp->setChecked(true);
    }
    else
    {
        ui->autoComp->setChecked(false);
    }

    if (mySettings->value("wordWrap").toBool())
    {
        ui->wordwrap->setChecked(true);
    }
    else
    {
        ui->wordwrap->setChecked(false);
    }

    if (mySettings->value("lineNumber").toBool())
    {
        ui->showLinenum->setChecked(true);
    }
    else
    {
        ui->showLinenum->setChecked(false);
    }

    if (mySettings->value("matchBracket").toBool())
    {
        ui->matchBrackts->setChecked(true);
    }
    else
    {
        ui->matchBrackts->setChecked(false);
    }

    if (mySettings->value("autoComplete").toBool())
    {
        ui->autoComp->setChecked(true);
    }
    else
    {
        ui->autoComp->setChecked(false);
    }
}

void Settings::saveStartUpSettings(QWidget *parent)
{

}



void Settings::on_comboBox_currentIndexChanged(int index)
{
    mySettings->setValue("caretWidth",index);
}


void Settings::on_saveButton_clicked()
{
    mySettings->setValue("font",ui->fontComboBox->currentFont().toString());
    mySettings->setValue("fontSize",ui->fontSize->text().toInt());
    mySettings->setValue("tabSize",ui->tabsize->text().toInt());
    mySettings->setValue("autoIndent",ui->autoIndent->isChecked());
    mySettings->setValue("matchBracket",ui->matchBrackts->isChecked());
    mySettings->setValue("lineNumbers",ui->showLinenum->isChecked());
    mySettings->setValue("wordWrap",ui->wordwrap->isChecked());
    mySettings->setValue("autoComplete",ui->autoComp->isChecked());
    this->close();
}

void Settings::on_cancelButton_clicked()
{
    this->close();
}
