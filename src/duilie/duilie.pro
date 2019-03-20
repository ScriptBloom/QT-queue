#-------------------------------------------------
#
# Project created by QtCreator 2018-06-27T10:57:29
#
#-------------------------------------------------

QT       += core gui
QT += webkitwidgets
QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = duilie2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    queue1.cpp \
    queue2.cpp \
    lianwidget.cpp \
    orderwidget.cpp

HEADERS  += mainwindow.h \
    queue1.h \
    queue2.h \
    lianwidget.h \
    orderwidget.h

FORMS    += mainwindow.ui \
    lianwidget.ui \
    orderwidget.ui

RESOURCES += \
    image.qrc
