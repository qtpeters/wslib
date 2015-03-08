
COMPILER=g++
INCLUDE=-I/boost/1.55.0
LIBS=-L/boost/1.55.0/bin.v2/libs/system/build/darwin-4.2.1/release/link-static/threading-multi
LINKS=-lboost_system
SRC=test/service_test.cpp src/service/server.cpp src/service/session.cpp
OUTPUT=-o bin/service_test

build: prelim
	${COMPILER} ${INCLUDE} ${LIBS} ${LINKS} ${SRC} ${OUTPUT}

prelim: clean
	mkdir bin

clean:
	rm -rf bin
