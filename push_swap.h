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

#endif
