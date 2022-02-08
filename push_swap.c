#include <stdlib.h>
#include "libft/libft.h"

int	sort(int *arr_a, int *arr_b, int len)
{
	int	mv;

	mv = 0;
	if (find_ind_min(arr_a, len) > len / 2)
		reverse
	else
		swap

	push
}

int	execute(int *arr_a, int len)
{
	int	*arr_b;
	int	res;

	arr_b = malloc(sizeof(int) * len);
	if (!arr_b)
		die("Malloc error\n");
	init_b(arr_b);
	res = sort(arr_a, arr_b, len);
}

int	initialize(int argc, char **argv)
{
	int	*arr_a;
	int	i;
	int	i2;

	i = 1;
	i2 = 0;
	while (i < argc)
		arr_a[i2++] = ft_atoi(argv[i++]);
	return (execute(arr_a, argc - 1));
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		check_errors(argc, argv);
		initialize(argc, argv);
	}
	return (0);
}
