all: MINILIBMX
MINILIBMX: src/*.c inc/*.h
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -o part_of_the_matrix src/*.c -I inc
clean:
	rm -rf part_of_the_matrix
uninstall: clean
reinstall: uninstall all
