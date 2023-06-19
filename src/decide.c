/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:25:18 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/02 16:25:19 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	decide_in_between(t_stack *a, t_stack *b, int *tmp, int i)
{
	tmp[i] = find_place(a, b->arr[i]);
	if (tmp[i] <= a->len / 2 && find_ind(b, b->arr[i]) <= b->len / 2)
	{
		if (tmp[i] > find_ind(b, b->arr[i]))
			tmp[i] = tmp[i] + 1;
		else
			tmp[i] = find_ind(b, b->arr[i]) + 1;
	}
	else if (tmp[i] > a->len / 2 && find_ind(b, b->arr[i]) <= b->len / 2)
		tmp[i] = (a->len - tmp[i]) + find_ind(b, b->arr[i]);
	else if (tmp[i] <= a->len / 2 && find_ind(b, b->arr[i]) > b->len / 2)
		tmp[i] = tmp[i] + (b->len - find_ind(b, b->arr[i]));
	else if (tmp[i] > a->len / 2 && find_ind(b, b->arr[i]) > b->len / 2)
	{
		if (tmp[i] < find_ind(b, b->arr[i]) || a->len < (a->len + b->len) / 2)
			tmp[i] = b->len - find_ind(b, b->arr[i]) + 1 + tmp[i];
		else
			tmp[i] = a->len - tmp[i] + 1;
	}
}

void	decide_min(t_stack *a, t_stack *b, int *tmp, int i)
{
	int	f;
	int	s;

	f = find_ind(a, a->min);
	s = find_ind(b, b->arr[i]);
	if (f > a->len / 2)
		f = a->len - f;
	if (s > b->len / 2)
		s = b->len - s;
	if (f > s)
		tmp[i] = f;
	else
		tmp[i] = s;
}

void	decide_max(t_stack *a, t_stack *b, int *tmp, int i)
{
	int	f;
	int	s;

	f = find_ind(a, a->max);
	s = find_ind(b, b->arr[i]);
	if (f > a->len / 2)
		f = a->len - f;
	if (s > b->len / 2)
		s = b->len - s;
	if (f > s)
		tmp[i] = f;
	else
		tmp[i] = s;
}

int	decide(t_stack *a, t_stack *b)
{
	int	tmp[510];
	int	i;
	int	len;

	i = 0;
	find_values(a);
	find_values(b);
	if (b->len <= 510)
		len = b->len;
	else
		len = 500;
	while (i < len)
	{
		if (b->arr[i] < a->max && b->arr[i] > a->min)
			decide_in_between(a, b, tmp, i);
		else if (b->arr[i] < a->min)
			decide_min(a, b, tmp, i);
		else if (b->arr[i] > a->max)
			decide_max(a, b, tmp, i);
		i++;
	}
	return (find_min_arr(tmp, len));
}
