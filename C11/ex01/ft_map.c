/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:16:00 by junykim           #+#    #+#             */
/*   Updated: 2022/02/23 10:55:04 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*ans;
	int	i;

	ans = (int *)malloc(sizeof(int) * length);
	if (!ans)
		return (0);
	i = -1;
	while (++i < length)
		ans[i] = f(tab[i]);
	return (ans);
}
