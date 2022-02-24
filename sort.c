#include "push_swap.h"

int	next(t_stack *a, int min_limit, int limit)
{
	int	i;

	i = 0;
	while (i < a->len)
	{
		if (a->arr[i] >= min_limit && a->arr[i] <= limit)
			return (a->arr[i]);
		i++;
	}
	return (0);
}

static int	get_med(t_stack *a, int min_limit, int limit)
{
	int	i;
	int	c;
	int	sum;

	i = 0;
	c = 0;
	sum = 0;
	while (i < a->len)
	{
		if (a->arr[i] >= min_limit && a->arr[i] < limit)
		{
			sum += a->arr[i];
			c++;
		}
		i++;
	}
	return (sum / c);
}

static int	get_half(t_stack *a, int min_limit, int limit)
{
	int	med;
	int	i;
	int	diff;
	int	ret;

	med = get_med(a, min_limit, limit);
	i = 0;
	while (a->arr[i] < min_limit || a->arr[i] > limit)
		i++;
	diff = ft_abs(med - a->arr[i]);
	i = 0;
	while (i < a->len)
	{
		if (a->arr[i] >= min_limit && a->arr[i] < limit)
		{
			if (ft_abs(med - a->arr[i]) < diff)
			{
				diff = ft_abs(med - a->arr[i]);
				ret = a->arr[i];
			}
		}
		i++;
	}
	return (ret);
}

static int	to_do(t_stack *a, int min_limit, int limit)
{
	int	i;

	i = 0;
	while (i < a->len)
	{
		if (a->arr[i] >= min_limit && a->arr[i] < limit)
			return (1);
		i++;
	}
	return (0);
}

static void	range(t_stack *a, t_stack *b, int min_limit, int limit)
{
	while (to_do(a, min_limit, limit))
	{
		if (a->arr[0] >= min_limit && a->arr[0] <= limit)
			pb(a, b);
		else
			ra(a, 1);
		find_values(b);
	}
}

int	is_in(int min_limit, int limit, int c)
{
	if (c > min_limit && c <= limit)
		return (1);
	return (0);
}

//void	fill_range(t_stack *a, t_stack *b, int min_limit)
//{
//	while (to_do(b, min_limit, b->max + 1))
//	{
//		find_values(a);
//		while (find_ind(b, b->max))
//		{
//			if (find_ind(b, b->max) > b->len / 2)
//				rrb(b, 1);
//			else
//				rb(b, 1);
//			if (a->arr[0] > a->arr[1])
//				sa(a, 1);
//		}
//		pa(a, b);
//		find_values(b);
//	}
//}
//

int find_place(t_stack *a, int c)
{
    int i;
    
    i = 0;
    while (i < a->len)
    {
        if (c > a->arr[i] && a->arr[i + 1] > c)
            return (i + 1);
        i++;
    }
    return (-1);
}

int	find_min_arr(int *arr, int len)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	while (i < len)
	{
		if (arr[i] + i < arr[ret])
			ret = i;
		i++;
	}
	return (ret);
}

int	decide(t_stack *a, t_stack *b)
{
	int	tmp[20];
	int	min;
	int	i;

	i = 0;
	if (b->len > 20)
	{
		while (i < 20)
		{
			if (b->arr[i] < a->max && b->arr[i] > a->min)
			{
				tmp[i] = find_place(a, b->arr[i]);
				if (tmp[i] < a->len / 2 && find_ind(b, b->arr[i]) < b->len  / 2)
				{
					if (tmp[i] > find_ind(b, b->arr[i]))
					{
						tmp[i] = tmp[i] + 1;
					}
					else
					{
						tmp[i] = find_ind(b, b->arr[i]) + 1;
					}
				}
				else if ((tmp[i] > a->len / 2 && find_ind(b, b->arr[i]) < b->len / 2) || tmp[i] < a->len / 2 && find_ind(b, b->arr[i]) > b->len / 2)
				{
					tmp[i] = tmp[i] + find_ind(b, b->arr[i]) + 1;
				}
				else if (tmp[i] > a->len / 2 && find_ind(b, b->arr[i]) > b->len / 2)
				{
					if (tmp[i] > find_ind(b, b->arr[i]))
					{
						tmp[i] = a->len - tmp[i] + 1;
					}
					else
					{
						tmp[i] = a->len - find_ind(b, b->arr[i]) + 1;
					}
				}
			}
			else if (b->arr[i] < a->min)
			{
				tmp[i] = find_ind(a, a->min);
				if (tmp[i] > a->len / 2)
					tmp[i] = a->len - tmp[i];
			}
			else if (b->arr[i] > a->max)
			{
				tmp[i] = find_ind(a, a->max) + 1;
				if (tmp[i] > a->len / 2)
					tmp[i] = a->len - tmp[i];
			}
			i++;
		}
		min = find_min_arr(tmp, 20);
	}
	else
		return (0);
	return (min);
}

