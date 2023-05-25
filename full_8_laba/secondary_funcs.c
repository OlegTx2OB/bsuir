#include "secondary_funcs.h"

short hash_calculation(char* buf)
{
    int hash = 0;
    for(int j = 0; j < strlen(buf); j++)hash += buf[j] * j;
    return (hash % MAX_ARRAY_SIZE);
}

int getint(int lower_bound, int upper_bound)
{
    int d;
    while (!scanf("%d", &d) || d < lower_bound || d > upper_bound || getchar() != '\n')
    {
        printf("invalid input\n");
        rewind(stdin);
    }
    return d;
}

array** create_hash_array()
{
    array** hash_table = malloc(MAX_ARRAY_SIZE * sizeof(array*));
    for(int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        hash_table[i] = malloc(sizeof(array));
        hash_table[i]->head = hash_table[i]->tail = NULL;
    }
    return hash_table;
}

list* create_cache_list()
{
    list* cache_list = malloc(sizeof(list));
    cache_list->head = cache_list->tail = NULL;
    cache_list->size = 0;
    return cache_list;
}

void swap(unsigned char *a, unsigned char *b)
{
    unsigned char temp = *a;
    *a = *b;
    *b = temp;
}

void rc4(unsigned char *key, unsigned char *data)
{
    int length = strlen(data);

    unsigned char s[256];
    int i, j = 0;

    for (i = 0; i < 256; i++) s[i] = i;

    for (i = 0; i < 256; i++)
    {
        j = (j + s[i] + key[i % strlen(key)]) % 256;
        swap(&s[i], &s[j]);
    }

    i = j = 0;
    for (int k = 0; k < length; k++)
    {
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        swap(&s[i], &s[j]);
        int t = (s[i] + s[j]) % 256;
        data[k] ^= s[t];
    }
}

//void* popFront(list *list)
//{
//    cache_node *prev;
//    void *tmp;
//    if (list->head == NULL) exit(2);
//
//    prev = list->head;
//    list->head = list->head->next;
//    if (list->head) list->head->prev = NULL;
//    if (prev == list->tail) list->tail = NULL;
//    tmp = prev->value;
//    free(prev);
//
//    return tmp;
//}


//void pushBack(list *list, void *value)
//{
//    cache_node *tmp = malloc(sizeof(cache_node));
//    if (tmp == NULL) exit(3);
//    tmp->value = value;
//    tmp->next = NULL;
//    tmp->prev = list->tail;
//    if (list->tail) list->tail->next = tmp;
//    list->tail = tmp;
//
//    if (list->head == NULL) list->head = tmp;
//}

//void* popBack(list *list)
//{
//    cache_node *next;
//    void *tmp;
//    if (list->tail == NULL) exit(4);
//
//    next = list->tail;
//    list->tail = list->tail->prev;
//    if (list->tail) list->tail->next = NULL;
//    if (next == list->head) list->head = NULL;
//    tmp = next->value;
//    free(next);
//
//    return tmp;
//}