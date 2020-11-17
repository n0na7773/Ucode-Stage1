int mx_strlen(const char *s);
void mx_swap_char(char *s1, char *s2);
void mx_str_reverse(char *s);

int mx_strlen(const char *s) {
    int count = 0;
    char i = s[0];
    while (i != '\0') {
        count++;
        i = s[count];
    }
    return count;
}
void mx_swap_char(char *s1, char *s2) {
    char temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

void mx_str_reverse(char *s) {
    int len = mx_strlen(s);
    int i = 0;
    while(i < len/2){
        mx_swap_char(&s[i], &s[len - 1 - i]);
        i++;
    }
}
