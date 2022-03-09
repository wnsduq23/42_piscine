/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:44:20 by junykim           #+#    #+#             */
/*   Updated: 2022/02/23 20:45:09 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

int	verify_chars(char *argv)
{
	int		i;
	int		fd;
	char	*buf;
	char	type[3];

	i = -1;
	while (++i < 3)
		type[i] = get_cell_type(argv, 3 - i);
	if (!verify_cell_type(type))
		return (0);
	fd = open(argv, O_RDONLY);
	skip_first_row(fd);
	buf = malloc(sizeof(char) * get_file_size(argv));
	if (!buf)
		return (0);
	i = read(fd, buf, get_file_size(argv));
	buf[i] = '\0';
	i = -1;
	while (buf[++i])
		if (buf[i] != type[0] && buf[i] != type[1] && buf[i] != '\n')
			return (0);
	close(fd);
	free(buf);
	return (1);
}

int	get_next_cols(char *argv, int fd)
{
	char	*buf;
	int		j;
	int		size_file;

	j = 0;
	size_file = get_file_size(argv);
	buf = malloc(size_file * sizeof(char));
	if (!buf)
		return (0);
	while (read(fd, &buf[j], 1))
	{
		if (buf[j] == '\n')
			break ;
		j++;
	}
	free(buf);
	return (j + 1);
}

int	verify_columns(char *argv)
{
	int	fd;
	int	i;
	int	j;

	i = 0;
	j = 0;
	fd = open(argv, O_RDONLY);
	skip_first_row(fd);
	while (i < g_row)
	{
		j = get_next_cols(argv, fd);
		if (j != g_col)
			return (0);
		i++;
	}
	close(fd);
	return (1);
}

int	verify_returns(char *argv)
{
	char	*buf;
	int		fd;
	int		file_size;
	int		ret;

	ret = 0;
	file_size = get_file_size(argv);
	fd = open(argv, O_RDONLY);
	skip_first_row(fd);
	buf = malloc(sizeof(char) * file_size);
	if (!buf)
		return (0);
	ret = read(fd, buf, g_col);
	while (ret)
	{
		if (buf[ret - 1] != '\n')
			return (0);
		ret = read(fd, buf, g_col);
	}
	free(buf);
	close(fd);
	return (1);
}

int	verify_map(char *argv)
{
	g_col = get_number_cols(argv);
	g_row = get_number_rows(argv);
	if (g_col < 1 || g_row < 1 || \
		!verify_chars(argv) || !verify_returns(argv) || !verify_columns(argv))
	{
		ft_putstr("map error\n");
		return (0);
	}
	return (1);
}
