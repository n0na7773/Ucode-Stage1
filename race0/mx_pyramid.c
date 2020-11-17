void mx_printchar(char c);
void mx_pyramid(int n){
    if (n > 1 && n % 2 == 0) {
        //first line
        //-----------------------------
        for (int i = 0; i < n-1; i++) mx_printchar(' ');
        mx_printchar('/');
        mx_printchar('\\');
        mx_printchar('\n');
        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n-2 - i; j++) mx_printchar(' ');
            mx_printchar('/');
            for (int j = 0; j < 1 + i*2; j++) mx_printchar(' ');
            mx_printchar('\\');         
            if (i >= (n-2)/2)
            {   
                for (int j = 0; j < n-2-i; j++) mx_printchar(' ');
                mx_printchar('|');
            }
            else {
                for (int j = 0; j < i + 1; j++) mx_printchar(' ');
                mx_printchar('\\');
            }
            mx_printchar('\n');
        }
        mx_printchar('/');
        for (int i = 0; i < 2 * n - 3; i++) mx_printchar('_');
        mx_printchar('\\');
        mx_printchar('|');
        mx_printchar('\n');
    }
}
