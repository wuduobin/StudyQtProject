QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 sdk_no_version_check
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.15

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cpuwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    memorywidget.cpp \
    sysinfo.cpp \
    sysinfowidget.cpp

HEADERS += \
    cpuwidget.h \
    mainwindow.h \
    memorywidget.h \
    sysinfo.h \
    sysinfowidget.h

windows {
    SOURCES += sysinfowindowsimpl.cpp
    HEADERS += sysinfowindowsimpl.h
}

linux {
    SOURCES += sysinfolinuximpl.cpp
    HEADERS += sysinfolinuximpl.h
}

macx {
    SOURCES += sysinfomacimpl.cpp
    HEADERS += sysinfomacimpl.h
}

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
