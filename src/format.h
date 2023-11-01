#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*printf("\x1B[36mTexting\033[0m\t\t");
printf("\x1B[36mTexting\033[0m\t\t");
printf("\x1B[36mTexting\033[0m\t\t");
printf("\x1B[37mTexting\033[0m\t\t");
printf("\x1B[93mTexting\033[0m\n");*/

#define WHITE_CONSOLE_COLOR "\033[0m"
#define RED_CONSOLE_COLOR "\x1B[31m"
#define GREEN_CONSOLE_COLOR "\x1B[32m"
#define YELLOW_CONSOLE_COLOR "\x1B[33m"
#define BLUE_CONSOLE_COLOR "\x1B[34m"
#define PURPLE_CONSOLE_COLOR "\x1B[35m"

char *datetime_to_str(struct tm datetime, char format[]);

char *datenow_to_str();

void printc(char *text, char *color);

char *color_digit(char *text, char *color, char odd);