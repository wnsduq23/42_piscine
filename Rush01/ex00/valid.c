/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siseo <siseo@student.42seoul.kra>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:24:27 by siseo             #+#    #+#             */
/*   Updated: 2022/02/13 17:11:23 by taekwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	up_valid(int board[4][4], int *up)
{
	int	i;
	int	j;
	int	cnt;
	int	max;

	i = 0;
	while (i < 4)
	{
		cnt = 0;
		max = 0;
		j = 0;
		while (j < 4)
		{
			if (max < board[j][i])
			{
				max = board[j][i];
				cnt++;
			}
			j++;
		}
		if (cnt != up[i])
			return (0);
		i++;
	}
	return (1);
}

int	down_valid(int board[4][4], int *down)
{
	int	i;
	int	j;
	int	cnt;
	int	max;

	i = 0;
	while (i < 4)
	{
		cnt = 0;
		max = 0;
		j = 0;
		while (j < 4)
		{
			if (max < board[3 - j][i])
			{
				max = board[3 - j][i];
				cnt++;
			}
			j++;
		}
		if (cnt != down[i])
			return (0);
		i++;
	}
	return (1);
}

int	left_valid(int board[4][4], int *left)
{
	int	i;
	int	j;
	int	cnt;
	int	max;

	i = 0;
	while (i < 4)
	{
		cnt = 0;
		max = 0;
		j = 0;
		while (j < 4)
		{
			if (max < board[i][j])
			{
				max = board[i][j];
				cnt++;
			}
			j++;
		}
		if (cnt != left[i])
			return (0);
		i++;
	}
	return (1);
}

int	right_valid(int board[4][4], int *right)
{
	int	i;
	int	j;
	int	cnt;
	int	max;

	i = 0;
	while (i < 4)
	{
		cnt = 0;
		max = 0;
		j = 0;
		while (j < 4)
		{
			if (max < board[i][3 - j])
			{
				max = board[i][3 - j];
				cnt++;
			}
			j++;
		}
		if (cnt != right[i])
			return (0);
		i++;
	}
	return (1);
}

int	board_view_checker(int board[4][4], int view[16])
{
	if (!up_valid(board, &view[0]))
		return (0);
	if (!down_valid(board, &view[4]))
		return (0);
	if (!left_valid(board, &view[8]))
		return (0);
	if (!right_valid(board, &view[12]))
		return (0);
	return (1);
}
