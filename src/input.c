#include "input.h"

int input_days_to_add(void) {
	int input;
    int is_ok = 0;

    while(!is_ok){
        char *dt_now = datenow_to_str("{%d}/{%m}/{%Y}");
    
        char message[512];
        sprintf(message, "Type a number between {0} and {N} ({0} is today (%s)) : ", dt_now);
        printc(message, ANSI_COLOR_GREEN, '{', '}');

        free(dt_now);

        scanf("%d", &input);
        fflush(stdin);

        if(input >= 0) is_ok = 1;
    }

	return input;
}

int input_from_list(const char *message, int list[], int size){
    int input;
    int is_ok = 0;

    while(!is_ok){
        printf("%s", message);

        scanf("%d", &input);
        fflush(stdin);

        for(int i = 0; i<size; i++){
            if(input == list[i]){
                is_ok = 1;
                break;
            }
        }
    }

    return input;
}

void input_time(const char* message, int *hour, int *minute, int *second){
    int is_ok = 0;

    do{
        printf("%s", message);

        scanf("%2d:%2d:%2d", hour, minute, second);
        fflush(stdin);

        if(*hour >= 0 && *hour < 24){
            if(*minute >= 0 && *minute < 60){
                if(*second >= 0 && *second < 60){
                    is_ok = 1;
                }
            }
        }
    } while (!is_ok);

    return;
}

bool str_to_int(int *dest, char const *str){
    if(isdigit(*str) != 0){
        *dest = atoi(str);
        return true;
    }
    return false;
}

bool convert_timestr_to_int(char const *str, int *hour, int *minute, int *second){
    char *token = strtok((char*)str, ":");
    if(token == NULL || !str_to_int(hour, token)) return false;
    
    token = strtok(NULL, ":");
    if(token == NULL || !str_to_int(minute, token)) return false;
  
    token = strtok(NULL, ":");
    if(token == NULL || !str_to_int(second, token)) return false;
    
    return true;
}

bool parse_time(int *hour, int *minute, int *second){
    if(*hour >= 0 && *hour < 24){
        if(*minute >= 0 && *minute < 60){
            if(*second >= 0 && *second < 60){
                return true;
            }
        }
    }
    return false;
}