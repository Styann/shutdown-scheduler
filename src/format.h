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

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void sprintc(char *text, const char *color, char opening, char ending);

void printc(char *format, const char *color, char opening, char ending);

char *datetime_to_str(struct tm datetime, char format[]);

char *datenow_to_str(char format[]);