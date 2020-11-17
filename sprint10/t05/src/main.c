#include "../inc/header.h"	

int main(int argc, char *argv[]) {
    if (argc == 3) {
        if (mx_strncmp(argv[1], "-p", 2) != 0 && mx_strncmp(argv[1], "-s", 2) != 0 && mx_strncmp(argv[1], "-n", 2) != 0){
            mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
            return 0;
        }
        int source = open(argv[2], O_RDONLY);
        if (source < 0) {
            mx_printerr("error\n");
            close(source);
            exit(-1);
        }
       
        char *text = mx_file_to_str(argv[2]);
        char *cpy = mx_strdup(text);
        int number_of_agents = 0;
        while (cpy) {
            char *test = mx_strnew(5);
            mx_strncpy(test, cpy, 5);
            if (mx_strcmp(test, "agent") == 0)  {
                number_of_agents++;
                cpy += 5;
            }     
            free(test);
            test = NULL;                 
            cpy = mx_strstr(cpy, "agent");
        }
        if (number_of_agents == 0) {
            mx_printerr("error\n");
            exit(-1);
        }
        t_agent **arr = malloc(16 * number_of_agents);
        for (int i = 0; i < number_of_agents; i++) arr[i] = malloc(16);
        
        text = mx_file_to_str(argv[2]);
        text = mx_strstr(text, "agent");

        for (int i = 0; i < number_of_agents; i++) {
            text = mx_strstr(text, "name: ");
            if (text == NULL) {
                number_of_agents--;
                text = mx_strstr(text, "agent");
                continue;
            }
            text += 6;

            int len = 0;
            while (text[len] != '\n')
                len++;

            char *name = mx_strnew(len);
            mx_strncpy(name, text, len);
            arr[i]->name = mx_strdup(name);

            free(name);
            name = NULL;

            text += len;
            text = mx_strstr(text, "power: ");
            if (text == NULL) {
                number_of_agents--;
                text = mx_strstr(text, "agent");
                continue;
            }
            text += 7;

            len = 0;
            while (text[len] != '\n')
                len++;

            char *power = mx_strnew(len);
            mx_strncpy(power, text, len);

            int p = 0;

            for (int i = 0; i < len; i++) {
                p *= 10;
                p += (int)power[i] - 48;
            }

            arr[i]->power = p;
        
            free(power);
            power = NULL;

            text += len;
            text = mx_strstr(text, "strength: ");
            if (text == NULL) {
                number_of_agents--;
                text = mx_strstr(text, "agent");
                continue;
            }
            text += 10;

            len = 0;
            while (text[len] != '\n')
                len++;

            char *strength = mx_strnew(len);
            mx_strncpy(strength, text, len);

            int s = 0;

            for (int i = 0; i < len; i++) {
                s *= 10;
                s += (int)strength[i] - 48;
            }

            arr[i]->strength = s;
        
            free(strength);
            strength = NULL;

            if (mx_strstr(text, "agent") != NULL)
               text = mx_strstr(text, "agent");
            else break;
        }
        int situation = -1;

        switch (argv[1][1]) {
            case 'n': situation = 0; break;
            case 'p': situation =  1; break;
            case 's': situation = 2; break;
        }

        for (int i = 0; i < number_of_agents; i++) {  
            int min_idx = i;  

            for (int j = i; j < number_of_agents - 1; j++) {
                switch (situation) {
                    case 0: {
                        if (mx_strcmp(arr[min_idx]->name, arr[j + 1]->name) > 0)
                            min_idx = j + 1;
                    }; break;
                    case 1: {
                        if (arr[min_idx]->power > arr[j + 1]->power)
                            min_idx = j + 1; 
                    }; break;
                    case 2: {
                        if (arr[min_idx]->strength > arr[j + 1]->strength)
                            min_idx = j + 1; 
                    }; break;
                }
            }
        
            if (min_idx != i) {
                t_agent *temp = arr[min_idx];
                arr[min_idx] = arr[i];
                arr[i] = temp;
            }
        }
        for (int i = 0; i < number_of_agents; i++) {
            mx_printstr("agent: ");
            mx_printstr(arr[i]->name);
            mx_printstr(", strength: ");
            mx_printint(arr[i]->strength);
            mx_printstr(", power: ");
            mx_printint(arr[i]->power);
            mx_printchar('\n');
        }  
        if (close(source) < 0) {            
            return 0;
        }
        for (int i = 0; i < number_of_agents; i++) {
            free(arr[i]->name);
            arr[i]->name = NULL;

            free(arr[i]);
            arr[i] = NULL;
        }

        free(arr);
        arr = NULL;
        free(cpy);
        cpy = NULL;
        text = NULL;
        return 0;
    }
    else {
        mx_printerr("usage: ./parse_agents [-p | -s | -n] [file_name]\n");
        return 0;
    }
}
