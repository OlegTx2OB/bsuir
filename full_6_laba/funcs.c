#include "funcs.h"
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