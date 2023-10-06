#include "format.h"

const char* datetimeToString(struct tm datetime, char format[]) {
	static char buffer[26];
	strftime(buffer, sizeof(buffer), format, &datetime);
	return buffer;
}

const char* dateNowToString(){
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return datetimeToString(tm, "%d-%m-%Y");
}