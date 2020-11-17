#include "header.h"

int main(int argc, char *argv[]) {
    if (argc >= 2) {
        for (int i = 1; i < argc; i++) {
            int source  = open(argv[i], O_RDONLY);
            if (source < 0) {
                mx_printerr("mx_cat: ");
                mx_printerr(argv[1]);
                mx_printerr(": No such file or directory\n");
                close(source);
                exit(-1);
            }
            char c;
            while(read(source, &c, 1) != 0) {
                mx_printchar(c);
            }        
            if (close(source) < 0) {            
                return 0;
            }

        }
        return 0; 
    }
    else if (argc == 1){
        char c;
        while (read(0, &c, 1) > 0 && c != '\n') mx_printchar(c);
        mx_printchar('\n');      
        return 0;
    }
}
