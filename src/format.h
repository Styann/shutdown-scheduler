#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define RESET_CONSOLE_COLOR "\033[0m"
#define PURPLE_CONSOLE_COLOR "\x1B[35m"
#define GREEN_CONSOLE_COLOR "\x1B[32m"

char *datetime_to_str(struct tm datetime, char format[]);

char *datenow_to_str();

void printc(char *text, char *color);