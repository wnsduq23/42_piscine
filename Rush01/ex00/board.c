/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kra>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:24:09 by siseo             #+#    #+#             */
/*   Updated: 2022/02/13 17:59:41 by siseo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	board_view_checker(int board[4][4], int view[16]);
int	is_exist_same_line(int board[4][4], int row, int col);

void	print_board(int board[4][4])
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tmp = board[i][j] + '0';
			write(1, &tmp, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	set_board(int board[4][4], int view[16], int row, int col)
{
	int	height;

	if (row == 4)
	{
		if (board_view_checker(board, view))
			return (1);
		return (0);
	}
	else if (col == 4)
		return (set_board(board, view, row + 1, 0));
	else
	{
		height = 1;
		while (height < 5)
		{
			board[row][col] = height;
			if (!is_exist_same_line(board, row, col))
				if (set_board(board, view, row, col + 1))
					return (1);
			height++;
		}
	}
	return (0);
}

void	init_board(int board[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
}
