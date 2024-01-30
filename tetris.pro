QT += core gui

CONFIG += c++17

TARGET = tetris
TEMPLATE = app

SOURCES += \
        main.cpp \
        tetrisboard.cpp \
        tetrispiece.cpp \
        tetriswindow.cpp

HEADERS += \
        tetrisboard.h \
        tetrispiece.h \
        tetriswindow.h

RESOURCES += tetris.qrc
