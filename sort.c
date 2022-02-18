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
	if (flag && find_ind(a, c) > a->len / 2 && find_ind(a, c) != 0)
		rrr(a, b);
	else if (flag && find_ind(a, c) < a->len / 2 && find_ind(a, c) != 0)
		rr(a, b);
	else if (find_ind(a, c) > a->len / 2 && find_ind(a, c) != 0)
		rra(a, 1);
	else if (find_ind(a, c) != 0)
		ra(a, 1);
	pb(a, b);
	if (b->arr[0] < b->arr[1] && b->len > 1)
		sb(b, 1);
	find_values(b);
	find_values(a);
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
	while (max <= range2)
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
		while (b->len)
			pa(a, b);
	}
}
