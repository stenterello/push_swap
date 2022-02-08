void	die(char *str)
{
	ft_putstr(str, 1);
	exit(-1);
}

int	ft_isinteger(char *str)
{
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(str))
			return (0);
		str++;
	}
	return (1);
}

int	check_duplicate(int argc, char **argv)
{
	int	i;
	int	i2;
	int	act;

	i = 1;
	i2 = i + 1;
	act = argv[1];
	while (i < argc)
	{
		while (i2 < argc)
		{
			if (argv[i2] == argv[1])
				return (0);
			i2++;
		}
		i++;
	}
	return (1);
}

void	check_errors(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isinteger(argv[i]))
			die("Error\n");
	}
	if (!check_duplicate(argc, argv))
		die("Error\n");
}

int	are_sorted(int *arr_a, int len)
{
	int	i;
	int	min;

	i = 1;
	min = arr_a[0];
	while (i < len)
	{
		if (arr_a[i] < min)
			return (0);
		else
			min = arr_a[i];
		i++;
	}
	return (1);
}
