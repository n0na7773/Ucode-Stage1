#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char *mx_strncpy(char *dst, const char *src, int len);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
void mx_strdel(char **str);
bool mx_isspace(char c);
char *mx_strtrim(const char *str);

char *mx_del_extra_whitespaces(const char *str){
    if (str == NULL) return NULL;
    char *c = mx_strtrim(str); 
    int spaces = 0;
    for (int i = 0; i < mx_strlen(c); i++){
        if (mx_isspace(c[i]) && mx_isspace(c[i+1])) spaces++;
    }
    int len = mx_strlen(c) - spaces;
    char *cc = mx_strnew(len);
    int first_space = 0;
    for (int i = 0, z = 0; i < len; z++){
        if(mx_isspace(c[z])) {
            if(first_space == 1){
                continue;
            }
            first_space = 1;
        }
        else { 
            first_space = 0;
        }
        cc[i] = c[z];
        i++;                    
    }    
    free(cc);
    return cc;
}
