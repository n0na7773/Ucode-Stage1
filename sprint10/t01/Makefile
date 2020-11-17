all: MINILIBMX
MINILIBMX: src/*.c inc/*.h
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -o mx_cp src/*.c -I inc
clean:
	rm -rf mx_cp
uninstall: clean
reinstall: uninstall all
