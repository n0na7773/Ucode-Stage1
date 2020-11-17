#include <stdio.h>
char *mx_strncpy(char *dst, const char *src, int len) {
    if ((dst == NULL) &&(src == NULL))
        return NULL;
    char *temp = dst;  
    while (*src && len--){
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    return temp;
}
