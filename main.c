#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		a.arr = ft_calloc(argc, sizeof(int));
		a.len = argc - 1;
		b.arr = ft_calloc(argc, sizeof(int));
		b.len = 0;
		checks(argc, argv, &a);
		//sort(&a, &b);
		ft_printf("%d\n", a.min);
		ft_printf("%d\n", a.half);
		ft_printf("%d\n", a.max);
		free(a.arr);
		free(b.arr);
	}
	return (0);
}
