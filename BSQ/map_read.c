/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:44:04 by junykim           #+#    #+#             */
/*   Updated: 2022/02/23 20:45:05 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

int	get_number_rows(char *argv)
{
	int		i;
	char	*buf;
	int		num_row;
	int		fd;

	i = 0;
	num_row = 0;
	fd = open(argv, O_RDONLY);
	buf = malloc(sizeof(char) * 80);
	if (!buf)
		return (0);
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] > '9' || buf[i] < '0')
			break ;
		num_row = num_row * 10 + (buf[i] - '0');
		i++;
	}
	free(buf);
	close(fd);
	return (num_row);
}

int	get_number_cols(char *argv)
{
	char	*buf;
	int		j;
	int		size_file;
	int		fd;

	j = 0;
	fd = open(argv, O_RDONLY);
	size_file = get_file_size(argv);
	skip_first_row(fd);
	buf = malloc(sizeof(char) * size_file);
	if (!buf)
		return (0);
	while (read(fd, &buf[j], 1))
	{
		if (buf[j] == '\n')
			break ;
		j++;
	}
	free(buf);
	close(fd);
	return (j + 1);
}

void	skip_first_row(int fd)
{
	int		i;
	char	*buf;

	i = 0;
	buf = malloc(sizeof(char) * 4096);
	if (!buf)
		return ;
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	free(buf);
}

void	buf_init(int fd, char **buf)
{
	int	i;
	int	ret;

	i = -1;
	while (++i < g_row)
	{
		buf[i] = malloc(sizeof(char) * g_col);
		if (!buf[i])
			return ;
		ret = read(fd, buf[i], g_col);
		if (ret == -1)
			return ;
		buf[i][g_col - 1] = 0;
	}
}

char	**read_file(char *argv)
{
	char	**buf;
	int		fd;
	int		ret;

	ret = 0;
	fd = open(argv, O_RDONLY);
	skip_first_row(fd);
	buf = malloc(sizeof(char *) * g_row);
	if (!buf)
		return (0);
	buf_init(fd, buf);
	close(fd);
	return (buf);
}
