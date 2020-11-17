#include <stdlib.h>
#include <stdio.h>

char *mx_strnew(const int size){
    if (size < 0) return NULL;
    char *s = malloc(size + 1);
    for (int i = 0; i < size; i++) s[i] = '\0';
    return s;
}

char *mx_nbr_to_hex(unsigned long nbr){
    unsigned long q = nbr; 
    int r, size = 0, j = 0;
    long temp = nbr;
    while (temp != 0){
        size++;
        temp /= 16;
    }
    char *hex  = mx_strnew(size);
    while (q != 0){
        r = q % 16;
        if (r < 10)
            hex[j] = 48 + r;
        else 
            hex[j] = 87 + r;
        j++;
        q /= 16;
    }
    j--;
    for (int i = 0; i < j; i++, j--){
        char tmp = hex[i];
        hex[i] = hex[j];
        hex[j] = tmp;
    }
    return hex;
}
