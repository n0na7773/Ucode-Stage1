#include <stdio.h>
#include <stdbool.h>

bool mx_isdigit(int c);
bool mx_isspace(char c);

int mx_atoi(const char *str) {
    int res = 0;
    int sign = 1;
    int i = 0;
    while (mx_isspace(str[i]) == true) i++;
    if (str[i] == '-' || str[i] == '+') {
            sign = 1 - 2 * (str[i++] == '-');
        }
    for (; str[i]; i++) {    
        if (mx_isdigit(str[i])) {
            res = 10 * res + (str[i] - '0');
        }
        if (!mx_isdigit(str[i])) return -351351351;
    }
    return res*sign;
}
