HEADERS += GoToCellDlg.h

SOURCES += main.cpp \
		   GoToCellDlg.cpp


FORMS += GoToCellDialog.ui


QT += core gui
greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets


TEMPLATE = app
TARGET = GoToCellDialog_3


CONFIG += debug \
		  warn_on \
		  console


DESTDIR = .\dest


RC_ICONS += app.ico

#RC_FILE

