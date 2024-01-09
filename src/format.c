#include "format.h"

char *datetime_to_str(struct tm datetime, char format[]) {
    char *buffer = (char *)malloc(512);
	strftime(buffer, 512, format, &datetime);
	return buffer;
}

char *datenow_to_str(char format[]){
    time_t t = time(NULL);
    struct tm datetime = *localtime(&t);
    return datetime_to_str(datetime, format);
}

void sprintc(char *text, const char *color, char opening, char ending){
    char buffer[512] = "";

    char buffer_char[2];
    buffer_char[1] = '\0';

    int is_printable = 0;
    
    for(int i = 0; i<strlen(text); i++){
        buffer_char[0] = text[i];

        is_printable = 1;

        if(buffer_char[0] == opening){
            strcat(buffer, color);
            is_printable = 0;
        }else if(buffer_char[0] == ending){
            strcat(buffer, ANSI_COLOR_RESET);
            is_printable = 0;
        }

        if(is_printable){
            strcat(buffer, buffer_char);
        }
    }
    
    strcpy(text, buffer);
}

void printc(char *text, const char *color, char opening, char ending){
    char buffer[512] = "";

    char buffer_char[2];
    buffer_char[1] = '\0';

    int is_printable = 0;
    
    for(int i = 0; i<strlen(text); i++){
        buffer_char[0] = text[i];

        is_printable = 1;

        if(buffer_char[0] == opening){
            strcat(buffer, color);
            is_printable = 0;
        }else if(buffer_char[0] == ending){
            strcat(buffer, ANSI_COLOR_RESET);
            is_printable = 0;
        }

        if(is_printable){
            strcat(buffer, buffer_char);
        }
    }

    printf("%s", buffer);
}

void color_fullstring(char *str, const char *color){
    char buffer[512] = ANSI_COLOR_RED;
    strcat(buffer, str);
    strcat(buffer, ANSI_COLOR_RESET);
    strcpy(str, buffer);
    return;
}

int print_error(const char *message){
    char buffer[512];
    strcpy(buffer, message);
    color_fullstring(buffer, ANSI_COLOR_RED);
    fprintf(stderr, buffer);
    return 1;
}