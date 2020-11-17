#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *mx_strnew(const int size);
void mx_printchar(char c);
void mx_printerr(const char *s);
int mx_strlen(const char *s);
char *mx_strnew(const int size);
void mx_printstr(const char *s);

void mx_printchar(char c) {
	write(1,&c,1);
}

void mx_printstr(const char *s) {
	write(1, s, mx_strlen(s));
}

void mx_printerr(const char *s) {
    write(2, s, mx_strlen(s));
}	

int mx_strlen(const char *s) {
    int count = 0;
    while (s[count]) 
        count++;
    return count;
}

char *mx_strnew(const int size) 
{
    char *buff = NULL;
    if (size > 0) 
    { 
        buff = malloc(size+1);
        buff[size] = '\0';    
    }
    return buff;
}

int main(int argc, char *argv[])
{
    int file_des;
    int file_len = 0;
    int i = 0;
    char buf[1];
    char *target_str = NULL;
    const char *s = "error";
    const char *v = "usage: ./read_file [file_path]";

    if (argc == 2)
    {
        file_des = open(argv[1], O_RDONLY);
        if (file_des < 0)
        {
            mx_printerr(s);
            return 0;
        }
        while (read(file_des, buf, 1))
            file_len++;
        target_str = (char *)mx_strnew(file_len);
        if (target_str == NULL)
        {
            mx_printerr(s);
            return 0;
        }
        close(2);
        file_des = open(argv[1], O_RDONLY);
        if (file_des < 0){
            mx_printerr(s);
            return 0;
        }
        while (read(file_des, buf, 1))
        {
            target_str[i] = buf[0];
            i++;
        }
        target_str[i] = '\0';
        mx_printstr(target_str);
    }
    else
    {
        mx_printstr(v);
        mx_printchar('\n');
    }
}
