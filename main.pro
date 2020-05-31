TEMPLATE = app
HEADERS = include/widget.h include/webview.h \
		include/form.h include/look.h \
		include/credentials.h
SOURCES = src/widget.cpp src/webview.cpp src/form.cpp \
		src/look.cpp src/credentials.cpp \
		src/main.cpp
INCLUDEPATH = include
QT += core gui widgets webkit webkitwidgets
TARGET = main


OBJECTS_DIR = build
UI_DIR = build
MOC_DIR = build


