/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:21:13 by junykim           #+#    #+#             */
/*   Updated: 2022/02/03 20:47:27 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_print_numbers(void)
{
	char	ip;

	ip = '0';
	while (ip <= '9')
	{
		write(1, &ip, 1);
		ip++ ;
	}
}