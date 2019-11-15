#-------------------------------------------------
#
# Project created by QtCreator 2019-11-13T08:58:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    roadstorage.cpp \
    roadinfo.cpp \
    sortfunction.cpp \
    mergesort.cpp \
    hillsort.cpp \
    bubblesort.cpp \
    sortchoose.cpp \
    heapsort.cpp \
    quicksort.cpp \
    bucketsort.cpp \
    countsort.cpp \
    readfile.cpp \
    searchfunction.cpp \
    binarysearch.cpp \
    searchui.cpp \
    mywarning.cpp \
    renewwidget.cpp \
    update.cpp \
    getdata.cpp \
    successwidget.cpp \
    ordersearch.cpp \
    wait.cpp

HEADERS += \
        mainwindow.h \
    roadstorage.h \
    roadinfo.h \
    sortfunction.h \
    mergesort.h \
    hillsort.h \
    bubblesort.h \
    sortchoose.h \
    heapsort.h \
    quicksort.h \
    bucketsort.h \
    countsort.h \
    readfile.h \
    searchfunction.h \
    binarysearch.h \
    searchui.h \
    mywarning.h \
    renewwidget.h \
    update.h \
    getdata.h \
    successwidget.h \
    ordersearch.h \
    wait.h

FORMS += \
        mainwindow.ui \
    sortchoose.ui \
    readfile.ui \
    searchui.ui \
    mywarning.ui \
    renewwidget.ui \
    getdata.ui \
    successwidget.ui \
    wait.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
