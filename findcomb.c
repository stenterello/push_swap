#include "push_swap.h"

void	ft_everydrop(int *array, int *i, t_stack *a)
{
	int	j;
	int	x;

	j = 0;
	while (a->arr[j] != array[*i])
		j++;
	while (a->arr[j] != array[0])
	{
		if (a->arr[j] > array[*i])
		{
			x = j;
			while(a->arr[x] != array[0])
			{
				if (a->arr[x] > array[*i] && a->arr[x] < a->arr[j])
					j = x;
				x++;
				if (x == a->len)
					x = 0;
			}
			*i += 1;
			array[*i] = a->arr[j];
		}
		j++;
		if (j == a->len)
			j = 0;
	}
}

int		*ft_bestcomb(int *array, int x, int *i, t_stack *a)
{
	int	j;

	array = (int *) malloc (sizeof(int) * a->len);
	*i = 0;
	array[*i] = a->arr[x];
	j = x + 1;
	if (j == a->len)
		j = 0;
	while (j != x)
	{
		if (a->arr[j] == array[*i] + 1)
		{
			*i += 1;
			array[*i] = a->arr[j];
		}
		j++;
		if (j == a->len)
			j = 0;
	}
	ft_everydrop(array, i, a);
	*i += 1;
	return (array);
}

void	ft_findcomb(t_stack *a)
{
	int	i;
	int *temp;
	int	best_len;
	int	size_temp;

	i = 0;
	temp = NULL;
	a->best = ft_bestcomb(a->best, i, &best_len, a);
	i += 1;
	while (i < a->len)
	{
		temp = ft_bestcomb(temp, i, &size_temp, a);
		if (size_temp > best_len)
		{
			free(a->best);
			a->best = temp;
			best_len = size_temp;
		}
		else
			free(temp);
		i++;
	}
	a->best_len = best_len;
}