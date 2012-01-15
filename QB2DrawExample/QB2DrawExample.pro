#-------------------------------------------------
#
# Project created by QtCreator 2012-01-15T16:53:50
#
#-------------------------------------------------

QT       += core gui

TARGET = QB2DrawExample
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qb2draw.cpp

HEADERS  += mainwindow.h \
    qb2draw.h

FORMS    +=

LIBS +=-lBox2D
