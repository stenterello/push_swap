/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:31:50 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/04 17:31:51 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_char(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (*(str + i) != '\0')
	{
		if (!ft_isdigit(*(str + i)) && *(str + i) != '-')
			return (1);
		i++;
	}
	return (0);
}

void	count_2(t_stack *a, int c)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < a->len)
	{
		if (a->arr[i++] == c)
			ret++;
		if (ret > 1)
			die("Error");
	}
}
