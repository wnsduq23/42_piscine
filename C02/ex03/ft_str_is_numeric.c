/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junykim <junykim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:42:50 by junykim           #+#    #+#             */
/*   Updated: 2022/02/10 19:42:37 by junykim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	index;
	int	flag;

	index = 0;
	flag = 1;
	while (*(str + index) != '\0')
	{
		if (str[index] < '0' || str[index] > '9')
		{
			flag = 0;
			break ;
		}
		index++;
	}
	return (flag);
}
