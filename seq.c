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

int fill_occ(t_stack *a, int i)
{
    int ret;
    int min;
    int i2;

    ret = 1;
    min = a->index[i];
    i2 = a->best_len - 1;
    a->best[i2--] = a->index[i];
    while (i >= 0)
    {
        if (a->index[i] < min)
        {
            a->best[i2--] = a->index[i];
            min = a->index[i];
            ret++;
        }
        i--;
    }
    return (ret);
}

int count_occ(t_stack *a, int i)
{
    int ret;
    int min;

    ret = 1;
    min = a->index[i];
    while (i >= 0)
    {
        if (a->index[i] < min)
        {
            min = a->index[i];
            ret++;
        }
        i--;
    }
    return (ret);
}

struct node {
	int val, len;
	struct node *next;
};
 
void get_lis(int *v, int len, t_stack *a)
{
	int i;
	struct node *p, *n = calloc(len, sizeof *n);
	for (i = 0; i < len; i++)
		n[i].val = v[i];
 
	for (i = len; i--; ) {
		// find longest chain that can follow n[i]
		for (p = n + i; p++ < n + len; ) {
			if (p->val > n[i].val && p->len >= n[i].len) {
				n[i].next = p;
				n[i].len = p->len + 1;
			}
		}
	}
 
	// find longest chain
	for (i = 0, p = n; i < len; i++)
		if (n[i].len > p->len) p = n + i;

    i = 0;
    a->best = ft_calloc(a->len, sizeof(int));
	do a->best[i++] = p->val; while ((p = p->next));
    a->best_len = i;

	free(n);
}

void    get_seq(t_stack *a)
{
    get_lis(a->arr, a->len, a);
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
