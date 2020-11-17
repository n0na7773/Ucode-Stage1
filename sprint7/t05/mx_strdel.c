#include <stdlib.h>
#include <stdio.h>

void mx_strdel(char **str) {
    if (!*str || !str) return;
    free(*str);
    *str = NULL;                 
}

/*int main() {
    char *arr1 = malloc(7);
    char *arr = "Hello!";
    int i=0;
    while (arr1[i] !=  '\0') {
        arr1[i] = arr[i];
        i++;
    }
    mx_strdel(&arr1);
    printf("%s", arr1);
}*/
