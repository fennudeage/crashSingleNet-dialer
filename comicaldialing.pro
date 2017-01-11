#-------------------------------------------------
#
# Project created by QtCreator 2016-10-22T11:36:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += network
TARGET = comicaldialing
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    addicon.cpp \
    dialup.cpp \
    about.cpp \
    aboutqt.cpp \
    md5.cpp

HEADERS  += mainwidget.h \
    addicon.h \
    dialup.h \
    about.h \
    aboutqt.h \
    md5.h

FORMS    += mainwidget.ui \
    about.ui

RESOURCES += \
    rec.qrc

