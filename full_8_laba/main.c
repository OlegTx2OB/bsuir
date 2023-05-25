#include "main_funcs.h"
#include "structs.h"
#include "secondary_funcs.h"

int main()
{
    list* cache_list = create_cache_list();
    array** hash_array = create_hash_array();

    while(1)
    {
        printf("1.LOAD n STRINGS   2.ADD   3.REMOVE BY IP   4.FIND IP   5.EXIT : ");
        short choose = getint(LOAD_n_STRINGS, EXIT);

        if(choose == LOAD_n_STRINGS) load_n_strings(cache_list, hash_array);
        else if (choose == ADD) add(cache_list, hash_array);
        else if (choose == REMOVE_BY_IP) remove_by_ip(cache_list, hash_array);
        else if (choose == FIND_IP) find_ip(cache_list, hash_array);
        else return 0;
    }
}
