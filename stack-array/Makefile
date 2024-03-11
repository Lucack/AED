CC = gcc -Wall -pedantic
EXE = $(BUILD)/main

build:
	mkdir -p build

element: build
	$(CC) -c element.c -o build/element.o

stack: element
	$(CC) -c stack.c -o build/stack.o

main: stack
	$(CC) main.c build/stack.o build/element.o -o build/main

run: main
	./build/main