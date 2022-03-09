/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 08:24:43 by junykim           #+#    #+#             */
/*   Updated: 2022/02/21 20:32:15 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*dest;
	int			*tmp;

	if (min >= max)
		return (0);
	dest = (int *)malloc(sizeof(int) * (long long)(max - min));
	if (!dest)
		return (0);
	tmp = dest;
	while (min < max)
	{
		*tmp = min++;
		tmp++;
	}
	return (dest);
}
