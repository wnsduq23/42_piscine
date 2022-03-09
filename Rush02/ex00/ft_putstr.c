/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 20:20:29 by junykim           #+#    #+#             */
/*   Updated: 2022/02/20 20:20:37 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putstr_ns(char *str)
{
	while (*str == ' ')
		str++;
	while (*str)
		write(1, str++, 1);
}

void	ft_putstr(char *str)
{
	while (*str == ' ')
		str++;
	while (*str)
		write(1, str++, 1);
	write(1, " ", 1);
}
