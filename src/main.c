#include <stdio.h>
#include <time.h>

#if defined _WIN32 || _WIN64
#include <Windows.h>
#elif defined __linux__
#include <unistd.h>
#endif

#include "input.h"
#include "format.h"

struct tm* create_timeout(int day, int hour, int minute, int second, int isTimeout){
    time_t timenow = time(NULL);
    struct tm* datetime = localtime(&timenow);

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

    int diff = (int)difftime( *target, time(NULL)) * 1000;



    
    time_t now = time(NULL);
    struct tm dt_start = *localtime(&now);
    struct tm dt_end = *localtime(target);

    char *str_dt_start = datetime_to_str(dt_start, "%c");
    char *str_dt_end = datetime_to_str(dt_end, "%c");
    printf("schedule start at %s, will end at %s", str_dt_start, str_dt_end);
    free(str_dt_start);
    free(str_dt_end);

    if(diff > 0){
        #if defined _WIN32 || defined _WIN64
            Sleep(diff);
            system("C:/Windows/System32/shutdown.exe /s /t 0");
        #elif defined __linux__
            sleep(diff);
            system("shutdown -P now");
        #endif
    } 

    /*
    time_t t;
    struct tm instant;
    do{
        t = time(NULL);
        instant = *localtime(&t);
        printf("%s\n", datetime_to_str(instant, "%c"));
    }while(t <= *target);

    if(time(NULL) >= *target) shutdown_by_os();*/
    return;
}

int main(){
    int day;
    day = input_days_to_add();

    char *text = "Specify a time or a timeout (1, 2) : ";
    int choices[] = {1, 2};
    int choice = input_from_list(text, choices, sizeof(choices));

    int hour, minute, second;
    input_time("Type a time (format hh:mm:ss) : ", &hour, &minute, &second);

    struct tm* dt = create_timeout(day, hour, minute, second, choice-1);
    time_t t = mktime(dt);
    if(dt != NULL){
        start_timeout(&t);
    }

    return 0;
}