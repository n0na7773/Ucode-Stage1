#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list {
    void*data;
    struct s_list*next;
}              t_list;

t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);

#endif
