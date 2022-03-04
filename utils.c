/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:26:41 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/02 16:26:44 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	die(char *str)
{
	ft_putendl_fd(str, 2);
	exit(-1);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	ret;

	i = 0;
	sign = 1;
	ret = 0;
	while ((*(str + i) > 8 && *(str + i) < 14) || *(str + i) == 32)
		i++;
	if (*(str + i) == 43 || *(str + i) == 45)
	{
		if (*(str + i) == 45)
			sign *= -1;
		i++;
	}
	if (*(str + i) == 43 || *(str + i) == 45)
		return (0);
	while (*(str + i) > 47 && *(str + i) < 58)
	{
		ret = (ret * 10) + (*(str + i) - 48);
		i++;
	}
	return (ret * sign);
}

int	ft_abs(int c)
{
	if (c < 0)
		return (-c);
	return (c);
}

int	find_ind(t_stack *st, int val)
{
	int	i;

	i = 0;
	while (i < st->len)
	{
		if (st->arr[i] == val)
			return (i);
		i++;
	}
	return (0);
}

void	change_ind(int flag, int *ind, int len)
{
	if (!flag)
		(*ind)--;
	else if (flag)
	{
		(*ind)++;
		if (*ind == len)
			*ind = 0;
	}
}
