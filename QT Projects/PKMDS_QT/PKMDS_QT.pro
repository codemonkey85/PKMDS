#-------------------------------------------------
#
# Project created by QtCreator 2013-08-16T19:33:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG +=c++11
QMAKE_CXXFLAGS += -std=c++0x

TARGET = PKMDS_QT
TEMPLATE = app

SOURCES += \
    ../main.cpp \
    ../qt_sqlite.cpp \
    ../mouseeventeater.cpp \
    ../pkmviewer.cpp \
    ../frmboxes.cpp \
    ../frmreport.cpp \
    ../otinfo.cpp \
    ../../lib/pkmds_g5.cpp \
    ../../lib/pkmds_g6.cpp \
    ../../lib/pkmds_gba.cpp \
    ../../lib/pkm_report.cpp \
    ../../lib/pkmds_g5_sqlite.cpp \
    ../../lib/pkmds_sql.cpp \
    ../../lib/pkmds_vector.cpp \
    ../../lib/sqlite3.c \
    ../../lib/stdafx.cpp

HEADERS  += \
    ../qt_sqlite.h \
    ../mouseeventeater.h \
    ../pkmviewer.h \
    ../frmboxes.h \
    ../frmreport.h \
    ../otinfo.h \
    ../../Visual_Studio/vs_sqlite.h \
    ../../include/sqlite3.h \
    ../../include/pkmds/pkmds_g5.h \
    ../../include/pkmds/pkmds_g6.h \
    ../../include/pkmds/pkmds_gba.h \
    ../../include/pkmds/stdafx.h \
    ../../include/pkmds/pkm_report.h \
    ../../include/pkmds/pkmds_g5_sqlite.h \
    ../../include/pkmds/pkmds_sql.h \
    ../../include/pkmds/pkmds_vector.h \
    ../../include/pkmds/pokeprng.h \
    ../../include/pkmds/wondercard.h \
    ../../include/pkmds/pack.h

FORMS    += \
    ../pkmviewer.ui \
    ../frmboxes.ui \
    ../frmreport.ui \
    ../otinfo.ui
