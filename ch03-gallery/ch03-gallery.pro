TEMPLATE = subdirs

SUBDIRS += \
    gallery-core \
    gallery-desktop

# depends表示gallery-core必须在gallery-desktop之前编译built
gallery-desktop.depends =  gallery-core
