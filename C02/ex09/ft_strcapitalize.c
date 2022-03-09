/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:17:33 by junykim           #+#    #+#             */
/*   Updated: 2022/02/10 13:42:07 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	delim(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (2);
	else if (c >= 'a' && c <= 'z')
		return (3);
	return (4);
}

char	*ft_strlowcase1(char *b)
{
	char	*c;

	c = b;
	while (*c)
	{
		if ('A' <= *c && *c <= 'Z')
			*c = *c - 'A' + 'a';
		c++;
	}
	return (b);
}

char	*ft_strcapitalize(char *str)
{
	int		flag;
	int		index;
	char	*a;

	flag = 1;
	a = ft_strlowcase1(str);
	if (delim(a[0]) == 3)
		a[0] = a[0] - 'a' + 'A';
	index = 0;
	while (a[index])
	{
		if (delim(a[index]) == 4)
			flag = 0;
		if (flag == 0 && delim(a[index]) != 4)
		{
			if (delim(a[index]) == 3)
				a[index] = a[index] - 'a' + 'A';
			flag = 1;
		}
		index++;
	}
	return (str);
}
