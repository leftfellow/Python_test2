include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES += INPUTDIR=\\\"$$PWD/\\\"

HEADERS += tests.h \
        ../app/common.h \
        ../app/text.h \
        ../app/_text.h \

SOURCES += main.cpp \
    ../app/move_cursor.c \
    ../app/show.c \
    ../app/load.c \
    ../app/rn.c \
    ../app/mwef.c \
    ../app/save.c \
    ../app/showfirstwords.c \
    ../app/process_forward.c \
    ../app/append_line.c \
    ../app/create_text.c \
    ../app/remove_all.c

DISTFILES += \
    input.txt \
    no_text.txt \
    test.txt \
    no_words.txt \

INCLUDEPATH += ../app
