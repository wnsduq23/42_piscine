/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:05:28 by junykim           #+#    #+#             */
/*   Updated: 2022/02/21 20:57:20 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
		*(dest++) = *(src++);
	return (dest);
}

void	make_joined_string(int size, char *total, char **strs, char *sep)
{
	int		i;
	char	*tmp;

	tmp = ft_strcpy(total, strs[0]);
	i = 1;
	while (i < size)
	{
		tmp = ft_strcpy(tmp, sep);
		tmp = ft_strcpy(tmp, strs[i++]);
	}
	*tmp = 0;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_length;
	int		i;
	char	*total;

	if (!size)
	{
		total = (char *)malloc(1);
		total[0] = 0;
		return (total);
	}
	total_length = 0;
	i = 0;
	while (i < size)
		total_length += ft_strlen(strs[i++]);
	total = (char *)malloc(total_length + 1 + ft_strlen(sep) * (size - 1));
	if (!total)
		return (0);
	make_joined_string(size, total, strs, sep);
	return (total);
}
