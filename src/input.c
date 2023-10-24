#include "input.h"

int input_days_to_add() {
	int input;
    int is_ok = 0;

    char *reset_console_color = "\033[0m";
    char *purple_console_color = "\x1B[35m";

    /*char zero[32];
    snprintf(zero, sizeof(zero), "%s%c%s", GREEN_CONSOLE_COLOR, '0', RESET_CONSOLE_COLOR);
    char n[32];
    snprintf(n, sizeof(n), "%s%c%s", GREEN_CONSOLE_COLOR, 'N', RESET_CONSOLE_COLOR);
*/
    while(!is_ok){
        /*char *dt_now = datenow_to_str("%d/%m/%Y");
        snprintf(dt_now, sizeof(dt_now), "%c", PURPLE_CONSOLE_COLOR, *dt_now, RESET_CONSOLE_COLOR);

        printf("Type a number between %s and %s (%s is today (%s)) : ", zero, n, zero, dt_now);
        free(dt_now);*/
        scanf("%d", &input);
        fflush(stdin);
        if(input>=0) is_ok = 1;
    }
	
	return input;
}


int input_from_list(char *text, int list[], int size){
    int input;
    int is_ok = 0;

    while(!is_ok){
        printf(text);
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

void input_time(char* text, int *hour, int *minute, int *second){
    int is_ok = 0;

    do{
        printf(text);
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