#include "input.h"

int input_days_to_add() {
	int input;
    int is_ok = 0;

    while(!is_ok){
        char *dt_now = datenow_to_str();
        printf("Type a number between 0 and N (0 is today (%s)) : ", dt_now);
        free(dt_now);
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