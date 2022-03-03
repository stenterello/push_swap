/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:26:19 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/02 16:26:21 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_occ(t_stack *a, int i)
{
	int	ret;
	int	min;
	int	i2;

	ret = 1;
	min = a->index[i];
	i2 = a->best_len - 1;
	a->best[i2--] = a->index[i];
	while (i >= 0)
	{
		if (a->index[i] < min)
		{
			a->best[i2--] = a->index[i];
			min = a->index[i];
			ret++;
		}
		i--;
	}
	return (ret);
}

int	count_occ(t_stack *a, int i)
{
	int	ret;
	int	min;

	ret = 1;
	min = a->index[i];
	while (i >= 0)
	{
		if (a->index[i] < min)
		{
			min = a->index[i];
			ret++;
		}
		i--;
	}
	return (ret);
}

int	in_best(t_stack *a, int c)
{
	int	i;

	i = 0;
	while (i < a->best_len)
	{
		if (c < a->best[i])
			return (0);
		if (c == a->best[i])
			return (1);
		i++;
	}
	return (0);
}

int	count(t_stack *a, int i, int counter)
{
	int	ret;
	int	prev;

	ret = 0;
	prev = a->index[i];
	i++;
	while (i < a->len)
	{
		if (a->index[i] <= prev + counter && a->index[i] > prev)
		{
			prev = a->index[i];
			ret++;
		}
		i++;
	}
	return (ret);
}
