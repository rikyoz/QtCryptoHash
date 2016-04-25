include(../common.pri)

QT       += testlib
QT       -= gui

TARGET = tst_qcryptohash$${ARCH_SUFFIX}

CONFIG   += testcase
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    tst_qcryptohash.cpp

########################### CONFIGURATION ############################
CONFIG += c++14

LIBS += -L$${DESTDIR} -lQtCryptoHash$${ARCH_SUFFIX}

INCLUDEPATH += $$PWD/../lib/include
DEPENDPATH += $$PWD/../lib/include
