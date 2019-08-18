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

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Settings *ui;
    QSettings *mySettings;

};

#endif // SETTINGS_H
