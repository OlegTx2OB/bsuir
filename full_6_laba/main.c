#include "lists_funcs.h"
#include "funcs.h"
//todo time.h и время в структуры норм добавь
//todo вывод даты
//todo pop при 2+
//todo сортировку доработать
//todo возможны ошибки из-за равно


int main()
{
    ring* r_head = NULL;
    queue* q_head = NULL;

    while(1)
    {
        printf("|-----------------------------------|\n"
               "| 1. Add pupil to queue             |\n"
               "| 2. Move clients from queue to ring|\n"
               "| 3. Print all pupils from ring     |\n"
               "| 4. Quit                           |\n"
               "|-----------------------------------|\n");
        short choose = getshort(1, 4);
        if (choose == ADD)add(&q_head);
        else if (choose == MOVE_CLIENTS)move_clients(&q_head, &r_head);//todo
        else if (choose == PRINT)print(r_head);
        else if (choose == QUIT) return 0;
    }
}
