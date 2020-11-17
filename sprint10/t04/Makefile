all: MINILIBMX
MINILIBMX: src/*.c inc/*.h
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -o mx_wc src/*.c -I inc
clean:
	rm -rf mx_wc
uninstall: clean
reinstall: uninstall all
