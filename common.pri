# Uncomment the following line to compile QtCrypotHash as static library!
# CONFIG += static

contains(QT_ARCH, i386) {
    PLATFORM = x86
} else {
    PLATFORM = x64	
	ARCH_SUFFIX = 64
}

CONFIG(debug, debug|release) {
    BUILD = debug
} else {
    BUILD = release
}

static {
    DESTDIR  = $$PWD/bin/$${PLATFORM}/static/$${BUILD}
} else {
    DESTDIR  = $$PWD/bin/$${PLATFORM}/dynamic/$${BUILD}
}
