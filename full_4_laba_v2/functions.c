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
int sort_condition(school bubble, school pj, char choose)
{
    if(choose == '1') return (pj.id > bubble.id);
    else if(choose == '2') return(strcmp(pj.full_name, bubble.full_name) > 0);
    else if(choose == '3') return(pj.age > bubble.age);
    else if(choose == '4') return(pj.cl1.i > bubble.cl1.i);
    else if(choose == '5') return(strcmp(pj.address, bubble.address) > 0);
    else if(choose == '6') return(pj.telephone > bubble.telephone);
}
void insertion_sort(school* p, int size, char choose)
{
    for(int m = 0; m < size; m++)
    {
        int j;
        school bubble = p[m];
        for(j = m - 1; j >= 0 && sort_condition(bubble, p[j], choose); j--)
        {
            p[j + 1] = p[j];
        }
        p[j + 1] = bubble;
    }
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