#include "push_swap.h"

void	move_b(int *ind, t_stack *b)
{
	while (*ind)
	{
		while (*ind > b->len / 2 && *ind)
		{
			find_values(b);
			rrb(b, 1);
			change_ind(1, ind, b->len);
		}
		while (*ind != 0)
		{
			rb(b, 1);
			change_ind(0, ind, b->len);
		}
	}
}

void	find_place_and_insert(t_stack *a, t_stack *b, int ind)
{
	int	i;

	i = 0;
	find_values(a);
	if (b->arr[ind] < a->max && b->arr[ind] > a->min)
	{
		treat_between(a, b, &ind, &i);
		move_b(&ind, b);
	}
	else if (b->arr[ind] < a->min)
	{
		treat_min(a, b, &ind);
		move_b(&ind, b);
	}
	else if (b->arr[ind] > a->max)
	{
		treat_max(a, b, &ind);
		move_b(&ind, b);
	}
	pa(a, b);
}

void	fill_range(t_stack *a, t_stack *b, int min_limit, int flag)
{
	int	mvs;

	if (flag)
	{
		pa(a, b);
		pa(a, b);
		pa(a, b);
		find_values(a);
		sort_small(a);
	}
	find_values(a);
	while (to_do(b, min_limit, b->max + 1))
	{
		mvs = decide(a, b);
		find_place_and_insert(a, b, mvs);
		find_values(a);
		find_values(b);
	}
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
	range(a, b, f_half, s_half);
	range(a, b, s_half, t_half);
	range(a, b, t_half, a->max);
	fill_range(a, b, t_half, 1);
	fill_range(a, b, s_half, 0);
	fill_range(a, b, f_half, 0);
	fill_range(a, b, b->min, 0);
	find_values(a);
	while (find_ind(a, a->min) > a->len / 2 && find_ind(a, a->min))
		rra(a, 1);
	while (find_ind(a, a->min) < a->len / 2 && find_ind(a, a->min))
		ra(a, 1);
}
