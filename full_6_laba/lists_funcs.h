#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#pragma once

enum options
{
    ADD = 1, MOVE_CLIENTS, PRINT, QUIT
};

typedef struct Info
{
    char full_name[64];
    long long cost;
    struct tm *date;
}info;

typedef struct Queue
{
    struct Queue *next;
    struct Info *info;
}queue;

typedef struct Ring
{
    struct Ring *next;
    struct Ring *prev;
    struct Info *info;
}ring;

void push(queue** q_head, queue** q_new);
info* pop_node_and_return_info(queue** q_head);
info* peek_node_and_return_info(queue** q_head);

void add(queue** q_head);
void add_info(info * info_new);

void print(ring* r_head);
void print_ring(ring* r_cycle);

void move_clients(queue** q, ring** r_head);
