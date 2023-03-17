CC := clang++

CFLAGS := $(shell wx-config --cxxflags std stc)
LIBS := $(shell wx-config --libs std stc)

all: build/wx_notepad

build/noname.o: codegen/noname.cpp codegen/noname.h
	mkdir -p build/
	${CC} ${CFLAGS} -c codegen/noname.cpp -o $@ ${LIBS}

build/find.o: src/find.cpp src/find.hpp
	mkdir -p build/
	${CC} ${CFLAGS} -c src/find.cpp -o $@ ${LIBS}

build/goto.o: src/goto.cpp src/goto.hpp
	mkdir -p build/
	${CC} ${CFLAGS} -c src/goto.cpp -o $@ ${LIBS}

build/font.o: src/font.cpp src/font.hpp
	mkdir -p build/
	${CC} ${CFLAGS} -c src/font.cpp -o $@ ${LIBS}

build/wx_notepad: src/wx_notepad.cpp build/noname.o build/goto.o build/find.o build/font.o
	mkdir -p build/
	${CC} ${CFLAGS} src/wx_notepad.cpp build/goto.o build/find.o build/font.o build/noname.o -o $@ ${LIBS}

clean:
	rm -rf build/

.PHONY: clean
