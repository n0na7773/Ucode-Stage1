#ifndef HEADER_H
#define HEADER_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>


typedef struct s_agent 
{
    char *name;
    int power;
    int strength;
}           t_agent;

int mx_strlen(const char *s);
void mx_printerr(const char *s);
void mx_printstr(const char *s);
int mx_strlen(const char *s);
void mx_printchar(char c);
int mx_count_words(const char *str, char delimiter);
char *mx_strnew(const int size);
char *mx_file_to_str(const char *filename);
bool mx_isspace(char c);
void mx_printint(int n);
int mx_strcmp(const char *s1, const char *s2);
char* mx_strchr(const char*s, int c);
char *mx_strdup(const char *str);
char *mx_strstr(const char *haystack, const char *needle);
int mx_strncmp(const char *s1, const char *s2, int n);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strcpy(char *dst, const char* src);

#endif
