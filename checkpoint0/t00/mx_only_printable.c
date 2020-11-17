#include <stdio.h>
#include <unistd.h>

void mx_printchar(char c);
void mx_only_printable(void);
void mx_printchar(char c) {
    write(1, &c, 1);
}

void mx_only_printable(void) {
	for(int i = 126; i >= 32; i--){
		mx_printchar(i);
	}
	mx_printchar('\n');
}
