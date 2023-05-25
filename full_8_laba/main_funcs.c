#include "main_funcs.h"
#include "work_with_nodes.h"

void load_n_strings(list* cache_list, array** hash_array)
{
    FILE *fp = fopen("db.txt", "r");

    printf("enter number of strings you want to load:");
    int n = getint(1, 19);
    for(int i = 0; i < n; i++)
    {
        unsigned char* buf = malloc(SIZEOF_BUF * sizeof(char));
        fgets(buf, SIZEOF_BUF,fp);
        push_in_cache(cache_list, buf);

        buf = realloc(buf, strlen(strtok(buf, ":")) + 1);
        rc4(KEY, buf);
        short hash = hash_calculation(buf);
        push_in_hash(hash_array, cache_list, hash);
    }
    fclose(fp);
}
    void add(list* cache_list, array** hash_array)
{

}

void remove_by_ip(list* cache_list, array** hash_array)
{

}

void find_ip(list* cache_list, array** hash_array)
{

}