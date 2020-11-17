#include <limits.h>
int mx_factorial_iter(int n);

int mx_factorial_iter(int n){
    if(n > INT_MAX || n < 0){
        return 0;
    }
    int fact = 1;
    for (int i = 1; i <= n; i++){
        if (fact > INT_MAX) return 0;
        fact *= i;
    }
    return fact;
}

