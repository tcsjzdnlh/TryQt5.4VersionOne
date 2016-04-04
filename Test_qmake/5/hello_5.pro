

SOURCES += main.cpp hello.cpp

HEADERS += hello.h


QT += core gui


greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets



RC_ICONS = hello_5.ico


SUBDIRS += world \
			bike/mybike.pro
		  
		  
CONFIG += ordered debug console		  
