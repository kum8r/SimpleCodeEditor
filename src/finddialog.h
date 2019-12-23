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
    bool getRegexp() const;
    bool getCasesensitive() const;
    bool getWholeword() const;

signals:

    void findButton_clicked(QString searchtext);
    void findPrev_clicked(QString searchtext);
    void findStringChanged();
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
    void on_findString_returnPressed();
    void on_findString_textChanged(const QString &arg1);
    void on_AdvacndBtn_clicked();

private:

    Ui::findDialog *ui;
    QString findString;
    QString replaceString;
    bool wholeword;
    bool casesensitive;
    bool regexp;
};

#endif // FINDDIALOG_H
