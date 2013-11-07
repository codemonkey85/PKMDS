#-------------------------------------------------
#
# Project created by QtCreator 2013-08-16T19:33:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG +=c++11

TARGET = PKMDS_QT
TEMPLATE = app

SOURCES += \
    ../main.cpp \
    ../qt_sqlite.cpp \
    ../mouseeventeater.cpp \
    ../pkmviewer.cpp \
    ../frmboxes.cpp \
    ../../lib/stdafx.cpp \
    ../../lib/sqlite3.c \
    ../../lib/pkmds_gba.cpp \
    ../../lib/pkmds_vector.cpp \
    ../../lib/pkmds_g5_sqlite.cpp \
    ../../lib/pkmds_g5.cpp \
    ../../lib/pkmds_sql.cpp \
    ../frmreport.cpp

HEADERS  += \
    ../qt_sqlite.h \
    ../mouseeventeater.h \
    ../pkmviewer.h \
    ../frmboxes.h \
    ../../include/sqlite3.h \
    ../../include/pkmds/wondercard.h \
    ../../include/pkmds/pokeprng.h \
    ../../include/pkmds/pkmds_vector.h \
    ../../include/pkmds/pkmds_gba.h \
    ../../include/pkmds/pkmds_g5_sqlite.h \
    ../../include/pkmds/stdafx.h \
    ../../include/pkmds/pkmds_g5.h \
    ../../include/pkmds/pkmds_sql.h \
    ../frmreport.h

FORMS    += \
    ../pkmviewer.ui \
    ../frmboxes.ui \
    ../frmreport.ui
