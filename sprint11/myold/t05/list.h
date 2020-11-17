#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    void*data;
    struct s_list*next;
}              t_list;

int mx_list_size(t_list *list);

#endif
