#pragma once

typedef struct cache
{
    char* dns;
    char* ip;

    struct cache* next;
    struct cache* prev;
}cache;

typedef struct
{
    int size;
    cache* head;
    cache* tail;
}list;

typedef struct hash
{
    cache** node;

    struct hash* next;
    struct hash* prev;
}hash;

typedef struct
{
    hash* head;
    hash* tail;
}array;
