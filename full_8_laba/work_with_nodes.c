#include "work_with_nodes.h"

void push_in_cache(list* cache_list, char* buf)
{
    cache* cache_node = malloc(sizeof(cache));
    cache_node->dns = strtok(buf, ":");
    cache_node->ip = strtok(NULL, "\n");
    cache_node->next = cache_node->prev = NULL;

    if(cache_list->tail == NULL) cache_list->tail = cache_node;
    else
    {
        cache_node->next = cache_list->head;
        cache_list->head->prev = cache_node;
    }
    cache_list->head = cache_node;
}

void push_in_hash(array** hash_array, list* cache_list, short num)
{
    hash* hash_node = malloc(sizeof(hash));
    hash_node->node = &cache_list->head;
    hash_node->next = hash_node->prev = NULL;

    if(hash_array[num]->tail == NULL) hash_array[num]->tail = hash_node;
    else
    {
        hash_node->next = hash_array[num]->head;
        hash_array[num]->head->prev = hash_node;
    }
    hash_array[num]->head = hash_node;
}