/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:39:15 by junykim           #+#    #+#             */
/*   Updated: 2022/02/21 20:40:02 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	my_strlen(char *str);
int	nbr_size(long long nbr, int base_len);
int	except_check(char *base);
int	is_space(char c);

char	*is_zero(char *base)
{
	char	*ans;

	ans = (char *)malloc(sizeof(char) * 2);
	ans[0] = base[0];
	ans[1] = 0;
	return (ans);
}

char	*putnbr_b(int nbr, char *base)
{
	long long		tmp;
	unsigned int	base_len;
	char			*ans;
	int				size;

	if (nbr == 0)
		return (is_zero(base));
	tmp = nbr;
	base_len = my_strlen(base);
	size = nbr_size(tmp, base_len);
	ans = (char *)malloc(size + 1);
	if (!ans)
		return (0);
	ans[size] = 0;
	if (tmp < 0)
		tmp *= -1;
	while (tmp)
	{
		ans[--size] = base[tmp % base_len];
		tmp /= base_len;
	}
	if (nbr < 0)
		ans[0] = '-';
	return (ans);
}

int	atoi_b(char *str, char *base)
{
	int	sign;
	int	ans;
	int	idx;

	sign = 1;
	ans = 0;
	while (is_space(*str))
		str++;
	while (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str)
	{
		idx = -1;
		while (++idx < my_strlen(base))
		{
			if (*str == base[idx])
				break ;
		}
		if (idx == my_strlen(base))
			break ;
		ans = ans * my_strlen(base) + idx;
		str++;
	}
	return (sign * ans);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (except_check(base_from) || except_check(base_to))
		return (0);
	return (putnbr_b(atoi_b(nbr, base_from), base_to));
}
