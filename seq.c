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

int	get_next(t_stack *a, int prev)
{
	int	i;
	int	save;

	i = 0;
	if (prev < a->arr[i])
		save = a->arr[i];
	else
		save = a->max;
	while (i < a->len)
	{
		if (a->arr[i] > prev && a->arr[i] < save)
		{
			save = a->arr[i];
		}
		i++;
	}
	return (find_ind(a, save));
}

void	get_indexes(t_stack *a)
{
	int	ind;
	int	rem;
	int	i;

	a->index = ft_calloc(a->len, sizeof(int));
	if (!a->index)
		return ;
	i = 0;
	while (i < a->len)
	{
		if (i > 0)
		{
			ind = get_next(a, rem);
			rem = a->arr[ind];
		}
		else
		{
			ind = find_ind(a, a->min);
			rem = a->min;
		}
		a->index[ind] = i++;
	}
}

void	create_n(int len, t_best_elem *n, int *arr)
{
	int	i;

	i = 0;
	while (i < len)
	{
		n[i].val = arr[i];
		i++;
	}
}

void	create_p(int len, t_best_elem *n, t_best_elem *p)
{
	int	i;

	i = len;
	while (i)
	{
		p = n + i;
		while (p++ < n + len)
		{
			if (p->val > n[i].val && p->len >= n[i].len)
			{
				n[i].next = p;
				n[i].len = p->len + 1;
			}
		}
		i--;
	}
	p = n;
	while (i < len)
	{
		if (n[i].len > p->len)
			p = n + i;
		i++;
	}
}

void	get_lis(int *arr, int len, t_stack *a)
{
	int			i;
	t_best_elem	*p;
	t_best_elem	*n;

	n = ft_calloc(len, sizeof(*n));
	if (!n)
		die("Malloc error");
	create_n(len, n, arr);
	p = ft_calloc(len, sizeof(*n));
	create_p(len, n, p);
	i = 0;
	a->best = ft_calloc(a->len, sizeof(int));
	if (!a->best)
		die("Malloc error");
	a->best[i++] = p->val;
	while (p->next)
	{
		a->best[i++] = p->val;
		p = p->next;
	}
	a->best[i++] = p->val;
	a->best_len = i;
	free(n);
	free(p);
}
