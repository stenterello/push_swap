#include "libft/libft.h"

void	init_b(int *arr_b, int len)
{
	int	i;

	i = 0;
	while (i < len)
		arr_b[i++] = '\0';
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

void	one_forward(int *arr, int ind, int len)
{
	int	i;
	int	tmp;

	i = 0;
	while (ind < len - 1)
	{
		tmp = arr[ind + 1];
		arr[ind + 1] = arr[ind];
		ind++;
		i++;
	}
}

void	one_back(int *arr, int ind)
{
	int	i;
	int	tmp;

	i = 0;
	while (ind > 0)
	{
		tmp = arr[ind - 1];
		arr[ind - 1] = arr[ind];
		ind--;
		i++;
	}
}

void	take_one(int *src, int *dst, int len)
{
	dst[len] = src[len];
}
