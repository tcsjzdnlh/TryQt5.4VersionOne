
HEADERS +=

SOURCES += main.cpp

#FORMS +=

RESOURCES += ui.qrc

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

QT += uitools


CONFIG += warn_on \
			debug


TEMPLATE = app
TARGET = DynamicDialog

DESTDIR = 