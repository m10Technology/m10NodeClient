QT += core
QT -= gui
QT += network

TARGET = m10NodeClient
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    client.cpp \
    commandthread.cpp

HEADERS += \
    client.h \
    commandthread.h

