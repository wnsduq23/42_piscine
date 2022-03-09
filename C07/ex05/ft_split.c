/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:55:38 by junykim           #+#    #+#             */
/*   Updated: 2022/02/21 20:41:33 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	if (c == 0)
		return (1);
	return (0);
}

long long	get_word_cnt(char *str, char *charset)
{
	long long	cnt;

	cnt = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			cnt++;
			while (*str && !is_charset(*str, charset))
				str++;
		}
		str++;
	}
	return (cnt);
}

void	ft_strcpy(char *dest, char *from, char *until)
{
	while (from < until)
		*(dest++) = *(from++);
	*dest = 0;
}

char	**ft_split(char *str, char *charset)
{
	char		**ret;
	char		*from;
	long long	i;

	ret = malloc(sizeof(char *) * get_word_cnt(str, charset) + 1);
	if (!ret)
		return (0);
	i = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			from = str;
			while (*str && !is_charset(*str, charset))
				str++;
			ret[i] = (char *)malloc(str - from + 1);
			ft_strcpy(ret[i++], from, str);
			if (!*str)
				break ;
		}
		str++;
	}
	ret[i] = 0;
	return (ret);
}
