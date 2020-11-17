#include "list.h"

void mx_pop_back(t_list **list){
    t_list *current = *list;
    if (current->next == NULL) {
        free(current);
        current = NULL;
        return;
    }
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
}
