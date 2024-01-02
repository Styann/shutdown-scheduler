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