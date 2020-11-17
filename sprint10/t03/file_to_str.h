#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char *mx_strnew(const int size);
char *mx_file_to_str(const char *filename);

#endif
