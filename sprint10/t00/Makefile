all: MINILIBMX
MINILIBMX: src/*.c inc/*.h
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -o read_file src/*.c -I inc
clean:
	rm -rf read_file
uninstall: clean
reinstall: uninstall all
