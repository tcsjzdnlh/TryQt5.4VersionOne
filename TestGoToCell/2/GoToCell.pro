
QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets




TEMPLATE = app
TARGET = GoToCellDlg
INCLUDEPATH += .

# Input
HEADERS += GoToCellDialog.h


		   
SOURCES += main.cpp \
		   GoToCellDialog.cpp

		   
		   
		   
FORMS += GoToCellDialog.ui




#RC_ICONS = app.ico
