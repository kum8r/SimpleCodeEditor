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
    mySettings->setValue("generalFont", ui->fontComboBox->font().toString());
    mySettings->setValue("fontSize", ui->genFontSize->text());
    mySettings->setValue("theme", ui->themeComboBox->currentText());
    mySettings->setValue("autosave", ui->AutoSave->isChecked());
    qDebug() << ui->themeComboBox->currentData(Qt::UserRole);
}

void Settings::saveTextEditorSettings()
{
    mySettings->value("editorFont", ui->Font->currentFont().toString());
    mySettings->value("editorFontSize", ui->editorfontSize->text());
    mySettings->value("caretWidth", ui->caretWidth->currentText());
    mySettings->value("autoComplete", ui->autoComp->isChecked());
    mySettings->value("colorScheme", ui->colorScheme->currentText());
    mySettings->value("wordWrap", ui->wordwrap->isChecked());
    mySettings->value("matchBrackets", ui->matchBrackts->isChecked());
    mySettings->value("lineNumbers", ui->showLinenum->isChecked());
}

void Settings::loadGeneralSettings()
{
    QFont font;
    ui->fontComboBox->setCurrentFont(QFont(mySettings->value("generalFont", font.defaultFamily()).toString()));
    ui->genFontSize->setText(mySettings->value("fontSize", "12").toString());
    ui->themeComboBox->setCurrentText(mySettings->value("theme", "Light").toString());
    ui->AutoSave->setChecked(mySettings->value("autosave", false).toBool());
}

void Settings::loadTextEditorSettings()
{
    QFont font;
    ui->Font->setCurrentFont(QFont(mySettings->value("editorFont", font.defaultFamily()).toString()));
    ui->editorfontSize->setText(mySettings->value("editorFontSize", "12").toString());
    ui->caretWidth->setCurrentText(mySettings->value("caretWidth", "1").toString());
    ui->autoComp->setChecked(mySettings->value("autoComplete", false).toBool());
    ui->colorScheme->setCurrentText(mySettings->value("colorScheme", "Light").toString());
    ui->wordwrap->setChecked(mySettings->value("wordWrap", false).toBool());
    ui->matchBrackts->setChecked(mySettings->value("matchBrackets", false).toBool());
    ui->showLinenum->setChecked(mySettings->value("lineNumbers", true).toBool());
}
