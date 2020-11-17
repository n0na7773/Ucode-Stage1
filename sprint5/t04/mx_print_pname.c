void mx_printstr(const char *s);
void mx_printchar(char c);
char* mx_strchr(const char*s, int c);

int main(int argc, char *argv[]) {
    char *str = argv[argc - argc];
    while (mx_strchr(str,'/')) {
        str = mx_strchr(str,(int)'/');
        str++;
    }
    mx_printstr(str);
    mx_printchar('\n');
}
