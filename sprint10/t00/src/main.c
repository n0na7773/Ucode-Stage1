#include "header.h"

int main(int argc, char *argv[]) {
    if (argc == 2) {
        int file  = open(argv[1], O_RDONLY);
        if (file < 0) {
            mx_printerr("error\n");
            close(file);
            return 0;
        }
        char c[1];
        int buffer = 1;
        while(buffer != 0) {
            buffer = read(file, &c, 1);
            if (buffer == 0) continue;
            mx_printchar(c[0]);
        }        
        if (close(file) < 0) {
            mx_printerr("error\n");
            return 0;
        }
        return 0;
    }
    else{
        mx_printerr("usage: ./read_file [file_path]\n");
        return 0;
    }
}
