#pragma once
#include <stdio.h>
#include "format.h"
/*#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>*/

int input_days_to_add();

int input_from_list(char *text, int list[], int size);

void input_time(char* text, int *hour, int *minute, int *second);