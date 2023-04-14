#include <unistd.h>
#include "lists_funcs.h"
#include "funcs.h"

void push(queue** q_head, queue** q_new)
{
    if(q_head == NULL)
    {
        (*q_head) = malloc(sizeof(queue));
        (*q_head) = (*q_new);
        (*q_head)->next = NULL;
    }
    else
    {
        (*q_new)->next = (*q_head);
        (*q_head) = (*q_new);
    }
}
info* pop_node_and_return_info(queue** q_head)
{
    queue* q_popped = (*q_head);
    for(;q_popped->next != NULL; q_popped = q_popped->next);

    queue* q_penult = (*q_head);
    for(;q_penult->next != q_popped && q_penult != q_popped; q_penult = q_penult->next);

    q_penult->next = NULL;
    info* info = q_popped->info;
    if(q_popped == (*q_head))
    {
        free((*q_head));
        (*q_head) = NULL;
    }
    else free(q_popped);

    return info;
}
info* peek_node_and_return_info(queue** q_head)
{
    queue* q_popped = (*q_head);
    for(; q_popped->next != NULL; q_popped = q_popped->next);
    info* info = q_popped->info;
    return info;
}

void add(queue** q_head)
{
    info *info_new = malloc(sizeof(info));
    add_info(info_new);
    queue* q_new = malloc(sizeof(queue));
    q_new->info = info_new;
    push(q_head, &q_new);
}

void add_info(info * info_new)
{
//full_name
    printf(" * Enter full name of this child (to 64 symbols):");
    fgets(info_new->full_name, 64, stdin);
    rewind(stdin);
//cost
    printf(" * Enter cost: ");
    info_new->cost = getlonglong(1, 9223372036854775807);
//date
    time_t my_time = time(NULL);
    info_new->date = localtime(&my_time);
}

void print(ring* r_head)
{
    if (r_head == NULL) printf(" * There is no added clients\n");
    else
    {
        ring* r_cycle = r_head;
        do
        {
            print_ring(r_cycle);
            r_cycle = r_cycle->next;
        }
        while(r_cycle != r_head);
    }
}
void print_ring(ring* r_cycle)
{
    printf("    |------------------------------\n"
           "    | 1. full name: %s"
           "    | 2. cost: %lld\n"
           "    | 3. date: %d.%d.%d\n"
           "    | 4. time: %d:%d:%d\n"
           "    |------------------------------\n", r_cycle->info->full_name, r_cycle->info->cost,
           r_cycle->info->date->tm_mday, r_cycle->info->date->tm_mon + 1, r_cycle->info->date->tm_year + 1900,
           r_cycle->info->date->tm_hour, r_cycle->info->date->tm_min, r_cycle->info->date->tm_sec);
}

void move_clients(queue** q_head, ring** r_head)
{
    if ((*q_head) == NULL) printf(" * Sorry, queue is empty\n");
    else
    {
        int x = 0;
        while ((*q_head) != NULL)
        {
//if head is clear
            if ((*r_head) == NULL)
            {
                (*r_head) = malloc(sizeof(ring));
                (*r_head)->info = pop_node_and_return_info(q_head);
                (*r_head)->next = (*r_head);
                (*r_head)->prev = (*r_head);
            }
//if head is 1 element
            else if ((*r_head)->next == (*r_head))
            {
                ring* r_new = malloc(sizeof(ring));
                r_new->info = pop_node_and_return_info(q_head);

                (*r_head)->next = r_new;
                (*r_head)->prev = r_new;
                r_new->next = (*r_head);
                r_new->prev = (*r_head);
            }
//2+
            else
            {
                ring* r_curr = (*r_head);
                ring* r_next = (*r_head)->next;
//todo сортировка элемента, который должен стать между хедом и последним
                while(1)
                {
                    if(r_next->info->cost >= r_curr->info->cost)
                    {
                        if(peek_node_and_return_info(q_head)->cost <= r_next->info->cost
                        && peek_node_and_return_info(q_head)->cost >= r_curr->info->cost)
                        {
                            ring* r_new = malloc(sizeof(ring));
                            r_new->info = pop_node_and_return_info(q_head);

                            r_new->next = r_next;
                            r_new->prev = r_curr;
                            r_curr->next = r_new;
                            r_next->prev = r_new;
                            break;
                        }
                        r_curr = r_curr->next;
                        r_next = r_next->next;
                    }
                    else
                    {
                        if(peek_node_and_return_info(q_head)->cost <= r_next->info->cost
                        || peek_node_and_return_info(q_head)->cost >= r_curr->info->cost)
                        {
                            ring *r_new = malloc(sizeof(ring));
                            r_new->info = pop_node_and_return_info(q_head);

                            r_new->next = r_next;
                            r_new->prev = r_curr;
                            r_curr->next = r_new;
                            r_next->prev = r_new;
                            break;
                        }
                        r_curr = r_curr->next;
                        r_next = r_next->next;
                    }
                }
            }
        }
    }
    printf(" * Moving has been successful\n");
}