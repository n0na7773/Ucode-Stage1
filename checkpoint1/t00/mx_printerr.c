#include <unistd.h>

int mx_strlen(const char *s) {
    int count = 0;
    char i = s[0];
    while (i != '\0') {
        count++;
        i = s[count];
    }
    return count;
}

void mx_printerr(const char *s){
    write(2, s, mx_strlen(s));
}
