TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


SOURCES += editor.c \
    load.c \
    move_cursor.c \
    save.c \
    show.c \
    append_line.c \
    create_text.c \
    process_forward.c \
    remove_all.c \
    showfirstwords.c \
    mwef.c \
    rn.c \

HEADERS += \
    common.h \
    _text.h \
    text.h


QMAKE_CFLAGS += -Wall -Wextra #-Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
