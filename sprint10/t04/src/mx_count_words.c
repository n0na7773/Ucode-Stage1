#include "header.h"

int mx_count_words(const char *str, char delimiter) {
    int i = 0;
    int res;
    if (str[i++] != delimiter) res = 1;
    else res = 0;
    while (str[i] != '\0') {
        if (delimiter == ' ') {
            if (!mx_isspace(str[i])) {
                i++;
            }
            if (mx_isspace(str[i])) {
                if (!mx_isspace(str[i+1]) && str[i+1] != '\0') {
                    res++;
                }
                i++;
            }
        }
        else {
            if (str[i] != delimiter) {
                i++;
            }
            if (str[i] == delimiter) {
                if (str[i+1] != delimiter && str[i+1] != '\0') {
                    res++;
                }
                i++;
            }
        }
    }
    return res;
}
