#include "functions.h"

short getshort(short lower_bound, short upper_bound)
{
    short hd;
    while (!scanf("%hd", &hd) || hd < lower_bound || hd > upper_bound || getchar() != '\n')
    {
        printf("invalid input\n");
        rewind(stdin);
    }
    return hd;
}
float getfloat(short lower_bound, short upper_bound)
{
    float f;
    while (!scanf("%f", &f) || f < lower_bound || f > upper_bound || getchar() != '\n')
    {
        printf("invalid input\n");
        rewind(stdin);
    }
    return f;
}
long long getlonglong(short lower_bound, long long upper_bound)
{
    long long lld;
    while (!scanf("%lld", &lld) || lld < lower_bound || lld > upper_bound || getchar() != '\n')
    {
        printf("invalid input\n");
        rewind(stdin);
    }
    return lld;
}
void writing_log_by_the_first_parameter(short parameter, unsigned short id, char* full_name, short age, short class,
                                        float av_mark, char* address, long long telephone)
{
    FILE* fp = fopen("data.log", "a+");
    char *first_word = NULL;
    if(parameter == ADDED) first_word = "Added";
    else if(parameter == REMOVED)first_word = "removed";
    else if(parameter == UPDATED)first_word = "updated to";
    fseek(fp, 0,SEEK_END);
    fprintf(fp, "%s id.%hd full_name.%s age.%hd class.%hd av_mark.%f address.%s telephone.%lld\n",
            first_word, id, full_name, age, class, av_mark, address, telephone);
    fclose(fp);
}