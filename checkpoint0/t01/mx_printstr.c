#include <stdio.h>
#include <unistd.h>
#include <string.h>

int mx_strlen(const char *s);
void mx_printstr(const char *s);

int mx_strlen(const char *s) {
	int count = 0;
	char c = s[0];
	while (c != '\0') {
		count++;
		c = s[count];
	}
	return count;
}

void mx_printstr(const char *s){
	write(1, s, mx_strlen(s));
}
