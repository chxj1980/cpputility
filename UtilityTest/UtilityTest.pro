TARGET = UtilityTest
TEMPLATE = lib
CONFIG -= qt
CONFIG += c++11

INCLUDEPATH += \
    $$PWD/../CPPUtility

unix
{
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/../build/debug
    } else {
        DESTDIR = $$PWD/../build/release
    }
}

HEADERS += \
    cthreadtest.h \
    cstringtest.h \
    cdatetimetest.h

SOURCES += \
    cthreadtest.cpp \
    cstringtest.cpp \
    cdatetimetest.cpp
