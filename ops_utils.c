#include "push_swap.h"

void	move_one_up(t_stack *st)
{
	int	i;

	i = 0;
	if (st->len > 0)
	{
		while (i < st->len - 1)
		{
			st->arr[i] = st->arr[i + 1];
			i++;
		}
	}
}

void	move_one_down(t_stack *st)
{
	int	i;

	if (st->len > 0)
	{
		i = st->len;
		while (i)
		{
			st->arr[i] = st->arr[i - 1];
			i--;
		}
		st->arr[1] = st->arr[0];
	}
}
