#pragma once
#include <stdio.h>
#include "format.h"

int input_days_to_add(void);

int input_from_list(const char *message, int list[], int size);

void input_time(const char* message, int *hour, int *minute, int *second);