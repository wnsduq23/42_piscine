/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:45:21 by junykim           #+#    #+#             */
/*   Updated: 2022/02/08 20:04:38 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	flag;
	int	index;

	index = 0;
	flag = 1;
	while (*(str + index) != '\0')
	{
		if (32 > str[index] || str[index] > 126)
		{
			flag = 0;
			break ;
		}
		index++;
	}
	return (flag);
}
