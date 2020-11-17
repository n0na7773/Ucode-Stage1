#include <stdlib.h>
#include <stdio.h>

char *mx_strcpy(char *dst, const char* src);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strdup(const char *str) {
    char *cp = mx_strnew(mx_strlen(str));
    if (cp == NULL) return NULL;          
    mx_strcpy(cp, str);                      
    return cp;                            
}
