all: MINILIBMX
MINILIBMX: src/*.c inc/*.h
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -o mx_cat src/*.c -I inc
clean:
	rm -rf mx_cat
uninstall: clean
reinstall: uninstall all
