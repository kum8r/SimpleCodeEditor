#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>

namespace Ui {
class findDialog;
}

class findDialog : public QDialog
{
    Q_OBJECT

public:

    explicit findDialog(QWidget *parent = nullptr);
    ~findDialog();

    QString getFindString();
    QString getReplaceString();
    void setFindString(const QString &value);
    void setReplaceString(const QString &value);
    void showreplaceWidget();
    void hidereplaceWidget();


signals:

    void findButton_clicked(QString searchtext);
    void findPrev_clicked(QString searchtext);
    void replace_clicked(QString replacetext);
    void replaceAll_clicked(QString searchtext,QString replacetext);
    void closeFindDialog();

private slots:

    void on_FindBtn_clicked();
    void on_FindPrevBtn_clicked();
    void on_replaceBtn_clicked();
    void on_replaceAllBtn_clicked();
    void on_findCloseBtn_clicked();
    void on_replaceCloseBtn_clicked();

private:

    Ui::findDialog *ui;
    QString findString;
    QString replaceString;
};

#endif // FINDDIALOG_H
