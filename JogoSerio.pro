#-------------------------------------------------
#
# Project created by QtCreator 2019-05-25T23:43:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = JogoSerio
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia


CONFIG += c++11

SOURCES += \
        chao.cpp \
        game.cpp \
        inimigo.cpp \
        jogador.cpp \
        main.cpp \
        parede.cpp \
    telas.cpp \
        tiro.cpp \
        tiroinimigo.cpp \
    escada.cpp \
    telapiso.cpp \
    upgrades.cpp \
    barravida.cpp \
    menu.cpp

HEADERS += \
    chao.h \
    game.h \
    inimigo.h \
    jogador.h \
    parede.h \
    telas.h \
    tiro.h \
    tiroinimigo.h \
    escada.h \
    telapiso.h \
    upgrades.h \
    barravida.h \
    menu.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
