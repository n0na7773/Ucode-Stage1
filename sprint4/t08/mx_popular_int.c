int mx_popular_int(const int *arr, int size){
    int res = 0;
    int max = 0;
    int value;
    int maxvalue;
    for (int i = 0; i < size; i++) {
        value = arr[i];
        res = 0;
        for (int j = 0; j < size; j++){
            if (arr[j] == value) res++;
        }
        if (res > max) {
            max = res;
            maxvalue = value;
        }
    }
    return maxvalue;
}
