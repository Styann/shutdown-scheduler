#include "input.h"
#include "format.h"

void clear(){
    //fseek(stdin, 0, SEEK_END);
    fflush(stdin);
}

int inputDaysToAdd() {
	int input;	
    int isOk = 0;

    while(!isOk){
        printf("Type a number between 0 and N (0 is today (%s)) : ", dateNowToString());
        scanf("%d", &input);     
        clear();
        if(input>=0) isOk = 1;    
    }
	
	return input;
}


int inputFromList(char *text, int list[], int size){
    int input;
    int isOk = 0;

    while(!isOk){
        printf(text);
        scanf("%d", &input);
        clear();

        for(int i = 0; i<size; i++){
            if(input == list[i]){
                isOk = 1;
                break;
            }
        }
    }

    return input;
}

void inputTime(char* text, int *hour, int *minute, int *second){
    int isOk = 0;

    do{
        printf(text);
        scanf("%2d:%2d:%2d", hour, minute, second);
        clear();
        //printf("\n%d:%d:%d\n", hour, minute, second);

        if(*hour >= 0 && *hour < 24){
            if(*minute >= 0 && *minute < 60){
                if(*second >= 0 && *second < 60){
                    isOk = 1;
                }
            }
        }
    } while (!isOk);
}