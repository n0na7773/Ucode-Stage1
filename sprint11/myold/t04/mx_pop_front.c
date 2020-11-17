#include "list.h"

void mx_pop_front(t_list **list){
    t_list *current = *list;
    if (current->next == NULL) {
        return;
    }
    t_list *next_node = NULL;
    next_node = current->next;
    free(current);
    current = next_node;
}
