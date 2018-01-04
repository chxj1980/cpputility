TARGET = CPPUtility
TEMPLATE = lib
CONFIG -= qt
CONFIG += c++11

unix
{
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/../build/debug
    } else {
        DESTDIR = $$PWD/../build/release
    }
}

HEADERS += \
    cthread.h \
    cdatetime.h \
    cstring.h \
    cnetwork.h

SOURCES += \
    cthread.cpp \
    cdatetime.cpp \
    cstring.cpp \
    cnetwork.cpp
