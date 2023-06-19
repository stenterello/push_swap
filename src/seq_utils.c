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

#include "../includes/push_swap.h"

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
