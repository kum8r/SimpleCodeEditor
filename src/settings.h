#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QListWidgetItem>
#include <QSettings>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget * parent = nullptr);
    ~Settings();

    void loadSettings();
    void saveSettings();
    void loadStartUpSettings();
    void saveStartUpSettings(QWidget * parent);

signals:
    void newColorScheme(QString filename);

private slots:
    void on_saveButton_clicked();
    void on_cancelButton_clicked();
    void on_pushButton_clicked();
    void on_autoSaveOptions_activated(const QString & arg1);

private:
    Ui::Settings * ui;
    QSettings * m_settings;
    void saveGeneralSettings();
    void saveTextEditorSettings();
    void loadGeneralSettings();
    void loadTextEditorSettings();
};

#endif // SETTINGS_H
