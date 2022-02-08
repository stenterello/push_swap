#include "libft/libft.h"

void	init_b(int *arr_b)
{

}

int	find_ind_min(int *arr_a, int len)
{
	int	min_val;
	int	min_ind;
	int	i;

	i = 0;
	min_ind = 0;
	min_val = arr_a[0];
	while (i < len)
	{
		if (arr_a[i] < min_val)
			min_ind = i;
		i++;
	}
	return (min_ind);
}

void	swap_a(int *arr_a, int len, int print)
{
	int	tmp;

	if (len >= 2)
	{
		tmp = arr_a[0];
		arr_a[0] = arr_a[1];
		arr_a[1] = tmp;
		if (print)
			ft_putstr_fd("sa\n", 1);
	}
}

void	swap_b(int *arr_b, int len, int print)
{
	int	tmp;

	if (len >= 2)
	{
		tmp = arr_b[0];
		arr_b[0] = arr_b[1];
		arr_b[1] = tmp;
		if (print)
			ft_putstr_fd("sb\n", 1);
	}
}

void	ss(int *arr_a, int *arr_b, int len)
{
	swap_a(arr_a, len, 0);
	swap_b(arr_b, len, 0);
}
