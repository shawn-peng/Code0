
CROSS:=x86_64-pc-msys-
CC:=gcc
PKG-CONFIG:=$(CROSS)pkg-config
GTK_VERSION:=3.0

CFLAGS:=`$(PKG-CONFIG) --cflags gtk+-$(GTK_VERSION)` 
LDFLAGS:=`$(PKG-CONFIG) --libs gtk+-$(GTK_VERSION)` -Wl,-rpath=./lib

SRCS:=$(shell find -name "*.c")
WINRES:=$(shell find -name "*.res")
RES:=$(shell find -name "*.ui" -or -name "*.xml" -or -name "*.rc")

all: gtktest

gtktest: $(SRCS) $(WINRES)
	gcc -o $@ $^ $(CFLAGS) $(LDFLAGS)

resources.c: code0.gresource.xml $(RES)
	glib-compile-resources.exe code0.gresource.xml --target=resources.c --generate-source

