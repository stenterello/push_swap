#include "libft/libft.h"

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
	ft_putstr_fd("ss\n", 1);
}

void	push_a(int *arr_a, int *arr_b, int len)
{
	one_back(arr_a, len);
	take_one(arr_a, arr_b, len);
	one_forward(arr_b, 0, len);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(int *arr_a, int *arr_b, int len)
{
	one_back(arr_b, len);
	take_one(arr_b, arr_a, len);
	one_forward(arr_a, 0, len);
	ft_putstr_fd("pb\n", 1);
}
