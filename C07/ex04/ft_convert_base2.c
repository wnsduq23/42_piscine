/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:54:17 by junykim           #+#    #+#             */
/*   Updated: 2022/02/21 20:40:35 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	is_space(char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	my_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int	except_check(char *base)
{
	int	len;
	int	i;

	len = 0;
	while (base[len])
	{
		i = len;
		if (base[len] == '+' || base[len] == '-' || is_space(base[len]))
			return (1);
		while (base[++i])
		{
			if (base[len] == base[i])
				return (1);
		}
		len++;
	}
	if (len <= 1)
		return (1);
	return (0);
}

int	nbr_size(long long nbr, int base_len)
{
	int	ans;

	if (!nbr)
		return (1);
	ans = 0;
	if (nbr < 0)
		ans++;
	while (nbr)
	{
		nbr /= base_len;
		ans++;
	}
	return (ans);
}
