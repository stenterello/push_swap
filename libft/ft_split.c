/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <ddelladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:48:24 by ddelladi          #+#    #+#             */
/*   Updated: 2022/01/19 16:27:34 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <signal.h>

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;
	int	flag;

	i = 0;
	words = 0;
	flag = 1;
	while (*(s + i) != '\0')
	{
		if (*(s + i) != c && flag == 1)
		{
			words++;
			flag = 0;
		}
		if (*(s + i) == c)
			flag = 1;
		i++;
	}
	return (words);
}

static int	count_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) != '\0' && *(s + i) != c)
		i++;
	return (i);
}

static int	find_start(const char *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) == c)
		i++;
	return (i);
}

static int	find_next_start(const char *s, char c)
{
	int	i;

	i = 0;
	while (*(s + i) != c && *(s + i) != '\0')
		i++;
	i += find_start(&s[i], c);
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		words;
	char	**ret;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	ret = malloc(sizeof(char *) * (words + 1));
	if (!ret)
		return (NULL);
	i = 0;
	start = find_start(s, c);
	while (i < words)
	{
		ret[i] = malloc(sizeof(char) * count_len(&s[start], c) + 1);
		if (!ret[i])
			return (NULL);
		ft_strlcpy(ret[i], &s[start], count_len(&s[start], c) + 1);
		start += find_next_start(&s[start], c);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
