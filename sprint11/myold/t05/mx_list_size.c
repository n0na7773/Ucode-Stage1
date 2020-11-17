#include "list.h"

int mx_list_size(t_list *list){   
    int res = 0;
    t_list *temp = list;
    while(temp != NULL) {
        temp = temp->next;
        res++;
    }
    return res;
}
