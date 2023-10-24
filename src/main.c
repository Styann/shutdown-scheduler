#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#if defined _WIN32 || _WIN64
#include <Windows.h>
#elif defined __linux__
#include <unistd.h>
#endif

#include "input.h"
#include "format.h"

struct tm *create_timeout(int day, int hour, int minute, int second, int isTimeout){
    time_t timenow = time(NULL);
    struct tm *datetime = localtime(&timenow);

    datetime->tm_mday += day;
    if(isTimeout == 1){
        datetime->tm_hour += hour;
        datetime->tm_min += minute;
        datetime->tm_sec += second;
    }else if(isTimeout == 0){
        datetime->tm_hour = hour;
        datetime->tm_min = minute;
        datetime->tm_sec = second;
    }
    
    return datetime;
}

void start_timeout(time_t *target){

    time_t now = time(NULL);
    struct tm dt_start = *localtime(&now);
    char *str_dt_start = datetime_to_str(dt_start, "%c");

    struct tm dt_end = *localtime(target);
    char *str_dt_end = datetime_to_str(dt_end, "%c");

    printf("schedule start at %s, will end at %s", str_dt_start, str_dt_end);
    free(str_dt_start);
    free(str_dt_end);

    int diff = (int)difftime( *target, time(NULL)) * 1000;

    if(diff > 0){
        #if defined _WIN32 || defined _WIN64
            Sleep(diff);
            system("C:/Windows/System32/shutdown.exe /s /t 0");
        #elif defined __linux__
            sleep(diff);
            system("shutdown -P now");
        #endif
    } 

    /*time_t t;
    struct tm instant;
    do{
        t = time(NULL);
        instant = *localtime(&t);
        printf("%s\n", datetime_to_str(instant, "%c"));
    }while(t <= *target);
    if(time(NULL) >= *target) shutdown_by_os();*/
    return;
}

void color_digit(char *text){
    char buffer[99] = "";
    char *buffer_char;
    char *color = "\x1B[32m";



    int is_digit = 0; //bool
    int previous_is_digit = 0; //bool

    for(int i = 0; i<strlen(text); i++){
        is_digit = isdigit(text[i]);

        if(is_digit && !previous_is_digit){
            sprintf(buffer_char, "%s%s", GREEN_CONSOLE_COLOR, text[i]);
            printf("-->d&!pd %s\n", buffer_char);
            //*buffer_char = text[i]; 
            previous_is_digit = 1;  
        }
        else if(!is_digit){
            //printf("-->!d %c\n", text[i]);
            *buffer_char = text[i]; 
            previous_is_digit = 0;
        }
        else{
            *buffer_char = text[i]; 
            //printf("--> %c\n", text[i]);
        }

        strcat(buffer, buffer_char);
    }

    printf("\n result -> %s\n", buffer);

}

int main(){
    /*printf("\n");
    printf("\x1B[31mTexting\033[0m\t\t");
    printf("\x1B[32mTexting\033[0m\t\t"); //green
    printf("\x1B[33mTexting\033[0m\t\t");
    printf("\x1B[34mTexting\033[0m\t\t");
    printf("\x1B[35mTexting\033[0m\n"); // purple
    
    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[36mTexting\033[0m\t\t");
    printf("\x1B[37mTexting\033[0m\t\t");
    printf("\x1B[93mTexting\033[0m\n");
    
    printf("\t\t");
    printf("\n");*/

    color_digit("test12123test123test789");

    int day = input_days_to_add(), hour, minute, second;

    char *text = "Specify a time or a timeout (1, 2) : ";
    int choices[2] = {1, 2};
    int choice = input_from_list(text, choices, sizeof(choices));

    input_time("Type a time (format hh:mm:ss) : ", &hour, &minute, &second);

    struct tm *dt = create_timeout(day, hour, minute, second, choice-1);
    time_t t = mktime(dt);
    if(dt != NULL){
        start_timeout(&t);
    }

    return 0;
}