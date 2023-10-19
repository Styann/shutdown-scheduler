#include "format.h"

char *datetime_to_str(struct tm datetime, char format[]) {
    char *buffer = malloc(26);
	strftime(buffer, 26, format, &datetime);
	return buffer;
}

char *datenow_to_str(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return datetime_to_str(tm, "%d-%m-%Y");
}