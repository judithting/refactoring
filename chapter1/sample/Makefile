.PHONY: all init build run test clean

all: build

init:
	mkdir -p build; \
	cd build; \
	cmake ..

build: init
	cmake --build build

run:
	./build/src/videorental

test:
	./build/test/videorental_test

clean:
	rm -rf build
