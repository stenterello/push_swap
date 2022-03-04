/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:26:56 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/02 16:26:57 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	next(t_stack *a, int min_limit, int limit)
{
	int	i;

	i = 0;
	while (i < a->len)
	{
		if (a->arr[i] >= min_limit && a->arr[i] <= limit)
			return (a->arr[i]);
		i++;
	}
	return (0);
}

int	get_med(t_stack *a, int min_limit, int limit)
{
	int	i;
	int	c;
	int	sum;

	i = 0;
	c = 0;
	sum = 0;
	while (i < a->len)
	{
		if (a->arr[i] >= min_limit && a->arr[i] < limit)
		{
			sum += a->arr[i];
			c++;
		}
		i++;
	}
	if (c != 0)
		return (sum / c);
	else
		return (a->min);
}

int	get_half(t_stack *a, int min_limit, int limit)
{
	int	med;
	int	i;
	int	diff;
	int	ret;

	med = get_med(a, min_limit, limit);
	i = 0;
	ret = 0;
	while (a->arr[i] < min_limit || a->arr[i] > limit)
		i++;
	diff = ft_abs(med - a->arr[i]);
	i = 0;
	while (i < a->len)
	{
		if (a->arr[i] >= min_limit && a->arr[i] < limit)
		{
			if (ft_abs(med - a->arr[i]) < diff)
			{
				diff = ft_abs(med - a->arr[i]);
				ret = a->arr[i];
			}
		}
		i++;
	}
	return (ret);
}

int	is_in(int min_limit, int limit, int c)
{
	if (c > min_limit && c <= limit)
		return (1);
	return (0);
}
