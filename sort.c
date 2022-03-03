/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:26:26 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/02 16:26:27 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b(int *ind, t_stack *b)
{
	while (*ind)
	{
		while (*ind > b->len / 2 && *ind)
		{
			rrb(b, 1);
			change_ind(1, ind, b->len);
		}
		while (*ind <= b->len / 2 && *ind != 0)
		{
			rb(b, 1);
			change_ind(0, ind, b->len);
		}
	}
}

void	find_place_and_insert(t_stack *a, t_stack *b, int ind)
{
	int	i;

	i = 0;
	find_values(a);
	if (b->arr[ind] < a->max && b->arr[ind] > a->min)
	{
		treat_between(a, b, &ind, &i);
		move_b(&ind, b);
	}
	else if (b->arr[ind] < a->min)
	{
		treat_min(a, b, &ind);
		move_b(&ind, b);
	}
	else if (b->arr[ind] > a->max)
	{
		treat_max(a, b, &ind);
		move_b(&ind, b);
	}
	pa(a, b);
}

void	fill_range(t_stack *a, t_stack *b, int min_limit, int flag)
{
	int	mvs;

	if (flag && !a->len)
	{
		pa(a, b);
		pa(a, b);
		pa(a, b);
		find_values(a);
		sort_small(a);
	}
	find_values(a);
	while (to_do(b, min_limit, b->max + 1))
	{
		mvs = decide(a, b);
		find_place_and_insert(a, b, mvs);
		find_values(a);
		find_values(b);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	int	s_half;
	int	f_half;
	int	t_half;

	get_lis(a->arr, a->len, a);
	find_values(a);
	s_half = get_half(a, a->min, a->max);
	f_half = get_half(a, a->min, s_half);
	t_half = get_half(a, s_half, a->max);
	range(a, b, t_half, a->max);
	range(a, b, s_half, a->max);
	range(a, b, f_half, a->max);
	range(a, b, a->min, a->max);
	fill_range(a, b, a->min, 0);
	find_values(a);
	while (find_ind(a, a->min) > a->len / 2 && find_ind(a, a->min))
		rra(a, 1);
	while (find_ind(a, a->min) < a->len / 2 && find_ind(a, a->min))
		ra(a, 1);
}
