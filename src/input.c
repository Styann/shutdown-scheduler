#include "input.h"
#include "format.h"

void clear(){
    //fseek(stdin, 0, SEEK_END);
    fflush(stdin);
}

int input_days_to_add() {
	int input;	
    int is_ok = 0;

    while(!is_ok){
        printf("Type a number between 0 and N (0 is today (%s)) : ", datenow_to_string());
        scanf("%d", &input);     
        clear();
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
        clear();

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
        clear();
        //printf("\n%d:%d:%d\n", hour, minute, second);

        if(*hour >= 0 && *hour < 24){
            if(*minute >= 0 && *minute < 60){
                if(*second >= 0 && *second < 60){
                    is_ok = 1;
                }
            }
        }
    } while (!is_ok);
}