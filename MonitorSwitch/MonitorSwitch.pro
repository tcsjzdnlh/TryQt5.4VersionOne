HEADERS += LogWnd.h \
		   MainWnd.h \
		   MonitorSwitch.h



SOURCES += LogWnd.cpp \
		   MainWnd.cpp \
		   MonitorSwitch.cpp \
		   winmain.cpp \
		   main.cpp


#FORMS +=

#RC_ICONS +=

#RC_FILE =

TEMPLATE = app

TARGET = MonitorSwitch

#DESTDIR = 

QT		+= core gui
greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets

CONFIG += debug \
		  warn_on





		   

