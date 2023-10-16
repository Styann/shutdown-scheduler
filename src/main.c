#include <stdio.h>
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

void start_timeout(time_t target){
    int s = 0;
    while(time(NULL) <= target){
        Sleep(1000);
        s++;
        printf("\n%d", s);
    }

    if(time(NULL) >= target) shutdown_by_os();
}

int main(){
    struct tm* dt = NULL;

    int day;
    day = input_days_to_add();


    char *text = "Specify a time or a timeout (1, 2) : ";
    int j;
    int choices[] = {1, 2};
    int choice = input_from_list(text, choices, sizeof(choices));

    int hour, minute, second;
    input_time("Type a time (format hh:mm:ss) : ", &hour, &minute, &second);
    printf("\n%d:%d:%d\n", hour, minute, second);

    dt = create_timeout(day, hour, minute, second, choice-1);

    if(dt != NULL){
        start_timeout(mktime(dt));
    }

    return 0;
}