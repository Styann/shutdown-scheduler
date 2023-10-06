#pragma once
#include <stdio.h>
/*#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>*/

void clear();

int inputDaysToAdd();

int inputFromList(char *text, int list[], int size);

void inputTime(char* text, int *hour, int *minute, int *second);