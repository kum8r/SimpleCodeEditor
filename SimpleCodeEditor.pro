#-------------------------------------------------
#
# Project created by QtCreator 2018-12-31T17:27:04
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SimpleCodeEditor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11 qscintilla2

SOURCES += \
        src/minimap.cpp \
        src/codeeditor.cpp \
        src/finddialog.cpp \
        src/main.cpp \
        src/mainwindow.cpp \
        src/settings.cpp


HEADERS += \
        src/minimap.h \
        src/codeeditor.h \
        src/finddialog.h \
        src/mainwindow.h \
        src/settings.h

FORMS += \
        src/minimap.ui \
        src/finddialog.ui \
        src/mainwindow.ui \
        src/settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/
!isEmpty(target.path): INSTALLS += target shortcut config


win32: header_files.path = win32_include_directory
linux: header_files.path = linux_include_directory

config.path = /usr/bin/
config.extra = ln -sf $$target.path/SimpleCodeEditor $$config.path/

shortcut.path = /usr/share/applications/
shortcut.files = SimpleCodeEditor.desktop

RESOURCES += \
    res.qrc

DISTFILES += \
    SimpleCodeEditor.desktop \
    editor_style.qss \
    editor_white_theme

