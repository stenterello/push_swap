#include "push_swap.h"

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
		free(a.arr);
		free(b.arr);
		//free(a.index);
		free(a.best);
	}
	return (0);
}
