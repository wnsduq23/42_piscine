/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_celltype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:43:53 by junykim           #+#    #+#             */
/*   Updated: 2022/02/23 20:44:54 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

char	get_cell_type(char *argv, int type)
{
	int		i;
	int		fd;
	char	c;
	char	*buf;

	i = 0;
	fd = open(argv, O_RDONLY);
	buf = malloc(80 * sizeof(char));
	if (!buf)
		return (0);
	while (read(fd, &buf[i], 1))
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	c = buf[i - type];
	free(buf);
	close(fd);
	return (c);
}

int	verify_cell_type(char type[3])
{
	int	i;

	if (type[0] == type[1] || type[0] == type[2] || type[1] == type[2])
		return (0);
	i = -1;
	while (++i < 3)
	{
		if (type[i] < 32 || type[i] == 127)
			return (0);
	}
	return (1);
}
