#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char *mx_strncpy(char *dst, const char *src, int len);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
void mx_strdel(char **str);
bool mx_isspace(char c);

char *mx_strtrim(const char *str){
    if (str == NULL) return NULL;   
    int start = 0;
    int end = mx_strlen(str);
    while(mx_isspace(str[start])) start++;
    while(mx_isspace(str[end - 1])) end--;
    int len = end - start;
    char *c = mx_strnew(len);
    mx_strncpy(c, str + start, len);
    c[len] = '\0';
    free(c);
    return c;
}
