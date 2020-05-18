TARGET = SimpleCodeEditor
TEMPLATE = app

QT       += core gui printsupport widgets

#ccache for speedup the build process
#QMAKE_CXX = ccache $$QMAKE_CXX


# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

include(src/singleapplication/singleapplication.pri)
DEFINES += QAPPLICATION_CLASS=QApplication


CONFIG += c++11 qscintilla2
#PKGCONFIG += qtermwidget5

LIBS += -lqtermwidget5


SOURCES += \
        src/comment.cpp \
        src/minimap.cpp \
        src/codeeditor.cpp \
        src/finddialog.cpp \
        src/main.cpp \
        src/mainwindow.cpp \
        src/settings.cpp \
        src/stylesheet.cpp \
        src/termwidget.cpp


HEADERS += \
        src/comment.h \
        src/minimap.h \
        src/codeeditor.h \
        src/finddialog.h \
        src/mainwindow.h \
        src/settings.h \
        src/stylesheet.h \
        src/termwidget.h

FORMS += \
        src/minimap.ui \
        src/finddialog.ui \
        src/mainwindow.ui \
        src/settings.ui

RESOURCES += \
    res.qrc

DISTFILES += \
    SimpleCodeEditor.desktop \
    dark_theme.qss \
    light_theme.qss

unix
{
    isEmpty(PREFIX)
    {
        PREFIX = /usr/local
    }
    BINDIR = $$PREFIX/bin
    DATADIR = $$PREFIX/share

    INSTALLS += target shortcut

    target.path = $$BINDIR
    shortcut.path = $$DATADIR/applications
    shortcut.files = SimpleCodeEditor.desktop
}
