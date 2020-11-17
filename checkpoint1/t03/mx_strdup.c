#include <stdlib.h>
#include <stdio.h>

char *mx_strcpy(char *dst, const char* src) {
    int i = 0;
    while (src[i] !=  '\0') {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return dst;
}
int mx_strlen(const char *s) {
    int count = 0;
    char i = s[0];
    while (i != '\0') {
        count++;
        i = s[count];
    }
    return count;
}
char *mx_strnew(const int size){
    if (size < 0) return NULL;
    char *s = malloc(size + 1);
    for (int i = 0; i < size; i++) s[i] = '\0';
    return s;
}
char *mx_strdup(const char *str) {
    char *cp = mx_strnew(mx_strlen(str));
    if (cp == NULL) return NULL;          
    mx_strcpy(cp, str);                      
    return cp;                            
}
