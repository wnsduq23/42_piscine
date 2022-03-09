/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:49:57 by junykim           #+#    #+#             */
/*   Updated: 2022/02/09 09:01:53 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
char	g_str[10];

void	ft_recur(int n, int x)
{
	if (x == n)
		return ;
	while (++g_str[x] <= '9')
	{
		g_str[x + 1] = g_str[x];
		ft_recur(n, x + 1);
		if (g_str[x + 1] <= '9')
		{
			write(1, g_str, n);
			if (g_str[0] != '9' - n + 1)
				write(1, ", ", 2);
		}
	}
}

void	ft_print_combn(int n)
{
	int	x;

	x = 0;
	g_str[0] = '0' - 1;
	ft_recur(n, x);
}
