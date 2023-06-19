/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:17:10 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/04 17:17:16 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	final_response(t_stack *a, t_stack *b)
{
	int	i;
	int	last;

	i = 0;
	last = a->arr[i++];
	while (i < a->len)
	{
		if (a->arr[i] > last)
			last = a->arr[i++];
		else
			return (0);
	}
	if (b->len != 0)
		return (0);
	return (1);
}

void	make_move(char *str, t_stack *a, t_stack *b)
{
	if (!ft_strncmp(str, "rrr\n", 4))
		checker_rrr(a, b);
	else if (!ft_strncmp(str, "rrb\n", 4))
		checker_rrb(b);
	else if (!ft_strncmp(str, "rra\n", 4))
		checker_rra(a);
	else if (!ft_strncmp(str, "rr\n", 3))
		checker_rr(a, b);
	else if (!ft_strncmp(str, "rb\n", 3))
		checker_rb(b);
	else if (!ft_strncmp(str, "ra\n", 3))
		checker_ra(a);
	else if (!ft_strncmp(str, "pb\n", 3))
		checker_pb(a, b);
	else if (!ft_strncmp(str, "pa\n", 3))
		checker_pa(a, b);
	else if (!ft_strncmp(str, "ss\n", 3))
		checker_ss(a, b);
	else if (!ft_strncmp(str, "sb\n", 3))
		checker_sb(b);
	else if (!ft_strncmp(str, "sa\n", 3))
		checker_sa(a);
	else
		die("Error");
}

void	transform(t_stack *a, t_stack *b)
{
	char	*str;

	str = get_next_line(0);
	if (str)
	{
		while (str)
		{
			find_values(a);
			find_values(b);
			make_move(str, a, b);
			free(str);
			str = get_next_line(0);
		}
	}
	free(str);
}

int	initialize(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		ret;

	allocate(&a, &b, argc);
	checks(argc, argv, &a);
	transform(&a, &b);
	ret = final_response(&a, &b);
	return (ret);
}

int	main(int argc, char **argv)
{
	int	ret;

	if (argc > 1)
	{
		ret = initialize(argc, argv);
		if (ret)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (0);
}
