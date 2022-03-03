/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:25:36 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/02 16:25:40 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	allocate(t_stack *a, t_stack *b, int argc)
{
	a->arr = ft_calloc(argc, sizeof(int));
	if (!a->arr)
		die("Malloc error");
	a->len = argc - 1;
	b->arr = ft_calloc(argc, sizeof(int));
	if (!b->arr)
		die("Malloc error");
	b->len = 0;
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		allocate(&a, &b, argc);
		checks(argc, argv, &a);
		if (a.len == 2 && !in_order(&a))
			sa(&a, 1);
		if (!in_order(&a) && a.len < 4)
			sort_small(&a);
		else if (!in_order(&a) && a.len < 6)
			sort_medium(&a, &b);
		else if (!in_order(&a))
			sort(&a, &b);
		free(a.arr);
		free(b.arr);
		if (a.index)
			free(a.index);
		free(a.best);
	}
	return (0);
}
