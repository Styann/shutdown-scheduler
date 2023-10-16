#include "format.h"

const char* datetime_to_string(struct tm datetime, char format[]) {
	static char buffer[26];
	strftime(buffer, sizeof(buffer), format, &datetime);
	return buffer;
}

const char* datenow_to_string(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return datetime_to_string(tm, "%d-%m-%Y");
}