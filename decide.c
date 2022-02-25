#include "push_swap.h"

void	decide_in_between(t_stack *a, t_stack *b, int *tmp, int i)
{
	tmp[i] = find_place(a, b->arr[i]);
	if (tmp[i] < a->len / 2 && find_ind(b, b->arr[i]) < b->len / 2)
	{
		if (tmp[i] > find_ind(b, b->arr[i]))
			tmp[i] = tmp[i] + 1;
		else
			tmp[i] = find_ind(b, b->arr[i]) + 1;
	}
	else if ((tmp[i] > a->len / 2 && find_ind(b, b->arr[i]) < b->len / 2)
		|| (tmp[i] < a->len / 2 && find_ind(b, b->arr[i]) > b->len / 2))
		tmp[i] = tmp[i] + find_ind(b, b->arr[i]) + 1;
	else if (tmp[i] > a->len / 2 && find_ind(b, b->arr[i]) > b->len / 2)
	{
		if (tmp[i] > find_ind(b, b->arr[i]))
			tmp[i] = a->len - tmp[i] + 1;
		else
			tmp[i] = a->len - find_ind(b, b->arr[i]) + 1;
	}
}

void	decide_min(t_stack *a, t_stack *b, int *tmp, int i)
{
	tmp[i] = find_ind(a, a->min);
	if (tmp[i] > a->len / 2)
		tmp[i] = a->len - tmp[i];
	tmp[i] += find_ind(b, b->arr[i]);
}

void	decide_max(t_stack *a, t_stack *b, int *tmp, int i)
{
	tmp[i] = find_ind(a, a->max) + 1;
	if (tmp[i] > a->len / 2)
		tmp[i] = a->len - tmp[i];
	tmp[i] += find_ind(b, b->arr[i]);
}

int	decide(t_stack *a, t_stack *b)
{
	int	tmp[500];
	int	i;
	int	len;

	i = 0;
	if (b->len <= 500)
		len = b->len;
	else
		len = 500;
	while (i < len)
	{
		if (b->arr[i] < a->max && b->arr[i] > a->min)
			decide_in_between(a, b, tmp, i);
		else if (b->arr[i] < a->min)
			decide_min(a, b, tmp, i);
		else if (b->arr[i] > a->max)
			decide_max(a, b, tmp, i);
		i++;
	}
	return (find_min_arr(tmp, len));
}
