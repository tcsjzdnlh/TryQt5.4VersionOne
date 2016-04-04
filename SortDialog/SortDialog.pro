HEADERS += SortDialog.h

SOURCES +=  main.cpp \
			SortDialog.cpp
			

FORMS += SortDialog.ui

QT += core gui
greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets


#RC_ICONS +=

#RC_FILE = 

TEMPLATE = app
TARGET = SortDialog


CONFIG += warn_on \
		  debug


#DESTDIR = 


