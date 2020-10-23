QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp
    Canvas.cpp \

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

QMAKE_CXXFLAGS += -std=gnu++14
