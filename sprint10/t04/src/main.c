#include "header.h"

int main(int argc, char *argv[]) {
    if (argc >= 2) {
        if (mx_strcmp(argv[1],".") == 0){
            mx_printerr("mx_wc: ");
            mx_printerr(argv[1]);
            mx_printerr(": read: Is a directory\n");
            exit(-1);
        }
        int words_t = 0;
        int lines_t = 0;
        int bytes_t = 0;
        for (int i = 1; i < argc; i++) {
            int source = open(argv[i], O_RDONLY);
            if (source < 0) {
                mx_printerr("mx_wc: ");
                mx_printerr(argv[1]);
                mx_printerr(": open: No such file or directory\n");
                close(source);
                exit(-1);
            }
            int words = mx_count_words(mx_file_to_str(argv[i]), ' ');
            int lines = 0;
            char c;
            int bytes = 0;
            while (read(source, &c, 1) > 0) {
                if (c == '\n') lines++;
                bytes++;
            }     
            if (close(source) < 0) {            
                return 0;
            }
            mx_printchar('\t');
            mx_printint(lines);
            mx_printchar('\t');
            mx_printint(words);
            mx_printchar('\t');
            mx_printint(bytes);
            mx_printchar(' ');
            mx_printstr(argv[i]);
            mx_printchar('\n');
            words_t += words;
            lines_t += lines;
            bytes_t += bytes;
        }
        if (argc > 2) {
            mx_printchar('\t');
            mx_printint(lines_t);
            mx_printchar('\t');
            mx_printint(words_t);
            mx_printchar('\t');
            mx_printint(bytes_t);
            mx_printchar(' ');
            mx_printstr("total");
            mx_printchar('\n'); 
        }
        return 0; 
    }
    else if (argc == 1){
        int words = 0;
        int lines = 0;
        char c;
        int bytes = 0;
        while (read(0, &c, 1) > 0) {
            bytes++;
            if(c == '\n') lines++;
            if(mx_isspace(c)) words++;
        }
        mx_printchar('\t');
        mx_printint(lines);
        mx_printchar('\t');
        mx_printint(words);
        mx_printchar('\t');
        mx_printint(bytes);
        mx_printchar('\n');      
        return 0;
    }
}
