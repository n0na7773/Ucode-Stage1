void mx_printstr(const char *s);
void mx_printchar(char c);
int mx_strcmp(const char *s1, const char *s2);
int mx_strlen(const char *s);

int main(int argc, char *argv[]) {
    char *tmp = 0;
    if (argc < 2) return 0;
    else {
        for (int i = 1; i < argc - 1; i++) {
            for (int j = 1; j < argc - 1; j++) {
                if (mx_strcmp(argv[j], argv[j + 1]) > 0) {
                    tmp = argv[j];
                    argv[j] = argv[j + 1];
                    argv[j + 1] = tmp;
                }
            }
        }
        for (int i = 1; i < argc; i++) {
            mx_printstr(argv[i]);
            mx_printchar('\n');
        }
    }
    return 0;
}
