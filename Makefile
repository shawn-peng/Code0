
CROSS:=x86_64-pc-msys-
CC:=g++
PKG-CONFIG:=$(CROSS)pkg-config
GTK_VERSION:=3.0

CFLAGS:=`$(PKG-CONFIG) --cflags gtkmm-$(GTK_VERSION)` -std=c++11 -g3
LDFLAGS:=`$(PKG-CONFIG) --libs gtkmm-$(GTK_VERSION)` -Wl,-rpath=./lib

SRCS:=$(shell find -name "*.cpp")
WINRES:=$(shell find -name "*.res")
RES:=$(shell find -name "*.ui" -or -name "*.xml" -or -name "*.rc")

all: code0

GENERATED:=resources.cpp

SRCS+=$(GENERATED)
SRCS:=$(sort $(SRCS))

code0: $(SRCS) $(WINRES)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

resources.cpp: code0.gresource.xml $(RES)
	glib-compile-resources.exe $(firstword $^) --target=$@ --generate-source
	
clean:
	rm -f *.o resources.cpp code0

