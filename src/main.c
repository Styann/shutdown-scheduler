#include <stdio.h>
#include <time.h>
#include <Windows.h>

#include "input.h"
#include "format.h"

void shutdown_by_os(){
    #if defined _WIN32 || defined _WIN64
        system("C:/Windows/System32/shutdown.exe /s /t 0");
    #elif defined __linux__
        system("shutdown -P now");
    #elif defined __APPLE__ || defined __MACH__
        return;
    #else
        return;
    #endif
}

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

void appendLog(char *msg){
    FILE *log = fopen("shutdown.log", "a");
    if(log != NULL){
        time_t t = time(NULL);
        struct tm instant = *localtime(&t);
        fprintf(log, "%s %s\n", msg, datetime_to_string(instant, "%c"));
    }
    fclose(log);
}

void start_timeout(time_t *target){

    int diff = (int)difftime( *target, time(NULL)) * 1000;
    appendLog("started at");
    if(diff > 0) Sleep(diff); 
    appendLog("done at");
    if(time(NULL) >= *target) shutdown_by_os();
    /*
    time_t t;
    struct tm instant;
    do{
        t = time(NULL);
        instant = *localtime(&t);
        printf("%s\n", datetime_to_string(instant, "%c"));
    }while(t <= *target);

    if(time(NULL) >= *target) shutdown_by_os();*/
}

int main(){
    int day;
    day = input_days_to_add();

    char *text = "Specify a time or a timeout (1, 2) : ";
    int j;
    int choices[] = {1, 2};
    int choice = input_from_list(text, choices, sizeof(choices));

    int hour, minute, second;
    input_time("Type a time (format hh:mm:ss) : ", &hour, &minute, &second);
    printf("\n%d:%d:%d\n", hour, minute, second);

    struct tm* dt = create_timeout(day, hour, minute, second, choice-1);
    time_t t = mktime(dt);
    if(dt != NULL){
        start_timeout(&t);
    }

    return 0;
}