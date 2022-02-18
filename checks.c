#include "push_swap.h"

static void	check_int_and_fill(int argc, char **argv, t_stack *a)
{
	int		i;
	int		i2;
	long	tmp;

	i = 0;
	i2 = 0;
	while (i < argc - 1)
	{
		if ((int)ft_strlen(argv[i + 1]) > 11)
			die("Error");
		while (i2 < (int)ft_strlen(argv[i + 1]))
		{
			if (!ft_isdigit(argv[i + 1][i2]) && argv[i + 1][i2] != '-')
				die("Error");
			i2++;
		}
		tmp = ft_atol(argv[i + 1]);
		if (tmp > 2147483647 || tmp < -2147483648)
			die("Error");
		a->arr[i++] = (int)tmp;
	}
	a->len = argc - 1;
}

static void	count(t_stack *a, int c)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (i < a->len)
	{
		if (a->arr[i++] == c)
			ret++;
		if (ret > 1)
			die("Error");
	}
}

static void	check_dupl(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->len)
		count(a, a->arr[i++]);
}

void	find_values(t_stack *a)
{
	int	i;

	i = 0;
	a->min = a->arr[i];
	a->max = a->arr[i];
	while (i < a->len)
	{
		if (a->arr[i] < a->min)
			a->min = a->arr[i];
		if (a->arr[i] > a->max)
			a->max = a->arr[i];
		i++;
	}
	find_half(a);
}

void	checks(int argc, char **argv, t_stack *a)
{
	check_int_and_fill(argc, argv, a);
	check_dupl(a);
	find_values(a);
}
