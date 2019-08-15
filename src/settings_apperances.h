#ifndef SETTINGS_APPERANCES_H
#define SETTINGS_APPERANCES_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFontComboBox>
#include <QCheckBox>
#include <QLineEdit>

class settings_apperances : public QWidget
{
    Q_OBJECT
public:
    explicit settings_apperances(QWidget *parent = nullptr);
    ~settings_apperances();

    QVBoxLayout* getlayout();
signals:


private:
    QVBoxLayout *mainLayout;

public slots:
};

#endif // SETTINGS_APPERANCES_H
