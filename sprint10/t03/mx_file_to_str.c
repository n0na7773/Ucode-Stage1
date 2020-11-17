#include "file_to_str.h"

char *mx_file_to_str(const char *filename){
    int source  = open(filename, O_RDONLY);
    if (source < 0) {
        close(source);
        return NULL;
    }  
    char c[1];
    int len = 0;
    while(read(source, &c, 1) != 0){
        len++;
    } 
    if (close(source) < 0) {
        return NULL;
    }
    source  = open(filename, O_RDONLY);
    if (source < 0) {
        close(source);
        return NULL;
    } 
    char *str = mx_strnew(len);
    read(source, str, len);
    str[len] = '\0';
    if (close(source) < 0) {
        return NULL;
    }     
    return str;
}
