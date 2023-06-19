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

void	create_n(int len, t_best_elem *n, int *arr)
{
	int	i;

	i = 0;
	if (n == NULL)
		ft_printf("ciao\n");

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

void	allocate_lists(t_best_elem **n, t_best_elem **p, int len)
{
	*n = ft_calloc(len, sizeof(t_best_elem));
	if (!*n)
		die("Malloc error");
	*p = ft_calloc(len, sizeof(t_best_elem));
	if (!*p)
		die("Malloc error");
}

void	get_lis(int *arr, int len, t_stack *a)
{
	int			i;
	t_best_elem	*p;
	t_best_elem	*n;

	p = NULL;
	n = NULL;
	allocate_lists(&n ,&p, len);
	create_n(len, n, arr);
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
