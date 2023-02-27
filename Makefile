CC := clang++

CFLAGS := $(shell wx-config --cxxflags)
LIBS := $(shell wx-config --libs)

all: build/wx_notepad

build/noname.o: codegen/noname.cpp
	mkdir -p build/
	${CC} ${CFLAGS} -c codegen/noname.cpp -o $@ ${LIBS}

build/wx_notepad: wx_notepad.cpp build/noname.o
	mkdir -p build/
	${CC} ${CFLAGS} wx_notepad.cpp build/noname.o -o $@ ${LIBS}

clean:
	rm -rf build/

.PHONY: clean
