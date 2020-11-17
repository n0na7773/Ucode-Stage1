all: MINILIBMX
MINILIBMX: src/*.c inc/*.h
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -o calc src/*.c -I inc
clean:
	rm -rf calc
uninstall: clean
reinstall: uninstall all
