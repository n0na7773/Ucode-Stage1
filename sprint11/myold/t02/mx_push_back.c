#include "list.h"

void mx_push_back(t_list **list, void *data){
    if (!data) return;
    t_list *new_node = mx_create_node(data);
    if (!new_node) return;
    t_list *last = *list;
    while(last->next != NULL) last = last->next;
    last->next = new_node;
}
