#include "push_swap.h"

int	get_next(t_stack *a, int prev)
{
	int	i;
	int	save;

	i = 0;
	save = a->arr[i + 1];
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

int	do_search(t_stack *a, int i)
{
	int	rem;
	int	c;
	int	ret;

	rem = a->arr[i];
	c = 0;
	ret = 0;
	while (i < a->len)
	{
		if (a->arr[i] > rem)
		{
			rem = a->arr[i];
			c++;
		}
		if (c > ret)
			ret = c;
		i++;
	}
	return (ret);
}

int	do_search2(t_stack *a, int i)
{
	int	c;
	int	rem;

	c = 1;
	rem = a->index[i++];
	while (i < a->len)
	{
		if (a->index[i] == rem + 1)
		{
			rem = a->index[i];
			c++;
		}
		i++;
	}
	return (c);
}

void	fill_best(t_stack *a, int ind)
{
	int	rem;
	int	rem2;
	int	i;

	a->best_len = a->len - ind;
	a->best = ft_calloc(a->best_len, sizeof(int));
	if (!a->best)
		return ;
	rem = a->arr[ind];
	rem2 = a->index[ind];
	i = 0;
	a->best[i] = rem;
	ind++;
	while (ind < a->len)
	{
		if (a->index[ind] == rem2 + 1)
		{
			rem = a->arr[ind];
			rem2 = a->index[ind];
			a->best[i++] = rem;
		}
		ind++;
	}
	a->best_len = i;
}

void	get_best(t_stack *a)
{
	int	i;
	int	b_l;
	int	ind;

	i = 0;
	ind = 0;
	while (i < a->len)
	{
		b_l = do_search2(a, i);
		if (b_l > do_search2(a, ind))
			ind = i;
		i++;
	}
	fill_best(a, ind);
}

int	in_best(t_stack *a, int c)
{
	int	i;

	i = 0;
	while (i < a->best_len)
	{
		if (c == a->best[i])
			return (1);
		i++;
	}
	return (0);
}

void	get_seq(t_stack *a)
{
	get_indexes(a);
	get_best(a);
}
