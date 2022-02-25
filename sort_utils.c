#include "push_swap.h"

void	sort_small(t_stack *a)
{
	if (a->arr[0] > a->arr[1] && a->max == a->arr[2])
		sa(a, 1);
	else if (a->max == a->arr[0] && a->arr[1] > a->arr[2])
	{
		sa(a, 1);
		rra(a, 1);
	}
	else if (a->max == a->arr[0] && a->arr[1] < a->arr[2])
		ra(a, 1);
	else if (a->min == a->arr[0] && a->arr[1] > a->arr[2])
	{
		sa(a, 1);
		ra(a, 1);
	}
	else if (a->max == a->arr[1])
		rra(a, 1);
}

void	sort_medium(t_stack *a, t_stack *b)
{
	find_min(a);
	while (find_ind(a, a->min))
		ra(a, 1);
	pb(a, b);
	find_min(a);
	while (find_ind(a, a->min))
		ra(a, 1);
	pb(a, b);
	find_values(a);
	sort_small(a);
	find_values(a);
	pa(a, b);
	pa(a, b);
	if (!in_order(a))
		sa(a, 1);
}

int	to_do(t_stack *a, int min_limit, int limit)
{
	int	i;

	i = 0;
	while (i < a->len)
	{
		if (a->arr[i] >= min_limit && a->arr[i] < limit)
			return (1);
		i++;
	}
	return (0);
}

void	range(t_stack *a, t_stack *b, int min_limit, int limit)
{
	while (to_do(a, min_limit, limit))
	{
		if (a->arr[0] >= min_limit && a->arr[0] <= limit)
			pb(a, b);
		else
			ra(a, 1);
		find_values(b);
	}
}

void	change_ind(int flag, int *ind, int len)
{
	// flag = 0 sottrai
	// flag = 1 incrementa
	if (!flag)
		(*ind)--;
	else if (flag)
	{
		(*ind)++;
		if (*ind == len)
			*ind = 0;
	}
}
