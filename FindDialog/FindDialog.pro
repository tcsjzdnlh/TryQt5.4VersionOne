HEADERS += FindDialog.h

SOURCES += main.cpp \
			FindDialog.cpp

FORMS +=

RC_ICONS +=

RC_FILE = FindDialog_app.rc

RESOURCES += FindDialog.qrc

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets


CONFIG += warn_on \
			debug

TEMPLATE = app
TARGET = finddlg

DESTDIR =