#include <stdio.h>

int mx_strncmp(const char *s1, const char *s2, int n);
char* mx_strchr(const char*s, int c);
int mx_strlen(const char *s);

char *mx_strstr(const char *s1, const char *s2) {
    while (*s1) {
		const char *start = s1;
		const char *sub = s2;
		while (*s1 && *sub && *s1 == *sub) {
		    s1++;
		    sub++;
		}
		if (!*sub) return (char*)start;	  
		s1 = start + 1; 
	}
	return NULL;
}
