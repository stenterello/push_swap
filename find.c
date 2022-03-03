/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:25:25 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/02 16:25:26 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_place(t_stack *a, int c)
{
	int	i;

	i = 0;
	while (i < a->len)
	{
		if (c > a->arr[i] && a->arr[i + 1] > c)
			return (i + 1);
		i++;
	}
	return (-1);
}

int	find_min_arr(int *arr, int len)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (i < len)
	{
		if (arr[i] < arr[ret])
			ret = i;
		i++;
	}
	return (ret);
}

int	find_max_arr(int *arr, int len)
{
	int	ret;
	int	i;

	i = 0;
	ret = arr[0];
	while (i < len - 1)
	{
		if (arr[i] > ret)
			ret = arr[i];
		i++;
	}
	return (ret);
}

int	find_ind_arr(int *arr, int c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
