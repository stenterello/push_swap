#include "push_swap.h"

int find_place(t_stack *b, int c)
{
    int i;
    
    i = 0;
    while (i < b->len)
    {
        if (c < b->arr[i] && b->arr[i + 1] < c && (b->arr[i] != b->max && b->arr[i] != b->min && b->arr[i + 1] != b->min && b->arr[i + 1] != b->max))
            return (i);
        i++;
    }
    return (-1);
}

void    find_place_and_insert(t_stack *a, t_stack *b)
{
    int i;
    int tmp;

    i = 0;
    find_values(b);
    if (a->arr[0] < b->max && a->arr[0] > b->min)
    {
        tmp = find_place(b, a->arr[0]);
        if (tmp > b->len / 2)
        {
            tmp = b->len - tmp;
            while (i++ <= tmp)
                rrb(b, 1);
        }
        else
        {
            while (i++ <= tmp)
                rb(b, 1);
        }
    }
    else if (a->arr[0] < b->min)
    {
        if (find_ind(b, b->min) > b->len / 2)
        {
            while (find_ind(b, b->min))
                rrb(b, 1);
            rb(b, 1);
        }
        else
        {
            while (find_ind(b, b->min))
                rb(b, 1);
            rb(b, 1);
        }
    }
    else if (a->arr[0] > b->max)
    {
        if (find_ind(b, b->max) > b->len / 2)
        {
            while (find_ind(b, b->max))
                rrb(b, 1);
            rb(b, 1);
        }
        else
        {
            while (find_ind(b, b->max))
                rb(b, 1);
            rb(b, 1);
        }
    }
    pb(a, b);
}

void	sort(t_stack *a, t_stack *b)
{
    pb(a, b);
    pb(a, b);
    pb(a, b);
    find_values(b);
    sort_rev_small(b);
    while (a->len)
    {
        find_place_and_insert(a, b);
        find_values(a);
        find_values(b);
    }
}