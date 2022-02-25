#include "push_swap.h"

void	sa(t_stack *a, int pr)
{
	int	tmp;

	if (a->len > 1)
	{
		tmp = a->arr[0];
		a->arr[0] = a->arr[1];
		a->arr[1] = tmp;
		if (pr)
			ft_printf("sa\n");
	}
}

void	sb(t_stack *b, int pr)
{
	int	tmp;

	if (b->len > 1)
	{
		tmp = b->arr[0];
		b->arr[0] = b->arr[1];
		b->arr[1] = tmp;
		if (pr)
			ft_printf("sb\n");
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

void	pa(t_stack *a, t_stack *b)
{
	int	tmp;

	if (b->len != 0)
	{
		tmp = b->arr[0];
		move_one_up(b);
		move_one_down(a);
		a->arr[0] = tmp;
		b->len--;
		a->len++;
		ft_printf("pa\n");
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->len != 0)
	{
		tmp = a->arr[0];
		move_one_up(a);
		move_one_down(b);
		b->arr[0] = tmp;
		a->len--;
		b->len++;
		ft_printf("pb\n");
	}
}
