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

private slots:


    void on_comboBox_currentIndexChanged(int index);


    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::Settings *ui;
    QSettings *mySettings;

};

#endif // SETTINGS_H
