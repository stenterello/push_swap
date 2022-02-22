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

void	sort_rev_small(t_stack *b)
{
	if (b->min == b->arr[0] && b->max == b->arr[2])
    {
        sb(b, 1);
        rrb(b, 1);
    }
    if (b->min == b->arr[1] && b->max == b->arr[2])
        rrb(b, 1);
    else if (b->max == b->arr[1] && b->min == b->arr[2])
        sb(b, 1);
    else if (b->min == b->arr[0] && b->max == b->arr[1])
        rb(b, 1);
    else if (b->max == b->arr[0] && b->min == b->arr[1])
    {
        rb(b, 1);
        sb(b, 1);
        rrb(b, 1);
    }
}