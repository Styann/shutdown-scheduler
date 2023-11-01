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
    printf("%s%s%s", color, text, WHITE_CONSOLE_COLOR);
    return;
}

char *color_digit(char *text, char* color, char odd){
    char *buffer = malloc(99);
    strcpy(buffer, "");
    char *buffer_char;

    int is_digit = 0; //bool
    int previous_is_digit = 0; //bool
    int is_color_open = 0; //bool

    for(int i = 0; i<strlen(text); i++){
        is_digit = isdigit(text[i]);

        buffer_char = text[i];
        printf("%s", buffer_char);


        /*if( (is_digit || text[i] == odd) && !previous_is_digit){
            strcat(buffer, color);
            *buffer_char = text[i];
            strcat(buffer, buffer_char);
            previous_is_digit = 1;
            is_color_open = 1;

        }
        else if(!is_digit){
            *buffer_char = text[i];
            strcat(buffer, WHITE_CONSOLE_COLOR);
            strcat(buffer, buffer_char);
            previous_is_digit = 0;
        }
        else{
            *buffer_char = text[i];
            strcat(buffer, buffer_char);
        }*/
    }

    if(is_color_open){
        strcat(buffer, WHITE_CONSOLE_COLOR);
    }


    return buffer;
}