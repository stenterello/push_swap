#include "push_swap.h"

int	next(t_stack *a, int min_limit, int limit)
{
	int	i;

	i = 0;
	while (i < a->len)
	{
		if (a->arr[i] >= min_limit && a->arr[i] <= limit)
			return (a->arr[i]);
		i++;
	}
	return (0);
}

static int	get_med(t_stack *a, int min_limit, int limit)
{
	int	i;
	int	c;
	int	sum;

	i = 0;
	c = 0;
	sum = 0;
	while (i < a->len)
	{
		if (a->arr[i] >= min_limit && a->arr[i] < limit)
		{
			sum += a->arr[i];
			c++;
		}
		i++;
	}
	return (sum / c);
}

static int	get_half(t_stack *a, int min_limit, int limit)
{
	int	med;
	int	i;
	int	diff;
	int	ret;

	med = get_med(a, min_limit, limit);
	i = 0;
	while (a->arr[i] < min_limit || a->arr[i] > limit)
		i++;
	diff = ft_abs(med - a->arr[i]);
	i = 0;
	while (i < a->len)
	{
		if (a->arr[i] >= min_limit && a->arr[i] < limit)
		{
			if (ft_abs(med - a->arr[i]) < diff)
			{
				diff = ft_abs(med - a->arr[i]);
				ret = a->arr[i];
			}
		}
		i++;
	}
	return (ret);
}

static int	to_do(t_stack *a, int min_limit, int limit)
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

static void	range(t_stack *a, t_stack *b, int min_limit, int limit)
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

int	is_in(int min_limit, int limit, int c)
{
	if (c > min_limit && c <= limit)
		return (1);
	return (0);
}

void	sort(t_stack *a, t_stack *b)
{
	int	s_half;
	int	f_half;
	int	t_half;

	find_values(a);
	s_half = get_half(a, a->min, a->max);
	f_half = get_half(a, a->min, s_half);
	t_half = get_half(a, s_half, a->max);
	range(a, b, a->min, f_half);
	find_values(b);
	range(a, b, f_half, s_half);
	find_values(b);
	range(a, b, s_half, t_half);
	find_values(b);
	range(a, b, t_half, a->max);
	find_values(b);
	while (to_do(b, t_half, b->max + 1))
	{
		find_values(a);
		while (find_ind(b, b->max))
		{
			if (find_ind(b, b->max) > b->len / 2)
				rrb(b, 1);
			else
				rb(b, 1);
			if (a->arr[0] > a->arr[1])
				sa(a, 1);
		}
		pa(a, b);
		find_values(b);
	}
	while (to_do(b, s_half, b->max + 1))
	{
		find_values(a);
		while (find_ind(b, b->max))
		{
			if (find_ind(b, b->max) > b->len / 2)
				rrb(b, 1);
			else
				rb(b, 1);
			if (a->arr[0] > a->arr[1])
				sa(a, 1);
		}
		pa(a, b);
		find_values(b);
	}
	while (to_do(b, f_half, b->max + 1))
	{
		find_values(a);
		while (find_ind(b, b->max))
		{
			if (find_ind(b, b->max) > b->len / 2)
				rrb(b, 1);
			else
				rb(b, 1);
			if (a->arr[0] > a->arr[1])
				sa(a, 1);
		}
		pa(a, b);
		find_values(b);
	}
	while (to_do(b, b->min, b->max + 1))
	{
		find_values(a);
		while (find_ind(b, b->max))
		{
			if (find_ind(b, b->max) > b->len / 2)
				rrb(b, 1);
			else
				rb(b, 1);
			if (a->arr[0] > a->arr[1])
				sa(a, 1);
		}
		pa(a, b);
		find_values(b);
	}
}
