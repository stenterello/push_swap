#include "push_swap.h"

static void	print(t_stack *st)
{
	int	i;

	i = 0;
	while (i < st->len)
	{
		ft_putnbr_fd(st->arr[i++], 1);
		ft_printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		a.arr = ft_calloc(argc, sizeof(int));
		if (!a.arr)
			return (-1);
		a.len = argc - 1;
		b.arr = ft_calloc(argc, sizeof(int));
		if (!b.arr)
			return (-1);
		b.len = 0;
		checks(argc, argv, &a);
		if (a.len == 2 && !in_order(&a))
			sa(&a, 1);
		if (!in_order(&a) && a.len < 4)
			sort_small(&a);
		else if (!in_order(&a) && a.len < 6)
			sort_medium(&a, &b);
		else if (!in_order(&a))
			sort(&a, &b);
		ft_printf("A\n");
		print(&a);
		ft_printf("B\n");
		print(&b);
		free(a.arr);
		free(b.arr);
	}
	return (0);
}
