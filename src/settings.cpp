#include "settings.h"
#include "ui_settings.h"

#include <QDebug>
#include <QFileDialog>
#include <QFontDatabase>

Settings::Settings(QWidget * parent)
  : QDialog(parent)
  , ui(new Ui::Settings)
{
    ui->setupUi(this);

    ui->themeComboBox->hide();
    ui->label_5->hide();

    ui->autosavetime_2->hide();
    ui->label_3->hide();

    if (ui->autoSaveOptions->currentText() == "After Delay")
    {
        ui->autosavetime_2->show();
        ui->label_3->show();
    }

    m_settings = new QSettings("kumar", "SimpleCodeEditor", this);
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
    m_settings->setValue("generalfont", ui->fontComboBox->font().toString());
    m_settings->setValue("fontsize", ui->genFontSize->text());
    m_settings->setValue("theme", ui->themeComboBox->currentText());
    m_settings->setValue("autosaveoption", ui->autoSaveOptions->currentText());
    m_settings->setValue("autosavetime", ui->autosavetime_2->value());
}

void Settings::saveTextEditorSettings()
{
    m_settings->setValue("editorfont", ui->Font->currentFont().toString());
    m_settings->setValue("editorfontsize", ui->editorfontSize->text());
    m_settings->setValue("caretstyle", ui->caretWidth->currentIndex());
    m_settings->setValue("autocomplete", ui->autoComp->isChecked());
    m_settings->setValue("colorscheme", ui->colorScheme->currentText());
    m_settings->setValue("wordwrap", ui->wordwrap->isChecked());
    m_settings->setValue("matchbracket", ui->matchBrackts->isChecked());
    m_settings->setValue("linenumbers", ui->showLinenum->isChecked());
    m_settings->setValue("tabwidth", ui->tabsize->text());
    m_settings->setValue("autoindent", ui->autoIndent->isChecked());
}

void Settings::loadGeneralSettings()
{
    QFont font = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    ui->fontComboBox->setCurrentFont(QFont(m_settings->value("generalfont", font).toString()));
    ui->genFontSize->setText(m_settings->value("fontsize", "12").toString());
    ui->themeComboBox->setCurrentText(m_settings->value("theme", "Light").toString());
    ui->autoSaveOptions->setCurrentText(m_settings->value("autosaveoption", "Never").toString());
    ui->autosavetime_2->setValue(m_settings->value("autosavetime", 5).toInt());
}

void Settings::loadTextEditorSettings()
{
    QFont font;
    ui->Font->setCurrentFont(QFont(m_settings->value("editorfont", font.defaultFamily()).toString()));
    ui->editorfontSize->setText(m_settings->value("editorfontsize", "12").toString());
    ui->caretWidth->setCurrentIndex(m_settings->value("caretstyle", "1").toInt());
    ui->autoComp->setChecked(m_settings->value("autocomplete", false).toBool());
    ui->colorScheme->setCurrentText(m_settings->value("colorscheme", "Default").toString());
    ui->wordwrap->setChecked(m_settings->value("wordwrap", false).toBool());
    ui->matchBrackts->setChecked(m_settings->value("matchbrackets", false).toBool());
    ui->showLinenum->setChecked(m_settings->value("linenumbers", true).toBool());
    ui->tabsize->setText(m_settings->value("tabwidth").toString());
    ui->autoIndent->setChecked(m_settings->value("autoindent").toBool());
}

void Settings::on_pushButton_clicked()
{
    QString importFile = QFileDialog::getOpenFileName(this, tr("Import Color Scheme"), QDir::homePath());

    if (importFile.isNull() || importFile.isEmpty())
        return;

    if (QFileInfo(importFile).suffix() == "xml")
    {
        if (QFile::exists(QDir::homePath() + "/.config/SimpleCodeEditor/ColorScheme/" + QFileInfo(importFile).fileName()))
            return;
        QFile::copy(importFile, QDir::homePath() + "/.config/SimpleCodeEditor/ColorScheme/");
        emit newColorScheme(importFile);
    }
}

void Settings::on_autoSaveOptions_activated(const QString & arg1)
{
    if (arg1 == "After Delay")
    {
        ui->autosavetime_2->show();
        ui->label_3->show();
    }
    else
    {
        ui->autosavetime_2->hide();
        ui->label_3->hide();
    }
}
