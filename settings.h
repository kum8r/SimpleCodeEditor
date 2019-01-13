#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
//#include "mainwindow.h"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();

    int fontSize;

    int setfontSize();

private slots:

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
