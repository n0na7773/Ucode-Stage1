#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
bool mx_isdigit(int c);
int mx_atoi(const char *str);
void mx_printint(int n);
void mx_printchar(char c);

int main(int argc, char *argv[])  {
    int sum = 0;
    if ( argc == 1) {
        return 0;
    }
    for (int i = 1; i < argc; i++){
        bool dig = 1;
        for (int j = 0; j < argv[i][j]; j++){
            if (argv[i][j] == '+' && argv[i][j+1] > 47 && argv[i][j+1] < 58){
                break;
            }
            else if (argv[i][j] == '-' && argv[i][j+1] > 47 && argv[i][j+1] < 58){
                break;
            }
            else {
                dig = 0;
                if (mx_isdigit(argv[i][j])) {
                    dig = 1;
                    continue;
                }
                break;
            }
        }
        if ( dig == 1)
            sum += mx_atoi(argv[i]);
    }
    mx_printint(sum);
    mx_printchar('\n');
    return 0;
}
