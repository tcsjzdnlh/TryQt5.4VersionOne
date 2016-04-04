
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets


TEMPLATE = app
TARGET = helloworld


HEADERS += hello.h

SOURCES += hello.cpp
SOURCES += main.cpp





CONFIG += debug

DESTDIR = ./dest

win32:debug{
	CONFIG += console
}


win32 {
	SOURCES += hellowin.cpp
}
unix {
	SOURCES += hellounix.cpp
}


RC_ICONS = app_3.ico