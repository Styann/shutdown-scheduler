#pragma once
#include <stdio.h>
#include <time.h>

const char* datetime_to_string(struct tm datetime, char format[]);

const char* datenow_to_string();