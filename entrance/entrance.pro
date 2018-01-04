TARGET = cpputility
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    $$PWD/../CPPUtility \
    $$PWD/../UtilityTest

unix
{
    CONFIG(debug, debug|release) {
        DESTDIR = $$PWD/../build/debug
        LIBS += -L$$PWD/../build/debug
    } else {
        DESTDIR = $$PWD/../build/release
        LIBS += -L$$PWD/../build/release
    }
}

SOURCES += main.cpp

LIBS += \
    -lUtilityTest \
    -lCPPUtility \
    -pthread
