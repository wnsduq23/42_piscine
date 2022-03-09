/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:11:00 by junykim           #+#    #+#             */
/*   Updated: 2022/02/10 19:41:00 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	convert_to_16(unsigned char *c)
{
	if (*c > 9)
		*c += 87;
	else
		*c += 48;
}

void	ft_printstr(unsigned char c)
{
	unsigned char	af_bsh[2];
	char			bslash;

	bslash = '\\';
	af_bsh[0] = c / 16;
	af_bsh[1] = c % 16;
	convert_to_16(&af_bsh[0]);
	convert_to_16(&af_bsh[1]);
	write(1, &bslash, 1);
	write(1, &af_bsh[0], 1);
	write(1, &af_bsh[1], 1);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str > 126)
			ft_printstr(*str);
		else
			write(1, str, 1);
		str++;
	}
}
