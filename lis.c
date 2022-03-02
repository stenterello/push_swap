#include "push_swap.h"

int arrlen(int *n)
{
    int i;
    i = 0;
    if (!n)
        return (0);
    while (*(n + i) != -1)
        i++;
    return (i);
}

void    arrcopy(int *dst, int *src)
{
    int i;
    i = 0;
    if (!src)
        return ;
    while (src[i] != -1)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = -1;
}

