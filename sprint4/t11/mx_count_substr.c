#include <stdio.h>

int mx_strncmp(const char *s1, const char *s2, int n);
char* mx_strchr(const char*s, int c);
int mx_strlen(const char *s);
char *mx_strstr(const char *s1, const char *s2);

int mx_count_substr(const char *str, const char *sub) {
    int res = 0;
    while (*str) {
        const char *tmp = str;
        if(tmp == mx_strstr(tmp, sub)) {
            res++;
            tmp += mx_strlen(sub);
            str = tmp;
        }
        else str = tmp + 1;  
    }
    return res;
}
