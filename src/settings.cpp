#include "settings.h"
#include "ui_settings.h"

#include <QDebug>

Settings::Settings(QWidget *parent) : QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    my_settings = new QSettings ("kumar","SimpleCodeEditor",this);
    loadSettings();
}

Settings::~Settings()
{
    delete ui;
}

void Settings::loadSettings()
{
    loadGeneralSettings();
    loadTextEditorSettings();
}

void Settings::on_saveButton_clicked()
{
    saveGeneralSettings();
    saveTextEditorSettings();
    this->close();
}

void Settings::on_cancelButton_clicked()
{
    this->close();
}

void Settings::saveGeneralSettings()
{
    my_settings->setValue("generalfont", ui->fontComboBox->font().toString());
    my_settings->setValue("fontsize", ui->genFontSize->text());
    my_settings->setValue("theme", ui->themeComboBox->currentText());
    my_settings->setValue("autosave", ui->AutoSave->isChecked());
}

void Settings::saveTextEditorSettings()
{
    my_settings->setValue("editorfont", ui->Font->currentFont().toString());
    my_settings->setValue("editorfontsize", ui->editorfontSize->text());
    my_settings->setValue("caretwidth", ui->caretWidth->currentText());
    my_settings->setValue("autocomplete", ui->autoComp->isChecked());
    my_settings->setValue("colorscheme", ui->colorScheme->currentText());
    my_settings->setValue("wordwrap", ui->wordwrap->isChecked());
    my_settings->setValue("matchbracket", ui->matchBrackts->isChecked());
    my_settings->setValue("linenumbers", ui->showLinenum->isChecked());
    my_settings->setValue("tabwidth", ui->tabsize->text());
    my_settings->setValue("autoindent", ui->autoIndent->isChecked());
}

void Settings::loadGeneralSettings()
{
    QFont font;
    ui->fontComboBox->setCurrentFont(QFont(my_settings->value("generalfont", font.defaultFamily()).toString()));
    ui->genFontSize->setText(my_settings->value("fontsize", "12").toString());
    ui->themeComboBox->setCurrentText(my_settings->value("theme", "Light").toString());
    ui->AutoSave->setChecked(my_settings->value("autosave", false).toBool());
}

void Settings::loadTextEditorSettings()
{
    QFont font;
    ui->Font->setCurrentFont(QFont(my_settings->value("editorfont", font.defaultFamily()).toString()));
    ui->editorfontSize->setText(my_settings->value("editorfontsize", "12").toString());
    ui->caretWidth->setCurrentText(my_settings->value("caretwidth", "1").toString());
    ui->autoComp->setChecked(my_settings->value("autocomplete", false).toBool());
    ui->colorScheme->setCurrentText(my_settings->value("colorscheme", "Default").toString());
    ui->wordwrap->setChecked(my_settings->value("wordwrap", false).toBool());
    ui->matchBrackts->setChecked(my_settings->value("matchbrackets", false).toBool());
    ui->showLinenum->setChecked(my_settings->value("linenumbers", true).toBool());
    ui->tabsize->setText(my_settings->value("tabwidth").toString());
    ui->autoIndent->setChecked(my_settings->value("autoindent").toBool());
}
