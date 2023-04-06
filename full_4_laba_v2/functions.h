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

int sort_condition(school bubble, school pj, char choose);
void insertion_sort(school* p, int size, char choose);

void writing_log_by_the_first_parameter(short parameter, unsigned short id, char* full_name, short age, short class,
                    float av_mark, char* address, long long telephone);