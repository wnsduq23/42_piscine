/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kra>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:24:16 by siseo             #+#    #+#             */
/*   Updated: 2022/02/13 13:43:43 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_valid_arg(char *str, int view[16]);
void	init_board(int board[4][4]);
int		set_board(int board[4][4], int view[16], int row, int col);
void	print_board(int board[4][4]);

int	main(int argc, char *argv[])
{
	int	view[16];
	int	board[4][4];

	if (argc != 2 || !is_valid_arg(argv[1], view))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	init_board(board);
	if (set_board(board, view, 0, 0))
		print_board(board);
	else
		write(1, "Error\n", 6);
	return (0);
}
