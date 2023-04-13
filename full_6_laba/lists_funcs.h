#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#pragma once

enum options
{
    ADD = 1, MOVE_CLIENTS, PRINT, QUIT
};

typedef struct Date
{
    short day;
    short month;
    short year;
}date;

typedef struct Information
{
    char full_name[64];
    long long cost;
    struct Date date;
}information;

typedef struct Queue
{
    struct Queue *next;
    struct Information *information;
}queue;

typedef struct Ring
{
    struct Ring *next;
    struct Ring *prev;
    struct Information *information;
}ring;
void push(queue** q_head, queue** q_new);
information* pop_node_and_return_info(queue** q_head);
information* peek_node_and_return_info(queue** q_head);

void add(queue** q_head);
void add_info(information * info_new);

void print(ring* r_head);
void print_ring(ring* r_cycle);

void move_clients(queue** q, ring** r_head);
