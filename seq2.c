#include "push_swap.h"

void    search(t_stack *a, int i)
{
}

void    get_seq(t_stack *a)
{
    int i;

    i = 0;
    while (i < a->len)
    {
        search(a, i);
        i++;
    }
}