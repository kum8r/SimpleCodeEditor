#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

}

Settings::~Settings()
{
    delete ui;
}

int Settings::setfontSize() {
    return fontSize;
}

void Settings::on_spinBox_valueChanged(int arg1) {

}
