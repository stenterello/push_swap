#include "push_swap.h"

void	treat_between_helper(t_stack *a, int tmp, int *i, int flag)
{
	if (!flag)
	{
		while (*i < a->len - tmp)
		{
			rra(a, 1);
			(*i)++;
		}
	}
	else
	{
		while (*i < tmp)
		{
			ra(a, 1);
			(*i)++;
		}
	}
}

void	treat_between(t_stack *a, t_stack *b, int *ind, int *i)
{
	int	tmp;

	tmp = find_place(a, b->arr[*ind]);
	if (tmp > a->len / 2)
	{
		while (*i < a->len - tmp && *ind > b->len / 2 && *ind)
		{
			rrr(a, b);
			change_ind(1, ind, b->len);
			(*i)++;
		}
		treat_between_helper(a, tmp, i, 0);
	}
	else
	{
		while (*i < tmp && *ind < b->len / 2 && *ind)
		{
			rr(a, b);
			change_ind(0, ind, b->len);
			(*i)++;
		}
		treat_between_helper(a, tmp, i, 1);
	}
}

void	treat_min(t_stack *a, t_stack *b, int *ind)
{
	if (find_ind(a, a->min) > a->len / 2)
	{
		while (find_ind(a, a->min) && *ind > b->len / 2 && *ind)
		{
			rrr(a, b);
			change_ind(1, ind, b->len);
		}
		while (find_ind(a, a->min))
			rra(a, 1);
	}
	else
	{
		while (find_ind(a, a->min) && *ind < b->len / 2 && *ind)
		{
			rr(a, b);
			change_ind(0, ind, b->len);
		}
		while (find_ind(a, a->min))
			ra(a, 1);
	}
}

void	treat_max(t_stack *a, t_stack *b, int *ind)
{
	if (find_ind(a, a->max) > a->len / 2)
	{
		while (find_ind(a, a->max) && *ind > b->len / 2 && *ind)
		{
			rrr(a, b);
			change_ind(1, ind, b->len);
		}
		while (find_ind(a, a->max))
			rra(a, 1);
		if (!find_ind(a, a->max))
			ra(a, 1);
	}
	else
	{
		while (find_ind(a, a->max) && *ind < b->len / 2 && *ind)
		{
			rr(a, b);
			change_ind(0, ind, b->len);
		}
		while (find_ind(a, a->max))
			ra(a, 1);
		if (!find_ind(a, a->max))
			ra(a, 1);
	}
}
