#include "settings.h"
#include "ui_settings.h"

#include <QDebug>

Settings::Settings(QWidget *parent) : QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    mySettings = new QSettings ("kumar","SimpleCodeEditor",this);
    ui->tabWidget->widget(0)->setLayout(ui->formLayout);
    loadSettings();
}

Settings::~Settings()
{
    delete ui;
}

void Settings::loadSettings()
{
    ui->fontComboBox->setCurrentFont(QFont(mySettings->value("font").toString()));
    ui->comboBox->setCurrentIndex(mySettings->value("caretWidth").toInt());
    ui->lineEdit->setText(mySettings->value("fontSize").toString());
    ui->lineEdit_2->setText(mySettings->value("tabSize").toString());
    if (mySettings->value("autoIndent").toBool())
    {
        ui->checkBox->setChecked(true);
    }
    else
    {
        ui->checkBox->setChecked(false);
    }

    if (mySettings->value("autoComplete").toBool())
    {
        ui->checkBox->setChecked(true);
    }
    else
    {
        ui->checkBox->setChecked(false);
    }

    if (mySettings->value("wordWrap").toBool())
    {
        ui->checkBox->setChecked(true);
    }
    else
    {
        ui->checkBox->setChecked(false);
    }

    if (mySettings->value("lineNumber").toBool())
    {
        ui->checkBox->setChecked(true);
    }
    else
    {
        ui->checkBox->setChecked(false);
    }

    if (mySettings->value("matchBracket").toBool())
    {
        ui->checkBox->setChecked(true);
    }
    else
    {
        ui->checkBox->setChecked(false);
    }

    if (mySettings->value("autoComplete").toBool())
    {
        ui->checkBox->setChecked(true);
    }
    else
    {
        ui->checkBox->setChecked(false);
    }
}



void Settings::on_comboBox_currentIndexChanged(int index)
{
    mySettings->setValue("caretWidth",index);
}


void Settings::on_saveButton_clicked()
{
    mySettings->setValue("font",ui->fontComboBox->currentFont().toString());
    mySettings->setValue("fontSize",ui->lineEdit->text().toInt());
    mySettings->setValue("tabSize",ui->lineEdit_2->text().toInt());
    mySettings->setValue("autoIndent",ui->checkBox->isChecked());
    mySettings->setValue("matchBracket",ui->checkBox_2->isChecked());
    mySettings->setValue("lineNumbers",ui->checkBox_3->isChecked());
    mySettings->setValue("wordWrap",ui->checkBox_4->isChecked());
    mySettings->setValue("autoComplete",ui->checkBox_5->isChecked());
    this->close();
}

void Settings::on_cancelButton_clicked()
{
    this->close();
}
