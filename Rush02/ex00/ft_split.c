/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:21:31 by chanhapa          #+#    #+#             */
/*   Updated: 2022/02/20 20:24:08 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	char	*str_sp;
	int		i;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * (_malloc_size(str, charset) + 1));
	if (!ret)
		return (0);
	while (*str)
	{
		while (_is_in(*str, charset) && *str)
			str++;
		if (!*str)
			break ;
		str_sp = str;
		while (!_is_in(*str, charset) && *str)
			str++;
		ret[i] = (char *)malloc(sizeof(char) * (str - str_sp + 1));
		if (!ret[i])
			return (0);
		ft_strncpy(ret[i], str_sp, str - str_sp);
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	_malloc_size(char *str, char *charset)
{
	int		len;

	len = 0;
	while (*str)
	{
		while (_is_in(*str, charset) && *str)
			str++;
		while (!_is_in(*str, charset) && *str)
			str++;
		len++;
	}
	return (len);
}

int	_is_in(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
		dest[i++] = '\0';
	return (dest);
}

char	*ft_trim(char *str, int is_num)
{
	char	*str_s;

	str_s = str;
	if (is_num == 1)
	{
		while (*str != ' ')
			str++;
		*str = 0;
		return (str_s);
	}
	else
	{
		while (*str == ' ')
			str++;
		return (str);
	}
}
