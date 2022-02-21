#include "push_swap.h"

int	define_range(t_stack *a, int range)
{
	if (a->len > 400)
		return (range / 10);
	else if (a->len > 90)
		return (range / 8);
	else
		return (range / 5);
}

int	next_smaller(t_stack *b, int c)
{
	int	i;
	int	diff;
	int	flag;
	int	next;

	i = 0;
	flag = 0;
	next = 0;
	while (i < b->len)
	{
		if (!flag && b->arr[i] < c)
		{
			diff = c - b->arr[i];
			flag = 1;
			next = b->arr[i];
		}
		else if (b->arr[i] < c && c - b->arr[i] < diff)
		{
			diff = c - b->arr[i];
			next = b->arr[i];
		}
		i++;
	}
	return (next);
}

int	define_flag(t_stack *b, int c)
{
	if (c < b->max && c > b->min && b->arr[0] != next_smaller(b, c))
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
		else if (!flag)
			ra(a, 1);
	}
    while (define_flag(b, c) && c > b->min && c < b->max)
	{
        rb(b, 1);
	}
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
		if (min != a->min)
		{
			find_values(a);
		    sort_a(a, b->arr[0]);
		}
        i = 0;
        a->last = b->arr[0];
		while (b->len)
        {
        	pa(a, b);
            i++;
        }
		if (min != a->min)
		{
			while (find_ind(a, a->last) != a->len - 1)
			{
				if (find_ind(a, a->last) > a->len / 2)
					rra(a, 1);
				else
					ra(a, 1);
			}
		}
		find_values(a);
		min += range2;
		max += range2;
	}
}
