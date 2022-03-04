/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:16:25 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/04 17:16:27 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_ra(t_stack *a)
{
	int	tmp;

	tmp = a->arr[0];
	move_one_up(a);
	a->arr[a->len - 1] = tmp;
}

void	checker_rb(t_stack *b)
{
	int	tmp;

	if (b->len > 1)
	{
		tmp = b->arr[0];
		move_one_up(b);
		b->arr[b->len - 1] = tmp;
	}
}

void	checker_rr(t_stack *a, t_stack *b)
{
	checker_ra(a);
	checker_ra(b);
}

void	checker_rra(t_stack *a)
{
	int	tmp;

	tmp = a->arr[a->len - 1];
	move_one_down(a);
	a->arr[0] = tmp;
}

void	checker_rrb(t_stack *b)
{
	int	tmp;

	tmp = b->arr[b->len - 1];
	move_one_down(b);
	b->arr[0] = tmp;
}
