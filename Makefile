CC = gcc
CFLAGS = -Wall

sources := $(wildcard src/*.c)
objects := $(patsubst src/%.c, build/%.o, $(sources))
tests := $(wildcard test/*.c)

all: libds.a

libds.a: $(objects)
	ar rcs libds.a $(objects) 

build/%.o: src/%.c
	mkdir -p build/
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

tests: libds.a


clean:
	rm -rf *.o build/ libds.a