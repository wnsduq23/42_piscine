/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanhapa <chanhapa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:23:07 by chanhapa          #+#    #+#             */
/*   Updated: 2022/02/20 20:23:04 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strlen(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	while (*str)
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	return (num);
}

char	*ft_strndup(char *src, int n)
{
	int		len;
	char	*new_str;

	len = 0;
	while (src[len] && len < n)
		len++;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (0);
	new_str[len] = 0;
	while (len-- > 0)
		new_str[len] = src[len];
	return (new_str);
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*new_str;

	len = 0;
	while (src[len])
		len++;
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (0);
	new_str[len] = 0;
	while (len-- >= 0)
		new_str[len] = src[len];
	return (new_str);
}

int	is_valid_argu(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(1, "error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
