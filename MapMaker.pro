TEMPLATE = app
TARGET = MapMaker

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

HEADERS += \
    headers/Worksheet.h \
    headers/Cell.h \
    headers/MapDraft.h

RESOURCES += \
    MapMakerResources.qrc

SOURCES += \
    src/MapDraft.cpp \
    src/Worksheet.cpp \
    src/Cell.cpp \
    main.cpp
