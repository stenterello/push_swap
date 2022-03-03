/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:26:12 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/02 16:26:13 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
