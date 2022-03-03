/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:42:32 by ddelladi          #+#    #+#             */
/*   Updated: 2022/01/19 16:25:49 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	int		i;

	i = 0;
	if (!s || start > ft_strlen(s))
		return (NULL);
	if (ft_strlen(s) + 1 > len)
		ret = malloc(sizeof(char) * (len + 1));
	else
		ret = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!ret)
		return (NULL);
	while ((size_t) i < len && s[start] != '\0' && start < ft_strlen(s))
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}
