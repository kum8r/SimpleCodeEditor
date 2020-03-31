#include "recentfilelist.h"

recentfilelist::recentfilelist(QWidget *parent) : QListWidget(parent)
{

}

void recentfilelist::resizeEvent(QResizeEvent *e)
{
    QListWidget::resizeEvent( e );
    const int MaxItemSize = 128 + 16;
    const int ItemRow = ( e->size().width() / MaxItemSize ) + 1;
    if( ItemRow > count() )
    {
        setIconSize( QSize( 128, 128 ) );
    }
    else
    {
        if( ItemRow > 0 )
        {
            const int SizeOffset = ( MaxItemSize - ( e->size().width() % MaxItemSize ) ) / ItemRow;
            const int IconSize = ( 128 - SizeOffset <= 0 ) ? 128 : 128 - SizeOffset;
            setIconSize( QSize( IconSize, IconSize ) );
        }
        else
        {
            setIconSize( QSize( 32, 32 ) );
        }
    }
}
