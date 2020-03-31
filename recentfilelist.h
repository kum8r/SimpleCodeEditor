#ifndef RECENTFILELIST_H
#define RECENTFILELIST_H

#include <QListWidget>
#include <QResizeEvent>

class recentfilelist : public QListWidget
{
    Q_OBJECT
public:
    recentfilelist(QWidget *parent = nullptr);
protected:

    virtual void resizeEvent( QResizeEvent* e);
};

#endif // RECENTFILELIST_H
