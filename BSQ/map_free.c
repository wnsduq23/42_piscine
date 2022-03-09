/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:46:57 by junykim           #+#    #+#             */
/*   Updated: 2022/02/23 20:47:07 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BSQ.h"

void	free_int_map(int **map)
{
	int	i;

	i = -1;
	while (++i < g_row)
		free(map[i]);
	free(map);
}

void	free_char_map(char **map)
{
	int	i;

	i = -1;
	while (++i < g_row)
		free(map[i]);
	free(map);
}
