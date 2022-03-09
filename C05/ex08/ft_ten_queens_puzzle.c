/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:55:31 by junykim           #+#    #+#             */
/*   Updated: 2022/02/19 12:59:24 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	is_catch(int *board, int x, int y)
{
	int	i;

	i = -1;
	while (++i < x)
	{
		if (y == board[i] || \
			i + board[i] == x + y || i - board[i] == x - y)
			return (0);
	}
	return (1);
}

void	ft_running(int *board, int *row, int col)
{
	int	i;
	int	j;

	if (col == 10)
	{
		*row += 1;
		j = -1;
		while (++j < 10)
			ft_putchar(board[j] + '0');
		ft_putchar('\n');
	}
	else
	{
		i = -1;
		while (++i < 10)
		{
			if (is_catch(board, col, i))
			{
				board[col] = i;
				ft_running(board, row, col + 1);
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	i;
	int	row;

	i = -1;
	while (++i < 10)
		board[i] = -1;
	row = 0;
	ft_running(board, &row, 0);
	return (row);
}
