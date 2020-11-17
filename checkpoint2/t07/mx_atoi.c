#include <stdbool.h>

static bool mx_isdigit(int c) {
    if (c >= 48 && c <= 57)
        return true;
    else    
        return false;
}

int mx_atoi(const char *str) {
    int i = -1;
    int result = 0;

    while (str[++i]) {
        if (mx_isdigit(str[i]))
            result = result * 10 + str[i] - '0';
        if (!mx_isdigit(str[i]))
            return result;
    }
    return result;
}
