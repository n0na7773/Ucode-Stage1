#include <stdlib.h>
#include <stdio.h>

char *mx_strcpy(char *dst, const char* src);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strcat(char *s1, const char *s2);
char *mx_strdup(const char *str);

char *mx_strjoin(char const *s1, char const *s2){
    if (s1 == NULL && s2 == NULL){
        return NULL;
    }
    if(s1 == NULL && s2 != NULL){
        char *c  = mx_strnew(mx_strlen(s2));
        c = mx_strdup(s2);
        return c;
    }
    if(s2 == NULL && s1 != NULL){
        char *c  = mx_strnew(mx_strlen(s1));
        c = mx_strdup(s1);
        return c;
    }
    char *s = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    mx_strcat(s,s1);
    mx_strcat(s,s2);
    return s; 
}
