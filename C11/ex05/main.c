/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:23:00 by junykim           #+#    #+#             */
/*   Updated: 2022/02/23 10:49:41 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ex05.h"
void	do_op(int a, int b, void (*f[5])(int, int), char c)
{
	if (c == '+')
		f[0](a, b);
	else if (c == '-')
		f[1](a, b);
	else if (c == '*')
		f[2](a, b);
	else if (c == '/')
		f[3](a, b);
	else if (c == '%')
		f[4](a, b);
	else
		write(1, "0\n", 2);
}

int	main(int ac, char **av)
{
	int		v1;
	int		v2;
	void	(*f[5])(int, int);

	f[0] = &add;
	f[1] = &sub;
	f[2] = &mul;
	f[3] = &div;
	f[4] = &mod;
	if (ac == 4)
	{
		v1 = ft_atoi(av[1]);
		v2 = ft_atoi(av[3]);
		if (av[2][1] != 0)
		{
			write(1, "0\n", 2);
			return (0);
		}
		do_op(v1, v2, f, av[2][0]);
	}
	return (0);
}
