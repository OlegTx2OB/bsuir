#include <stdio.h>
#include <stdlib.h>
#include "struct_functions.h"
#pragma once

enum log_parameter
{
    ADDED = 1, REMOVED, UPDATED,
};
short getshort(short lower_bound, short upper_bound);
float getfloat(short lower_bound, short upper_bound);
long long getlonglong(short lower_bound, long long upper_bound);
void writing_log_by_the_first_parameter(short parameter, unsigned short id, char* full_name, short age, short class,
                                        float av_mark, char* address, long long telephone);