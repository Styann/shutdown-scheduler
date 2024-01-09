#include <stdio.h>
#include <time.h>
#include <string.h>

#if defined _WIN32 || _WIN64
#include <Windows.h>
#elif defined __linux__
#include <unistd.h>
#endif

#include "input.h"
#include "format.h"

#define TIMEOUT 1
#define AT_HOUR 2 

struct tm *create_timeout(int day, int hour, int minute, int second, int choice){
    time_t timenow = time(NULL);
    struct tm *datetime = localtime(&timenow);

    datetime->tm_mday += day;
    if(choice == 1){
        datetime->tm_hour += hour;
        datetime->tm_min += minute;
        datetime->tm_sec += second;
    }else if(choice == 2){
        datetime->tm_hour = hour;
        datetime->tm_min = minute;
        datetime->tm_sec = second;
    }
    
    return datetime;
}

void start_timeout(time_t *target){

    time_t now = time(NULL);
    struct tm dt_start = *localtime(&now);
    char *str_dt_start = datetime_to_str(dt_start, "{%d}/{%m}/{%Y} {%H}:{%M}:{%S}");

    struct tm dt_end = *localtime(target);
    char *str_dt_end = datetime_to_str(dt_end, "{%d}/{%m}/{%Y} {%H}:{%M}:{%S}");
    sprintc(str_dt_end, ANSI_COLOR_MAGENTA, '{', '}');

    char message[512];
    sprintf(message, "schedule start at %s, will end at %s", str_dt_start, str_dt_end);
    printc(message, ANSI_COLOR_GREEN, '{', '}');
    
    free(str_dt_start);
    free(str_dt_end);

    int diff = (int)difftime(*target, time(NULL)) * 1000;

    if(diff > 0){
        #if defined _WIN32 || defined _WIN64
            Sleep(diff);
            system("C:/Windows/System32/shutdown.exe /s");
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

int main(int argc, char const *argv[]){
    int choice = 0;

    if(argc >= 4){
        //to or hour
        if(strcmp(argv[1], "-to") == 0) choice = TIMEOUT;
        else if(strcmp(argv[1], "-h") == 0) choice = AT_HOUR;
        
        //day to add
        int days;
        if(!str_to_int(&days, argv[2])){
            return print_error("Error: days is not a number.");
        }

        //hours
        int hour, minute, second;
        if(!convert_timestr_to_int(argv[3], &hour, &minute, &second)){
            return print_error("Error: input hour wrong format.");
        }

        if(!parse_time(&hour, &minute, &second)){
            return print_error("Error: input hour wrong format.");
        }

        struct tm *dt = create_timeout(days, hour, minute, second, choice);
        time_t t = mktime(dt);
        
        if(dt != NULL){
            start_timeout(&t);
        }
    }
    else{
        return print_error("ArgumentError: not enough argument(s) were provided."); 
    }



    return 0;
}