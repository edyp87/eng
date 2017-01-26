TEMPLATE = app

QT       += core gui widgets

CONFIG += c++11
CONFIG -= console
CONFIG -= app_bundle


SOURCES += main.cpp \
    pairpicker.cpp \
    directorygetter.cpp \
    textprinter.cpp \
    wordsteacher.cpp

HEADERS += \
    pairpicker.h \
    directorygetter.h \
    types.h \
    textprinter.h \
    wordsteacher.h

FORMS += \
    wordsteacher.ui

RESOURCES += \
    resources.qrc
