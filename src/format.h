#pragma once
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char *datetime_to_str(struct tm datetime, char format[]);

char *datenow_to_str();