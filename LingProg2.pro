TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    files.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    files.h \
    error.h

