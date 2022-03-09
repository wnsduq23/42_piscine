/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 15:21:52 by junykim           #+#    #+#             */
/*   Updated: 2022/02/09 09:16:10 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	change_to_str(int a, int b)
{
	char	x;
	char	y;

	x = '0' + a / 10;
	y = '0' + a % 10;
	write(1, &x, 1);
	write(1, &y, 1);
	write(1, " ", 1);
	x = '0' + b / 10;
	y = '0' + b % 10;
	write(1, &x, 1);
	write(1, &y, 1);
	write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a != 98)
	{
		b = a + 1;
		while (b != 100)
		{
			change_to_str(a, b);
			b++;
		}
		a++;
	}
	write(1, "98 99", 5);
}
