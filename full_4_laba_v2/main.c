#include "struct_functions.h"
#include "functions.h"

int main()
{                                                           //todo добавить функцию добавления человека при пустом списке людей
    school* p = NULL;

    while(1)
    {
        printf("|----------------------------------|\n"
               "| 1. Add pupil                     |\n"
               "| 2. Print all pupils              |\n"
               "| 3. Update information about pupil|\n"
               "| 4. Remove pupil                  |\n"
               "| 5. Sort pupils                   |\n"
               "| 6. Find retarded pupil(-s)       |\n"
               "| 7. Quit                          |\n"
               "|----------------------------------|\n");
        short choose = getshort(1, 7);
        if (choose == ADD)
        {
            add(&p);
            printf(" * New pupil has been added * \n");

        }
        else if (choose == PRINT)
        {
            school* curr = p;
            if(curr == NULL) printf(" * List of pupils is clear \n");
            else while(curr != NULL)
                {
                    print(curr);
                    curr = curr->next;
                }
            free(curr);
        }
        else if (choose == UPDATE) update(&p);
        else if (choose == KILL) kill(&p);
        //else if (choose == SORT) sort(p);
        else if (choose == RETARDED) retarded(p);
        else if (choose == QUIT) return 0;
    }
}
