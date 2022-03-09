/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:24:05 by junykim           #+#    #+#             */
/*   Updated: 2022/02/15 17:33:32 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
unsigned int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (*(str + index))
		index++;
	return (index);
}

void	ft_putnbr(int nbr, char *base)
{
	int	base_len;

	base_len = ft_strlen(base);
	if (nbr == 0)
		return ;
	ft_putnbr(nbr / base_len, base);
	write(1, &base[nbr % base_len], 1);
}

int	Except_check(char *base)
{
	int	len;
	int	i;

	len = 0;
	while (base[len])
	{
		i = len;
		if (base[len] == '+' || base[len] == '-')
			return (1);
		while (base[++i])
		{
			if (base[len] == base[i])
				return (1);
		}
		len++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long		tmp;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (Except_check(base) || base_len == 0 || base_len == 1)
		return ;
	tmp = nbr;
	if (tmp < 0)
	{
		write(1, "-", 1);
		tmp *= -1;
	}
	ft_putnbr(tmp / base_len, base);
	write(1, &base[tmp % base_len], 1);
}
