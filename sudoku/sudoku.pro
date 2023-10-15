#-------------------------------------------------
#
# Project created by QtCreator 2019-11-01T10:42:19
#
#-------------------------------------------------

QT       += core gui widgets


TARGET = sudoku
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

CONFIG(release,debug|release){
DESTDIR=$$PWD/sudoku
OBJECTS_DIR=$$DESTDIR/other/.obj
MOC_DIR=$$DESTDIR/other/.moc
RCC_DIR=$$DESTDIR/other/.rcc
UI_DIR=$$DESTDIR/other/.ui
}

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    zapoln.cpp \
    my_table.cpp

HEADERS += \
        mainwindow.h \
    zapoln.h \
    my_table.h

FORMS += \
        mainwindow.ui
