#include "header.h"

int main(int argc, char *argv[]) {
    if (argc == 3) {
        int source  = open(argv[1], O_RDONLY);
        if (source < 0) {
            mx_printerr("mx_cp: ");
            mx_printerr(argv[1]);
            mx_printerr(": No such file or directory\n");
            close(source);
            exit(-1);
        }
        int destination = open(argv[2], O_EXCL | O_CREAT, 0666);
        if (destination < 0) {
            close(destination);
            exit(-1);
        }
        else {
            close(destination);
            destination = open(argv[2], O_WRONLY);        
            if (destination < 0) {
                close(destination);
                exit(-1);
            }
        }
        char c[1];
        int buffer = 1;
        while(buffer != 0) {
            buffer = read(source, &c, 1);
            if (buffer == 0) continue;
            write(destination, &c, 1);
        }        
        if (close(source) < 0) {            
            return 0;
        }
        if (close(destination) < 0) {            
            return 0;
        }
        return 0;
    }
    else{
        mx_printerr("usage: ./mx_cp [source_file] [destination_file]\n");
        return 0;
    }
}
