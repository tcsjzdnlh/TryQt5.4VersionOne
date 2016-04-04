

# qmake -tp vc hello.pro


QT += core gui
greaterThan(QT_MAJOR_VERSION, 4) : QT += widgets


CONFIG += debug


HEADERS += hello.h

SOURCES += hello.cpp
SOURCES += main.cpp


!exists( main.cpp ){
	error("main.cpp does not exists")
}

win32{
	SOURCES += hellowin.cpp
}
unix{
	SOURCES += hellounix.cpp
}

win32:debug{
	CONFIG += console
}


#win32{
#	debug{
#		CONFIG += console
#	}
#}