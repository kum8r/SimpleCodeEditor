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
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

    void loadSettings();
    void saveSettings();
    void loadStartUpSettings();
    void saveStartUpSettings(QWidget *parent);

private slots:
    void on_saveButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::Settings *ui;
    QSettings *mySettings;
    void saveGeneralSettings();
    void saveTextEditorSettings();
    void loadGeneralSettings();
    void loadTextEditorSettings();

};

#endif // SETTINGS_H
