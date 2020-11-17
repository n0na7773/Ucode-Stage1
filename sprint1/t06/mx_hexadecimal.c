#include <stdio.h>

void mx_printchar(char c);

void mx_hexadecimal(void) {
	for(int i = 0; i < 16; i++){
		char c = i < 10 ? i + 48 : i + 55;
		mx_printchar(c);
	}
	mx_printchar('\n');
}
