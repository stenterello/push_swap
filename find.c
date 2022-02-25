#include "push_swap.h"

int	find_place(t_stack *a, int c)
{
	int	i;

	i = 0;
	while (i < a->len)
	{
		if (c > a->arr[i] && a->arr[i + 1] > c)
			return (i + 1);
		i++;
	}
	return (-1);
}

int	find_min_arr(int *arr, int len)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (i < len)
	{
		if (arr[i] + i < arr[ret])
			ret = i;
		i++;
	}
	return (ret);
}
