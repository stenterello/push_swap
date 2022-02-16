#include "push_swap.h"

void	move_one_up(t_stack *st)
{
	int	i;

	i = 0;
	while (i < st->len - 1)
	{
		st->arr[i] = st->arr[i + 1];
		i++;
	}
	st->len--;
}

void	move_one_down(t_stack *st)
{
	int	i;

	i = st->len - 1;
	st->len++;
	while (i)
	{
		st->arr[i] = st->arr[i - 1];
		i++;
	}
}
