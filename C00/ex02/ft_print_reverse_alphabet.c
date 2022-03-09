/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:15:46 by junykim           #+#    #+#             */
/*   Updated: 2022/02/03 20:44:03 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
void	ft_print_reverse_alphabet(void)
{
	char	ip;

	ip = 'z';
	while (ip >= 'a')
	{
		write(1, &ip, 1);
		ip-- ;
	}
}
