#include "push_swap.h"

//static void	take_min_and_push(t_stack *a, t_stack *b)
//{
//	if (find_ind(a, a->min) < a->len / 2)
//	{
//		while (find_ind(a, a->min))
//			ra(a, 1);
//	}
//	else
//	{
//		while (find_ind(a, a->min))
//			rra(a, 1);
//	}
//	pb(a, b);
//}
//
//static void	take_max_and_push(t_stack *a, t_stack *b)
//{
//	if (find_ind(a, a->max) < a->len / 2)
//	{
//		while (find_ind(a, a->max))
//			ra(a, 1);
//	}
//	else
//	{
//		while (find_ind(a, a->max))
//			rra(a, 1);
//	}
//	if (!in_order(a))
//		pb(a, b);
//}

int	define_range(t_stack *a, int range)
{
	if (a->len > 500)
		return (range / 11);
	else if (a->len > 100)
		return (range / 5);
	else
		return (range / 5);
}

int	define_flag(t_stack *b, int c)
{
	if (b->len > 1 && c < b->arr[0])
		return (1);
	return (0);
}

void    sort_b(t_stack *b)
{
    find_values(b);
    while (find_ind(b, b->max) && find_ind(b, b->max) < b->len / 2 && !in_rev_order(b))
    {
        if (b->arr[0] < b->arr[1] && b->len > 1 && find_ind(b, b->min))
		    sb(b, 1);
        if (!in_rev_order(b))
            rb(b, 1);
    }
    while (find_ind(b, b->max) && find_ind(b, b->max) > b->len / 2 && !in_rev_order(b))
    {
        if (b->arr[0] < b->arr[1] && b->len > 1)
		    sb(b, 1);
        if (!in_rev_order(b))
            rrb(b, 1);
    }
    while (find_ind(b, b->min) != b->len - 1 && find_ind(b, b->max))
    {
        if (find_ind(b, b->min) < b->len / 2)
            rb(b, 1);
        else
            rrb(b, 1);
    }
    if (b->arr[0] < b->arr[1] && b->len > 1)
		sb(b, 1);
}

void	to_b(t_stack *a, t_stack *b, int c)
{
	int	flag;

	while (find_ind(a, c))
	{
		flag = define_flag(b, c);
		if (flag && find_ind(a, c) > a->len / 2)
			rrr(a, b);
		else if (flag && find_ind(a, c) < a->len / 2)
			rr(a, b);
		else if (find_ind(a, c) > a->len / 2)
			rra(a, 1);
		else
			ra(a, 1);
	}
    while (define_flag(b, c) && c > b->min)
        rb(b, 1);
	pb(a, b);
	find_values(b);
	find_values(a);
    if (!in_rev_order(b))
        sort_b(b);
}

int	to_do(t_stack *a, int min, int max)
{
	int	i;

	i = 0;
	while (i < a->len)
	{
		if (a->arr[i] >= min && a->arr[i] <= max)
			return (1);
		i++;
	}
	return (0);
}

void    sort_a(t_stack *a, int c)
{
    int last;
    int i;

    i = 0;
    last = a->min;
    while (i < a->len)
    {
        if (a->arr[i] < c && a->arr[i] > last)
            last = a->arr[i];
        i++;
    }
    i = 0;
    if (find_ind(a, last) > a->len / 2)
    {
        while (find_ind(a, last) != a->len - 1)
            rra(a, 1);
    }
    if (find_ind(a, last) < a->len / 2)
    {
        while (find_ind(a, last) != a->len - 1)
            ra(a, 1);
    }
}

void	sort(t_stack *a, t_stack *b)
{
	int	min;
	int	max;
	int	range;
	int	range2;
	int	i;

	i = 0;
	find_values(a);
	range = ft_abs(a->min) + ft_abs(a->max);
	range2 = define_range(a, range);
	min = a->min;
	max = a->min + range2 - 1;
	while (min <= range)
	{
		i = 0;
		while (to_do(a, min, max) && i < a->len)
		{
			if (a->arr[i] >= min && a->arr[i] <= max)
			{
				to_b(a, b, a->arr[i]);
				i = 0;
			}
			else
				i++;
		}
		min += range2;
		max += range2;
        find_values(a);
        sort_a(a, b->arr[0]);
        i = 0;
        a->last = b->arr[0];
		while (b->len)
        {
        	pa(a, b);
            i++;
        }
        find_values(a);
        while (find_ind(a, a->last) != a->len - 1)
        {
            if (find_ind(a, a->last) > a->len / 2)
                rra(a, 1);
            else
                ra(a, 1);
        }
	}
}
