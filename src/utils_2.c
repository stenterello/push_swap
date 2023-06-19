/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:26:50 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/02 16:26:51 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_min(t_stack *st)
{
	int	i;

	i = 0;
	st->min = st->max;
	while (i < st->len)
	{
		if (st->arr[i] < st->min)
			st->min = st->arr[i];
		i++;
	}
}

void	find_max(t_stack *st)
{
	int	i;

	i = 0;
	st->max = st->min;
	while (i < st->len)
	{
		if (st->arr[i] > st->max)
			st->max = st->arr[i];
		i++;
	}
}

int	in_order(t_stack *a)
{
	long	ret;
	int		i;

	i = 0;
	while (i < a->len)
	{
		if (i > 0 && a->arr[i] < ret)
			return (0);
		ret = a->arr[i++];
	}
	return (1);
}

int	in_rev_order(t_stack *st)
{
	int	i;
	int	ret;

	i = 0;
	while (i < st->len)
	{
		if (i > 0 && ret < st->arr[i])
			return (0);
		ret = st->arr[i++];
	}
	return (1);
}

void	allocate(t_stack *a, t_stack *b, int argc)
{
	a->arr = ft_calloc(argc, sizeof(int));
	if (!a->arr)
		die("Malloc error");
	a->len = argc - 1;
	b->arr = ft_calloc(argc, sizeof(int));
	if (!b->arr)
		die("Malloc error");
	b->len = 0;
}
