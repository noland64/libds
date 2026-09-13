CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -MMD -MP
LIB = libds.a

SRCS := $(wildcard src/*.c)
OBJS := $(patsubst src/%.c, build/%.o, $(SRCS))
DEPS := $(patsubst %.o, %.d, $(OBJS))
TEST_SRCS = $(wildcard test/*.c)
TESTS := $(patsubst test/%.c, bin/%, $(TEST_SRCS))

all: $(LIB)

$(LIB): $(OBJS)
	@rm -rf bin/
	ar rcs $@ $(OBJS)

build/%.o: src/%.c
	@mkdir -p build/
	$(CC) $(CFLAGS) -c $< -o $@


bin/%: test/%.c libds.a
	@mkdir -p bin/
	$(CC) $(CFLAGS)  $< -L. -lds -o $@

-include $(DEPS)

test: $(TESTS)
	@echo "RUNNING TESTS..."
	@for test in $(TESTS); do echo -n "Running $$test..."; ./$$test; echo "PASS"; done;
clean:
	rm -rf *.o build/ libds.a bin/