/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:43:44 by junykim           #+#    #+#             */
/*   Updated: 2022/02/23 20:44:48 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			if (verify_map(av[i]) == 0)
				;
			else
				print_solution(i, av);
			if (i != ac - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
