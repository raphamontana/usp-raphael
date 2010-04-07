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
    analisadorlexico.cpp \
    analisadorsemantico.cpp \
    compilador.cpp \
    analisadorsintatico.cpp
HEADERS += analisadorlexico.h \
    analisadorsemantico.h \
    erro.h \
    compilador.h \
    analisadorsintatico.h
QMAKE_CXXFLAGS += -Wall \
    -Wextra \
    -pedantic-errors
