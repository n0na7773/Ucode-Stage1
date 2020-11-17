#include "minilibmx.h"

int mx_add(int a, int b) {
    return (a + b);
}
int mx_sub(int a, int b) {
    return (a - b);
}
int mx_mul(int a, int b) {
    return (a * b);
}
int mx_div(int a, int b) {
    return (a / b);
}

void mx_operation_question(char *a, char *b, char *c, int check){
    if (check == 0)
    if(mx_add(mx_atoi(a), mx_atoi(b)) == mx_atoi(c)) printf("%s + %s = %s\n", a, b, c);
    if (check == 1)
    if(mx_sub(mx_atoi(a), mx_atoi(b)) == mx_atoi(c)) printf("%s - %s = %s\n", a, b, c);
    if (check == 2)
    if(mx_mul(mx_atoi(a), mx_atoi(b)) == mx_atoi(c)) printf("%s * %s = %s\n", a, b, c);
    if (check == 3){
        if(mx_atoi(b) == 0) NULL;
        else if(mx_div(mx_atoi(a), mx_atoi(b)) == mx_atoi(c)) printf("%s / %s = %s\n", a, b, c);
    }

}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        char *proper_usage = "usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n";
        write(2, proper_usage, mx_strlen(proper_usage));
        exit(-1);
    }
    char *first_char;
    char *operation;
    char *second_char;
    char *result_char;
    bool space_before_char = false;
    for(int i = 1; i < argc; ++i){
        space_before_char = true;
        for(int j = 0; space_before_char; ++j){
            if(argv[i][j] != ' '){
                switch (i){
                    case 1: first_char = mx_strdup(&argv[1][j]); space_before_char = false; break;
                    case 2: operation = mx_strdup(&argv[2][j]); space_before_char = false; break;
                    case 3: second_char = mx_strdup(&argv[3][j]); space_before_char = false; break;
                    case 4: result_char = mx_strdup(&argv[4][j]); space_before_char = false; break;
                }
            }
        }
    }

    bool first_char_b = false;
    bool second_char_b = false;
    bool result_char_b = false;
    bool operation_b = false;

    for(int i = 1; i < argc; ++i){
        for(int j = 0; argv[i][j] != '\0'; ++j){
            if(argv[i][j] == '?'){
                switch(i){
                    case 1: first_char_b = true; break;
                    case 2: operation_b = true; break;
                    case 3: second_char_b = true; break;
                    case 4: result_char_b = true; break;
                }
            }
        }
    }

    //Error handling

    if (mx_atoi(first_char) == -351351351) {
        write(2,"Invalid operand: ", 17);
        write(2, first_char, mx_strlen(first_char));
        exit(-1);
    }
    if (mx_strlen(operation) != 1 || (operation[0] != '+' && operation[0] != '-' && operation[0] != '*' && operation[0] != '/' && operation[0] != '?')) {
        write(2,"Invalid operation: ", 19);
        write(2, operation, mx_strlen(operation));
        exit(-1);
    }
    if (mx_atoi(second_char) == -351351351) {
        write(2,"Invalid operand: ", 17);
        write(2, second_char, mx_strlen(second_char));
        exit(-1);
    }
    if (mx_atoi(result_char) == -351351351) {
        write(2,"Invalid result: ", 16);
        write(2, result_char, mx_strlen(result_char));
        exit(-1);
    } 

    // Loop
    int check = 0;
    //int dig_counter = 0;
    bool solo = true;
    if (operation_b && !first_char_b && !second_char_b && !result_char_b) {
        while (check < 4) {
            mx_operation_question(first_char, second_char, result_char, check);
            check++;
        }
    }
    else if (operation_b && first_char_b && !second_char_b && !result_char_b) {
        for (int i = 0; first_char[i]; ++i){
            if (first_char[i] == '?'){
                check = 0;
                for(int j = 0; j < 10; ++j){
                    first_char[i] = j + 48;
                    mx_operation_question(first_char, second_char, result_char, check);
                    if (j == 9 && check < 4){
                        j = -1;
                        check++;
                    }
                }
            }
        }
    }
    else if (operation_b && !first_char_b && second_char_b && !result_char_b) {
        for (int i = 0; second_char[i]; ++i){
            if (second_char[i] == '?'){
                check = 0;
                for(int j = 0; j < 10; ++j){
                    second_char[i] = j + 48;
                    mx_operation_question(first_char, second_char, result_char, check);
                    if (j == 9 && check < 4){
                        j = -1;
                        check++;
                    }
                }
            }
        }
    }
    else if (operation_b && !first_char_b && !second_char_b && result_char_b) {
        for (int i = 0; result_char[i]; ++i){
            if (result_char[i] == '?'){
                check = 0;
                for(int j = 0; j < 10; ++j){
                    result_char[i] = j + 48;
                    mx_operation_question(first_char, second_char, result_char, check);
                    if (j == 9 && check < 4){
                        j = -1;
                        check++;
                    }
                }
            }
        }
    }
    free(first_char);
    free(second_char);
    free(result_char);
    free(operation);
}
