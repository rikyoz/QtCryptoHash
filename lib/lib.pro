include(../common.pri)

TARGET = QtCryptoHash$${ARCH_SUFFIX}

QT      -= gui

TEMPLATE = lib

INCLUDEPATH += ./include/ \
               ./3rdparty/include

SOURCES += \
           src/rmd160.cpp \
           src/tiger.cpp \
           src/whirlpool.cpp \
           src/qcryptohash.cpp \
           src/hashalgorithm.cpp

HEADERS += \
           include/rmd160.hpp \
           include/tiger.hpp \
           include/whirlpool.hpp \
           include/hashalgorithm.hpp \
           include/qcryptohash.hpp

########################### CONFIGURATION ############################
!static {
    DEFINES += QTCRYPTOHASH_EXPORT
}

VER_MAJ = 0
VER_MIN = 1
VER_PAT = 2
VERSION = $${VER_MAJ}.$${VER_MIN}.$${VER_PAT}

######################## OS DEPENDENT OPTIONS ########################
win32 {
    CONFIG += skip_target_version_ext # no version in lib file

    !static : !staticlib {
        CONFIG += dll
        TARGET_EXT = .dll

        # CONTENT OF THE RC FILE #
        QMAKE_TARGET_PRODUCT = QtCryptoHash
        QMAKE_TARGET_COMPANY = rikyoz
        QMAKE_TARGET_COPYRIGHT = Copyright (c) 2016 $${QMAKE_TARGET_COMPANY}
    }

    !win32-g++ {
        contains(QT_ARCH, i386) {
            QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.01
        } else {
            QMAKE_LFLAGS_WINDOWS = /SUBSYSTEM:WINDOWS,5.02
        }
    }
}

unix {
    target.path = /usr/lib
    INSTALLS += target
}
