CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -lncurses

all: MINILIBMX
MINILIBMX: src/*.c inc/*.h
	clang $(CFLAGS) -o matrix_rain src/*.c -I inc
clean:
	rm -rf matrix_rain
uninstall: clean
reinstall: uninstall all
