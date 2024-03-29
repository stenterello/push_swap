/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:24:22 by ddelladi          #+#    #+#             */
/*   Updated: 2022/03/02 16:24:25 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "includes/ft_printf.h"
# include "libft/libft.h"

typedef struct s_stack
{
	int	*arr;
	int	min;
	int	max;
	int	len;
	int	*best;
	int	best_len;
}				t_stack;

typedef struct s_best_elem
{
	int					val;
	int					len;
	struct s_best_elem	*next;
}				t_best_elem;

void	die(char *str);
long	ft_atol(const char *str);
int		ft_abs(int c);
void	allocate(t_stack *a, t_stack *b, int argc);
void	checks(int argc, char **argv, t_stack *a);
void	find_half(t_stack *a);
void	move_one_up(t_stack *st);
void	move_one_down(t_stack *st);
void	sa(t_stack *a, int pr);
void	sb(t_stack *b, int pr);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a, int pr);
void	rb(t_stack *b, int pr);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, int pr);
void	rrb(t_stack *b, int pr);
void	rrr(t_stack *a, t_stack *b);
void	checker_sa(t_stack *a);
void	checker_sb(t_stack *b);
void	checker_ss(t_stack *a, t_stack *b);
void	checker_pa(t_stack *a, t_stack *b);
void	checker_pb(t_stack *a, t_stack *b);
void	checker_ra(t_stack *a);
void	checker_rb(t_stack *b);
void	checker_rr(t_stack *a, t_stack *b);
void	checker_rra(t_stack *a);
void	checker_rrb(t_stack *b);
void	checker_rrr(t_stack *a, t_stack *b);
int		find_place(t_stack *a, int c);
int		find_min_arr(int *arr, int len);
int		find_max_arr(int *arr, int len);
int		find_ind_arr(int *arr, int c, int len);
int		find_ind(t_stack *st, int val);
void	find_min(t_stack *st);
void	find_max(t_stack *st);
void	sort_small(t_stack *a);
void	sort_medium(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);
int		in_order(t_stack *a);
int		in_rev_order(t_stack *st);
void	find_values(t_stack *a);
int		next(t_stack *a, int min_limit, int limit);
int		get_med(t_stack *a, int min_limit, int limit);
int		get_half(t_stack *a, int min_limit, int limit);
int		is_in(int min_limit, int limit, int c);
void	decide_in_between(t_stack *a, t_stack *b, int *tmp, int i);
void	decide_min(t_stack *a, t_stack *b, int *tmp, int i);
void	decide_max(t_stack *a, t_stack *b, int *tmp, int i);
int		decide(t_stack *a, t_stack *b);
void	treat_between(t_stack *a, t_stack *b, int *ind, int *i);
void	treat_min(t_stack *a, t_stack *b, int *ind);
void	treat_max(t_stack *a, t_stack *b, int *ind);
int		to_do(t_stack *a, int min_limit, int limit);
int		to_do_a(t_stack *a, int min_limit, int limit);
void	range(t_stack *a, t_stack *b, int min_limit, int limit);
void	change_ind(int flag, int *ind, int len);
int		count_seq(t_stack *a, int i);
int		search_seq(t_stack *a);
int		in_best(t_stack *a, int c);
void	get_lis(int *arr, int len, t_stack *a);
int		count(t_stack *a, int i, int counter);
void	count_2(t_stack *a, int c);
int		check_char(char *str);

#endif
