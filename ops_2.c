#include "push_swap.h"

void	ra(t_stack *a, int pr)
{
	int	tmp;

	tmp = a->arr[0];
	move_one_up(a);
	a->arr[a->len - 1] = tmp;
	if (pr)
		ft_printf("ra\n");
}

void	rb(t_stack *b, int pr)
{
	int	tmp;

	tmp = b->arr[0];
	move_one_up(b);
	b->arr[b->len - 1] = tmp;
	if (pr)
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	ra(b, 0);
	ft_printf("rr\n");
}

void	rra(t_stack *a, int pr)
{
	int	tmp;

	tmp = a->arr[a->len - 1];
	move_one_down(a);
	a->arr[0] = tmp;
	if (pr)
		ft_printf("rra\n");
}

void	rrb(t_stack *b, int pr)
{
	int	tmp;

	tmp = b->arr[b->len - 1];
	move_one_down(b);
	b->arr[0] = tmp;
	if (pr)
		ft_printf("rrb\n");
}
