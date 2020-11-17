#include <stdbool.h>

bool mx_isupper(int);

bool mx_islower(int c){
    if (c >= 97  && c <= 122) {
        return true;
    } 
    else {
        return false;
    }
}

