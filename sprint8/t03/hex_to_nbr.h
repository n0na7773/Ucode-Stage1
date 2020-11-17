#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdbool.h>

bool mx_isupper(int);
bool mx_islower(int c);
bool mx_isspace(char c);
bool mx_isdigit(int c);
unsigned long mx_hex_to_nbr(const char *hex);

#endif
