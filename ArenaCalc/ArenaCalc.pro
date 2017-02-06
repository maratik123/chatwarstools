#-------------------------------------------------
#
# Project created by QtCreator 2017-02-02T01:11:45
#
#-------------------------------------------------

QT       += core gui

CONFIG   += c++11 stl hide_symbols exceptions

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ArenaCalc
TEMPLATE = app

DEFINES += QT_NO_CAST_FROM_ASCII \
           QT_NO_CAST_TO_ASCII


SOURCES += main.cpp\
    mainwindow.cpp \
    randomdialog.cpp \
    randomholder.cpp \
    commonstringholder.cpp

HEADERS  += mainwindow.h \
    randomdialog.h \
    randomholder.h \
    commonstringholder.h \
    enumclassutil.h

FORMS    += mainwindow.ui \
    randomdialog.ui
