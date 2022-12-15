CC=gcc
CFLAGS= -Wall -Wextra -g
.c.o:
	@ echo "Compiling $<"
	@ $(CC) $(CFLAGS) -c $<

.PHONE: all
all: run-test app clean

test: test.o mod11.o
	@ echo "Linking $@"
	@ $(CC) $(CFLAGS) -o $@ $?

app: main.o mod11.o
	@ echo "Linking $@"
	@ $(CC) $(CFLAGS) -o $@ $?

.PHONY: run-test
run-test: test
	@ echo "Running test"
	@ ./test

.PHONY: run
run: app
	@ echo "Running app"
	@ ./app

.PHONY: clean
clean:
	@ echo "Cleaning up"
	@ rm -f *.o test
