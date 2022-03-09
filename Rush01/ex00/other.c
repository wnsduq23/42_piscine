/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kra>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:23:59 by siseo             #+#    #+#             */
/*   Updated: 2022/02/13 13:05:23 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_arg(char *str, int view[16])
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			if (str[i] < '1' || str[i] > '4')
				return (0);
			if (cnt == 16)
				return (0);
			view[cnt] = str[i] - '0';
			cnt++;
		}
		else if (str[i] != ' ')
			return (0);
		i++;
	}
	if (cnt != 16 || i != 31)
		return (0);
	return (1);
}

int	is_exist_same_line(int board[4][4], int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (board[i][col] == board[row][col])
			return (1);
		i++;
	}
	i = 0;
	while (i < col)
	{
		if (board[row][i] == board[row][col])
			return (1);
		i++;
	}
	return (0);
}
