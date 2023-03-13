QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17 sdk_no_version_check
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.15

TARGET = desktop-gallery
TEMPLATE = app

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    albumlistwidget.cpp \
    albumwidget.cpp \
    gallerywidget.cpp \
    main.cpp \
    mainwindow.cpp \
    picturedelegate.cpp \
    picturewidget.cpp \
    thumbnailproxymodel.cpp

HEADERS += \
    albumlistwidget.h \
    albumwidget.h \
    gallerywidget.h \
    mainwindow.h \
    picturedelegate.h \
    picturewidget.h \
    thumbnailproxymodel.h

FORMS += \
    albumlistwidget.ui \
    albumwidget.ui \
    gallerywidget.ui \
    mainwindow.ui \
    picturewidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../gallery-core/release/ -lgallery-core
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../gallery-core/debug/ -lgallery-core
else:unix: LIBS += -L$$OUT_PWD/../gallery-core/ -lgallery-core

INCLUDEPATH += $$PWD/../gallery-core
DEPENDPATH += $$PWD/../gallery-core

RESOURCES += \
    res/resource.qrc

DISTFILES +=
