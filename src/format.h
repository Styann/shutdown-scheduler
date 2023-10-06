#pragma once
#include <stdio.h>
#include <time.h>

const char* datetimeToString(struct tm datetime, char format[]);

const char* dateNowToString();