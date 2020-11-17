#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    void*data;
    struct s_list*next;
}              t_list;

void mx_pop_back(t_list **list);

#endif
