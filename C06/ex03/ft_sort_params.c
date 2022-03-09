/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 11:20:08 by junykim           #+#    #+#             */
/*   Updated: 2022/02/17 20:29:11 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	ft_strcmp(char *a, char *b)
{
	int	i;

	i = 0;
	while ((a[i] || b[i]) && (a[i] == b[i]))
		i++;
	return (a[i] - b[i]);
}

void	ft_swap(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	print_argv(int i, int argc, char **argv)
{
	while (i < argc)
	{
		while (*argv[i])
			write(1, argv[i]++, 1);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	flag;
	int	argc1;

	argc1 = argc;
	while (1)
	{
		i = 0;
		flag = 1;
		while (++i < argc1 - 1)
		{
			if (ft_strcmp(argv[i], argv[i + 1]) > 0)
			{
				ft_swap(&argv[i], &argv[i + 1]);
				flag = 0;
			}
		}
		argc1--;
		if (flag == 1)
			break ;
	}
	print_argv(1, argc, argv);
	return (0);
}
