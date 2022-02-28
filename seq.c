#include "push_swap.h"

int	get_next(t_stack *a, int prev)
{
	int	i;
	int	save;

	i = 0;
	if (prev < a->arr[i])
		save = a->arr[i];
	else
		save = a->max;
	while (i < a->len)
	{
		if (a->arr[i] > prev && a->arr[i] < save)
		{
			save = a->arr[i];
		}
		i++;
	}
	return (find_ind(a, save));
}

void	get_indexes(t_stack *a)
{
	int	ind;
	int	rem;
	int	i;

	a->index = ft_calloc(a->len, sizeof(int));
	if (!a->index)
		return ;
	i = 0;
	while (i < a->len)
	{
		if (i > 0)
		{
			ind = get_next(a, rem);
			rem = a->arr[ind];
		}
		else
		{
			ind = find_ind(a, a->min);
			rem = a->min;
		}
		a->index[ind] = i++;
	}
}

int	count(t_stack *a, int i, int counter)
{
	int	ret;
	int	prev;

	ret = 0;
	prev = a->index[i];
	i++;
	while (i < a->len)
	{
		if (a->index[i] <= prev + counter && a->index[i] > prev)
		{
			prev = a->index[i];
			ret++;
		}
		i++;
	}
	return (ret);
}

void	fill_best(t_stack *a, int ind, int counter)
{
	int	i;
	int	i2;

	i = 0;
	a->best = ft_calloc(a->best_len, sizeof(int));
	if (!a->best)
		return ;
	a->best[i] = a->index[ind];
	i++;
	ind++;
	while (i < a->best_len)
	{
		i2 = ind + 1;
		while (i2 < a->len)
		{
			if (a->index[i2] <= a->best[i - 1] + counter && a->index[i2] > a->best[i - 1])
			{
				a->best[i++] = a->index[i2];
				ind = i2;
				break ;
			}
			i2++;
		}
	}
}

void	incremental_search(t_stack *a)
{
	int	i;
	int	ind;
	int	b_c;
	int	counter;
	int	r_counter;

	b_c = 0;
	counter = 1;
	while (counter < a->len / 10)
	{
		i = 0;
		while (i < a->len)
		{
			if (count(a, i, counter) > b_c)
			{
				b_c = count(a, i, counter);
				ind = i;
				r_counter = counter;
			}
			i++;
		}
		counter++;
	}
	a->best_len = b_c;
	fill_best(a, ind, r_counter);
}

void	translate_best_arr(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->best_len)
	{
		a->best[i] = a->arr[find_ind_arr(a->index, a->best[i], a->len)];
		i++;
	}
}

void	get_seq(t_stack *a)
{
	get_indexes(a);
	incremental_search(a);
	translate_best_arr(a);
}

int	in_best(t_stack *a, int c)
{
	int	i;

	i = 0;
	while (i < a->best_len)
	{
		if (c < a->best[i])
			return (0);
		if (c == a->best[i])
			return (1);
		i++;
	}
	return (0);
}
