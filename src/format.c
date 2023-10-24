#include "format.h"

char *datetime_to_str(struct tm datetime, char format[]) {
    char *buffer = malloc(26);
	strftime(buffer, 26, format, &datetime);
	return buffer;
}

char *datenow_to_str(char format[]){
    time_t t = time(NULL);
    struct tm datetime = *localtime(&t);
    return datetime_to_str(datetime, format);
}

void printc(char *text, char *color){
    printf("%s%s%s", color, text, RESET_CONSOLE_COLOR);
    return;
} 