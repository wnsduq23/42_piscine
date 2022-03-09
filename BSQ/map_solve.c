/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:44:12 by junykim           #+#    #+#             */
/*   Updated: 2022/02/24 10:28:47 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

int	**malloc_map(void)
{
	int	**map;
	int	i;

	i = 0;
	map = malloc(sizeof(int *) * g_row);
	if (!map)
		return (0);
	while (i < g_row)
	{
		map[i] = malloc(sizeof(int) * g_col);
		if (!map[i])
			return (0);
		i++;
	}
	return (map);
}

int	get_max_length(char **map, int **c_map, char obst, int max_length)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_row)
	{
		j = -1;
		while (++j < g_col - 1)
		{
			if (map[i][j] == obst)
				c_map[i][j] = 0;
			else if (i == 0 || j == 0)
				c_map[i][j] = 1;
			else
				c_map[i][j] = ft_min(c_map[i - 1][j], \
						c_map[i][j - 1], c_map[i - 1][j - 1]) + 1;
			if (c_map[i][j] > max_length)
			{
				max_length = c_map[i][j];
				g_pos = i * (g_col - 1) + j;
			}
		}
	}
	return (max_length);
}

char	**fill_map(char **map, char *cell_types)
{
	int	i;
	int	j;
	int	length;
	int	**c_map;

	c_map = malloc_map();
	if (c_map == 0)
		return (0);
	length = get_max_length(map, c_map, cell_types[0], 0);
	i = g_pos / (g_col - 1) - length + 1;
	while (i < g_pos / (g_col - 1) + 1)
	{
		j = g_pos % (g_col - 1) - length + 1;
		while (j < g_pos % (g_col - 1) + 1)
		{
			map[i][j] = cell_types[1];
			j++;
		}
		i++;
	}
	free_int_map(c_map);
	return (map);
}

void	print_solution(int i, char **argv)
{
	int		fd;
	char	**map;
	int		j;
	char	cell_types[2];

	map = 0;
	cell_types[0] = get_cell_type(argv[i], 2);
	cell_types[1] = get_cell_type(argv[i], 1);
	fd = open(argv[i], O_RDONLY);
	if (fd >= 0)
		map = read_file(argv[i]);
	fill_map(map, cell_types);
	j = -1;
	while (++j < g_row)
	{
		ft_putstr(map[j]);
		ft_putchar('\n');
	}
	free_char_map(map);
	close(fd);
}
