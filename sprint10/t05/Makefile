all: MINILIBMX
MINILIBMX: src/*.c inc/*.h
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic -o parse_agents src/*.c -I inc
clean:
	rm -rf parse_agents
uninstall: clean
reinstall: uninstall all
