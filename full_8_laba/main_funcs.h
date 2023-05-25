#include "structs.h"
#include "secondary_funcs.h"
#pragma once

enum options
{
    LOAD_n_STRINGS = 1, ADD, REMOVE_BY_IP, FIND_IP, EXIT
};

void load_n_strings(list* cache_list, array** hash_array);
void add(list* cache_list, array** hash_array);
void remove_by_ip(list* cache_list, array** hash_array);
void find_ip(list* cache_list, array** hash_array);
