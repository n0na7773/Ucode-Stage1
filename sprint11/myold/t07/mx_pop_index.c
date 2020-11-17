#include "list.h"

void mx_pop_index(t_list **list, int index) {
    if(list == NULL || *list == NULL) return;
    t_list *len = *list;
    int size=0;
    while (len != NULL) {
        size++;
        len = len->next;
    }
    if(index <= 0) {
        mx_pop_front(list);
        return;
    }
    if(index >= size) {
        mx_pop_back(list);
        return;
    }
    t_list *current = *list;
    t_list *temp_node = NULL;
	for (int count = 0; count < index - 1; count++)
		current = current->next;
	temp_node = current->next;
	current->next = temp_node->next;
    free(temp_node);
    temp_node = NULL;
}
