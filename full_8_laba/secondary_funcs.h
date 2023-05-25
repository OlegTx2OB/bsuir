#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include "structs.h"
#pragma once

#define MAX_ARRAY_SIZE 1000
#define SIZEOF_BUF 100
#define KEY "key"

short hash_calculation(char* buf);
int getint(int lower_bound, int upper_bound);
array** create_hash_array();
list* create_cache_list();
void swap(unsigned char *a, unsigned char *b);
void rc4(unsigned char *key, unsigned char *data);

