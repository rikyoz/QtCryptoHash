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

DESTDIR = $$PWD/bin/$${PLATFORM}/$${BUILD}
