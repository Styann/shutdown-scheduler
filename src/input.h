#pragma once
#ifndef INPUT
#define INPUT


#include <stdio.h>
#include <stdbool.h>
#include "format.h"

int input_days_to_add(void);

int input_from_list(const char *message, int list[], int size);

void input_time(const char* message, int *hour, int *minute, int *second);

bool str_to_int(int *dest, char const *str);

bool convert_timestr_to_int(char const *str, int *hour, int *minute, int *second);

bool parse_time(int *hour, int *minute, int *second);

#endif