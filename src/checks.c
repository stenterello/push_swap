/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:25:11 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/02 16:25:13 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	check_int_and_fill(int argc, char **argv, t_stack *a)
{
	int		i;
	long	tmp;
	int		dig;

	i = 0;
	while (i < argc - 1)
	{
		dig = check_char(argv[i + 1]);
		if (dig)
			die("Error");
		if ((int)ft_strlen(argv[i + 1]) > 11)
			die("Error");
		tmp = ft_atol(argv[i + 1]);
		if (tmp > 2147483647 || tmp < -2147483648)
			die("Error");
		a->arr[i++] = (int)tmp;
	}
	a->len = argc - 1;
}

static void	check_dupl(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->len)
		count_2(a, a->arr[i++]);
}

void	find_values(t_stack *a)
{
	int	i;

	i = 0;
	a->min = a->arr[i];
	a->max = a->arr[i];
	while (i < a->len)
	{
		if (a->arr[i] < a->min)
			a->min = a->arr[i];
		if (a->arr[i] > a->max)
			a->max = a->arr[i];
		i++;
	}
}

void	checks(int argc, char **argv, t_stack *a)
{
	check_int_and_fill(argc, argv, a);
	check_dupl(a);
	find_values(a);
}
