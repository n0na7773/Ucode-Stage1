#include "duplicate.h"

t_intarr *mx_del_dup_sarr(t_intarr *src) {
  if (src == NULL)
    return NULL;
  int *arr = mx_copy_int_arr(src, src->size);
  int t = 0;
  int k = -1;
  for (int i = 0; i < src->size; i++) {
    k = 0;
    for (int j = i; j < src->size; j++) {
      if (src->arr[i] == src->arr[j] && i != j) {
        k = 0;
      }
      else {
        for (int p = 0; p < t; p++) {
          if (src->arr[i] == arr[p]) {
            k = 1;
          }
        }
        if (k != 1) {
          arr[t] = src->arr[i];
          t++;
          k = 0;
          break;
        }

      }
    }
  }
  return arr;
}
int main() {
  int *arr1 = {0,1,2,3};
  t_intarr *a;
  a->size = 2;
  a->arr = mx_copy_int_arr(a->arr, arr1);
}
