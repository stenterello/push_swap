#include "push_swap.h"

static int	get_med(t_stack *a)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < a->len)
		sum += a->arr[i++];
	return (sum / a->len);
}

static int	get_half(t_stack *a)
{
	int	med;
	int	i;
	int	diff;
	int	ret;

	med = get_med(a);
	i = 0;
	diff = ft_abs(med - a->arr[i]);
	while (i < a->len)
	{
		if (ft_abs(med - a->arr[i]) < diff)
		{
			diff = ft_abs(med - a->arr[i]);
			ret = a->arr[i];
		}
		i++;
	}
	return (ret);
}

static int	to_do(t_stack *a, int half, char *str)
{
	int	i;

	i = 0;
	if (!ft_strncmp("f", str, 1))
	{
		while (i < a->len)
		{
			if (a->arr[i] <= half)
				return (1);
			i++;
		}
	}
	else
	{
		while (i < a->len)
		{
			if (a->arr[i] > half)
				return (1);
			i++;
		}
	}
	return (0);
}

static void	first_range(t_stack *a, t_stack *b, int half)
{
	while (to_do(a, half, "f"))
	{
		if (a->arr[0] >= a->min && a->arr[0] <= half)
			pb(a, b);
		else
			ra(a, 1);
		if (b->arr[0] < b->arr[1])
			sb(b, 1);
	}
}

static void	second_range(t_stack *a, t_stack *b, int half)
{
	while (to_do(a, half, "s"))
	{
		if (a->arr[0] > half && a->arr[0] <= a->max)
			pb(a, b);
		else
			ra(a, 1);
		if (b->arr[0] < b->arr[1])
			sb(b, 1);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	//int	i;
	int	half;

	find_values(a);
	half = get_half(a);
	first_range(a, b, half);
	find_values(a);
	second_range(a, b, half);
	find_values(b);
	while (to_do(b, half, "f"))
	{
		if (find_ind(b, b->max) > b->len / 2)
		{
			while (find_ind(b, b->max))
				rrb(b, 1);
		}
		else
		{
			while (find_ind(b, b->max))
				rb(b, 1);
		}
		pa(a, b);
		find_values(b);
	}
	//i = 0;
	//while (i < b->len)
	//{
	//	ft_printf("%d\n", b->arr[i++]);
	//}
}
