#-------------------------------------------------
#
# Project created by QtCreator 2015-05-19T19:57:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 2048
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    start.cpp \
    finish.cpp \
    fillnumber.cpp

HEADERS  += mainwindow.h \
    start.h \
    finish.h \
    fillnumber.h

FORMS    += mainwindow.ui \
    start.ui \
    finish.ui

win32:CONFIG(release, debug|release): LIBS += $$quote(C:/Program Files(x86)/Microsoft SDKs/Windows/v7.1A/Lib/shell32.lib)
else:win32:CONFIG(debug, debug|release): LIBS += $$quote(C:/Program Files (x86)/Microsoft SDKs/Windows/v7.1A/Lib/shell32.lib)

INCLUDEPATH += $$quote(C:/Program Files (x86)/Microsoft   SDKs/Windows/v7.1A/Include)
DEPENDPATH += $$quote(C:/Program Files (x86)/Microsoft SDKs/Windows/v7.1A/Include)

DISTFILES += \
    ../GitHub/2048/image/0.png

RESOURCES += \
    2048.qrc
