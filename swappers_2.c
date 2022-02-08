#include "libft/libft.h"

void	rotate_a(int *arr_a, int len, int flag)
{
	int	i;
	int	tmp;
	int	half;

	i = 0;
	half = len / 2;
	while (i <= half)
	{
		tmp = arr_a[i];
		arr_a[i] = arr_a[len];
		arr_a[len] = tmp;
		i++;
		len--;
	}
	if (flag)
		ft_putstr_fd("ra\n", 1);
}

void	rotate_b(int *arr_b, int len, int flag)
{
	int	i;
	int	tmp;
	int	half;

	i = 0;
	half = len / 2;
	while (i <= half)
	{
		tmp = arr_b[i];
		arr_b[i] = arr_b[len];
		arr_b[len] = tmp;
		i++;
		len--;
	}
	if (flag)
		ft_putstr_fd("rb\n", 1);
}

void	rr(int *arr_a, int *arr_b, int len)
{
	rotate_a(arr_a, len, 0);
	rotate_b(arr_b, len, 0);
	ft_putstr_fd("rr\n", 1);
}

void	rev_rotate_a(int *arr_a, int len)
{
	int	tmp;

	tmp = arr_a[0];
	one_back(arr_a, len);
	arr_a[len] = tmp;
	ft_putstr_fd("rra\n", 1);
}

void	rev_rotate_b(int *arr_b, int len)
{
	int	tmp;

	tmp = arr_b[0];
	one_back(arr_b, len);
	arr_b[len] = tmp;
	ft_putstr_fd("rrb\n", 1);
}
