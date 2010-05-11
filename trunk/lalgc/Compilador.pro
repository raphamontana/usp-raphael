# -------------------------------------------------
# Project created by QtCreator 2010-04-05T22:08:38
# -------------------------------------------------
QT -= core \
    gui
TARGET = Compilador
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
SOURCES += main.cpp \
    compilador.cpp \
    analisadorsintatico.cpp \
    analisadorsemantico.cpp \
    analisadorlexico.cpp
HEADERS += erro.h \
    compilador.h \
    analisadorsintatico.h \
    analisadorsemantico.h \
    analisadorlexico.h
QMAKE_CXXFLAGS += -Wall \
    -Wextra \
    -pedantic-errors
