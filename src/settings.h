#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QListWidgetItem>


namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();


private slots:

private:
    Ui::Settings *ui;

};

#endif // SETTINGS_H
