#include <stdlib.h>
#include <stdio.h>

char *mx_strcpy(char *dst, const char* src);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
char *mx_strcat(char *s1, const char *s2);
char *mx_strdup(const char *str);
char *mx_strjoin(char const *s1, char const *s2);
void mx_strdel(char **str);

char *mx_concat_words(char **words){
    if (words == NULL) return NULL;   
    int len = 0;
    for (int i = 0; words[i] != NULL; i++) 
        len += mx_strlen(words[i]) + 1; //word + space
    len--;                              //for the last one space
    char *c = mx_strnew(len);
    for (int i = 0; words[i] != NULL; i++) 
        c = mx_strcat(c, mx_strjoin(words[i], " "));
    c[len] = '\0';
    free(c);
    return c;
}
