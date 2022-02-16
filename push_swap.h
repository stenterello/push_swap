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

#endif
