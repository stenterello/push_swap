#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "includes/includes/ft_printf.h"

typedef struct s_stack
{
	int	*arr;
	int	min;
	int	max;
	int	half;
	int	len;
	int	last;
}				t_stack;

void	die(char *str);
long	ft_atol(const char *str);
int		ft_abs(int c);
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
int		find_ind(t_stack *st, int val);
void	find_min(t_stack *st);
void	find_max(t_stack *st);
void	sort_small(t_stack *a);
void	sort_rev_small(t_stack *b);
void	sort_medium(t_stack *a, t_stack *b);
void	sort(t_stack *a, t_stack *b);
int		in_order(t_stack *a);
int		in_rev_order(t_stack *st);
void	find_values(t_stack *a);

#endif
