/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:16:47 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/04 17:16:50 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_sa(t_stack *a)
{
	int	tmp;

	if (a->len > 1)
	{
		tmp = a->arr[0];
		a->arr[0] = a->arr[1];
		a->arr[1] = tmp;
	}
}

void	checker_sb(t_stack *b)
{
	int	tmp;

	if (b->len > 1)
	{
		tmp = b->arr[0];
		b->arr[0] = b->arr[1];
		b->arr[1] = tmp;
	}
}

void	checker_ss(t_stack *a, t_stack *b)
{
	checker_sa(a);
	checker_sb(b);
}

void	checker_pa(t_stack *a, t_stack *b)
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
	}
}

void	checker_pb(t_stack *a, t_stack *b)
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
	}
}