void    find_place_and_insert(t_stack *a, t_stack *b)
{
    int i;
    int tmp;

    i = 0;
    find_values(a);
    if (b->arr[0] < a->max && b->arr[0] > a->min)
    {
        tmp = find_place(a, b->arr[0]);
        if (tmp > a->len / 2)
        {
            tmp = a->len - tmp;
            while (i++ < tmp)
                rra(a, 1);
        }
        else
        {
            while (i++ < tmp)
                ra(a, 1);
        }
    }
    else if (b->arr[0] < a->min)
    {
    	if (find_ind(a, a->min) > a->len / 2)
        {
            while (find_ind(a, a->min))
                rra(a, 1);
        }
        else
        {
            while (find_ind(a, a->min))
                ra(a, 1);
        }
    }
    else if (b->arr[0] > a->max)
    {
        if (find_ind(a, a->max) > a->len / 2)
        {
            while (find_ind(a, a->max))
                rra(a, 1);
            ra(a, 1);
        }
        else
        {
            while (find_ind(a, a->max))
                ra(a, 1);
            ra(a, 1);
        }
    }
    pa(a, b);
}

void	change_ind(int flag, int *ind, int len)
{

	// flag = 0 sottrai
	// flag = 1 incrementa
	if (!flag)
		(*ind)--;
	else if (flag)
	{
		(*ind)++;
		if (*ind == len)
			*ind = 0;
	}
}

void    find_place_and_insert2(t_stack *a, t_stack *b, int ind)
{
    int i;
    int tmp;
	int	flag;

    i = 0;
	flag = 0;
    find_values(a);
    if (b->arr[ind] < a->max && b->arr[ind] > a->min)
    {
        tmp = find_place(a, b->arr[ind]);
        if (tmp > a->len / 2)
        {
            tmp = a->len - tmp;
            while (i++ < tmp && ind > b->len / 2 && ind)
			{
                rrr(a, b);
				change_ind(0, &ind, b->len);
			}
			while (i++ < tmp)
				rra(a, 1);
        }
        else
        {
            while (i++ < tmp && ind < b->len / 2 && ind)
			{
                rr(a, b);
				change_ind(1, &ind, b->len);
			}
			while (i++ < tmp)
				ra(a, 1);
        }
		while (ind)
		{
			while (ind > b->len / 2 && ind)
			{
				rrb(b, 1);
				change_ind(1, &ind, b->len);
			}
			while (ind != 0)
			{
				rb(b, 1);
				change_ind(0, &ind, b->len);
			}
		}
    }
    else if (b->arr[ind] < a->min)
    {
    	if (find_ind(a, a->min) > a->len / 2)
        {
            while (find_ind(a, a->min) && ind > b->len / 2 && ind)
			{
                rrr(a, b);
				change_ind(1, &ind, b->len);
			}
			while (find_ind(a, a->min))
				rra(a, 1);
        }
        else
        {
            while (find_ind(a, a->min) && ind < b->len / 2 && ind)
			{
                rr(a, b);
				change_ind(0, &ind, b->len);
			}
			while (find_ind(a, a->min))
				ra(a, 1);
        }
		while (ind)
		{
			while (ind > b->len / 2 && ind)
			{
				rrb(b, 1);
				change_ind(1, &ind, b->len);
			}
			while (ind != 0)
			{
				rb(b, 1);
				change_ind(0, &ind, b->len);
			}
		}
    }
    else if (b->arr[ind] > a->max)
    {
        if (find_ind(a, a->max) > a->len / 2)
        {
            while (find_ind(a, a->max) && ind > b->len / 2 && ind)
			{
                rrr(a, b);
				change_ind(1, &ind, b->len);
			}
			while (find_ind(a, a->max))
			{
				rra(a, 1);
				flag = 1;
			}
			if (flag)
	            ra(a, 1);
        }
        else
        {
            while (find_ind(a, a->max) && ind > b->len / 2 && ind)
			{
                rr(a, b);
				change_ind(0, &ind, b->len);
			}
			while (find_ind(a, a->max))
            	ra(a, 1);
        }
		while (ind)
		{
			while (ind > b->len / 2 && ind)
			{
				rrb(b, 1);
				change_ind(1, &ind, b->len);
			}
			while (ind != 0)
			{
				rb(b, 1);
				change_ind(0, &ind, b->len);
			}
		}
    }
    pa(a, b);
}

void	fill_range(t_stack *a, t_stack *b, int min_limit, int flag)
{
	int	mvs;

	if (flag)
	{
		pa(a, b);
		pa(a, b);
		pa(a, b);
		find_values(a);
		sort_small(a);
	}
	find_values(a);
	while (to_do(b, min_limit, b->max + 1))
	{
		mvs = decide(a, b);
		find_place_and_insert2(a, b, mvs);
        find_values(a);
        find_values(b);
	}
}


void	sort(t_stack *a, t_stack *b)
{
	int	s_half;
	int	f_half;
	int	t_half;

	find_values(a);
	s_half = get_half(a, a->min, a->max);
	f_half = get_half(a, a->min, s_half);
	t_half = get_half(a, s_half, a->max);
	range(a, b, a->min, f_half);
	find_values(b);
	range(a, b, f_half, s_half);
	find_values(b);
	range(a, b, s_half, t_half);
	find_values(b);
	range(a, b, t_half, a->max);
	find_values(b);
	fill_range(a, b, t_half, 1);
	fill_range(a, b, s_half, 0);
	fill_range(a, b, f_half, 0);
	fill_range(a, b, b->min, 0);
	find_values(a);
	while (find_ind(a, a->min))
		rra(a, 1);
}
